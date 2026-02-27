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


def decode_text(text: str, alphabet: str):
    with open(
        text,
        encoding="utf-8",
    ) as f1, open(
        alphabet,
        encoding="utf-8",
    ) as f2, open(
        "decoded.txt",
        "w",
        encoding="utf-8",
    ) as f3:
        line = f1.read()
        alp = json.load(f2)
        print(line)
        for c in line:
            if c in alp:
                f3.write(alp[c])
            else:
                f3.write(c)


def find_best_manager(path_file: str):
    with open(path_file, encoding="utf-8") as f:
        data = json.load(f)
        best_manager = {}
        max_sum = 0
        for item in data:
            tmp_sum = 0
            for car in item["cars"]:
                tmp_sum += car["price"]
            if tmp_sum > max_sum:
                max_sum = tmp_sum
                best_manager = item["manager"].copy()

        print(f"{best_manager['first_name']} {best_manager['last_name']} {max_sum}")
