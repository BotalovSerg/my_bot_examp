from pydantic import BaseModel, EmailStr, ConfigDict


class UserBase(BaseModel):
    username: str


class CreateUser(UserBase):
    username: str


class UserSchema(BaseModel):
    model_config = ConfigDict(strict=True)
    username: str
    password: bytes
    email: EmailStr | None = None
    active: bool = True


class TokenInfo(BaseModel):
    access_token: str
    token_type: str


class UserTgSchema(BaseModel):
    username: str
    telegram_id: int
