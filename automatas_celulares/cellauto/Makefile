CC=g++
CFLAGS=-Wall
HEADERS=CellAutom.h
OFILES=main.o CellAutom.o

all: cellauto

CellAutom.o: CellAutom.cc CellAutom.h
	$(CC) $(CFLAGS) -c CellAutom.cc

main.o: main.cc $(HEADERS)
	$(CC) $(CFLAGS) -c main.cc

cellauto: $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $@


clean:
	rm *.o cellauto
