import json
from datetime import datetime
import pytz

with open("Car.json", "r", encoding="utf-8") as f:
    data = json.load(f)
    moscow_tz = pytz.timezone("Europe/Moscow")
    str_current_time = datetime.now(tz=moscow_tz).strftime("%Y-%m-%d %H:%M:%S")
    company_id = 1
    license_plate = data.get("number")
    sts = data.get("sts")
    car_id = data.get("carNameHistory")[0].get("carId")
    name = data.get("carNameHistory")[0].get("name")
    brand = data.get("mark")
    vin = data.get("vin")
    owner = data.get("owner")

    car_data = {
        "id": car_id,
        "company_id": company_id,
        "name": name,
        "license_plate": license_plate,
        "sts": sts,
        "brand": brand,
        "vin": vin,
        "owner": owner,
        "created_at": str_current_time,
        "updated_at": str_current_time,
    }

    # print(car_data)

    insert_fields = [key for key in car_data]
    format_insert_values = [f"'{value}'" for value in car_data.values()]

    query = f"""
        INSERT INTO db1.car ({', '.join(insert_fields)})
        VALUES ({', '.join(format_insert_values)})
    """

    print(query)


# import json
# from datetime import datetime
# import pytz

# from db.client_db import ClickHouseManager
# from services.telegram_bot_employee.db_manager import BotDBManager

# with open("Car.json", "r", encoding="utf-8") as f:

#     BotDBManager.initialize()
#     client = BotDBManager.get_db_client()

#     data = json.load(f)
#     moscow_tz = pytz.timezone("Europe/Moscow")
#     str_current_time = datetime.now(tz=moscow_tz).strftime("%Y-%m-%d %H:%M:%S")
#     company_id = 1
#     license_plate = data.get("number")
#     sts = data.get("sts")
#     car_id = data.get("carNameHistory")[0].get("carId")
#     name = data.get("carNameHistory")[0].get("name")
#     brand = data.get("mark")
#     vin = data.get("vin")
#     owner = data.get("owner")

#     car_data = {
#         "id": car_id,
#         "company_id": company_id,
#         "name": name,
#         "license_plate": license_plate,
#         "sts": sts,
#         "brand": brand,
#         "vin": vin,
#         "owner": owner,
#         "created_at": str_current_time,
#         "updated_at": str_current_time,
#     }

#     insert_fields = [key for key in car_data]
#     format_insert_values = [f"'{value}'" for value in car_data.values()]

#     query = f"""
#         INSERT INTO db1.car ({', '.join(insert_fields)})
#         VALUES ({', '.join(format_insert_values)})
#     """

#     ClickHouseManager.execute_command(client, query)
