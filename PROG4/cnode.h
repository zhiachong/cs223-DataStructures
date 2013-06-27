
// ADT Binary Tree Node:
// Spec and implementation file
//    data object: a node for a dynamic binary tree
//    operations: two constructors
// Friend classes: Cbintree, Cbstree
// Contract: the items for the node are defined in class Citem
//           and citem has a GOOD copy constructor

#include "citem.h"
#include "ckey.h"
#include <cstddef>

#ifndef CNODE_H
#define CNODE_H

class Cnode
{
private:

   // creates a node
   // post: the item of the node is empty and the kids are NULL
   // usage: newptr = new cnode();
   Cnode():mleftptr(NULL),mrightptr(NULL) {};

   // creates a node with a given item and kids
   // post: the item of the node is nodeItem, the kids are left and right
   // usage:aptr = new  cnode (thisone, NULL, NULL);
   // CAUTION: REQUIRES THAT COPY WORKS IN CITEM!!
   Cnode (const Citem& nodeItem, 
          Cnode* left, Cnode* right):
          mitem (nodeItem), mkey (nodeItem), mleftptr (left), mrightptr (right) {}

   // implementation of data object
   Citem mitem;
   Ckey mkey;
   Cnode* mleftptr;
   Cnode* mrightptr;

   friend class cbintree;
   friend class cbstree;
};
#endif
