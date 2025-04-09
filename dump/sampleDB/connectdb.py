import pymongo
import datetime as dt
import pprint


client = pymongo.MongoClient("mongodb://127.0.0.1:27017")
# db = client.testdata
# coll = db.users

db = client.newdb
coll = db.newcol
# res = coll.insert_one({"_id": 1, "name": "test_1"})
# print("OK")

# data = [
#     {
#         "_id": 9,
#         "name": "test_9",
#         "time": datetime.datetime.now(),
#         "status": True
#     },
#     {
#         "_id": 10,
#         "name": "test_10",
#         "time": datetime.datetime.now(),
#         "status": False
#     },
#     {
#         "_id": 11,
#         "name": "test_11",
#         "time": datetime.datetime.now(),
#         "status": True
#     },
# ]

# coll.insert_many(data)


# print(dt_from)
# for item in coll.find({"dt": {"$gte" : dt_from, "$lte": dt_upto}}, {"_id":  0}):
#     print(item)

# query = {"name": "test_4"}
# res = coll.find(query)
# print(f"query: {type(res)}")


# d = dt.datetime(2022, 9, 1, 0)
# f = dt.datetime(2022, 2, 2, 0)

dt_from = dt.datetime.strptime("2022-09-30T00:00:00", "%Y-%m-%dT%H:%M:%S")
dt_upto = dt.datetime.strptime("2022-10-05T23:59:59", "%Y-%m-%dT%H:%M:%S")
dict_date = {}
# for post in coll.find({"dt": {"$gte" : dt_from, "$lte": dt_upto}}, {"_id":  0}):
#     key = post['dt'].strftime("%Y-%m-%d")
#     dict_date[key] = dict_date.get(key, 0) + post["value"]
# with open('d.txt', '+a') as f:
#     print(post, file=f)

# pprint.pprint(dict_date)
d = (dt_upto - dt_from).days
print(d)

# {
# "dt_from": "2022-09-30T00:00:00",
# "dt_upto": "2022-10-05T23:59:59",
# "group_type": "day"
# }
