prog6: prog6.o cavltree.o cbstree.o cbintree.o ckey.o cexception.o
	g++ -o prog6 prog6.o cavltree.o cbstree.o cbintree.o ckey.o cexception.o

prog6.o: prog6.cpp cavltree.h cnode.h cbstree.h cbintree.h ckey.h cexception.h
	g++ -c prog6.cpp

cavltree.o: cavltree.cpp cavltree.h cbstree.h cbintree.h ckey.h cexception.h
	g++ -c cavltree.cpp

cbstree.o: cbstree.cpp cbstree.h cbintree.h ckey.h cexception.h
	g++ -c cbstree.cpp 
	
cbintree.o: cbintree.cpp cbintree.h cnode.h cexception.h
	g++ -c cbintree.cpp 
	
ckey.o: ckey.cpp ckey.h
	g++ -c ckey.cpp

cexception.o: cexception.cpp cexception.h
	g++ -c cexception.cpp
