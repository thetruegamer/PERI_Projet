# Projet PERI Sorbonne Universités 2017/2018

## Guide d'utilisation

### Sur l'Arduino
1. Uploader le code arduino/send_datas.ino sur un Arduino équipé d'un capteur de luminosité et d'un module NRF. 

### Sur le Raspberry

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
L'architecture du code est très simple : on lit la valeur du capteur avec analogRead et on l'envoie avec radio.write, toutes les X ms avec delay (1000 par défaut).

- **/server** :
	- **receive_data.cpp :** 2 rôles : récupérer les données sur le réseau sans fil, puis les ajouter à la DB.
Architecture du code : on lit la valeur sur le canal radio, puis on exécute une requête SQL sur la DB préalablement créée, grâce à la librairie C++ sqlite3. On ajoute un délai supérieur ou égal à celui de send_datas pour éviter les "doubles ajouts".

	- **server.py :** extrait les données de la DB puis les envoie sur le serveur web.
Codé à l'aide de flask : on se sert de l'api sqlite3 pour sélectionner toutes les entrées de la base (on pourrait modifier la requête pour ne prendre que les X dernières si l'on voulait) puis les afficher. Ces données sont ensuite communiquées au template "graph" qui les affiche.

	- **templates/graph.html** : fichiers HTML pour Flask **adresse codée en dur à modifier si necéssaire** JS / HTML tirés de https://www.fontenay-ronan.fr/dynamic-charts-with-highcharts-sqlite-and-python/
	
	- **static/** : fichiers js pour l'affichage graphique
	
- **/database** : 
	- **LAUNCH_ME.sh** : Script pour initialiser la DB avec les paramètres trouvables dans **config.sql.**
	- **arduino.db** Fichier contenant la db une fois le script lancé.

## DOC 

### Sqlite / Flask

- http://flask.pocoo.org/docs/0.12/patterns/sqlite3/
- https://www.tutorialspoint.com/flask/flask_sqlite.htm

### JS / HTML
- https://www.fontenay-ronan.fr/dynamic-charts-with-highcharts-sqlite-and-python/ 
