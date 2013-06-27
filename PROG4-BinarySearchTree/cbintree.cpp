//@author Zhia Chong
//@date 2/20/2011
//@file cbintree.cpp
//@description

// Implementation of ADT Binary Tree
//Data object: A binary tree T that is either empty or in the form
//                            r
//                          /   \
//                         TL    TR
//            where r is called the root and left and right subtrees
//            TL and TR are binary trees
//Data structure: A linked binary tree that has a root and left and right subtrees
// Operations: (a scaled-down version)
//       create, destroy, copy, operator=, isEmpty, prettyDisplay, makeTree
//       traversals (preorder, inorder, postorder)
// Contract: Assumes the this class can access private data members of class cnode.
//    Those data members are: citem mitem, ckey key, cnode* mleftptr, cnode* mrightptr.
//    There is a constructor that allows caller to give item, left and right ptrs.

#include <iostream>
#include <fstream>
#include "cbintree.h"
using namespace std;


//@post prints out white spaces
//@usage PrintSpace(width);
void PrintSpace(int num)
{
   for (int i = 0; i < num; i++)
   {
      cout << " ";
   }
}

// creates an empty binary tree
// post: object is an empty binary tree
// usage: cbintree zags;
cbintree::cbintree(): mroot(NULL)
{}

// creates a new binary tree that is a copy of an existing tree
// post: object is a copy of rhstree
// usage: cbintree zags (bulldog);
cbintree::cbintree(const cbintree& rhstree): mroot(NULL)
{
   copyTree (mroot, rhstree.mroot);
}

// releases the memory of a binary tree
// pre: object exists
// post: memory for the object has been released. object theoretically does not exist
//       but in practice, it is empty.
cbintree:: ~cbintree()
{
   destroyTree (mroot);
}

// ******************** member functions ********************************************
// pre: binary tree object exists
// **********************************************************************************
// post: returns true if the object is empty; else returns false
// usage: if (tree.isEmpty())
bool cbintree::isEmpty() const
{
   return (mroot == NULL);
}

//@prints the tree to look like a computer science tree
//@post: outputs the tree as in the example below
//
//                        bar
//                  foo
//                        geeU
//  root ->  queue
//                        stack
//                  list
//                        array
//@nodes at the same level are indented the same.
//@Viewer must rotate head 90 degrees in order to look like a cs tree
//@usage: tree.prettyDisplay();
void cbintree::prettyDisplay()
{
   writePretty(mroot, 0);
}

// pre: rhstree is an assigned tree.
// post: object is a copy of rhstree
// usage: atree = btree = ctree;
cbintree& cbintree::operator=(const cbintree& rhstree)
{
   if (this != &rhstree)
   {
      destroyTree (mroot);
      copyTree (mroot, rhstree.mroot);
   }
   return *this;
}  

// Add prettyDisplay and writePretty from the .h file

// *************** on the following traversals
// uses: operator<< from citem
// post: prints the objects in the tree in order specified
// usage: tree.preorderTraverse();  
// similarly for the other traversals
// *****************************************************
void cbintree::preorderTraverse ()
{
   preorder (mroot);
}

void cbintree::inorderTraverse ()
{
   inorder (mroot);
}
   
void cbintree::postorderTraverse()
{
   postorder (mroot);
}

// makes a tree for testing purposes. You may add a file parameter
// post: the tree is a full tree of height 3 
// usage: mytree.makeTree();
void cbintree:: makeTree(ifstream& infile) throw (cexception)
{
   Citem item;
   infile >> item;
   mroot = new (nothrow) Cnode (item, NULL, NULL);
   if (mroot == NULL)
   {
      throw cexception("makeTree: Not enough memory");
   } else {
      infile >> item;
      mroot -> mleftptr = new (nothrow) Cnode (item, NULL, NULL);
      infile >> item;
      mroot -> mrightptr = new (nothrow) Cnode (item, NULL, NULL); 
  
      Cnode* curptr = mroot -> mleftptr;
      infile >> item;
      curptr -> mleftptr = new (nothrow) Cnode (item, NULL, NULL);
      infile >> item;
      curptr -> mrightptr = new (nothrow) Cnode (item, NULL, NULL); 
   
      Cnode* newptr = mroot -> mrightptr;
      infile >> item;
      newptr -> mleftptr = new (nothrow) Cnode (item, NULL, NULL);
      infile >> item;
      newptr -> mrightptr = new (nothrow) Cnode (item, NULL, NULL); 
   }
}


