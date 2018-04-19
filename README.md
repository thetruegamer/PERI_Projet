# Projet PERI Sorbonne Université 2017/2018

1.  L'Arduino envoie des données à une BDD sqlite3 **"en passant par le réseau sans fil"** donc j'imagine qu'on doit faire comme en TME : on se sert d'un PC pour lire les valeurs de l'Arduino et on envoie le tout à la BDD depuis le PC qui a lu. **TODO** un mail pour confirmer

- Le Raspberry Pi héberge un serveur Web qui récupère et affiche les données sous forme de graphe etc. Le serveur est sous Flask.

- On a 20. Ne pas hésiter à ajouter des choses pertinentes au fur et à mesure : on peut commencer sans BDD, avec des tableaux et pas des beaux graphes.
Eventuellement on peut accepter des ordres envoyés depuis le site web pour afficher des trucs sur l'écran oled

## Arborescence

- **/arduino** : Code pour lire les valeurs et les stocker dans la DB.
- **/server** : Serveur Flask qui tourne sur le RPi
	-
- **/database** : 
	- **LAUNCH_ME.sh** : Script pour initialiser la DB avec config.sql.
	- **arduino_db.sqlt** Fichier contenant la db une fois le script lancé.
## DOC : 

### Sqlite

- http://flask.pocoo.org/docs/0.12/patterns/sqlite3/
- https://www.tutorialspoint.com/flask/flask_sqlite.htm
