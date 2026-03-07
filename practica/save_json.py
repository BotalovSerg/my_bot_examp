import json
from collections import defaultdict


def save_profile(data):
    with open("profile.json", "w", encoding="utf-8") as f:
        json.dump(data, f, ensure_ascii=False, indent=2)


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


def export_comments_by_category(comments: list[dict]):
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
        filename = f"{key.lower()}_comments.json"

        with open(filename, "w", encoding="utf-8") as f:
            json.dump(comments_category[key], f, indent=2, ensure_ascii=False)


comments3 = [
    {"user": "Артем", "text": "Python — сила!", "likes": 15, "category": "Python"},
    {"user": "Мария", "text": "Обожаю JavaScript", "likes": 10, "category": "JavaScript"},
    {"user": "John", "text": "JS проще, чем C++", "likes": 7, "category": "JavaScript"},
    {"user": "Alex", "text": "C++ сложный, но мощный", "likes": 12, "category": "C++"},
]

export_comments_by_category(comments3)


def export_poll_results(*args):
    result_votes = defaultdict(int)
    for item in args:
        for key in item:
            result_votes[key] += item[key]

    sorted_items = sorted(result_votes.items(), key=lambda item: item[1], reverse=True)
    total_votes = sum(result_votes.values())

    grouped_results = []
    current_votes = None
    current_languages = []

    for lang, votes in sorted_items:
        if votes != current_votes:
            if current_languages:
                grouped_results.append(
                    {
                        "languages": sorted(current_languages),
                        "votes": current_votes,
                        "percent": round((current_votes / total_votes) * 100, 5),
                    }
                )
            current_votes = votes
            current_languages = [lang]
        else:
            current_languages.append(lang)

    if current_languages:
        grouped_results.append(
            {
                "languages": sorted(current_languages),
                "votes": current_votes,
                "percent": round((current_votes / total_votes) * 100, 5),
            }
        )

    with open("results.json", "w", encoding="utf-8") as f:
        json.dump(grouped_results, f, ensure_ascii=False, indent=2)


export_poll_results(
    {"Python": 10, "Rust": 5, "Go": 15},
    {
        "Python": 20,
        "Java": 20,
        "C++": 5,
    },
    {"Rust": 15, "Kotlin": 10},
)
