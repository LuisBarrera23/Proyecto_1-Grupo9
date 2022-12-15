import tkinter as tk
import serial 
import requests

def encender():
    url = 'https://arqui1api.000webhostapp.com/base.php'
    args = { "Methods": "GETP1"}
    
    response = requests.post(url, json=args)
    
    if response.status_code == 200:
        payload = response.json()
        resultado = payload
        
        salida1_9r = 0
        salida9_16r = 0
        
        salida1_9v = 0
        salida9_16v = 0
        
        salida1_9a = 0
        salida9_16a = 0
        
        i=0
        y=0
        for estado in resultado:
            r=2**i
            if i < 8:
                if estado.get('state') == "0":
                    salida1_9v+=r
                elif estado.get('state') == "1":
                    salida1_9r+=r
                elif estado.get('state') == "2":
                    salida1_9a+=r
            else:
                r = 2**y
                if estado.get('state') == "0":
                    salida9_16v+=r
                elif estado.get('state') == "1":
                    salida9_16r+=r
                elif estado.get('state') == "2":
                    salida9_16a+=r
                y += 1
            i+=1

        cadena = str(salida1_9v) + "," + str(salida9_16v) + "," + str(salida1_9a)+ "," + str(salida9_16a)+ "," + str(salida1_9r)+ "," + str(salida9_16r)
        print("Salida " , cadena)

    s.write(cadena.encode())

       
s= serial.Serial('COM2')

sc=tk.Tk()

sc.config(width=300, height=180)

sc.title("Control de Led")

b1=tk.Button(text="On", command=encender)
b1.place(x=50,y= 10)

sc.mainloop()