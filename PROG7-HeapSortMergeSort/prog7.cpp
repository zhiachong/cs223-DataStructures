//@author Zhia Chong
//@date 4/10/2011
//@file prog7.cpp
//@description this is a visualization program for MergeSort
//@             and HeapSort. The purpose is to educate about the
//@            working sequence of the two sorting algorithms.

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "cnode.h"
#include "ckey.h"
#include "cheap.h"
using namespace std; 


const char RED[] = "\033[22;31m"; //sets the output to red
const char RESET[] = "\033[0m"; //resets to white color

const int MAXSIZE = 6;
int mergeline;

//prints out the array for mergesort 
//@pre thelist, first and last are assigned
//@post prints out a graphical representation of the mergesort's array
//@param thelist
//@param first
//@param last
void PrintArray(const Citem thelist[], int first, int last);

//@prints the introduction for Mergesort
//@post a beautiful introduction with header is printed on screen
void PrintIntro();

//prints the mergesort sequence and increments mergeline
//@post prints the mergesort sequence on screen
//@usage PrintList();
void PrintList();

//@prints the actual merge sequence
//@param num
//@usage PrintMerge(0);
void PrintMerge(int num);

//@prints a number of new lines
//@pre num is assigned a positive number
//@post outputs num new lines
//@param num is the number of new lines to output
//@usage PrintLines(2);
void PrintLines(int line);

//@MergeSort sorts an array
//@pre list exists, begin and end are assigned
//@post recursively sortes the list
//@param list
//@param begin
//@param end
//@usage MergeSort(list, begin, end);
void MergeSort(Citem list[], int begin, int end);

//@merges two separate sublists together
//@pre list exists, first, mid and last are assigned
//@post merges two sublists together in order
//@param list
//@param first
//@param mid
//@param last
//@usage Merge(list, first, mid, last);
void Merge(Citem list[], int first, int mid, int last);

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue();

//@prints a number of new lines
//@pre num is assigned a positive number
//@post outputs num new lines
//@param num is the number of new lines to output
//@param outfile
//@usage PrintLines(2, outfile);
void PrintLines(int num);

//@opens an external file for reading
//@post if the external file fileName exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning else an exception
//@     is thrown
//@param infile
//@usage OpenInputFile(infile);
void OpenInputFile(ifstream& infile) throw (cexception);

//@this function reads items from a file and inserts it
//@into a tree 
//@pre infile is open, and tree are assigned
//@post inputs data from file into tree
//@param infile
//@param item
//@usage GetInputFromFile(infile, item);
void GetInputFromFile(ifstream& infile, Citem& item);

//@prints a number of new spaces
//@pre num is assigned a positive number
//@post outputs num new lines
//@param num is the number of new lines to output
//@usage PrintSpace(2, outfile);
void PrintSpace(int num);

//@this function closes the textfile
//@post textfile is closed
//@param infile
//@usage CloseInputFile(infile);
void CloseInputFile(ifstream& infile);

//Retrives the user's choice and processes it accordingly
//usage DoOption();
void DoOption();

//@initializes parameters used for MergeSort
void StartProgram();

//@prints out headers and starts MergeSort
void MergeSortStart();

//@prints out headers and starts HeapSort
void HeapSortStart();

int main()
{
   StartProgram();
   return 0;
}

//@prints out headers and starts HeapSort
void HeapSortStart()
{
   cout << "* " << RED << "RED" << RESET << " denotes the integer is sorted";
   PrintLines(2);
   ifstream infile;
   OpenInputFile(infile);
   Citem key;
   Citem list[7];
   Cheap heap;
   for (int i = 0; i < 7; i++)
   {
      GetInputFromFile(infile, key);
      list[i] = key;
      heap.Insert(key);
   }
   CloseInputFile(infile);
   char ch;
   cin.get(ch);
   
   cout << "The max. heap looks like this: " << endl;
   heap.PrintHeap(9);
   heap.PrintTree();
   PrintLines(1);
   ToContinue();
   
   PrintLines(1);
   heap.HeapSort();
   ToContinue();
}

