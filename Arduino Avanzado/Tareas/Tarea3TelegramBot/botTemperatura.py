import telepot, time, serial
ser = serial.Serial('COM3', 9600)

def handle(msg):

	userName = msg['from']['first_name']+" "+msg['from']['last_name']

	content_type, chat_type, chat_id = telepot.glance(msg)

	if (content_type == 'text'):
		command = msg['text']
		print ('Comando ingresado: %s' % command)

		if '/temperatura' in command:
			valor = ser.read(5)
			bot.sendMessage(chat_id, "Temperatura:  ")
			bot.sendMessage(chat_id, valor)
			bot.sendMessage(chat_id, " °C")

# Create a bot using the token given by BotFather
bot = telepot.Bot('1014077216:AAGRmH8FkSQsDbtCwAkR_ZAs10lcrxeghpY')

# Add handle function to be called every received message.
bot.message_loop(handle)

# Wait for new messages
while 1:
	time.sleep(20)