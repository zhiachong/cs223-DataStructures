//@ Zhia Chong
//@ 3/20/2011
//@ file: cavltree.cpp
//@description:

// Implementation of ADT AVL Tree
//Data object: An Adelson-Velskii & Landis Tree (AVL) is-a binary search tree that is either empty or in the form
//                            r
//                          /   \
//                         TL    TR
//            where r is called the root and left and right subtrees, the data are arranged 
//            in order, such that |HR - HL| <= 1, where HL is height of TL and HR is height of
//            TR and TL and TR are AVL trees.
//Data structure: A linked AVL tree 
// Operations: (a scaled-down version)
//       create, destroy, copy, insert
// Contract: Assumes the this class can access private data members of class cnode and public 
//           methods of cbintree.
//    Those data members are: citem mitem, ckey key, cnode* mleftptr, cnode* mrightptr for cnode.
//    Those methods for cbintree are: bool isEmpty, void prettyDisplay,void makeTree
//       void traversals (preorder, inorder, postorder)
//    Those methods for cbstree are: retrieve, rebalanceTree, insert, remove, and inorderTraverser

#include "cavltree.h"
#include "cexception.h"
#include <fstream>
 
const int MAXHEIGHT = 15;
struct SearchPath
{
   Cnode* path[MAXHEIGHT];
   int size;
   int pivot;
   SearchPath();   //prototype of constructor
};

//constructor
//@post initializes size, pivot and path
SearchPath::SearchPath()
{
   size = 0;
   pivot = -1;
   for(int i = 0; i < MAXHEIGHT; i++)
      path[i] = NULL;
}    

//@creates a new AVL tree
//@post: an empty AVL tree object exists
//@usage: cbstree bst;
cavltree::cavltree(): cbstree()
{}

//@releases memory for a AVL tree
//@pre: AVL tree object exists
//@post: AVL tree object does not exist
//@usage: automatically done at end of score
cavltree::~cavltree()
{
   itemCount = 0;
   destroyTree(mroot);
}

//@creates a new AVL tree that is a copy of an existing tree
//@post: object is a copy of rhstree
//@usage: cavltree zags (bulldog);
cavltree::cavltree(const cavltree& rhstree)
{
   itemCount = rhstree.itemCount;
   copyTree(mroot, rhstree.mroot);
}

//@checks to see if the added node is attached to the shorter
// side from the pivot. 
//@pre: search has been assigned and has a pivot. 
//@post: returns true if added node is attached to shorter side of tree
//       else returns false
//@param search
//@usage if(IsAddedToShortSide(search));
bool cavltree::IsAddedToShortSide(const SearchPath& search) const
{
   Cnode* pivotptr;
   Cnode* nextpathptr;
   
   pivotptr = search.path[search.pivot];
   nextpathptr = search.path[search.pivot + 1];
   
   if(pivotptr -> mbalance == -1 && pivotptr -> mrightptr == nextpathptr)
      return true;  // tall left and added right
   else if(pivotptr -> mbalance  == 1 && pivotptr -> mleftptr == nextpathptr)
      return true;  // tall right and added left
   else
      return false;
}  

//@Checks whether or not the AVL tree needs a Left Rotate
//@pre:   the pivot exists, the search path exists and contains the path
//        taken by the insert function 
//@post:  Returns true if the search path goes right twice from the pivot,
//        otherwise returns false.
//@usage: if(IsSingleRotateLeft)
//           (do something);
//@param search
bool cavltree::IsSingleRotateLeft(const SearchPath& search) const
{
   if(search.path[search.pivot] -> mrightptr == search.path[search.pivot + 1])
      return (search.path[search.pivot + 1] -> mrightptr == search.path[search.pivot + 2]);
   else
      return false;
}

//@Checks whether or not the AVL tree needs a Right Rotate
//@pre:   the pivot exists, the search path exists and contains the path
//        taken by the insert function
//@post:  Returns true if the search path goes left twice,
//        otherwise returns false.
//@usage: if(IsSingleRotateRight)
//           (do something);
//@param search
bool cavltree::IsSingleRotateRight(const SearchPath& search) const
{
   if(search.path[search.pivot] -> mleftptr == search.path[search.pivot + 1])
      return (search.path[search.pivot + 1] -> mleftptr == search.path[search.pivot + 2]);
   else
      return false;
}

// Checks if the tree needs to be rotated left then right
// pre: Calling AVL Tree object exists
//      search has been assigned and has a pivot
//      A new item has been added to the long side of the tree
// post: If search path goes left then right from pivot, then returns true
//       else returns false
// param search
// usage: if (ourawesometree.IsDoubleRotateLeftRight (search)) {DoDoubleRotateLeftRight ()};
bool cavltree::IsDoubleRotateLeftRight (const SearchPath& search) const
{
   return ((search.path [search.pivot] -> mleftptr == search.path [search.pivot + 1]) &&
           (search.path [search.pivot + 1] -> mrightptr == search.path [search.pivot + 2]));
}  

