import serial

# Creo mi objeto para comunicación serial
arduino = serial.Serial("COM3",9600)

print("Comandos: ")
print("p - prender LED")
print("a - apagar LED")
print("s - salir")

# Se lee alguno de los comandos
opcion = input()

while opcion != 's':
	# Casteamos a 'string' (str)
	# Llamamos el método encode para mandarlo como bytes
	arduino.write(str(opcion).encode())
	opcion = input()

arduino.close()