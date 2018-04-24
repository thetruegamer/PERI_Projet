RPI?=23
SRC=src
APP=receive_data
DST=levy-masson

CROSSDIR        = /users/enseig/franck/peri
CROSS_COMPILE   = $(CROSSDIR)/arm-bcm2708hardfp-linux-gnueabi/bin/bcm2708hardfp-

INC=$(HOME)/rf24/include # -I$(HOME)/sqlite3/include 
LIB=$(HOME)/rf24/lib # -L$(HOME)/sqlite3/lib
CFLAGS=-Wall -Wfatal-errors -O2 -I$(INC)
LDFLAGS=-L$(LIB) -lrf24 # -lsqlite3

all: $(APP).x

$(APP).x: $(APP).cpp
	$(CROSS_COMPILE)g++ -std=c++11 -o $@ -I$(INC) $< -O2 $(LDFLAGS)

upload: 
	scp -P50$(RPI) $(APP).x pi@peri:$(DST)

clean:
	rm -f *.o *.x *~
