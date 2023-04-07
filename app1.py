from aiogram import Bot, Dispatcher, executor, types

from config.config import load_config


conf = load_config('.env')


bot = Bot(token=conf.tg_bot.token)
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