//author Zhia Chong
//date 4/14/2011
//filename: C234node.cpp
//description:

// ADT 2-3-4 Tree Node:
// Specification file
//    data object: a node for a 2-3-4 tree
//    data structure: an array of C234nodes and an array of Citems
//    operations: two constructors
// Contract: the items for the node are defined in class Citem
//           and citem has a GOOD copy constructor

#include <cstddef>
#include "citem.h"
#include "c234node.h"

   // creates a node with a given item and no kids
   // pre: newItem is assigned
   // post: the newitem is inserted into the node and the kids are NULL
   // usage: C234node node = new C234node(newitem);
   C234node::C234node(const Citem& newItem)
   {
      for (int i = 0; i < 4; i++)
         mkids[i] = NULL;
      mitem[0] = newItem;
   }
   
   // creates a node with a given item and kids
   // pre: newItem, leftKid, rightKid are assigned
   // post: the item of the node is newItem, the kids are left and right
   // usage: aptr = new C234node (thisone, NULL, NULL);
   C234node::C234node (const Citem& newItem, C234node* leftKid, C234node* rightKid)
   {
      mkids[0] = leftKid;
      mkids[1] = rightKid;
      mitem[0] = newItem;
   }
   
   //releases memory of a node
   // pre: node exists
   // post: node does not exist
   // usage: node.~C234node();
   C234node::~C234node()
   {
      for (int i = 0; i < 4; i++)
      {
         delete mkids[i];
         mkids[i] = NULL;
     }
   }
   
   // copies one node to another
   // pre: rhsnode is assigned and node exists
   // post: copies rhsnode to another node
   // param rhsnode
   // usage: node = rhsnode;
   C234node& C234node::operator= (const C234node& rhsnode)
   {
      if (this != &rhsnode)
      {
         for (int i = 0; i < 4; i++)
            mkids[i] = rhsnode.mkids[i];
         for (int i = 0; i < 3; i++)
            mitem[i] = rhsnode.mitem[i]; 
      }
      return *this;
   }
   
   
   // empties the two rightmost items in node
   //@pre two rightmost positions on node are occupied
   //@post two rightmost positions on node are cleared
   //@usage node.recycleNode();
   void C234node::recycleNode()
   {
      mitem[1].EmptyOut();
      mitem[2].EmptyOut();
   }
   
