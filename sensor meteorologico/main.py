# Importamos los modulos

from dht import DHT22
from machine import Pin
from utime import sleep

# Creamos el objeto del sensor de temperatura

sensorDHT = DHT22(Pin(15))

while True:
    
    sleep(1)
    sensorDHT.measure()
    temp = sensorDHT.temperature()
    hum = sensorDHT.humidity()
    kelvin = temp + 273
    far = (temp * 5)/9 + 32
    print("T = {:2} °C  H = {:2} %  K = {:2} K  F = {:2} °F".format(temp,hum,kelvin,far))