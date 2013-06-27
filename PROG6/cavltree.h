//@ Zhia Chong
//@ 3/20/2011
//@ file: cavltree.h
//@description:

// Implementation of ADT AVL Tree
//Data object: An Adelson-Velskii & Landis Tree (AVL) is-a AVL tree that is either empty or in the form
//                            r
//                          /   \
//                         TL    TR
//            where r is called the root and left and right subtrees, the data are arranged 
//            in order, such that |HR - HL| <= 1, where HL is height of TL and HR is height of
//            TR and TL and TR are AVL trees.
// Operations: (a scaled-down version)
//       create, destroy, insert, copy
// Contract: Assumes the this class can access private data members of class cnode and public
//           methods of cbstree and cbintree.
//    Those data members for cnode are: citem mitem, ckey mkey, int mbalance, cnode* mleftptr, cnode* mrightptr.
//    Those methods for cbintree are: bool isEmpty, void prettyDisplay,void makeTree
//       void traversals (preorder, inorder, postorder)
//    Those methods for cbstree are: retrieve, rebalanceTree, insert, remove, and inorderTraverser


#ifndef CAVLTREE_H
#define CAVLTREE_H
#include "cbstree.h"
#include "ckey.h"
#include "cexception.h"

struct SearchPath ;

class cavltree: public cbstree
{
public:
   //@creates a new AVL tree
   //@post: an empty AVL tree object exists
   //@usage: cavltree tree;
   cavltree();
   
   //@releases memory for a AVL tree
   //@pre: AVL tree object exists
   //@post: AVL tree object does not exist
   //@usage: automatically done at end of score
   ~cavltree();
   
   // creates a new AVL tree that is a copy of an existing tree
   // post: object is a copy of rhstree
   // usage: cavltree zags (bulldog);
   cavltree(const cavltree& rhstree);
      
   //@inserts a new item into the AVL tree
   //@pre: newItem has been assigned
   //@post: if the newItem's key is not already in the tree
   //         then the newItem is added to the tree
   //       else an exception is thrown
   //@usage: tree.insert(newItem);
   void insert (const Citem& newItem) throw (cexception);
   
protected:  

   // *****************************************************************
   // *  Helper functions
   // *****************************************************************
   
   //@runs binary tree insert then builds the search array path and assigns
   //@   size
   //@pre AVL newitem, treeptr, and search are all assigned
   //@post newitem is added to the tree, treeptr is updated, and search has been created
   //@   and filled out
   //@param newitem
   //@param treeptr
   //@param search, the Search Path of the AVL tree
   //@throw cexception
   //@usage try {BStreeInsertNMakeSearchPath(newitem, mroot, search); }
   //@      throw (cexception except) {cout << except.what(); }
   void BSTreeInsertNMakeSearchPath(const Citem& newitem, Cnode*& treeptr,SearchPath& search) throw (cexception);
   
   //@description: determines whether or not there is a pivot in the search path    
   //              and if there is, sets the pivot index in search
   //@pre search.path has been assigned, search.size is assigned the size of
   //     the search path, search.pivot is initialized to -1
   //@post assigns a value to search.pivot if there is a pivot
   //@     and returns false else returns true
   //@param search
   //@usage if(AVLtree.HasNoPivot(search))
   bool HasNoPivot(SearchPath& search) const;
   
   //@ Adjusts the balances of the nodes in a portion of the search path on an AVL tree after an insert
   //@ pre: start and search are assigned
   //@ post: AVL tree Nodes are changed appropriately on the search path from index start down to parent of new new node
   //@ param: search, the Search Path of the AVL tree
   //@ param: start, the starting point in the path where mbalance needs to be adjusted
   //@ usage: ChangesBalances(mysearch, 0);
   void ChangesBalances(const SearchPath& search, int start);

   //@checks to see if the added node is attached to the shorter
   // side from the pivot. 
   //@pre: search has been assigned and has a pivot. 
   //@post: returns true if added node is attached to shorter side of tree
   //       else returns false
   //@param search, the Search Path of the AVL tree
   //@usage if(IsAddedToShortSide(search));
   bool IsAddedToShortSide(const SearchPath& search) const;
   
   //@Checks whether or not the AVL tree needs a Left Rotate
   //@pre:   the pivot exists, the search path exists and contains the path
   //        taken by the insert function 
   //@post:  Returns true if the search path goes right twice from the pivot,
   //        otherwise returns false.
   //@usage: if(IsSingleRotateLeft)
   //           (do something);
   //@param search
   bool IsSingleRotateLeft(const SearchPath& search) const;
   
   //@Checks whether or not the AVL tree needs a Right Rotate
   //@pre:   the pivot exists, the search path exists and contains the path
   //        taken by the insert function
   //@post:  Returns true if the search path goes left twice,
   //        otherwise returns false.
   //@usage: if(IsSingleRotateRight)
   //           (do something);
   //@param search
   bool IsSingleRotateRight(const SearchPath& search) const;
   
   // Checks if the tree needs to be rotated left then right
   // pre: Calling AVL Tree object exists
   //      search has been assigned and has a pivot
   //      A new item has been added to the long side of the tree
   // post: If search path goes left then right from pivot, then returns true
   //       else returns false
   // param search
   // usage: if (ourawesometree.IsDoubleRotateLeftRight (search)) {DoDoubleRotateLeftRight ()};
   bool IsDoubleRotateLeftRight (const SearchPath& search) const;
   
   //@does a single left rotate of the AVL tree
   //@pre: tree exists, search exists and contains the path taken by insert function
   //@post: the tree is rotated to the left from the pivot point down
   //@param search
   //@usage: DoSingleRotateLeft();
   void DoSingleRotateLeft(SearchPath& search);
   
   //@does a single right rotate of the AVL tree
   //@pre: tree exists, tree exists, search exists and contains the path taken by insert function
   //@post: the tree is rotated to the right from the pivot point down
   //@param search
   //@usage: DoSingleRotateRight();
   void DoSingleRotateRight (SearchPath& search);
   
   //@does a double rotate. Changes the orientation of the tree from pivot point
   //@down
   //@pre: tree exists, tree exists, search exists and contains the path taken by insert function
   //@post: tree is rotated so that tree is balanced
   //@param search
   //@usage: DoDoubleRotateLeftRight();
   void DoDoubleRotateLeftRight (SearchPath& search);
   
   //@does a double rotate. Changes orientation of the tree from pivot point 
   //@down. Opposite direction of DoDoubleRotateLeftRight()
   //@pre: tree exists, tree exists, search exists and contains the path taken by insert function
   //@post: tree is rotated such that the tree is balanced
   //@param search
   //@usage DoDoubleRotateLeft();
   void DoDoubleRotateRightLeft (SearchPath& search);
  };
#endif
