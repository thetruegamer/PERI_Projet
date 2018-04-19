import sqlite3 as sql

try:
   # là on chope les données reçues via le wifi. TODO
   date = "2018-04-18"
   temperature = 27
   humidity = 42
   luminosity = 43
   
   # ces 4 lignes permettent de push les données plus haut dans la db en argument de connect
   with sql.connect("../database/arduino_db.sqlt") as con:
      cur = con.cursor()
      cur.execute("INSERT INTO datas (Dates,Temperature,Humidite,Luminosite) VALUES (?,?,?,?)",(date,temperature,humidity,luminosity))
      con.commit()

except:
   con.rollback()