//@inserts a new item into the AVL tree
//@pre: newItem has been assigned
//@post: if the newItem's key is not already in the tree
//         then the newItem is added to the tree
//       else an exception is thrown
//@usage: bst.insert(newItem);
void cavltree::insert (const Citem& newItem) throw (cexception)
{
   SearchPath search;
   BSTreeInsertNMakeSearchPath(newItem, mroot, search);   
   
   if (HasNoPivot (search))
      ChangesBalances (search, 0);
   else if (IsAddedToShortSide (search))
      ChangesBalances (search, search.pivot);
   else if (IsSingleRotateLeft (search))
      DoSingleRotateLeft (search);
   else if (IsSingleRotateRight (search))
      DoSingleRotateRight (search);
   else if (IsDoubleRotateLeftRight (search))
      DoDoubleRotateLeftRight (search);
   else
      DoDoubleRotateRightLeft (search);   
}  

//@runs binary tree insert then builds the search array path and assigns
//@   size
//@pre AVL newitem, treeptr, and search are all assigned
//@post newitem is added to the tree, treeptr is updated, and search has been created
//@   and filled out
//@param newitem
//@param treeptr
//@param search
//@throw cexception
//@usage try {BStreeInsertNMakeSearchPath(newitem, mroot, search); }
//@      throw (cexception except) {cout << except.what(); }
void cavltree::BSTreeInsertNMakeSearchPath(const Citem& newitem, Cnode*& treeptr,
                                           SearchPath& search) throw (cexception)
{
   if (treeptr == NULL) {
      treeptr = new (nothrow) Cnode(newitem, NULL, NULL);
      if (treeptr == NULL)
      {
         search.size = 0;
         throw ("Cavltree::BSTreeInsertNMakeSearchPath - Not Enough Memory to Make Node");
      }
      search.path[search.size] = treeptr;
      search.size++;
      itemCount++;
   } else if (newitem < treeptr -> mitem) {
      search.path[search.size] = treeptr;
      search.size++;
      BSTreeInsertNMakeSearchPath(newitem, treeptr -> mleftptr, search);
   } else {
      search.path[search.size] = treeptr;
      search.size++;
      BSTreeInsertNMakeSearchPath(newitem, treeptr -> mrightptr, search);
   }
}

//@description: determines whether or not there is a pivot in the search path    
//              and if there is, sets the pivot index in search
//@pre search.path has been assigned, search.size is assigned the size of
//     the search path, search.pivot is initialized to -1
//@post assigns a value to search.pivot if there is a pivot
//@     and returns false else returns true
//@param search
//@usage if(AVLtree.HasNoPivot(search))
bool cavltree::HasNoPivot(SearchPath& search) const
{
   bool noPivot = true;
   int index = search.size - 1;
   do {
      if (search.path[index] -> mbalance != 0)
      {
         search.pivot = index;
	      noPivot = false;
      }
      index--;
   } while (index >= 0 && noPivot);
	
   return noPivot;
}

//@ Adjusts the balances of the nodes in a portion of the search path on an AVL tree after an insert
//@ pre: start and search are assigned
//@ post: AVL tree Nodes are changed appropriately on the search path from index start down to parent of new new node
//@ param: search, the Search Path of the AVL tree
//@ param: start, the starting point in the path where mbalance needs to be adjusted
//@ usage: ChangesBalances(mysearch, 0);
void cavltree::ChangesBalances(const SearchPath& search, int start)
{
   for(int k = start; k < search.size - 1; k++)
   {
      if(search.path[k] -> mrightptr == search.path[k+1])
         search.path[k] -> mbalance = search.path[k] -> mbalance + 1;
      else
         search.path[k] -> mbalance = search.path[k] -> mbalance - 1;
   }
}

/************HELPER FUNCTIONS***************/


//@does a single left rotate of the AVL tree
//@pre: tree exists, search exists and contains the path taken by insert function
//@post: the tree is rotated to the left from the pivot point down
//@param search
//@usage: DoSingleRotateLeft();
void cavltree::DoSingleRotateLeft (SearchPath& search)
{
   search.path[search.pivot] -> mbalance = 0;
   ChangesBalances(search, search.pivot + 2);
   if (search.path[search.pivot - 1] -> mleftptr == search.path[search.pivot])
   {
      search.path[search.pivot - 1] -> mleftptr = search.path[search.pivot + 1]; 
   } else if (search.path[search.pivot - 1] -> mrightptr == search.path[search.pivot])
   {
      search.path[search.pivot - 1] -> mrightptr = search.path[search.pivot + 1]; 
   } else {
      mroot = search.path[search.pivot + 1];
   }
   search.path[search.pivot] -> mrightptr = search.path[search.pivot + 1] -> mleftptr;
   search.path[search.pivot + 1] -> mleftptr = search.path[search.pivot];
}

