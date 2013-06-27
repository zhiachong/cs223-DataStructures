prog7: prog7.o ckey.o cexception.o cheap.o
	g++ -o prog7 prog7.o ckey.o cexception.o cheap.o

prog7.o : prog7.cpp ckey.h cexception.h cheap.h
	g++ -c prog7.cpp

cheap.o : cheap.cpp cheap.h ckey.h cexception.h cnode.h
	g++ -c cheap.cpp
	
ckey.o: ckey.cpp ckey.h
	g++ -c ckey.cpp

cexception.o: cexception.cpp cexception.h
	g++ -c cexception.cpp
