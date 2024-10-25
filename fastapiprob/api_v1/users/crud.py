from sqlalchemy.ext.asyncio import AsyncSession
from sqlalchemy import select
from sqlalchemy.engine import Result
from sqlalchemy.orm import joinedload, selectinload

from core.models import User, Profile, Post
from .schemas import CreateUser


async def create_user(session: AsyncSession, username: CreateUser) -> User:
    user = User(**username.model_dump())
    session.add(user)
    await session.commit()

    return user


async def create_user_profile(
    session: AsyncSession,
    user_id: int,
    first_name: str | None = None,
    last_name: str | None = None,
) -> Profile:

    profile = Profile(user_id=user_id, first_name=first_name, last_name=last_name)
    session.add(profile)
    await session.commit()

    return profile


async def get_user_by_username(session: AsyncSession, username: str) -> User | None:
    stmt = select(User).where(User.username == username)
    # result: Result = await session.execute(stmt)
    # user = result.scalar_one_or_none()
    user = await session.scalar(stmt)
    return user


async def show_users_with_profiles(session: AsyncSession) -> list[User]:
    stmt = select(User).options(joinedload(User.profile)).order_by(User.id)

    users = await session.scalars(stmt)

    return users


async def create_posts(
    session: AsyncSession,
    user_id: int,
    *posts_titles: str,
) -> list[Post]:
    posts = [Post(title=title, user_id=user_id) for title in posts_titles]
    session.add_all(posts)
    await session.commit()

    return posts


async def get_users_with_posts(
    session: AsyncSession,
):
    stmt = select(User).options(selectinload(User.posts)).order_by(User.id)
    users = await session.scalars(stmt)

    return users
