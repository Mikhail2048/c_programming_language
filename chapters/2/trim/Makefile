EXECUTABLE=main.out

OBJ_DIRECTORY=obj

GCC=gcc

OPTIONS=-Wall -g

compile: stringutils.o trim.o
	$(GCC) $(OPTIONS) $(OBJ_DIRECTORY)/stringutils.o $(OBJ_DIRECTORY)/trim.o -o $(EXECUTABLE)

stringutils.o:
	$(GCC) -c stringutils.c -o $(OBJ_DIRECTORY)/stringutils.o

trim.o:
	$(GCC) -c trim.c -o $(OBJ_DIRECTORY)/trim.o

clean:
	rm -rdf $(OBJ_DIRECTORY)/*.o