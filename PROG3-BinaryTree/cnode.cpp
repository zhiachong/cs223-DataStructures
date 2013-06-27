//@author: Zhia Chong
//@file: cnode.cpp
//@date 2/7/2011
//@description: cnode.cpp   
//Implementation for Cnode
//     data object is a static array.
// operations: create, destroy, copy, operator=, getleftchild
//             getrightchild, setleftchild, setrightchild, setitem
//             getitem

#include "cnode.h"
#include <iostream>
using namespace std;

//creates a node
//@post: node object exists
//@usage Cnode node;
Cnode::Cnode()
{
   mleftChild = -1;
   mrightChild = -1;
   mitem = '-';
}
   
//destroys a node
//@pre: node object exists
//@post: node object does not exist
//@usage automatically called at the end of scope
Cnode::~Cnode()
{
   mleftChild = -1;
   mrightChild = -1;
   mitem = '-';
}
   
// makes a new node as a copy
// pre: rhsNode exists
// post: node object is a copy of rhsNode
// uses: operator=
// usage: Cnode lhsNode(rhsNode);
Cnode::Cnode(const Cnode& rhsNode)
{
   mleftChild = -1;
   mrightChild = -1;
   mitem = '-';
   operator=(rhsNode);
}
   
// assigns one node to another one
// pre: node object exists
// post: calling object is a copy of rhsNode
// usage: aNode = bNode;
Cnode& Cnode::operator= (const Cnode& rhsNode)
{
   if (this != &rhsNode)
   {
      mleftChild = -1;
      mrightChild = -1;
      mitem = '-';
      mleftChild = rhsNode.mleftChild;
      mrightChild = rhsNode.mrightChild;
      mitem = rhsNode.mitem;
   }
   return* this;
}

//gets left child of node object
//@pre: node object exists
//@post: returns the left child of node object
//@usage rhsnode.GetLeftChild();
int Cnode::GetLeftChild() const
{
   return mleftChild;
}
   
//@gets right child of node object
//@pre node object exists
//@post returns right child of node object
//@usage rhsnode.GetRightChild();
int Cnode::GetRightChild() const
{
   return mrightChild;
}
   
//@gets the item in node object
//@pre: node object exists
//@post returns item
//@usage rhsnode.GetItem();
ItemType Cnode::GetItem() const
{
   return mitem;
}

//@assigns rchild to the node object's right child 
//@pre: node object exists and rchild is assigned
//@post rchild is assigned to node object's right child 
//@param rchild
//@usage rhsnode.SetRightChild(2);
void Cnode::SetRightChild(const int rchild)
{
   mrightChild = rchild;
}

//@assigns lchild to the node object's left child
//@pre: node object exists and lchild is assigned
//@post: lchild is assigned to node object's left child
//@param lchild
//@usage rhsnode.SetLeftChild(3);
void Cnode::SetLeftChild(const int lchild)
{
   mleftChild = lchild;
}

//@assigns newItem to node object's item
//@pre: node object exists and newItem is assigned
//@post: newItem is assigned to node object's item
//@param newItem
//@usage rhsnode.SetItem('k');
void Cnode::SetItem(const char newItem)
{
   mitem = newItem;
}	
