//@author: Zhia Chong
//@file: cbintree.h
//@date 2/7/2011
//@description: cbintree.h   
//Specification for ADT Binary Tree
//     data object is a binary tree.
//        A binary tree is a tree which is either
//        (1) empty or
//        (2) in the form     r
//                          /   \
//                         TL    TR
//            where r is called the root and left and right subtrees
//            TL and TR are binary trees
// operations: create, destroy, copy, operator=, add a node, 
//             prints (preorder, inorder, postorder)
// friend: operator >>
//
// Contract: based on cnode that is based on citem

#ifndef CBINTREE_H
#define CBINTREE_H

#include "cnode.h"
#include <iostream>
const int MAXNODES = 15;
using namespace std;

class Cbintree
{
   //@gets input from user
   //@pre rhstree exists. input is open.
   //@post input is retrieved
   //@param input
   //@param rhstree
   //@usage cin >> tree;  
   friend istream& operator>>(istream& input, Cbintree& rhstree);
   
public:
   // creates a binary tree
   // post: binary tree object exists
   // usage: Cbintree b;
   Cbintree();

   // destroys a binary tree
   // pre: binary tree object exists
   // post: binary tree object does not exist
   // usage: automatically called at the end of scope
   ~Cbintree();

   // makes a new binary tree as a copy
   // pre: rhstree exists
   // post: binary tree object is a copy of rhstree
   // uses: operator=
   // usage: Cbintree lhstree(rhstree);
   Cbintree(const Cbintree& rhstree);  

   // member functions pre: binary tree object exists

   // assigns one binary tree to another one
   // pre: binary tree object exists
   // post: calling object is a copy of rhstree
   // usage: atree = btree;
   Cbintree& operator= (const Cbintree& rhstree);

   // adds a node to a binary tree
   // pre: binary tree object exists
   // post: newNode has been added to the tree
   // usage: b.addNode (thisNode);
   void addNode (const Cnode& newNode);

   // pre: all prints assume the standard output's pointer is
   //       at the beginning of a new line.

   // prints the nodes in a tree in pre-order, binary tree object exists
   // pre: standard output's pointer is at the beginning of a new line
   // post: if tree object is not empty, displays the node items
   //    in preorder on standard output else does nothing
   // usage: b.preOrderPrint();
   void preOrderPrint ();

   // prints the nodes in a tree in in-order
   // pre: standard output's pointer is at the beginning of a new line
   // post: if tree object is not empty, displays the node items
   //    in in-order on standard output else does nothing
   // usage: b.inOrderPrint();
   void inOrderPrint ();

   // prints the nodes in a tree in post-order
   // pre: standard output's pointer is at the beginning of a new line
   // post: if tree object is not empty, displays the node items
   //   in post-order
   // usage: b.postOrderPrint();
   void postOrderPrint ();

private:
   void preorderHelper(int subroot);
   void postorderHelper(int subroot);
   void inorderHelper(int subroot);
   
   Cnode mTree [MAXNODES];
   int mroot;
   int mfree;
};
#endif
