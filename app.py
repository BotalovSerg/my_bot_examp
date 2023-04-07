from aiogram import Bot, Dispatcher, executor, types
import motor.motor_asyncio
from datetime import datetime

TOKEN = "5361419831:AAF1tMmHcjI8_QvrBb3yDujqV9gXz9KreXc"

bot = Bot(token=TOKEN)
dp = Dispatcher(bot)

cluster = motor.motor_asyncio.AsyncIOMotorClient("mongodb://127.0.0.1:27017/?directConnection=true&serverSelectionTimeoutMS=2000&appName=mongosh+1.8.0")

collection = cluster.my_db.sampleDB

async def add_user(user_id):
    date = datetime.now().date()
    collection.insert_one({
        "_id" : user_id,
        "date" : str(date)
    })


async def add_user(user_id):
    date = datetime.now().date()
    collection.insert_one({
        "_id" : user_id,
        "date" : str(date)
    })



@dp.message_handler(commands=["start"])
async def start(message: types.Message):
    await bot.send_message(message.chat.id, "Hello")
    user_id = message.chat.id
    await add_user(user_id)





executor.start_polling(dp)