#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <RF24/RF24.h>
#include <sqlite3.h>

typedef uint8_t byte;

using namespace std;

RF24 radio(15,8); // radio(CE,CS)

byte addresses[][6] = {"0CLBM"};

// value to insert to DB
int luminosity = 42;
stringstream ss_lum;

// DB objects
sqlite3 *db;
sqlite3_stmt *stmt;

string sqlstatement;

void setup() {
    radio.begin();
    radio.setPALevel(RF24_PA_LOW);
    radio.openReadingPipe(1, addresses[0]);
    radio.printDetails();
    radio.startListening();
}

void loop() {

    // read value from sensor
	if(radio.available()) {
		radio.read(&luminosity, sizeof(luminosity));
	}

    // conversion from int to string
	ss_lum << luminosity;
 	string str_lum = ss_lum.str();

  	ss_lum.str(string());

	// form the query
    sqlstatement = "INSERT INTO datas (Luminosite) VALUES (" + str_lum + ");";
    //cout << sqlstatement;

    if(sqlite3_open("../database/arduino.db", &db) == SQLITE_OK) {
        // prepare the query
        sqlite3_prepare(db, sqlstatement.c_str(), -1, &stmt, NULL);
        //execute it
        sqlite3_step(stmt);
    }
    else
        cout << "Failure opening database \n";

    sqlite3_finalize(stmt);
    sqlite3_close(db);

	sleep(1);

}

int main(int argc, char **argv)
{
    setup();
    while (1)
        loop();
    return 0;
}
