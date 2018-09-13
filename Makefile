CC = gcc
CFLAGS = -Wall
SRC1 = task1.c 
SRC2 = pacman.c
EXE1 = task1 
EXE2 = pacman

build: $(EXE1) $(EXE2)
	
$(EXE1): $(SRC1)
	$(CC) -o $(EXE1) $(SRC1) $(CFLAGS)

$(EXE2): $(SRC2)
	$(CC) -o $(EXE2) $(SRC2) $(CFLAGS)

clean:
	rm -f $(EXE1) $(EXE2)
