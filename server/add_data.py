import sqlite3 as sql
from lib_nrf24 import NRF24
# import RPi.GPIO as GPIO
import spidev

# GPIO.setmode(GPIO.BCM)

adress = "0XYZE"

radio = NRF24(22, spidev.SpiDev())
radio.begin(0, 17)
radio.setPayloadSize(32)
radio.setChannel(0x60)
 
radio.setDataRate(NRF24.BR_2MBPS)
radio.setPALevel(NRF24.PA_LOW)
radio.setAutoAck(True)
radio.enableDynamicPayloads()
radio.enableAckPayload()
 
radio.openReadingPipe(0, adress)
radio.printDetails()
 
radio.startListening()
 
while(1):
    ackPL = [1]
    while not radio.available(0):
        time.sleep(1 / 100)
    receivedMessage = []
    radio.read(receivedMessage, radio.getDynamicPayloadSize())
    print("Received: {}".format(receivedMessage))

# try:
#    # là on chope les données reçues via le wifi. TODO
#    date = "2018-04-18"
#    temperature = 27
#    humidity = 42
#    luminosity = 43
   
#    # ces 4 lignes permettent de push les données plus haut dans la db en argument de connect
#    with sql.connect("../database/arduino_db.sqlt") as con:
#       cur = con.cursor()
#       cur.execute("INSERT INTO datas (Dates,Temperature,Humidite,Luminosite) VALUES (?,?,?,?)",(date,temperature,humidity,luminosity))
#       con.commit()

# except:
#    con.rollback()
