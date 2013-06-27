//@author Zhia chong
//@date 2/19/2011
//@file cbintree.h

// Specification of ADT Binary Tree
//Data object: A binary tree T that is either empty or in the form
//                            r
//                          /   \
//                         TL    TR
//            where r is called the root and left and right subtrees
//            TL and TR are binary trees
//    Operations: (a scaled-down version)
//       create, destroy, copy, operator=, isEmpty, prettyDisplay, makeTree
//       traversals (preorder, inorder, postorder)
// Contract: Assumes the this class can access private data members of class cnode.
//    Those data members are: citem mitem, ckey key, cnode* mleftptr, cnode* mrightptr.
//    There is a constructor that allows caller to give item, left and right ptrs.

#ifndef CBINTREE_H
#define CBINTREE_H
#include "cnode.h"
#include "cexception.h"
#include <fstream>
using namespace std;
typedef Ckey Citem;

class cbintree
{
public:
   //@creates an empty binary tree
   //@post: object is an empty binary tree
   //@usage: Cbintree zags;
   cbintree();

   //@creates a new binary tree that is a copy of an existing tree
   //@post: object is a copy of rhstree
   //@param rhstree
   //@usage: Cbintree zags (bulldog);
   cbintree(const cbintree& rhstree);

   //@releases the memory of a binary tree
   //@pre: object exists
   //@post: memory for the object has been released. object theoretically does not exist
   //       but in practice, it is empty.
   ~cbintree();

   // ******************** member functions ********************************************
   //@pre: binary tree object exists
   // **********************************************************************************
   //@checks for an empty tree
   //@post: returns true if the object is empty; else returns false
   //@return: true if object is empty; false if object is not
   //@usage: if (tree.isEmpty())
   bool isEmpty() const;

   //@copies one tree to another
   //@pre: rhstree is an assigned tree.
   //@post: object is a copy of rhstree
   //@param rhstree
   //@usage: atree = btree = ctree;
   cbintree& operator=(const cbintree& rhstree);

   //@prints the tree to look like a computer science tree with (#) to show the balance
   //@post: outputs the tree as in the example below
   //
   //                        bar (0)
   //                     /
   //                  foo(1)
   //                     
   //                       
   //               /     
   //  root ->  queue(0)
   //               \
   //                        
   //                     
   //                  list(-1)
   //                     \
   //                        array(0)
   //@nodes at the same level are indented the same.
   //@Viewer must rotate head 90 degrees in order to look like a cs tree
   //@ 0 means its balanced, +1 means left side tall, -1 means right side tall.
   //@param: outfile
   //@usage: tree.prettyDisplay(outfile);
   void prettyDisplay(ofstream& outfile);

   // *************** on the following traversals
   //@uses: operator<< from citem
   //@post: prints the objects in the tree in order specified
   //@usage: tree.preorderTraverse();  
   //@similarly for the other traversals
   // *****************************************************
   void preorderTraverse ();
   void inorderTraverse ();
   void postorderTraverse();

   //@makes a full binary tree of height 2
   //@post: object is a full binary tree of height 2
   //@usage: tree.makeTree();
   void makeTree(ifstream& infile) throw (cexception);

protected:   // helper functions for coding member functions

    //@Copies one binary tree to another
    //@pre: oldtreep points to the root of a binary tree
    //@post: newtreep points to the root of a binary tree
    //  that has copies of the nodes of oldtreep's tree
    //@param oldtreep
    //@param newtreep
    //@usage: copyTree (newptr, oldptr);
    void copyTree (Cnode*& newtreep, Cnode* oldtreep); 

    //@Releases memory for a binary tree
    //@pre: treep points to the root of a binary tree
    //@post: releases all of the nodes in the tree pointed to by treep
    //    and leaves treep empty.
    //@param treep
    //@usage: destroyTree (mroot);
    void destroyTree (Cnode*& treep);

    //@recursive helper for prettyDisplay()
    //@pre: treep and level are assigned, treep points to root of binary tree
    //@post: binary tree is printed out from right-handside most first
    //@param treep
    //@param level
    //@usage writePretty(treep, 3);
    void writePretty (Cnode* treep, int level, ofstream& outfile);

    // ********** recursive helpers for the traversals ****************
    //@pre: treep points to the root of a binary tree to be traversed
    //@post: prints the objects of the nodes on the screen in the 
    //     specified order
    //@param treep
    //@usage: preorder (mroot);   
    //    similarly for the others
    void preorder (Cnode* treep);
    void inorder (Cnode* treep);
    void postorder (Cnode* treep);

    // data member
    Cnode* mroot;
};
#endif
