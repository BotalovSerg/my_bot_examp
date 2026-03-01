import json
from collections import defaultdict


# def save_profile(data):
#     with open("profile.json", "w", encoding="utf-8") as f:
#         json.dump(data, f, ensure_ascii=False, indent=2)


def save_profile(compact=False, sort=False, **data):
    indent = None if compact else 2
    print(data)
    with open("profile.json", "w", encoding="utf-8") as f:
        json.dump(data, f, ensure_ascii=False, indent=indent, sort_keys=sort)


content = {
    "name": "Артем",
    "age": 35,
    "hobbies": ["теннис", "чтение", "программирование"],
    "is_student": False,
}

# save_profile(
#     name="Андрей",
#     age=40,
#     occupation="Data Engineer",
#     country="Россия",
#     compact=True,
#     sort=True,
# )


def export_comments(comments: list[dict], filename: str, reverse=None):
    if reverse is not None:
        comments = sorted(comments, key=lambda item: item["likes"], reverse=reverse)
    with open(filename, "w", encoding="utf-8") as f:
        json.dump(comments, f, indent=2, ensure_ascii=False)


comments = [
    {"user": "Артем", "text": "Отличный урок!", "likes": 12},
    {"user": "Мария", "text": "Спасибо, всё понятно", "likes": 8},
    {"user": "John", "text": "Great explanation!", "likes": 15},
]

export_comments(comments, "comments.json")

comments1 = [
    {"user": "Артем", "text": "Отличный урок!", "likes": 12},
    {"user": "Мария", "text": "Спасибо, всё понятно", "likes": 8},
    {"user": "John", "text": "Great explanation!", "likes": 15},
]

export_comments(comments1, "sorted_desc.json", reverse=True)


def export_grouped_comments(comments: list[dict], filename: str):
    comments_category = defaultdict(list)
    for item in comments:
        comments_category[item["category"]].append(
            {
                "user": item["user"],
                "text": item["text"],
                "likes": item["likes"],
            }
        )
    for key, value in comments_category.items():
        comments_category[key] = sorted(value, key=lambda item: item["likes"], reverse=True)

    with open(filename, "w", encoding="utf-8") as f:
        json.dump(comments_category, f, indent=2, ensure_ascii=False)


comments2 = [
    {"user": "Артем", "text": "Очень классный урок!", "likes": 10, "category": "Python"},
    {"user": "Мария", "text": "Жду продолжения курса!", "likes": 5, "category": "Python"},
    {"user": "John", "text": "JavaScript — the best!", "likes": 8, "category": "JavaScript"},
    {"user": "Alex", "text": "C++ слишком сложный", "likes": 3, "category": "C++"},
    {"user": "Dmitry", "text": "Python forever!", "likes": 12, "category": "Python"},
]

export_grouped_comments(comments2, "grouped.json")