// helper functions for coding member functions
// Copies one binary tree to another
// pre: oldtreep points to the root of a binary tree
// post: newtreep points to the root of a binary tree
//  that has copies of the nodes of oldtreep's tree
// usage: copyTree (newptr, oldptr);
void cbintree::copyTree (Cnode*& newtreep, Cnode* oldtreep) 
{
   if (oldtreep == NULL)
      newtreep = NULL;
   else
   {
      // preorder traversal
      newtreep = new Cnode(oldtreep -> mitem, NULL, NULL);
      copyTree (newtreep -> mleftptr, oldtreep -> mleftptr);
      copyTree (newtreep -> mrightptr, oldtreep -> mrightptr);
   }
}

// Releases memory for a binary tree
// pre: treep points to the root of a binary tree
// post: releases all of the nodes in the tree pointed to by treep
//    and leaves treep empty.
// usage: destroyTree (mroot);
void cbintree::destroyTree (Cnode*& treep)
{
   // do a postorder traversal
   if (treep != NULL)
   {
      destroyTree (treep -> mleftptr);
      destroyTree (treep -> mrightptr);
      delete treep;
      treep = NULL;
   }
}

//@recursive helper for prettyDisplay()
//@pre: treep and level are assigned, treep points to root of binary tree
//@post: binary tree is printed out from right-handside most first
//@param treep
//@param level
//@usage writePretty(treep, 0);
void cbintree::writePretty (Cnode* treep, int level)
{
   if (treep != NULL)
   {
      level++;
      writePretty(treep -> mrightptr, level);
      int space = (level * 8) - 1;
      int signspace = ((level + 1) * 7);
    
      if (treep -> mrightptr != NULL) 
      {
          PrintSpace(signspace);
          cout << "/" << endl << endl;
      }
		
      PrintSpace(space);
		
      if (level == 1)
      {
         cout << endl;
         cout << "mroot -> ";
      }
		
      cout << treep -> mkey << endl << endl;
   
      if (treep -> mleftptr != NULL)
      {
         PrintSpace(signspace);
         cout << "\\" << endl << endl;
      }
      writePretty(treep -> mleftptr, level);
   }
}
                
// ********** recursive helpers for the traversals ****************
// pre: treep points to the root of a binary tree to be traversed
// post: prints the objects of the nodes on the screen in the
// specified order
// usage: preorder (mroot);   
//    similarly for the others
void cbintree::preorder (Cnode* treep)
{
   if (treep != NULL)
   {
      cout <<  treep -> mitem << endl;
      preorder (treep -> mleftptr);
      preorder (treep -> mrightptr);
   }
}

// pre: treep points to the root of a binary tree to be traversed
// post: prints the objects of the nodes on the screen in the
// specified order
// usage: inorder (mroot); 
void cbintree::inorder (Cnode* treep)
{
   if (treep != NULL)
   {
      inorder (treep -> mleftptr);
      cout <<  treep -> mitem << endl; 
      inorder (treep -> mrightptr);
   }
}

// pre: treep points to the root of a binary tree to be traversed
// post: prints the objects of the nodes on the screen in the
// specified order
// usage: postorder (mroot); 
void cbintree::postorder (Cnode* treep)
{
   if (treep != NULL)
   {
      postorder (treep -> mleftptr);
      postorder (treep -> mrightptr);
      cout <<  treep -> mitem << endl;
   }
}
