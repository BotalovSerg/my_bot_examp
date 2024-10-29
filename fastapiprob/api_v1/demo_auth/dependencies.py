import secrets
from typing import Annotated, Any
import uuid
from fastapi import HTTPException, status, Depends, Header, Cookie
from fastapi.security import HTTPBasic, HTTPBasicCredentials


security = HTTPBasic()

usernames_to_passwords = {
    "admin": "admin",
    "serg": "qwerty",
}

static_auth_token_to_username = {
    "f583ce61bdabc97b06573930a3abbe5e": "admin",
    "f1aa3386223b85ba74fa54bd93d44552": "Serg",
}

COOKIES: dict[str, dict[str, Any]] = {}
COOKIES_SESSION_ID_KEY = "wep-app-session-id"


def generate_session_id() -> str:
    return uuid.uuid4().hex


def get_auth_user_username(
    credentials: Annotated[HTTPBasicCredentials, Depends(security)],
):
    unauthed_exc = HTTPException(
        status_code=status.HTTP_401_UNAUTHORIZED,
        detail="Invalid username or password",
        headers={"WWW-Authenticate": "Basic"},
    )
    correct_password = usernames_to_passwords.get(credentials.username)
    if correct_password is None:
        raise unauthed_exc

    if not secrets.compare_digest(
        credentials.password.encode("utf-8"),
        correct_password.encode("utf-8"),
    ):
        raise unauthed_exc

    return credentials.username


def get_username_by_static_token(static_token: str = Header(alias="x-auth-token")):
    if static_token not in static_auth_token_to_username:
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail="Invalid token",
        )

    return static_auth_token_to_username[static_token]


def get_session_data(
    session_id: str = Cookie(alias=COOKIES_SESSION_ID_KEY),
) -> dict:
    if session_id not in COOKIES:
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail="not authenticated",
        )
    return COOKIES[session_id]
