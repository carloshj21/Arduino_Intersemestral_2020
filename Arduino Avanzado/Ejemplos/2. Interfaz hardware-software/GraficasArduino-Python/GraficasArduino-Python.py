import serial
from matplotlib import pyplot  # Librería para graficar
from time import time  # Librería para tiempo

puerto = 'COM3'

arduino = serial.Serial(puerto,9600)

pyplot.ion()  # Inicializa modo interactivo

tInicio = time()
tiempo = []
datosY = []
rango = [-100,1100]
tiempoMostrado = 4
duracion = 24

fig1 = pyplot.figure()
pyplot.axes().grid(True)
linea = pyplot.plot(datosY)
pyplot.ylim(rango)
pyplot.xlim([0,tiempoMostrado])

programa = True

while programa: 
	arduino.reset_input_buffer()
	dato = arduino.readline().decode().split(' ')

	try:
		datosY.append(float(dato[0]))
		tiempo.append(time()-tInicio)
		tActual = tiempo[-1]
		linea.set_xdata(tiempo)
		linea.set_ydata(datosY)
		if tActual > tiempoMostrado:
			pyplot.xlim([tActual-tiempoMostrado,tActual])
			if tiempo[-1] > duracion:
				programa =  False

	except:
		pass  # Pasa la iteración y lo vuelve a intentar para que no se cierre el programa

	fig1.canvas.draw()

pyplot.close()
arduino.close()