//@prints the actual merge sequence
//@param line
//@usage PrintMerge(0);
void PrintMerge(int line)
{
   string display [12];
   display [0] = "|5|66|1|85|54";
   display [1] = "|5|66|1|";
   display [2] = "|85|54|";
   display [3] = "|5|66|";
   display [4] = "|1|";
   display [5] = "|85|";
   display [6] = "|54|";
   display [7] = "|5|";
   display [8] = "|66|";
   display [9] = "|1|5|66|";
   display [10] = "|1|5|54|66|85|";
   display [11] = "|54|85|";
	
   switch (line) 
   {
      case 0:
         PrintSpace(7);
	 cout << RED << display[0] << RESET << endl;
	 PrintSpace(3);
	 cout << display[1];
	 PrintSpace(5);
	 cout << display[2] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(3);
	 cout << display [4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	  	
	 cout << display [7];
	 PrintSpace(3);
	 cout << display [8];
	 PrintSpace(3);
	 cout << display[4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(5);
	 cout << display [4];
	 PrintSpace(5);
	 cout << display [11] << endl;
	 PrintSpace(5);
	 cout << display [9];
	 PrintSpace(7);
	 cout << display [11] << endl;
	 PrintSpace(7);
	 cout << display[10] << endl;
	 break;
      case 1: 
	 PrintSpace(7);
	 cout <<  display[0] << endl;
	 PrintSpace(3);
	 cout << RED << display[1] << RESET;
	 PrintSpace(5);
	 cout << display[2] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(3);
	 cout << display [4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 
	 cout << display [7];
	 PrintSpace(3);
	 cout << display [8];
	 PrintSpace(3);
	 cout << display[4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(5);
	 cout << display [4];
	 PrintSpace(5);
	 cout << display [11] << endl;
	 PrintSpace(5);
	 cout << display [9];
	 PrintSpace(7);
	 cout << display [11] << endl;
	 PrintSpace(7);
	 cout << display[10] << endl;
	 break;
      case 2:
	 PrintSpace(7);
         cout <<  display[0] << endl;
	 PrintSpace(3);
	 cout  << display[1];
	 PrintSpace(5);
	 cout <<  display[2] << endl;
	 PrintSpace(1);
	 cout << RED << display [3] << RESET;
	 PrintSpace(3);
	 cout << display [4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 
	 cout << display [7];
	 PrintSpace(3);
	 cout << display [8];
	 PrintSpace(3);
	 cout << display[4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(5);
	 cout << display [4];
	 PrintSpace(5);
	 cout << display [11] << endl;
	 PrintSpace(5);
	 cout << display [9];
	 PrintSpace(7);
	 cout << display [11] << endl;
	 PrintSpace(7);
	 cout << display[10] << endl;
	 break;
      case 3:
         PrintSpace(7);
	 cout <<  display[0] << endl;
	 PrintSpace(3);
	 cout  << display[1];
	 PrintSpace(5);
	 cout <<  display[2] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(3);
	 cout << display [4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 cout << RED << display [7] << RESET;
	 PrintSpace(3);
	 cout << display [8];
	 PrintSpace(3);
	 cout << display[4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(5);
	 cout << display [4];
	 PrintSpace(5);
	 cout << display [11] << endl;
	 PrintSpace(5);
	 cout << display [9];
	 PrintSpace(7);
	 cout << display [11] << endl;
	 PrintSpace(7);
	 cout << display[10] << endl;
	 break;
      case 4:
         PrintSpace(7);
	 cout <<  display[0] << endl;
	 PrintSpace(3);
	 cout  << display[1];
	 PrintSpace(5);
	 cout <<  display[2] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(3);
	 cout << display [4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 
	 cout << display [7];
	 PrintSpace(3);
	 cout << RED << display [8] << RESET;
	 PrintSpace(3);
	 cout << display[4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(5);
	 cout << display [4];
	 PrintSpace(5);
	 cout << display [11] << endl;
	 PrintSpace(5);
	 cout << display [9];
	 PrintSpace(7);
	 cout << display [11] << endl;
	 PrintSpace(7);
	 cout << display[10] << endl;
	 break;
         
      case 5:
         PrintSpace(7);
	 cout <<  display[0] << endl;
	 PrintSpace(3);
	 cout  << display[1];
	 PrintSpace(5);
	 cout <<  display[2] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(3);
	 cout << RED << display [4] << RESET;
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 
	 cout << display [7];
	 PrintSpace(3);
	 cout << display [8];
	 PrintSpace(3);
	 cout << display[4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(5);
	 cout << display [4];
	 PrintSpace(5);
	 cout << display [11] << endl;
	 PrintSpace(5);
	 cout << display [9];
	 PrintSpace(7);
	 cout << display [11] << endl;
	 PrintSpace(7);
	 cout << display[10] << endl;
	 break;
         
      case 6:
         PrintSpace(7);
	 cout <<  display[0] << endl;
	 PrintSpace(3);
	 cout  << display[1];
	 PrintSpace(5);
	 cout <<  RED << display[2] << RESET << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(3);
	 cout <<  display [4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 
	 cout << display [7];
	 PrintSpace(3);
	 cout << display [8] ;
	 PrintSpace(3);
	 cout << display[4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(5);
	 cout << display [4];
	 PrintSpace(5);
	 cout << display [11] << endl;
	 PrintSpace(5);
	 cout << display [9];
	 PrintSpace(7);
	 cout << display [11] << endl;
	 PrintSpace(7);
	 cout << display[10] << endl;
	 break;
      case 7:
         PrintSpace(7);
	 cout <<  display[0] << endl;
	 PrintSpace(3);
	 cout  << display[1];
	 PrintSpace(5);
	 cout <<  display[2] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(3);
	 cout <<  display [4];
	 PrintSpace(5);
	 cout << RED << display [5] << RESET;
	 PrintSpace(3);
	 cout << display [6] << endl;
	 
	 cout << display [7];
	 PrintSpace(3);
	 cout << display [8] ;
	 PrintSpace(3);
	 cout << display[4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(5);
	 cout << display [4];
	 PrintSpace(5);
	 cout << display [11] << endl;
	 PrintSpace(5);
	 cout << display [9];
	 PrintSpace(7);
	 cout << display [11] << endl;
	 PrintSpace(7);
	 cout << display[10] << endl;
	 break;
         
      case 8:
         PrintSpace(7);
	 cout <<  display[0] << endl;
	 PrintSpace(3);
	 cout  << display[1];
	 PrintSpace(5);
	 cout <<  display[2] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(3);
	 cout <<  display [4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << RED << display [6] << RESET << endl;
	 
	 cout << display [7];
	 PrintSpace(3);
	 cout << display [8] ;
	 PrintSpace(3);
	 cout << display[4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(5);
	 cout << display [4];
	 PrintSpace(5);
	 cout << display [11] << endl;
	 PrintSpace(5);
	 cout << display [9];
	 PrintSpace(7);
	 cout << display [11] << endl;
	 PrintSpace(7);
	 cout << display[10] << endl;
	 break;
         
         
      case 9:
         PrintSpace(7);
	 cout <<  display[0] << endl;
	 PrintSpace(3);
	 cout  << display[1];
	 PrintSpace(5);
	 cout <<  display[2] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(3);
	 cout <<  display [4];
	 PrintSpace(5);
	 cout << RED << display [5] << RESET;
	 PrintSpace(3);
	 cout << display [6] << endl;
	 
	 cout << display [7];
	 PrintSpace(3);
	 cout << display [8] ;
	 PrintSpace(3);
	 cout << display[4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(5);
	 cout << display [4];
	 PrintSpace(5);
	 cout << display [11] << endl;
	 PrintSpace(5);
	 cout << display [9];
	 PrintSpace(7);
	 cout << display [11] << endl;
	 PrintSpace(7);
	 cout << display[10] << endl;
	 break;
      case 10:
         PrintSpace(7);
	 cout <<  display[0] << endl;
	 PrintSpace(3);
	 cout  << display[1];
	 PrintSpace(5);
	 cout <<  display[2] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(3);
	 cout <<  display [4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << RED << display [6] << RESET << endl;
	 
	 cout << display [7];
	 PrintSpace(3);
	 cout << display [8] ;
	 PrintSpace(3);
	 cout << display[4];
	 PrintSpace(5);
	 cout << display [5];
	 PrintSpace(3);
	 cout << display [6] << endl;
	 PrintSpace(1);
	 cout << display [3];
	 PrintSpace(5);
	 cout << display [4];
	 PrintSpace(5);
	 cout << display [2] << endl;
	 PrintSpace(5);
	 cout << display [9];
	 PrintSpace(7);
	 cout << display [2] << endl;
	 PrintSpace(7);
	 cout << display[10] << endl;
	 break;
      default:
	 break;
	}
}	
//prints out the array for mergesort 
//@pre thelist, first and last are assigned
//@post prints out a graphical representation of the mergesort's array
//@param thelist
//@param first
//@param last
void PrintArray(const Citem thelist[], int first, int last)
{
   cout << "| ";
   while (first <= last)
   {
      cout << thelist[first] << " | ";
      first++;
   }
	
}

//@prints out headers and starts MergeSort
void MergeSortStart()
{
   mergeline = 0;
   PrintIntro();
   Citem mList[MAXSIZE];
   Citem copy[MAXSIZE];
   Citem key;
   ifstream infile;
   OpenInputFile(infile);
   for (int i = 0; i < 5; i++)
   {
      GetInputFromFile(infile, key);
      mList[i] = key;
   }
   CloseInputFile(infile);
   for (int Z = 0; Z < 5; Z++)
   {
      copy [Z] = mList[Z];
   }
   PrintLines(2);
   PrintSpace(15);
   cout << "----------------------------------" << endl;
   PrintSpace(15);
   cout << "----Demonstrating A MergeSort-----" << endl;
   PrintSpace(15);
   cout << "----------------------------------" << endl;
   PrintLines(1);
	
   cout << "This is an unsorted array of size 6 : " << endl;
   PrintList();
   PrintLines(2);
   ToContinue();
   PrintSpace(15);
   cout << "--------------------------------" << endl;
   PrintSpace(15);
   cout << "----Starting Merge sort---------" << endl;
   PrintSpace(15);
   cout << "--------------------------------" << endl;

	
   PrintLines(2);   
   mergeline = 1;
   MergeSort(mList, 0, 4);
   PrintLines(1);
}

//prints the mergesort sequence and increments mergeline
//@post prints the mergesort sequence on screen
//@usage PrintList();
void PrintList()
{
   PrintLines(2);
   PrintMerge(mergeline);
   mergeline++;
	
}

//@prints the introduction for Mergesort
//@post a beautiful introduction with header is printed on screen
void PrintIntro()
{
   char ch;
   PrintLines(2); 
   PrintSpace(15);
   cout << "------------------------------------------" << endl;
   PrintSpace(15);
   cout << "--Welcome To The MergeSort Demonstration--" << endl;
   PrintSpace(15);
   cout << "------------------------------------------" << endl;
	
   cout << "Introduction: " << endl;
   cout << "Merge sort is an O(n log n) comparison-based sorting algorithm." << endl;
   cout << "Conceptually, a merge sort works by diving an unsorted list into" << endl;
   cout << "two sublists of about half the size of original list, then sorts" << endl;
   cout << "each sublist recursively. Finally, the two sublists are merged back " << endl;
   cout << "into one sorted list." << endl;
	
   PrintLines(2);
   cin.get(ch);
   ToContinue();
}

//@prints a number of new spaces
//@pre num is assigned a positive number
//@post outputs num new lines
//@param num is the number of new lines to output
//@usage PrintSpace(2, outfile);
void PrintSpace(int num)
{
   for (int i = 0; i < num; i++)
   {
      cout << " ";
   }
}

//@MergeSort sorts an array
//@pre list exists, begin and end are assigned
//@post recursively sortes the list
//@param list
//@param begin
//@param end
//@usage MergeSort(list, begin, end);
void MergeSort(Citem list[], int begin, int end)
{
   if (begin < end)
   {
      cout << "-----------------------------------------------" << 
endl;
      PrintLines(1);
      int middle = (begin + end) / 2;
      cout << "array[Mid]: " << list[middle] << endl;
      cout << "Sorting left sublist" << endl;
      PrintList();
      
      PrintSpace(4);
      PrintLines(1);
      
      
      ToContinue();
      MergeSort(list, begin, middle);
      
      
      PrintLines(1);
      cout << "array[Mid + 1]: " << list[middle + 1] << endl;
      cout << "Sorting right sublist" << endl;
      PrintSpace(4);
      
      PrintList();
      
      PrintLines(1);
      ToContinue();
      MergeSort(list, middle+1, end);
      
      PrintLines(1);
      cout << "-----------------------------------------------" << endl;
      PrintSpace(6);
      cout << "**Merging left and right sublists**";
      PrintLines(1);
      Merge(list, begin, middle, end);
      PrintLines(2);
      cout << "The sorted array: " << endl;
      PrintArray(list, begin, end);
      PrintLines(1);
      cout << "-----------------------------------------------" << endl;
      ToContinue();
   } 
}

//@merges two separate sublists together
//@pre list exists, first, mid and last are assigned
//@post merges two sublists together in order
//@param list
//@param first
//@param mid
//@param last
//@usage Merge(list, first, mid, last);
void Merge(Citem list[], int first, int mid, int last)
{
   PrintSpace(4);
   PrintLines(2);
   PrintSpace(5);
   cout << "-----Initializing temporary array-----" << endl << endl;
   Citem tempArray [MAXSIZE];
   int first1 = first;
   int last1 = mid;
   int first2 = mid + 1;
   int last2 = last;
   int index = first1;
  
   //determine which of the 2 arrays is smallest
   for(; (first1 <= last1) && (first2 <= last2); ++index)
   {
      if (list[first1] < list[first2])
      {
         tempArray[index] = list[first1];
	 cout << "Inserting -> " << list[first1] << " into temporary array" << endl;
	++first1;
       } else {
 		tempArray[index] = list[first2];
           	cout << "Inserting -> " << list[first2] << " into temporary array" << endl;
		first2++;
	}
	cout << "The temporary array: " << endl;
	PrintArray(tempArray, first, last);
	PrintLines(2);
    }
	//if any remains, place into the temp aray
   for (; first1 <= last1; ++ first1, ++index)
   {
      tempArray[index] = list[first1];
      cout << "Inserting -> " << list[first1] << " into temporary array" << endl;
      cout << "The temporary array: " << endl;
      PrintArray(tempArray, first, last);
      PrintLines(2);
   }
	
	//if any remains, place into the temp array
   for(; first2 <= last2; ++first2, ++ index)
   {
      tempArray[index] = list[first2];
      cout << "Inserting -> " << list[first2] << " into temporary array" << endl;
      cout << "The temporary array: " << endl;
      PrintArray(tempArray, first, last);
      PrintLines(2);
   }
	
   cout << "--------------------------------------------" << endl;
   cout << "Copying from temporary array to actual array" << endl;
   cout << "--------------------------------------------" << endl;
	
   for (index = first; index <= last; ++index)
      list[index] = tempArray[index];
}

//Prints out a menu that allows users to choose their options
//usage ScreenMenu();
void ScreenMenu()
{
   PrintLines(2);
   cout << "********************************|Menu|***********************************" << endl;
   cout << "Your options: " << endl;
   cout << "   d) Show visualization of MergeSort" << endl;
   cout << "   f) Show visualization of HeapSort" << endl;
   cout << "   x) exit the program" << endl;
   cout << "*************************************************************************" << endl;
}

//Retrives the user's choice and processes it accordingly
//usage DoOption();
void DoOption()
{
   char choice = 'a';
   bool ok = true;
   while (ok)
   {
      ScreenMenu();
      cout << "Enter option -> ";
      cin.get(choice);
      PrintLines(2);
      if (choice == 'd')
      {
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
         cout << "Option d - Show MergeSort" << endl;
         MergeSortStart();
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
      } else if (choice == 'f')
      {
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
         cout << "Option f - Show HeapSort";
         PrintLines(2);
         char ch;
         PrintLines(2); 
         PrintSpace(15);
         cout << "------------------------------------------" << endl;
         PrintSpace(15);
         cout << "--Welcome To The HeapSort Demonstration--" << endl;
         PrintSpace(15);
         cout << "------------------------------------------" << endl;
         PrintLines(2);
         HeapSortStart();
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
      }  else if (choice == 'x')
      {
         ok = false;
      } 
   }
}

//initializes the parameters needed for the 
void StartProgram() 
{  	
   DoOption();
}

//@prints a number of new lines
//@pre num is assigned a positive number
//@post outputs num new lines
//@param num is the number of new lines to output
//@param outfile
//@usage PrintLines(2, outfile);
void PrintLines(int num)
{
   for (int i = 0; i < num; i++)
   {
      cout << endl;
   }
}

//@opens an external file for reading
//@post if the external file fileName exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning else an exception
//@     is thrown
//@param infile
//@usage OpenInputFile(infile);
void OpenInputFile(ifstream& infile) throw (cexception)
{
   try {
      infile.open("in7.dat");
	} 
   catch (cexception de)
   {
      cout << de.what() << endl;
   }
}



//@this function reads items from a file and inserts it
//@into a tree 
//@pre infile is open, and tree are assigned
//@post inputs data from file into tree
//@param infile
//@param item
//@usage GetInputFromFile(infile, item);
void GetInputFromFile(ifstream& infile, Citem& item)
{
   infile >> item;
}


//@this function closes the textfile
//@post textfile is closed
//@param infile
//@usage CloseInputFile(infile);
void CloseInputFile(ifstream& infile)
{
   infile.close();
}

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue()
{
   char ch;
   PrintLines(2);
   cout << "                     Hit <Enter> to continue -> ";
   cin.get(ch);
}