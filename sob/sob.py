import requests
import json

_URL = "https://jsonplaceholder.typicode.com/posts/{0}"


json_list = []

for index in range(1, 11):
    url = _URL.format(index)
    response = requests.get(url)

    response.raise_for_status()
    json_list.append(response.json())

with open("result.json", "+w", encoding="utf-8") as file:
    json.dump(json_list, file)