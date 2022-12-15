import tkinter as tk
import serial
import requests
import time
import threading
import json
from flask import jsonify

s = serial.Serial(port='COM2', baudrate=9600, timeout=200, write_timeout=1)
estadoLED1_old = "0"
estadoLED2_old = "0"
estadoLED3_old = "0"
estadoLED4_old = "0"
estadoLED5_old = "0"
estadoLED6_old = "0"
estadoLED7_old = "0"
estadoLED8_old = "0"


def hilo():
    global estadoLED1_old
    global estadoLED2_old
    global estadoLED3_old
    global estadoLED4_old
    global estadoLED5_old
    global estadoLED6_old
    global estadoLED7_old
    global estadoLED8_old

    while(True):
        
        url1 = 'https://arqui1api.000webhostapp.com/base.php'
        args1 = {"Methods": "GETP2"}

        response1 = requests.post(url1, json=args1, timeout=4)

        url = 'https://arqui1api.000webhostapp.com/base.php'
        args = {"Methods": "GETP1"}

        response = requests.post(url, json=args, timeout=4)
        

        if response.status_code == 200 and response1.status_code==200 :
            payload = response.json()
            payload1=response1.json()
            payload.extend(payload1)
            resultado = payload
            cadena = ""
            estadoLED1 = resultado[0].get('state')

            if estadoLED1!=estadoLED1_old:
                estadoLED1_old = estadoLED1
                if estadoLED1 == "2":
                    cadena =  "A,2"
                    
            estadoLED2 = resultado[1].get('state')
            if estadoLED2!=estadoLED2_old:
                estadoLED2_old = estadoLED2
                if estadoLED2 == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "B,2"

            estadoLED3 = resultado[2].get('state')
            if estadoLED3!=estadoLED3_old:
                estadoLED3_old = estadoLED3
                if estadoLED3 == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "C,2"
                

            estadoLED4 = resultado[3].get('state')
            if estadoLED4!=estadoLED4_old:
                estadoLED4_old = estadoLED4
                if estadoLED4 == "2": 
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "D,2"
                

            estadoLED5 = resultado[4].get('state')
            if estadoLED5!=estadoLED5_old:
                estadoLED5_old = estadoLED5
                if estadoLED5 == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "E,2"

            estadoLED6 = resultado[5].get('state')
            if estadoLED6!=estadoLED6_old:
                estadoLED6_old = estadoLED6
                if estadoLED6 == "2" :
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "F,2"
                

            estadoLED7 = resultado[6].get('state')
            if estadoLED7!=estadoLED7_old:
                estadoLED7_old = estadoLED7
                if estadoLED7 == "2": 
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "G,2"
                

            estadoLED8 = resultado[7].get('state')
            if estadoLED8!=estadoLED8_old:
                estadoLED8_old = estadoLED8
                if estadoLED8 == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "H,2"
                

            if (cadena != ""):
                print(cadena)
                s.write(cadena.encode())

            time.sleep(2)
            
                
        


def lectura():
    while True:
        time.sleep(2)
        try:
            raw_string_b = s.readline()
            raw_string_s = raw_string_b.decode('utf-8')
            print(raw_string_s)
            parametros=raw_string_s.split(",")
            url = 'https://arqui1api.000webhostapp.com/base.php'
            args = {"Methods": parametros[0],"estado" : parametros[1],"id":parametros[2]}

            response = requests.post(url, json=args)
            payload = response.json()
            #print(payload)
                
                
        except:
            pass
            #print("fallo")
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