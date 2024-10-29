from time import time
from typing import Annotated

from fastapi import APIRouter, Depends, Response, Cookie
from fastapi.security import HTTPBasic, HTTPBasicCredentials

from .dependencies import (
    get_auth_user_username,
    get_username_by_static_token,
    COOKIES,
    COOKIES_SESSION_ID_KEY,
    generate_session_id,
    get_session_data,
)


router = APIRouter(prefix="/demo-auth", tags=["Demo auth"])

security = HTTPBasic()


@router.get("/basic-auth/")
def demo_basic_auth_credentials(
    credentials: Annotated[HTTPBasicCredentials, Depends(security)],
):
    return {
        "message": "Auth User",
        "username": credentials.username,
        "password": credentials.password,
    }


@router.get("/basic-auth-username/")
def demo_basic_auth_username(
    auth_username: str = Depends(get_auth_user_username),
):
    return {"message": f"Hi, {auth_username}", "username": auth_username}


@router.get("/some-http-header-auth/")
def demo_auth_some_http_header(
    username: str = Depends(get_username_by_static_token),
):
    return {"message": f"Hi, {username}", "username": username}


@router.post("/login-cookie/")
def demo_auth_login_set_cookie(
    response: Response,
    auth_username: str = Depends(get_auth_user_username),
):
    session_id = generate_session_id()
    COOKIES[session_id] = {
        "username": auth_username,
        "login_at": int(time()),
    }
    response.set_cookie(COOKIES_SESSION_ID_KEY, session_id)
    return {"result": "ok"}


@router.get("/check-coolie")
def demo_auth_check_cookie(
    user_session_data: dict = Depends(get_session_data),
):
    username = user_session_data["username"]
    return {"message": f"Hello {username}", **user_session_data}


@router.get("/logout-cookie/")
def demo_logout_cookie(
    response: Response,
    session_id: str = Cookie(alias=COOKIES_SESSION_ID_KEY),
    user_session_data: dict = Depends(get_session_data),
):
    COOKIES.pop(session_id)
    response.delete_cookie(COOKIES_SESSION_ID_KEY)
    username = user_session_data["username"]
    return {"message": f"Bye, {username}!"}
