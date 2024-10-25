from pydantic import BaseModel


class UserBase(BaseModel):
    username: str


class CreateUser(UserBase):
    username: str


class User(UserBase):
    id: int
