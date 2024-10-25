from sqlalchemy.ext.asyncio import AsyncSession
from fastapi import APIRouter, Depends, status

from core.models import db_helper
from .schemas import CreateUser, User
from . import crud

router = APIRouter(tags=["Users"])


@router.post("/")
async def create_user(
    username: CreateUser,
    session: AsyncSession = Depends(db_helper.session_dependency),
):
    return await crud.create_user(session=session, username=username)


@router.get("/", response_model=User)
async def get_user_by_username(
    username: str,
    session: AsyncSession = Depends(db_helper.scoped_session_dependency),
):
    return await crud.get_user_by_username(session=session, username=username)
