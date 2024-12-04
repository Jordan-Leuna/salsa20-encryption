CC = gcc
CFLAGS = -Wall
OBJ = salsa20.o test.o

# Ziel: alles erstellen
all: salsa20_test

# Kompilieren der salsa20.o
salsa20.o: salsa20.c salsa20.h
	$(CC) $(CFLAGS) -c salsa20.c

# Kompilieren der test.o
test.o: test.c salsa20.h
	$(CC) $(CFLAGS) -c test.c

# Erstellen des Programms
salsa20_test: $(OBJ)
	$(CC) $(CFLAGS) -o salsa20_test $(OBJ)

# Aufräumen
clean:
	rm -f salsa20.o test.o salsa20_test
