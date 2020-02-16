import serial
# Librería para mandar correo
import smtplib
# simple mail transfer protocol

arduino = serial.Serial("COM3",9600)

destinatario = 'd880884@urhen.com'

remitente = 'charles210800@gmail.com'
contrasena = '.Carlos#21101523.'

asunto = 'INTRUSO'
mensaje = 'Se ha detectado un intruso'

def enviarCorreo():
	print("Enviando correo...")
	correo = smtplib.SMTP("smtp.gmail.com",587)
	correo.ehlo()
	correo.starttls()
	correo.ehlo()
	correo.login(remitente,contrasena)

	# Correo destino
	cuerpo = 'To: ' + destinatario + '\n'
	# Correo origen
	cuerpo += 'From: ' + remitente + '\n'
	# Asunto
	cuerpo += 'Subject: ' + asunto + '\n'

	msg = cuerpo + '\n' + mensaje + '\n'

	correo.sendmail(remitente,destinatario,msg)
	correo.close()

while True:
	# Guardamos lo que llegue del Arduino
	lectura = arduino.read()
	if lectura == b'H':
		enviarCorreo()