CC = gcc -std=gnu99
FLAG = -g -o 
OBJ = xlua.o lauxlib.o lstate.o

xlua :	$(OBJ) 
	$(CC) $(FLAG) xlua $(OBJ) 
	rm -f $(OBJ)


xlua.o : xlua.c 
lauxlib.o : lauxlib.c
lstate.o : lstate.c

clean :
	rm -f *.o
