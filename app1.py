from aiogram import Bot, Dispatcher, executor, types

TOKEN = "5361419831:AAF1tMmHcjI8_QvrBb3yDujqV9gXz9KreXc"

bot = Bot(token=TOKEN)
dp = Dispatcher(bot)



@dp.message_handler(commands=["start"])
async def start(message: types.Message):
    await bot.send_message(message.chat.id, "Hello")
    
@dp.message_handler(content_types=['text'])
async def msg(message: types.Message):
    #msg = message.text[1:-1].split(',')
    dt_from, dt_upto, group_type = message.text[1:-1].split(', ')
    print(dt_from)
    print(dt_upto)
    print(group_type)    
    await bot.send_message(message.chat.id, "Loading>>>>")
    


executor.start_polling(dp)