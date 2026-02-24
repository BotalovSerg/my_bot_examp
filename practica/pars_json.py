import json


def print_sorted_people(json_string: str):
    dict_people = json.loads(json_string)
    list_sort = sorted(dict_people, key=lambda item: (item["age"], item["name"]))
    for item in list_sort:
        print(item["name"], item["country"], item["age"], sep=", ")


people = '[{"name": "Alice Johnson", "country": "USA", "age": 28}, {"name": "Mark Smith", "country": "UK", "age": 35}, {"name": "Sophie Lee", "country": "Australia", "age": 22}, {"name": "Ivan Petrov", "country": "Russia", "age": 30}]'
print_sorted_people(people)
