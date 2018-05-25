# Projet PERI Sorbonne Universités 2017/2018

## Guide d'utilisation

### Sur l'Arduino
1. Uploader le code arduino/send_datas.ino sur un Arduino équipé d'un capteur de luminosité et d'un module NRF. 

### Sur le Raspberry
>>>>>>> 0cc544f3468481ffb9c7456ecc26f41920bfcbef
1. Uploader tout le dossier server/ ainsi que /database sur le raspberry.

2. Se rendre dans /database et lancer le LAUNCH_ME.sh.

3. Dans server/, faire un make et lancer l'exécutable produit.

4. Dans server/ exécuter "python server.py".

### Tests
1. La base de données arduino.db devrait maintenant se remplir, vous pouvez le tester avec sqlite3.

2. L'adresse "localhost:8000/graph" devrait afficher un graphique avec les valeurs contenues dans la base de données "arduino.db".
**Si rien ne s'affiche** : l'adresse localhost est codée en dur dans le code de /templates/graph.html or sur les machines de la fac, le domaine localhost est remplacé par l'adresse du routeur. Il faut donc remplacer "localhost:8000/datas.json" par "132.227.102.36:80XX/datas.json" où XX est le numéro du Rpi.
## Arborescence

- **/arduino/send_datas.ino** : Code pour lire les valeurs des capteurs et les envoyer via NRF.

- **/server** :
	- **receive_data.cpp :** 2 rôles : récupérer les données sur le réseau sans fil, puis les ajouter à la DB.
	- **server.py :** extrait les données de la DB puis les envoie sur le serveur web.
	- **templates/graph.html** : fichiers HTML pour Flask ** adresse codée en dur à modifier si necéssaire**
	- **static/** : fichiers js pour l'affichage graphique
	
- **/database** : 
	- **LAUNCH_ME.sh** : Script pour initialiser la DB avec les paramètres trouvables dans **config.sql.**
	- **arduino.db** Fichier contenant la db une fois le script lancé.

## DOC 

### Sqlite

- http://flask.pocoo.org/docs/0.12/patterns/sqlite3/
- https://www.tutorialspoint.com/flask/flask_sqlite.htm

### NRF24L01

- http://invent.module143.com/daskal_tutorial/raspberry-pi-3-wireless-pi-to-arduino-communication-with-nrf24l01/
