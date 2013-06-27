//@file cexception.h
//@author Zhia Chong
//@date Feb 18, 2011
//@Specification for ADT Exception Message
//    data object: a message explaining an exception
//    operations: constructor, what

#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#include <string>
using namespace std;

class cexception
{
public:
   //@creates an exception message
   //@pre  theMessage passed may be a literal string
   //@post exception message object is assigned theMessage
   //@usage throw cexception ("BAD MOVE");
   cexception(string theMessage) ;

   //@outputs a message exception
   //@pre message object has been assigned 
   //@post returns the exception message when exception is thrown
   //@usage cout << except.what() << endl;
   const string what();
private:
    string mmessage;
};
#endif
