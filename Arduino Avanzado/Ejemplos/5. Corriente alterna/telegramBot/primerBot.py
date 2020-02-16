#import telebot

#bot = telebot.TeleBot("1014077216:AAGRmH8FkSQsDbtCwAkR_ZAs10lcrxeghpY")

#@bot.message_handler(commands=['hola', 'help'])
#def send_welcome(message):
#	bot.reply_to(message, "Hola señor")

#print("Tu bot te escucha")
#bot.polling()*/

import telebot

bot = telebot.TeleBot("1014077216:AAGRmH8FkSQsDbtCwAkR_ZAs10lcrxeghpY")

@bot.message_handler(commands=['hola', 'help'])
def send_welcome(message):
	chatid = message.chat.id
	saludo = "Buenas, caballero"
	bot.send_message(chatid,saludo)

print("El bot está escuchando")
bot.polling()
