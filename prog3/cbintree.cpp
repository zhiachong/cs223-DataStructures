//@author: Zhia Chong
//@file: cbintree.cpp
//@date 2/7/2011
//@description: cbintree.cpp
//Implementation for ADT Binary Tree
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
// Contract: based on cnode that is based on citem


#include <iostream>
#include "cbintree.h"
using namespace std;

//******Helper functions*********

//helper function for preOrderPrint
//@pre subroot is assigned
//@post prints out the binary tree in a pre-order
//@param subroot
//@usage preorderHelper(mroot);
void Cbintree::preorderHelper(int subroot)
{
   bool ok;
   ok = (subroot != -1);
   if (ok)
   {
      cout << mTree[subroot].GetItem() << " ";
      preorderHelper(mTree[subroot].GetLeftChild());
      preorderHelper(mTree[subroot].GetRightChild());
   }
}

//a helper function for inOrderPrint
//@pre subroot is assigned
//@post prints out the binary tree in an in-order
//@param subroot
//@usage inorderHelper(mroot);
void Cbintree::inorderHelper(int subroot)
{
   bool ok;
   ok = (subroot != -1);
   if (ok)
   {
      inorderHelper(mTree[subroot].GetLeftChild());
      cout << mTree[subroot].GetItem() << " ";
      inorderHelper(mTree[subroot].GetRightChild());
   }
}

//a helper function for postOrderPrint
//@pre subroot is assigned
//@post prints out the binary tree in a ppost-order
//@param subroot
//@usage postorderHelper(mroot);
void Cbintree::postorderHelper(int subroot)
{
   bool ok; 
   ok = (subroot != -1);
   if (ok)
   {
      postorderHelper(mTree[subroot].GetLeftChild());
      postorderHelper(mTree[subroot].GetRightChild());
      cout << mTree[subroot].GetItem() << " ";
   }
}

//****Class methods******

// creates a binary tree
// post: binary tree object exists
// usage: Cbintree b;
Cbintree::Cbintree()
{
   mroot = -1;
   mfree = 0; 
}

// destroys a binary tree
// pre: binary tree object exists
// post: binary tree object does not exist
// usage: automatically called at the end of scope
Cbintree::~Cbintree()
{
   mroot = -1;
   mfree = 0;
}

// makes a new binary tree as a copy
// pre: rhstree exists
// post: binary tree object is a copy of rhstree
// uses: operator=
// usage: Cbintree lhstree(rhstree);
Cbintree::Cbintree(const Cbintree& rhstree)
{
   mroot = -1; 
   mfree = 0;
   operator=(rhstree);
}

// assigns one binary tree to another one
// pre: binary tree object exists
// post: calling object is a copy of rhstree
// usage: atree = btree;
Cbintree& Cbintree::operator= (const Cbintree& rhstree)
{
   if (this != &rhstree)
   {
      mroot = -1;
      mfree = 0;
      mroot = rhstree.mroot;
      mfree = rhstree.mfree;
      for (int i = 0; i < mfree; i++)
      {
         mTree[i] = rhstree.mTree[i];
      }
   }
   return *this;
}

// adds a node to a binary tree
// pre: binary tree object exists
// post: newNode has been added to the tree
// usage: b.addNode (thisNode);
void Cbintree::addNode (const Cnode& newNode)
{
   if (mfree < MAXNODES)
   {
      mTree[mfree] = newNode;
      mfree++;
   }
}

// prints the nodes in a tree in pre-order, binary tree object exists
// pre: standard output's pointer is at the beginning of a new line
// post: if tree object is not empty, displays the node items
//    in preorder on standard output else does nothing
// usage: b.preOrderPrint();
void Cbintree::preOrderPrint ()
{
   preorderHelper(mroot);
}

// prints the nodes in a tree in in-order
// pre: standard output's pointer is at the beginning of a new line
// post: if tree object is not empty, displays the node items
//    in in-order on standard output else does nothing
// usage: b.inOrderPrint();
void Cbintree::inOrderPrint ()
{
   inorderHelper(mroot);
}

// prints the nodes in a tree in post-order
// pre: standard output's pointer is at the beginning of a new line
// post: if tree object is not empty, displays the node items
//   in post-order
// usage: b.postOrderPrint();
void Cbintree::postOrderPrint ()
{
   postorderHelper(mroot);
}

//@gets input from user/file
//@pre rhstree exists. input is open.
//@post input is retrieved
//@param input
//@param rhstree
//@usage cin >> tree;
istream& operator>>(istream& input, Cbintree& rhstree)
{
   char newItem;
   int leftchild, rightchild;
   Cnode newNode;
   if (&input == &cin)
   {
      input >> newItem;
      cout << "Enter left child: ";
      input >> leftchild;
      cout << "Enter right child: ";
      input >> rightchild;
      newNode.SetItem(newItem);
      newNode.SetLeftChild(leftchild);
      newNode.SetRightChild(rightchild);
   } else {
      input >> newItem;
      input >> leftchild;
      input >> rightchild;
      newNode.SetItem(newItem);
      newNode.SetLeftChild(leftchild);
      newNode.SetRightChild(rightchild);
   }  
   rhstree.addNode(newNode);
}
