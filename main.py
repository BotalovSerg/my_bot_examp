import json
import pymongo
import datetime as dt
from dateutil.relativedelta import relativedelta
#client = pymongo.MongoClient("mongodb://127.0.0.1:27017/?directConnection=true&serverSelectionTimeoutMS=2000&appName=mongosh+1.8.0")
client = pymongo.MongoClient("mongodb://127.0.0.1:27017")
db = client.newdb
coll = db.newcol

def init_dict(st, fn, gr):
    tmp = {}
    if gr == "month":
        n = fn.month - st.month + 1
        for i in range(n):
            tmp[st.strftime("%Y-%m-%dT%H:%M:%S")] = 0            
            st += relativedelta(months=+1)
        return tmp
    elif gr == "day":
        n = fn.day - st.day + 1
        for i in range(n):
            tmp[st.strftime("%Y-%m-%dT%H:%M:%S")] = 0            
            st += relativedelta(days=+1)
        return tmp
    elif gr == "hour" and st.day != fn.day:            
        for i in range(25):
            tmp[st.strftime("%Y-%m-%dT%H:%M:%S")] = 0            
            st += relativedelta(hours=+1)
        return tmp


def get_key(dt_data, agr):
    if agr == "month":
        return dt_data.strftime("%Y-%m") + "-01T00:00:00"
    elif agr == "day":
        return dt_data.strftime("%Y-%m-%d") + "T00:00:00"
    elif agr == "hour":
        return dt_data.strftime("%Y-%m-%dT%H") + ":00:00"


 
def main_app(dt_from, dt_upto, group_type):
    # dt_from = dt.datetime.strptime(dt_from, "%Y-%m-%dT%H:%M:%S")
    # dt_upto = dt.datetime.strptime(dt_upto, "%Y-%m-%dT%H:%M:%S")
    d = init_dict(dt_from, dt_upto, group_type)
    if d is None:
        return "Не допустимый запрос"

    for val in coll.find({"dt": {"$gte" : dt_from, "$lte": dt_upto}}, {"_id":  0}):
        #print(val)
        #key = str(val["dt"].year) + "/" + str(val["dt"].month)
        k = get_key(val["dt"], group_type)   
        #d[key] = d.get(key, []) + [val["value"]]
        d[k] = d.get(k, 0) + val["value"]

    res = {
    "dataset" : [],
    "labels" : []
    }   

    for key, val in d.items():
       res["dataset"].append(val)
       res["labels"].append(key)

    return json.dumps(res)



dt_from = dt.datetime.strptime("2022-10-01T00:00:00", "%Y-%m-%dT%H:%M:%S")
dt_upto = dt.datetime.strptime("2022-11-30T23:59:00", "%Y-%m-%dT%H:%M:%S")
group_type = "day"
print(main_app(dt_from, dt_upto, group_type))
