//@file cexception.cpp
//@author Zhia Chong
//@date Feb 18, 2011

//@Implementation of ADT Exception message
//    data object: a message explaining an exception
//    data structure: whatever the string class uses
//    operations: create and what

#include "cexception.h"

//@creates an exception message
//@pre  theMessage passed may be a literal string
//@post exception message object is assigned theMessage
//@usage throw cexception ("BAD MOVE");
cexception::cexception(string theMessage ) 
{
   mmessage = theMessage;
}

//@outputs a message exception
//@pre message object has been assigned 
//@post returns the exception message when exception is thrown
//@usage cout << except.what() << endl;
const string cexception::what()
{
   return mmessage;
}
