from typing import Annotated
from fastapi import APIRouter, Path


router = APIRouter(prefix="/items", tags=["Items"])


@router.get("/")
def list_items():
    return ["item1", "item2", "item3"]


@router.get("/latest/")
def get_latest_item():
    return {"item": {"id": "0", "name": "Latest"}}


@router.get("/{item_id}/")
def get_item_by_id(item_id: Annotated[int, Path(ge=1)]):
    return {
        "item": {
            "id",
            item_id,
        },
    }