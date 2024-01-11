Customer.o: Customer.h Customer.c
	gcc -c Customer.c
Kiosk.o: Customer.h Kiosk.h Kiosk.c
	gcc -c Kiosk.c
node.o: Customer.h node.h node.c
	gcc -c node.c
List.o: Customer.h node.h List.h List.c
	gcc -c List.c
Queue.o: Customer.h node.h List.h Queue.h Queue.c
	gcc -c Queue.c
testQueue: node.o List.o Queue.o testQueue.c
	gcc -o testQueue node.o List.o Queue.o testQueue.c
des: Customer.o Kiosk.o node.o List.o Queue.o des.c
	gcc -o des Customer.o Kiosk.o node.o List.o Queue.o des.c
clean:
	rm *.o





