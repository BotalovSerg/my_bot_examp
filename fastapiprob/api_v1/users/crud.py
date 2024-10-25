from sqlalchemy.ext.asyncio import AsyncSession
from sqlalchemy import select
from sqlalchemy.engine import Result

from core.models import User, Profile, Post
from .schemas import CreateUser


async def create_user(session: AsyncSession, username: CreateUser) -> User:
    user = User(**username.model_dump())
    session.add(user)
    await session.commit()

    return user


async def get_user_by_username(session: AsyncSession, username: str) -> User | None:
    stmt = select(User).where(User.username == username)
    # result: Result = await session.execute(stmt)
    # user = result.scalar_one_or_none()
    user = await session.scalar(stmt)
    return user
