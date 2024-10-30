from jwt.exceptions import InvalidTokenError
from fastapi import Form, status, HTTPException, Depends
from fastapi.security import HTTPBearer, HTTPAuthorizationCredentials
from .schemas import UserSchema

from auth import utils as auth_utils

http_bearer = HTTPBearer()

user_1 = UserSchema(
    username="Sergey",
    password=auth_utils.hash_password("qwerty"),
    email="test@test.ru",
)

user_2 = UserSchema(
    username="Kina",
    password=auth_utils.hash_password("pena"),
    email="taksa@best.gav",
)

user_db: dict[str, UserSchema] = {
    user_1.username: user_1,
    user_2.username: user_2,
}


def validate_auth_user(
    username: str = Form(),
    password: str = Form(),
):
    unauthed_exc = HTTPException(
        status_code=status.HTTP_401_UNAUTHORIZED,
        detail="Invalide username or password",
    )
    if not (user := user_db.get(username)):
        raise unauthed_exc

    if not auth_utils.validate_password(
        password=password,
        hashed_password=user.password,
    ):
        raise unauthed_exc

    return user


def get_current_auth_user(
    credentials: HTTPAuthorizationCredentials = Depends(http_bearer),
) -> UserSchema:
    token = credentials.credentials
    try:
        payload = auth_utils.dencode_jwt(token=token)
    except InvalidTokenError as e:
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail="Invalid token",
        )

    username = payload.get("sub")

    if not (user := user_db.get(username)):
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail="User not found",
        )

    return user
