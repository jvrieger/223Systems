testList: testList.o List.o node.o
	gcc -o testList testList.o List.o node.o
testList.o: List.h testList.c
	gcc -c  testList.c
List.o: List.h List.c
	gcc -c List.c
node.o: node.h node.c
	gcc -c node.c