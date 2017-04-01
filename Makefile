CC = gcc -std=gnu99
FLAG = -g -o 
OBJ = doo.o table.o 

doo :	$(OBJ) 
	$(CC) $(FLAG) doo $(OBJ) 
	rm -f $(OBJ)

doo.o : doo.c 
table.o : table.c
object.o :object.c

clean :
	rm -f *.o
