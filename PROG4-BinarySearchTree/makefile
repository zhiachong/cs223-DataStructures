prog4: prog4.o ckey.o cexception.o citem.o cbintree.o cbstree.o
	g++ -o prog4 prog4.o cexception.o ckey.o citem.o cbintree.o cbstree.o
	
prog4.o: prog4.cpp ckey.h cexception.h citem.h cbintree.h cbstree.h cnode.h
	g++ -c prog4.cpp 

cbstree.o: cbstree.cpp cbstree.h cbintree.h citem.h ckey.h cexception.h
	g++ -c cbstree.cpp 
	
cbintree.o: cbintree.cpp cbintree.h cnode.h citem.h cexception.h
	g++ -c cbintree.cpp 
	
citem.o: citem.cpp ckey.h citem.h 
	g++ -c citem.cpp

ckey.o: ckey.cpp ckey.h
	g++ -c ckey.cpp

cexception.o: cexception.cpp cexception.h
	g++ -c cexception.cpp
