//=========================================================================================================
// Program:		Binary Trees
// Author:		Holly Eaton
// Description:	Program that provides practice working with binary search trees.
//=========================================================================================================

#include "BTree.h"

//function prototypes
void printStringAndLevel(string theName, int depth = 0);
void deleteFromTreeAndReprint(string nameToBeDeleted, BTree& treeToDeleteFrom);

int main()
{
	BTree names;

	names.insert("Kirk");
	names.insert("Chekov");
	names.insert("Sisko");
	names.insert("Chapel");
	names.insert("Data");
	names.insert("Janeway");
	names.insert("Sulu");
	names.insert("Bones");
	names.insert("Q");
	names.insert("Scotty");
	names.insert("Uhuru");
	names.insert("Picard");
	names.insert("Spock");
	names.insert("Worf");

	names.inorderTransversal(printStringAndLevel);
	cout << endl;
	BTree names2(names); //copy tree

	deleteFromTreeAndReprint("Bones", names);
	deleteFromTreeAndReprint("Sisko", names);
	deleteFromTreeAndReprint("Sulu", names);
	deleteFromTreeAndReprint("Kirk", names);

	names.postorderTransversal(printStringAndLevel);
	cout << endl;
	names.preorderTransversal(printStringAndLevel);
	cin.get();
	return 0;
}

//==========================================================================================================
//Name: printStringAndLevel
//
//Description: Prints the data (a string) and it's depth in a binary tree
//
//Parameters: (I) theName - The string to be displayed
//				(I) depth - The level of the data in the binary tree
//
//Return: None
//==========================================================================================================
void printStringAndLevel(string theName, int depth)
{
	cout << theName << " (" << depth << ")\n"; 
}

//==========================================================================================================
//Name: deleteFromTreeAndReprint
//
//Description: Removes a name (string) from a binary tree and calls the print function to show it worked
//
//Parameters: (I) nameToBeDeleted - the string to be removed
//				(I/O) treeToDeleteFrom - the binary tree holding the data
//
//Return: None
//==========================================================================================================
void deleteFromTreeAndReprint(string nameToBeDeleted, BTree& treeToDeleteFrom)
{
	treeToDeleteFrom.deleteNode(nameToBeDeleted);
	cout << "After deleting " << nameToBeDeleted << ": " << endl;
	treeToDeleteFrom.inorderTransversal(printStringAndLevel);
	cout << endl;
}