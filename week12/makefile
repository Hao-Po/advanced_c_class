CC = gcc
OBJ = space.o stack.o main.o

EXE = run
all: $(EXE)
.c.o: ; $(CC) -c $*.c

$(EXE): $(OBJ)
	$(CC) -o $@ $(OBJ)

clean:
	del $(EXE) *.o *.d *.exe core

