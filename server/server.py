from flask import Flask, render_template, request
import sqlite3 as sql
import json
app = Flask(__name__)


# it's a list for now, TODO transform the list into a graph (more HTML side than flask I think)
@app.route('/data.json')
def list():

	# connect to the database
	con = sql.connect("../database/arduino.db")

	cur = con.cursor()

	# the query can be changed but our db doesn't have irrelevant information for the user such as IDs so we select *
	cur.execute("SELECT * FROM datas")
	res = cur.fetchall(); 

	print res
	# "push" all fetched datas to the "list.html" page
	# return render_template("list.html",rows = rows)
	return json.dumps(res)

@app.route("/graph")
def graph():
    return render_template('graph.html')

if __name__ == "__main__":
	app.run(host="", port=8000, debug=True)