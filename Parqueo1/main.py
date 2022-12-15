import tkinter as tk
import serial
import requests
import time
import threading
import json

s = serial.Serial(port='COM2', baudrate=9600, timeout=1, write_timeout=1)

def hilo():
    while(True):
        print("hola")
        url = 'https://arqui1api.000webhostapp.com/base.php'
        args = {"Methods": "GETP1"}

        response = requests.post(url, json=args)

        url1 = 'https://arqui1api.000webhostapp.com/base.php'
        args1 = {"Methods": "GETP2"}

        response1 = requests.post(url1, json=args1)
        

        if response.status_code == 200 and response1.status_code==200 :
            payload = response.json()
            payload1=response1.json()
            payload.extend(payload1)
            resultado = payload

            salida1_9r = 0
            salida9_16r = 0

            salida1_9v = 0
            salida9_16v = 0

            salida1_9a = 0
            salida9_16a = 0

            i = 0
            y = 0
            for estado in resultado:
                r = 2**i
                if i < 8:
                    if estado.get('state') == "0":
                        salida1_9v += r
                    elif estado.get('state') == "1":
                        salida1_9r += r
                    elif estado.get('state') == "2":
                        salida1_9a += r
                else:
                    r = 2**y
                    if estado.get('state') == "0":
                        salida9_16v += r
                    elif estado.get('state') == "1":
                        salida9_16r += r
                    elif estado.get('state') == "2":
                        salida9_16a += r
                    y += 1
                i += 1

            cadena = str(salida1_9v) + "," + str(salida9_16v) + "," + str(salida1_9a) + \
                "," + str(salida9_16a) + "," + \
                str(salida1_9r) + "," + str(salida9_16r)
            #print("Salida " , cadena)

        s.write(cadena.encode())
        time.sleep(2)


def lectura():
    while True:
        time.sleep(2)
        try:
            raw_string_b = s.readline()
            raw_string_s = raw_string_b.decode('utf-8')
            if(raw_string_s.index("}")>=0 and raw_string_s.index("{")==0):
                print(raw_string_s)
            else:
                print("nada")
        except:
            print("fallo")
def encender():
    t=threading.Thread(target=hilo,args=())
    t.start()
    t2=threading.Thread(target=lectura,args=())
    t2.start()
    




sc = tk.Tk()

sc.config(width=300, height=180)

sc.title("Control de Led")

b1 = tk.Button(text="On", command=encender)
b1.place(x=50, y=10)

sc.mainloop()
