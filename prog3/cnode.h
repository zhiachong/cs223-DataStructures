//@author: Zhia Chong
//@file: cnode.h
//@date 2/7/2011
//@description: cnode.h   
//Specification for Cnode
//     data object is a static array
// operations: create, destroy, copy, operator=, getleftchild
//             getrightchild, setleftchild, setrightchild, setitem
//             getitem
//

#ifndef CNODE_H
#define CNODE_H
typedef char ItemType;
class Cnode
{
public: 
   //creates a node
   //@post: node object exists
   //@usage Cnode node;
   Cnode();
   
   //destroys a node
   //@pre: node object exists
   //@post: node object does not exist
   //@usage automatically called at the end of scope
   ~Cnode();
   
   // makes a new node as a copy
   // pre: rhsNode exists
   // post: node object is a copy of rhsNode
   // uses: operator=
   // usage: Cnode lhsNode(rhsNode);
   Cnode(const Cnode& rhsNode);
   
   // assigns one node to another one
   // pre: node object exists
   // post: calling object is a copy of rhsNode
   // usage: aNode = bNode;
   Cnode& operator= (const Cnode& rhsNode);
   
   //gets left child of node object
   //@pre: node object exists
   //@post: returns the left child of node object
   //@usage rhsnode.GetLeftChild();
   int GetLeftChild() const;
   
   //@gets right child of node object
   //@pre node object exists
   //@post returns right child of node object
   //@usage rhsnode.GetRightChild();
   int GetRightChild() const;
   
   //@gets the item in node object
   //@pre: node object exists
   //@post returns item
   //@usage rhsnode.GetItem();
   ItemType GetItem() const;
   
   //@assigns rchild to the node object's right child 
   //@pre: node object exists and rchild is assigned
   //@post rchild is assigned to node object's right child 
   //@param rchild
   //@usage rhsnode.SetRightChild(2);
   void SetRightChild(const int rchild);

   //@assigns lchild to the node object's left child
   //@pre: node object exists and lchild is assigned
   //@post: lchild is assigned to node object's left child
   //@param lchild
   //@usage rhsnode.SetLeftChild(3);
   void SetLeftChild(const int lchild);

   //@assigns newItem to node object's item
   //@pre: node object exists and newItem is assigned
   //@post: newItem is assigned to node object's item
   //@param newItem
   //@usage rhsnode.SetItem('k');
   void SetItem(const char newItem);
   
private:
   ItemType mitem;
   int mleftChild, mrightChild;
};
#endif
