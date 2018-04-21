-- no need for CREATE or USE, thx to SQLite <3

-- create a table with some relevant datas to be stored
CREATE TABLE datas (
	Date datetime default current_timestamp,
	Luminosite integer
);
