# Projet PERI Sorbonne Universités 2017/2018

1.  L'Arduino envoie des données à un Raspberry Pi via nRF24L01 qui les stocke dans une BDD sqlite3 

2. Le Raspberry Pi héberge un serveur Web qui récupère et affiche les données sous forme de graphe etc. Le serveur est sous Flask.

3. On a 20. Ne pas hésiter à ajouter des choses pertinentes au fur et à mesure : on peut commencer sans BDD, avec des tableaux et pas des beaux graphes.
Eventuellement on peut accepter des ordres envoyés depuis le site web pour afficher des trucs sur l'écran oled

## Arborescence

- **/arduino/send_datas.ino** : Code pour lire les valeurs des capteurs et les envoyer sur un réseau sans fil à déterminer (mail en cours).

- **/server** :
	- **receive_data.cpp :** 2 rôles : récupérer les données sur le réseau sans fil, puis les ajouter à la DB
	- **server.py :** extrait les données de la DB puis les mets sur le serveur
	- **templates/** : fichiers HTML pour Flask
	
- **/database** : 
	- **LAUNCH_ME.sh** : Script pour initialiser la DB avec les paramètres trouvables dans **config.sql.**
	- **arduino.db** Fichier contenant la db une fois le script lancé.

## DOC 

### Sqlite

- http://flask.pocoo.org/docs/0.12/patterns/sqlite3/
- https://www.tutorialspoint.com/flask/flask_sqlite.htm

### NRF24L01

- http://invent.module143.com/daskal_tutorial/raspberry-pi-3-wireless-pi-to-arduino-communication-with-nrf24l01/