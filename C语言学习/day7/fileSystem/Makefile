FF = fileFunction.o fileSys.o
file: $(FF)
	gcc -Wall -g fileSys.o fileFunction.o -o $@
fileSys.o: fileSys.c
	gcc -Wall -g -c fileSys.c -o $@
fileFunction.o: fileFunction.c file.h
	gcc -Wall -g -c fileFunction.c -o $@


RM:fileFunction.o fileSys.o
	rm fileFunction.o fileSys.o file