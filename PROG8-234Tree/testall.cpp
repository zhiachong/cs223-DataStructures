#include <iostream>
#include <fstream>
#include "c234node.h"
#include "citem.h"
#include "c234tree.h"
#include "cexception.h"
using namespace std;

//@opens an external file for reading
//@post if the external file fileName exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning else an exception
//@     is thrown
//@param infile
//@usage OpenInputFile(infile);
void OpenInputFile(ifstream& infile) throw (cexception);

int main()
{
   ifstream infile;
   Citem item;
   c234tree tree;
   cout << "*testing citem's friend functions*" << endl;
   infile.open("in8.dat");
   infile >> item; 
   cout << endl << endl;
   cout << "First item is: ";
   cout << item << endl << endl;
   cout << "*testing tree's insert and prettydisplay functions*" << endl;
   C234node* node = new C234node(item);
   tree.Insert(item);
   tree.prettyDisplay();
   cout <<endl;
   cout << "*testing tree's isEmpty function*" << endl;
   if (tree.isEmpty())
   { 
      cout << "tree is empty" << endl << endl;
   } else {
      cout << "tree is not empty" << endl << endl;
   }
   cout << "*testing tree's copy constructor*" << endl;
   c234tree zagtree(tree);
   cout << "Copying tree" << endl << endl;
   zagtree.prettyDisplay();
   
   
   cout << "*testing citem's bool functions*" << endl;
   Citem item2;
   infile >> item2;
   cout << "2nd item to insert: " << item2 << endl << endl;
   if (item2 < item)
   { 
      cout << "second input is less than first" << endl;
   } else if (item2 == item)
   {
      cout << "second input is == first" << endl;
   } else if (item2 > item)
   {
      cout << "second input is more than first" << endl;
   }
   
   cout << endl;
   Citem item3(item);
   if (item3.IsEmptyItem())
      cout << "item 3 is not empty because it is not  initalized yet" << 
endl;
   else {
      cout << "item is copied -> " << item3 << endl;
   }
   cout << endl;
   item.EmptyOut();
   cout << "after method EmptyOut()" << endl;
   cout << "item is now -> " << item << endl;
   
   C234node* ptrnode = new C234node(item);
   C234node* newptrnode = new C234node(item2);
   C234node* constructer = new C234node(item, ptrnode, newptrnode);

   constructer -> recycleNode();

   return 0;
   
}

//@opens an external file for reading
//@post if the external file fileName exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning else an exception
//@     is thrown
//@param infile
//@usage OpenInputFile(infile);
void OpenInputFile(ifstream& infile) throw (cexception)
{
   infile.open("in8.dat");
   if (infile.fail())
   {
      throw ("Error! Dictionary not found!");
   }	
	
}
