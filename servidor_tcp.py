import serial

arduino = serial.Serial('/dev/ttyACM0', 9600)

estado_actual = "NORMAL"

while True:

    dato = arduino.readline().decode().strip()

    print(dato)

    if "ALERTA" in dato:
        estado_actual = "ALERTA"

        with open("estado.txt", "w") as archivo:
            archivo.write("ALERTA")

    else:

        with open("estado.txt", "w") as archivo:
            archivo.write("NORMAL")
