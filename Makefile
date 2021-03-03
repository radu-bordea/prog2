# Variable
OBJ = date.o sessionlist.o tracker.o
OBJ2 = datetest.o date.o sessionlist.o
OBJ3 = sessionlisttest.o sessionlist.o date.o 
CFLAGS = -Wall -pedantic

#Operativ System dependent variables
ifeq ($(OS), Windows_NT)
RM = del
BIN = tracker.exe datetest.exe sessionlisttest.exe
else 
RM = rm
BIN = tracker datetest sessionlisttest
endif

# Targets
#%.o: %.c
#	gcc $(CFLAGS) -c $< -o $@

date.o: date.c date.h
	gcc $(CFLAGS) -c date.c -o date.o

sessionlist.o: sessionlist.c  sessionlist.h date.h debug.h
	gcc $(CFLAGS) -c sessionlist.c -o sessionlist.o

tracker.o: tracker.c date.h sessionlist.h debug.h
	gcc $(CFLAGS) -c tracker.c -o tracker.o


tracker: date.o sessionlist.o tracker.o 	
	gcc $(CFLAGS) $(OBJ) -o tracker 


all: tracker datetest sessionlisttest

clean:
	$(RM) $(BIN) $(OBJ) $(OBJ2) $(OBJ3)

# ========================
# TEST TARGETS
# ========================

datetest.o: datetest.c date.h
	gcc $(CFLAGS) -c datetest.c -o datetest.o


datetest: datetest.o date.o sessionlist.o
	gcc $(CFLAGS) $(OBJ2) -o datetest	



sessionlisttest.o: sessionlisttest.c sessionlist.h
	gcc $(CFLAGS) -c sessionlisttest.c -o sessionlisttest.o



sessionlisttest: sessionlisttest.o date.o sessionlist.o
	gcc $(CFLAGS) $(OBJ3) -o sessionlisttest

test: datetest sessionlisttest
	
	
runtest: datetest sessionlisttest
	./datetest.exe
	./sessionlisttest.exe

.DEFAULT_GOAL := all
