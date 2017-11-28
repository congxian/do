CC = gcc -std=gnu99
FLAG = -g -o 
OBJ = lua.o lauxlib.o lstate.o lmem.o

LUA = lua

lua:	$(OBJ) 
	$(CC) $(FLAG) $(LUA) $(OBJ)

lua.o:	lua.c
lauxlib.o: lauxlib.c
lstate.o: lstate.c
lmem.o:	lmem.c

clean :
	rm -f $(OBJ) lua