//@does a single right rotate of the AVL tree
//@pre: tree exists, tree exists, search exists and contains the path taken by insert function
//@post: the tree is rotated to the right from the pivot point down
//@param search
//@usage: DoSingleRotateRight();
void cavltree::DoSingleRotateRight (SearchPath& search)
{
   search.path[search.pivot] -> mbalance = 0;
   ChangesBalances(search, search.pivot + 2);
   for (int i = search.pivot; i < search.size - 3; i++)
      search.path[i + 2] -> mbalance = -1;   
   if (search.path[search.pivot - 1] -> mleftptr == search.path[search.pivot])
   {
      search.path[search.pivot - 1] -> mleftptr = search.path[search.pivot + 1]; 
   } else if (search.path[search.pivot - 1] -> mrightptr == search.path[search.pivot])
   {
      search.path[search.pivot - 1] -> mrightptr = search.path[search.pivot + 1]; 
   } else {
      mroot = search.path[search.pivot + 1];
   }
   search.path[search.pivot] -> mleftptr = search.path[search.pivot + 1] -> mrightptr;
   search.path[search.pivot + 1] -> mrightptr = search.path[search.pivot];  
}

//@does a double rotate. Changes the orientation of the tree from pivot point
//@down
//@pre: tree exists, tree exists, search exists and contains the path taken by insert function
//@post: tree is rotated so that tree is balanced
//@param search
//@usage: DoDoubleRotateLeftRight();
void cavltree::DoDoubleRotateLeftRight(SearchPath& search)
{
   if (search.path[search.pivot + 2] -> mleftptr == search.path[search.pivot + 3])
   {
      search.path[search.pivot] -> mbalance = 1;
   } else {
      search.path[search.pivot + 1] -> mbalance = -1;
      search.path[search.pivot] -> mbalance = 0;
   }
   ChangesBalances(search, search.pivot + 3);
   if (search.path[search.pivot - 1] -> mleftptr == search.path[search.pivot])
   {
      search.path[search.pivot - 1] -> mleftptr = search.path[search.pivot + 2]; 
   } else if (search.path[search.pivot - 1] -> mrightptr == search.path[search.pivot])
   {
      search.path[search.pivot - 1] -> mrightptr = search.path[search.pivot + 2]; 
   } else {
      mroot = search.path[search.pivot + 2];
   }
   search.path[search.pivot] -> mleftptr = search.path[search.pivot + 2] -> mrightptr;
   search.path[search.pivot + 1] -> mrightptr = search.path[search.pivot + 2] -> mleftptr;
   search.path[search.pivot + 2] -> mleftptr = search.path[search.pivot + 1];
   search.path[search.pivot + 2] -> mrightptr = search.path[search.pivot];
   
}

//@does a double rotate. Changes orientation of the tree from pivot point 
//@down. Opposite direction of DoDoubleRotateLeftRight()
//@pre: tree exists, tree exists, search exists and contains the path taken by insert function
//@post: tree is rotated such that the tree is balanced
//@param search
//@usage DoDoubleRotateLeft();
void cavltree::DoDoubleRotateRightLeft (SearchPath& search)
{
   if (search.path[search.pivot + 2] -> mleftptr == search.path[search.pivot + 3])
   {
      search.path[search.pivot] -> mbalance = 0;
      search.path[search.pivot + 1] -> mbalance = 1;
   } else {
      search.path[search.pivot] -> mbalance = -1;
      search.path[search.pivot + 1] -> mbalance = 0;
   }
   ChangesBalances(search, search.pivot + 3);    
   
   if (search.path[search.pivot - 1] -> mleftptr == search.path[search.pivot])
   {
      search.path[search.pivot - 1] -> mleftptr = search.path[search.pivot + 2]; 
   } else if (search.path[search.pivot - 1] -> mrightptr == search.path[search.pivot])
   {
      search.path[search.pivot - 1] -> mrightptr = search.path[search.pivot + 2]; 
   } else {
      mroot = search.path[search.pivot + 2];
   }
   search.path[search.pivot] -> mrightptr = search.path[search.pivot + 2] -> mleftptr;
   search.path[search.pivot + 1] -> mleftptr = search.path[search.pivot + 2] -> mrightptr;
   search.path[search.pivot + 2] -> mrightptr = search.path[search.pivot + 1];
   search.path[search.pivot + 2] -> mleftptr = search.path[search.pivot];  
}
