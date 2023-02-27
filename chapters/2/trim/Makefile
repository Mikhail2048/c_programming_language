EXECUTABLE=main.out

OBJ_DIRECTORY=obj

GCC=gcc

OPTIONS=-Wall

TARGET_FILE=$(HOME)/CLionProjects/c_programming_language/$(EXECUTABLE)

compile: stringutils.o trim.o
	$(GCC) $(OPTIONS) $(OBJ_DIRECTORY)/stringutils.o $(OBJ_DIRECTORY)/trim.o -o $(TARGET_FILE)

stringutils.o:
	$(GCC) -c stringutils.c -o $(OBJ_DIRECTORY)/stringutils.o -g

trim.o:
	$(GCC) -c trim.c -o $(OBJ_DIRECTORY)/trim.o -g

clean:
	rm -rdf $(OBJ_DIRECTORY)/*.o