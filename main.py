import pymongo
import datetime as dt
#client = pymongo.MongoClient("mongodb://127.0.0.1:27017/?directConnection=true&serverSelectionTimeoutMS=2000&appName=mongosh+1.8.0")
client = pymongo.MongoClient("mongodb://127.0.0.1:27017")
db = client.newdb_1
coll = db.sample_collection

dt_from = dt.datetime.strptime("2022-02-01T00:00:00", "%Y-%m-%dT%H:%M:%S")
dt_upto = dt.datetime.strptime("2022-02-02T00:00:00", "%Y-%m-%dT%H:%M:%S")
group_type = "hour"


res = {
    "dataset" : [],
    "labels" : []
}

d = {}

def get_key(dt_data, agr):
    if agr == "month":
        return dt_data.strftime("%Y-%m") + "-01T00:00:00"
    elif agr == "day":
        return dt_data.strftime("%Y-%m-%d") + "T00:00:00"
    elif agr == "hour":
        return dt_data.strftime("%Y-%m-%dT%H") + ":00:00"


for val in coll.find({"dt": {"$gte" : dt_from, "$lte": dt_upto}}, {"_id":  0}).sort("df", 1):
    #print(val)
    #key = str(val["dt"].year) + "/" + str(val["dt"].month)
    k = get_key(val["dt"], group_type)   
    #d[key] = d.get(key, []) + [val["value"]]
    d[k] = d.get(k, 0) + val["value"]


#print(d)

for key, val in d.items():
    res["dataset"].append(val)
    res["labels"].append(key)



print(res)





{
   "dt_from": "2022-02-01T00:00:00",
   "dt_upto": "2022-02-02T00:00:00",
   "group_type": "hour"
}


{
   "dt_from": "2022-10-01T00:00:00",
   "dt_upto": "2022-11-30T23:59:00",
   "group_type": "day"
}

# {"dt_from": "2022-09-01T00:00:00", "dt_upto": "2022-12-31T23:59:00", "group_type": "month"}