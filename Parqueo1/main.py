import tkinter as tk
import serial
import requests
import time
import threading
import json

s = serial.Serial(port='COM2', baudrate=9600, timeout=200, write_timeout=1)
s1 = serial.Serial(port='COM4', baudrate=19200, timeout=200, write_timeout=1)
estadoLED1_old = "0"
estadoLED2_old = "0"
estadoLED3_old = "0"
estadoLED4_old = "0"
estadoLED5_old = "0"
estadoLED6_old = "0"
estadoLED7_old = "0"
estadoLED8_old = "0"
estadoLED9_old = "0"
estadoLED10_old = "0"
estadoLED11_old = "0"
estadoLED12_old = "0"
estadoLED13_old = "0"
estadoLED14_old = "0"
estadoLED15_old = "0"
estadoLED16_old = "0"

def hilo():
    global estadoLED1_old
    global estadoLED2_old
    global estadoLED3_old
    global estadoLED4_old
    global estadoLED5_old
    global estadoLED6_old
    global estadoLED7_old
    global estadoLED8_old
    global estadoLED9_old
    global estadoLED10_old
    global estadoLED11_old
    global estadoLED12_old
    global estadoLED13_old
    global estadoLED14_old
    global estadoLED15_old
    global estadoLED16_old

    while(True):
        
        url1 = 'https://arqui1grupo9.website/base.php'
        args1 = {"Methods": "GETP2"}

        response1 = requests.post(url1, json=args1, timeout=4)

        url = 'https://arqui1grupo9.website/base.php'
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

                if estadoLED1 == "0" and estadoLED1_old == "2":
                    cadena =  "A,0"
                
                estadoLED1_old = estadoLED1
                if estadoLED1 == "2":
                    cadena =  "A,2"
                    
            estadoLED2 = resultado[1].get('state')
            if estadoLED2!=estadoLED2_old:

                if estadoLED2 == "0" and estadoLED2_old == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "B,0"

                estadoLED2_old = estadoLED2
                if estadoLED2 == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "B,2"

            estadoLED3 = resultado[2].get('state')
            if estadoLED3!=estadoLED3_old:
                if estadoLED3 == "0" and estadoLED3_old == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "C,0"

                estadoLED3_old = estadoLED3
                if estadoLED3 == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "C,2"
                

            estadoLED4 = resultado[3].get('state')
            if estadoLED4!=estadoLED4_old:
                if estadoLED4 == "0" and estadoLED4_old == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "D,0"

                estadoLED4_old = estadoLED4
                if estadoLED4 == "2": 
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "D,2"
                

            estadoLED5 = resultado[4].get('state')
            if estadoLED5!=estadoLED5_old:
                if estadoLED5 == "0" and estadoLED5_old == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "E,0"

                estadoLED5_old = estadoLED5
                if estadoLED5 == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "E,2"

            estadoLED6 = resultado[5].get('state')
            if estadoLED6!=estadoLED6_old:
                if estadoLED6 == "0" and estadoLED6_old == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "F,0"
                estadoLED6_old = estadoLED6
                if estadoLED6 == "2" :
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "F,2"
                

            estadoLED7 = resultado[6].get('state')
            if estadoLED7!=estadoLED7_old:
                if estadoLED7 == "0" and estadoLED7_old == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "G,0"

                estadoLED7_old = estadoLED7
                if estadoLED7 == "2": 
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "G,2"
                

            estadoLED8 = resultado[7].get('state')
            if estadoLED8!=estadoLED8_old:
                if estadoLED8 == "0" and estadoLED8_old == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "H,0"
                estadoLED8_old = estadoLED8
                if estadoLED8 == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "H,2"

            estadoLED9 = resultado[8].get('state')
            if estadoLED9!=estadoLED9_old:
                if estadoLED9 == "0" and estadoLED9_old == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "I,0"
                estadoLED9_old = estadoLED9
                if estadoLED9 == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "I,2"

            estadoLED10 = resultado[9].get('state')
            if estadoLED10!=estadoLED10_old:
                if estadoLED10 == "0" and estadoLED10_old == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "J,0"
                estadoLED10_old = estadoLED10
                if estadoLED10 == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "J,2"

            estadoLED11 = resultado[10].get('state')
            if estadoLED11!=estadoLED11_old:
                if estadoLED11 == "0" and estadoLED11_old == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "K,0"
                estadoLED11_old = estadoLED11
                if estadoLED11 == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "K,2"

            estadoLED12 = resultado[11].get('state')
            if estadoLED12!=estadoLED12_old:
                if estadoLED12 == "0" and estadoLED12_old == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "L,0"
                estadoLED12_old = estadoLED12
                if estadoLED12 == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "L,2"

            estadoLED13 = resultado[12].get('state')
            if estadoLED13!=estadoLED13_old:
                if estadoLED13 == "0" and estadoLED13_old == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "M,0"
                estadoLED13_old = estadoLED13
                if estadoLED13 == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "M,2"

            estadoLED14 = resultado[13].get('state')
            if estadoLED14!=estadoLED14_old:
                if estadoLED14 == "0" and estadoLED14_old == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "N,0"
                estadoLED14_old = estadoLED14
                if estadoLED14 == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "N,2"

            estadoLED15 = resultado[14].get('state')
            if estadoLED15!=estadoLED15_old:
                if estadoLED15 == "0" and estadoLED15_old == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "O,0"
                estadoLED15_old = estadoLED15
                if estadoLED15 == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "O,2"
        
            estadoLED16 = resultado[15].get('state')
            if estadoLED16!=estadoLED16_old:
                if estadoLED16 == "0" and estadoLED16_old == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "P,0"
                estadoLED16_old = estadoLED16
                if estadoLED16 == "2":
                    if(cadena != ""):
                        cadena += ","
                    cadena +=  "P,2"

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
            url = 'https://arqui1grupo9.website/base.php'
            args = {"Methods": parametros[0],"estado" : parametros[1],"id":parametros[2]}

            response = requests.post(url, json=args)
            payload = response.json()
            #print(payload)
                
                
        except:
            pass
            #print("fallo")


def consultarlcd():
    while(True):
        url = 'https://arqui1grupo9.website/base.php'
        args = {"Methods": "GETNUMP12"}

        response = requests.post(url, json=args, timeout=4)

        cadena=""

        if response.status_code == 200 :
            payload = response.json()

            ocupado = payload.get('ocupados')
            res = payload.get('reservados')
            tot = ocupado + res
            cadena=" ,"
            if tot==16:
                cadena +="FULL,"
            elif ocupado==16:
                cadena +="FULL,"
            else:
                cadena +="FREE,"

            cadena += str(payload.get('disponibles'))+","
            cadena += str(payload.get('ocupados'))+","
            cadena += str(payload.get('reservados'))

            if (cadena != ""):
                print(cadena)
                s1.write(cadena.encode())

        time.sleep(5)   

def encender():
    t=threading.Thread(target=hilo,args=())
    t.start()
    t2=threading.Thread(target=lectura,args=())
    t2.start()
    t3=threading.Thread(target=consultarlcd,args=())
    t3.start()
    




sc = tk.Tk()

sc.config(width=300, height=180)

sc.title("Control de Led")

b1 = tk.Button(text="On", command=encender)
b1.place(x=50, y=10)

sc.mainloop()