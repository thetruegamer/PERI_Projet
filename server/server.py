from flask import Flask, render_template, request
import sqlite3 as sql
app = Flask(__name__)


# it's a list for now, TODO transform the list into a graph (more HTML side than flask I think)
@app.route('/list')
def list():

	# connect to the database
	con = sql.connect("../database/arduino.db")

	# config the rows for the fetch later
	con.row_factory = sql.Row
	cur = con.cursor()

	# the query can be changed but our db doesn't have irrelevant information for the user such as IDs so we select *
	cur.execute("SELECT * FROM datas")
	rows = cur.fetchall(); 

	# "push" all fetched datas to the "list.html" page
	return render_template("list.html",rows = rows)