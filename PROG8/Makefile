prog8: prog8.o c234node.o citem.o c234tree.o cexception.o
	g++ -o prog8 prog8.o c234node.o citem.o c234tree.o cexception.o

prog8.o : prog8.cpp c234node.h citem.h c234tree.h cexception.h
	g++ -c prog8.cpp

c234tree.o: c234tree.cpp c234tree.h c234node.h citem.h cexception.h
	g++ -c c234tree.cpp 
	
c234node.o: c234node.cpp c234node.h citem.h cexception.h 
	g++ -c c234node.cpp

citem.o : citem.cpp citem.h
	g++ -c citem.cpp

cexception.o: cexception.cpp cexception.h
	g++ -c cexception.cpp
