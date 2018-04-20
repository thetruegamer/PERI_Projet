#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <RF24/RF24.h>
#include <ctime>
#include <sqlite3.h>

typedef uint8_t byte;

using namespace std;

RF24 radio(15,8); // radio(CE,CS)

byte addresses[][6] = {"0XXXX"};

// values to insert to DB
int luminosity;
string date;

// DB objects
sqlite3 *db;
sqlite3_stmt *stmt;

string sqlstatement;

void setup() {
    radio.begin();
    radio.setPALevel(RF24_PA_LOW);
    radio.openReadingPipe(addresses[0]);
    radio.printDetails();
}


void loop() {
    cout << "." << flush;

    // read value from sensor
    radio.read(&luminosity, sizeof(luminosity));

    // format date before inserting into db
    stfrtime(date, sizeof(date), "%Y-%m-%d", std::chrono::system_clock::now());

    // form the query
    sqlstatement = "INSERT INTO datas VALUES (" + date +", " + luminosity + ");"

    if(sqlite3_open("../database/arduino.db", &db) == SQLITE_OK) {
        // prepare the query
        sqlite3_prepare(db, sqlstatement.c_str, -1, &stmt, NULL);
        //execute it
        sqlite3_step(stmt);
    }
    else
        cout << "Failure opening database \n"

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int main(int argc, char **argv)
{
    setup();
    while (1)
        loop();
    return 0;
}