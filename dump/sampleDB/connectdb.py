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

dt_from = dt.datetime.strptime("2022-09-01T00:00:00", "%Y-%m-%dT%H:%M:%S")
dt_upto = dt.datetime.strptime("2022-12-31T23:59:00", "%Y-%m-%dT%H:%M:%S")
# print(dt_from)
# for item in coll.find({"dt": {"$gte" : dt_from, "$lte": dt_upto}}, {"_id":  0}):
#     print(item)

# query = {"name": "test_4"}
# res = coll.find(query)
# print(f"query: {type(res)}")
    

d = dt.datetime(2022, 9, 1, 0)
f = dt.datetime(2022, 2, 2, 0)

for post in coll.find({"dt": {"$gte" : dt_from, "$lte": dt_upto}}).limit(3):
    pprint.pprint(post)