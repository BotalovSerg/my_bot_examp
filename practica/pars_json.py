import json


def print_sorted_people(json_string: str):
    dict_people = json.loads(json_string)
    list_sort = sorted(dict_people, key=lambda item: (item["age"], item["name"]))
    for item in list_sort:
        print(item["name"], item["country"], item["age"], sep=", ")


people = '[{"name": "Alice Johnson", "country": "USA", "age": 28}, {"name": "Mark Smith", "country": "UK", "age": 35}, {"name": "Sophie Lee", "country": "Australia", "age": 22}, {"name": "Ivan Petrov", "country": "Russia", "age": 30}]'
# print_sorted_people(people)


with open("group_people.json", encoding="utf-8") as f:
    data = json.load(f)
    m_count = 0
    m_id = 0
    for item in data:
        count = 0
        # print(item.get("id_group"))
        for p in item.get("people"):
            if p.get("gender") == "Female" and p.get("year") > 1977:
                count += 1
        if count > m_count:
            m_count = count
            m_id = item.get("id_group")
    print(f"id {m_id} - count {m_count}")