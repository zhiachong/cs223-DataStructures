prog3: prog3.o cnode.o cbintree.o 
	g++ -o prog3 prog3.o cnode.o cbintree.o

prog3.o: prog3.cpp cbintree.h cnode.h
	g++ -c prog3.cpp

cbintree.o: cbintree.cpp cbintree.h cnode.h
	g++ -c cbintree.cpp

cnode.o: cnode.cpp cnode.h
	g++ -c cnode.cpp
