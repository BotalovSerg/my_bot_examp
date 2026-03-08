import json
from collections import defaultdict


def export_stats(*args):
    total_comments = 0
    total_likes = 0
    total_categories = len(args)

    users_dict = {}
    for file in args:
        with open(file, "r", encoding="utf-8") as f:
            data = json.load(f)
            total_comments += len(data)

            for item in data:
                total_likes += item.get("likes", 0)
                if item.get("user") not in users_dict:
                    users_dict[item.get("user")] = {
                        "user": item.get("user"),
                        "comments": 1,
                        "likes": item.get("likes"),
                    }
                else:
                    users_dict[item.get("user")]["comments"] += 1
                    users_dict[item.get("user")]["likes"] += item.get("likes")

    users = sorted(users_dict.values(), key=lambda value: (-value["likes"], value["user"]))
    total_users = len(users)
    result = {}
    result["total_comments"] = total_comments
    result["total_likes"] = total_likes
    result["total_users"] = total_users
    result["total_categories"] = total_categories
    result["users"] = users
    with open("stats.json", "w", encoding="utf-8") as f:
        json.dump(result, f, ensure_ascii=False, indent=2)


# export_stats("python_comments.json", "javascript_comments.json")
export_stats("python.json", "javascript.json", "go.json", "rust.json")
