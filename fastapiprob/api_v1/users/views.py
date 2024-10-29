from sqlalchemy.ext.asyncio import AsyncSession
from fastapi import APIRouter, Depends, status

from core.models import db_helper
from .schemas import CreateUser, UserSchema, TokenInfo
from . import crud
from .dependencies import validate_auth_user, get_current_auth_user
from auth import utils as auth_utils

router = APIRouter(tags=["Users JWT"])


@router.post("/login/", response_model=TokenInfo)
def auth_user_issue_jwt(user: UserSchema = Depends(validate_auth_user)):
    jwt_payload = {"sub": user.username, "email": user.email}
    token = auth_utils.encode_jwt(jwt_payload)
    return TokenInfo(
        access_token=token,
        token_type="Bearer",
    )


@router.get("/users/me/")
def auth_user_check(user: UserSchema = Depends(get_current_auth_user)):
    return {"username": user.username, "email": user.email}


# @router.post("/")
# async def create_user(
#     username: CreateUser,
#     session: AsyncSession = Depends(db_helper.session_dependency),
# ):
#     return await crud.create_user(session=session, username=username)


# @router.get("/", response_model=User)
# async def get_user_by_username(
#     username: str,
#     session: AsyncSession = Depends(db_helper.scoped_session_dependency),
# ):
#     return await crud.get_user_by_username(session=session, username=username)
