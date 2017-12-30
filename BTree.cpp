//=========================================================================================================
// Program:		Binary Trees
// Author:		Holly Eaton
// Description:	Program that provides practice working with binary search trees.
//=========================================================================================================

#include "BTree.h"

//==========================================================================================================
//Default Constructor
//==========================================================================================================
BTree::BTree()
{
	root = NULL;
}

//==========================================================================================================
//Overloaded Default Constructor
//
//Used to make deep copies of the binary tree
//==========================================================================================================
BTree::BTree(BTree& otherTree)
{
	if (otherTree.root == NULL)
		root = NULL;
	else
		copyTree(root, otherTree.root);
}

//==========================================================================================================
//Destructor
//==========================================================================================================
BTree::~BTree()
{
	deleteTree(root);
	root = NULL;
}

//==========================================================================================================
//Name: deleteTree
//
//Description: Deletes a node from the tree
//
//Parameters: (I) myNode - Pointer to the node to be deleted
//
//Return: None
//==========================================================================================================
void BTree::deleteTree(Node* myNode)
{
	if (myNode != NULL)
	{
		deleteTree(myNode->left);
		deleteTree(myNode->right);
		delete myNode;
	}
}

//==========================================================================================================
//Name: copyTree
//
//Description: Makes a deep copy of a binary tree to a new tree
//
//Parameters:	(I/O) copiedTreeRoot - Pointer to the new tree node which is getting a copy of the data
//				(I) otherTreeRoot - Pointer to a node being copied
//
//Return: None
//==========================================================================================================
void BTree::copyTree(Node* &copiedTreeRoot, Node* otherTreeRoot)
{
	if (otherTreeRoot == NULL)
		copiedTreeRoot = NULL;
	else
	{
		copiedTreeRoot = new Node;
		copiedTreeRoot->data = otherTreeRoot->data;
		copyTree(copiedTreeRoot->left, otherTreeRoot->left);
		copyTree(copiedTreeRoot->right, otherTreeRoot->right);
	}
}

//==========================================================================================================
//Name: insert
//
//Description: Add a new string to the binary tree
//
//Parameters: (I) myData - the string being added
//
//Return: True - The name was successfully added
//		  False - The name was not successfully added
//==========================================================================================================
bool BTree::insert(string myData)
{
	Node* newNode;
	newNode = new Node;
	newNode->data = myData;
	newNode->left  = NULL;
	newNode->right = NULL;

	if (root == NULL) //empty tree
	{
		root = newNode;
		return true;
	}
	else
	{
		Node* current = root;
		Node* parent = NULL;
		while (current != NULL)
		{
			parent = current;
			if (newNode->data < current->data)
				current = current->left;
			else if (newNode->data > current->data)
				current = current->right;
			else
			{
				delete newNode;
				return false;
			}
		}
		if (newNode->data < parent->data)
			parent->left = newNode;
		else
			parent->right = newNode;
		return true;
	} //else 
}

//==========================================================================================================
//Name: isEmpty
//
//Description: Checks to see if a tree is empty
//
//Parameters: None
//
//Return: True - The tree is empty
//		  False - The tree is not empty
//==========================================================================================================
bool BTree::isEmpty()
{
	return (root == NULL);
}

//==========================================================================================================
//Name: inorderTransversal
//
//Description: Transverses a binary tree in order
//
//Parameters: (I) funcToCall - Function pointer which requires a string and an int
//
//Return: None
//==========================================================================================================
void BTree::inorderTransversal(void (*funcToCall)(string, int))
{
	inorder(root, 0, funcToCall);
}

//==========================================================================================================
//Name: preorderTransversal
//
//Description: Transverses a binary tree in preorder
//
//Parameters: (I) funcToCall - Function pointer which requires a string and an int
//
//Return: None
//==========================================================================================================
void BTree::preorderTransversal(void (*funcToCall)(string, int))
{
	preorder(root, 0, funcToCall);
}

//==========================================================================================================
//Name: postorderTransversal
//
//Description: Transverses a binary tree in post order
//
//Parameters: (I) funcToCall - Function pointer which requires a string and an int
//
//Return: None
//==========================================================================================================
void BTree::postorderTransversal(void (*funcToCall)(string, int))
{
	postorder(root, 0, funcToCall);
}

//======================================================================================================================
//Name: inorder
//
//Description: Recursively goes through the tree in order and implements the function pointer for the data in each node
//
//Parameters:	(I) p - Pointer to the Node being used
//				(I) depth - The level in the tree of the Node
//				(I) funcToCall - Function pointer which requires a string and an int
//
//Return: None
//=======================================================================================================================
void BTree::inorder(Node *p, int depth, void (*funcToCall)(string, int))
{
	if (p != NULL)
	{
		inorder(p->left, depth+1, funcToCall);
		funcToCall(p->data, depth);
		inorder(p->right, depth+1, funcToCall);
	}
}

//==========================================================================================================================
//Name: preorder
//
//Description: Recursively goes through the tree in preorder and implements the function pointer for the data in each node
//
//Parameters:	(I) p - Pointer to the Node being used
//				(I) depth - The level in the tree of the Node
//				(I) funcToCall - Function pointer which requires a string and an int
//
//Return: None
//==========================================================================================================================
void BTree::preorder(Node *p, int depth, void (*funcToCall)(string, int))
{
	if (p != NULL)
	{
		funcToCall(p->data, depth);
		preorder(p->left, depth+1, funcToCall);
		preorder(p->right, depth+1, funcToCall);
	}
}

//==========================================================================================================================
//Name: postorder
//
//Description: Recursively goes through the tree in postorder and implements the function pointer for the data in each node
//
//Parameters:	(I) p - Pointer to the Node being used
//				(I) depth - The level in the tree of the Node
//				(I) funcToCall - Function pointer which requires a string and an int
//
//Return: None
//==========================================================================================================================
void BTree::postorder(Node *p, int depth, void (*funcToCall)(string, int))
{
	if (p != NULL)
	{
		postorder(p->left, depth+1, funcToCall);
		postorder(p->right, depth+1, funcToCall);
		funcToCall(p->data, depth);
	}
}

//==========================================================================================================
//Name: destroy
//
//Description: Deletes a node
//
//Parameters:  (I) p - Pointer to the Node to be deleted
//
//Return: None
//==========================================================================================================
void BTree::destroy(Node* &p)
{
	if (p != NULL)
	{
		destroy(p->left);
		destroy(p->right);
		delete p;
		p = NULL;
	}
}

//==========================================================================================================
//Name: destroyTree
//
//Description: Deletes the entire tree
//
//Parameters:  None
//
//Return: None
//==========================================================================================================
void BTree::destroyTree()
{
	destroy(root);
}

//==========================================================================================================
//Name: deleteFromTree
//
//Description: Deletes a Node from the tree
//
//Parameters: (I) p - The Node to be deleted
//
//Return: None
//==========================================================================================================
void BTree::deleteFromTree(Node* &p)
{
	Node* current;
	Node* trailCurrent;
	Node* temp;

	if (p == NULL)
		cout << "Error: The node to be deleted is NULL\n";
	else if (p->left == NULL && p->right == NULL)
	{
		temp = p;
		p = NULL;
		delete temp;
	}
	else if (p->left == NULL)
	{
		temp = p;
		p = temp->right;
		delete temp;
	}
	else if (p->right == NULL)
	{
		temp = p;
		p = temp->left;
		delete temp;
	}
	else
	{
		current = p->left;
		trailCurrent = NULL;

		while (current->right != NULL)
		{
			trailCurrent = current;
			current = current->right;
		}

		p->data = current->data;
		if (trailCurrent == NULL)
			p->left = current->left;
		else
			trailCurrent->right = current->left;

		delete current;
	}//end else
}//end deleteTree

//==========================================================================================================
//Name: deleteNode
//
//Description: Locates the string data in the tree which matches the Node to be deleted
//
//Parameters: (I) deleteItem - The data to be deleted
//
//Return: None
//==========================================================================================================
void BTree::deleteNode(const string& deleteItem)
{
	Node *current;
	Node *trailCurrent;
	bool found = false;

	if (root == NULL)
		cout << "Cannot delete from an empty tree\n";
	else
	{
		current = root;
		trailCurrent = root;

		while (current != NULL && !found)
		{
			if (current->data == deleteItem)
				found = true;
			else
			{
				trailCurrent = current;

				if (current->data > deleteItem)
					current = current->left;
				else
					current = current->right;
			}
		}

		if (current == NULL)
			cout << "The item to be deleted is not in the tree\n";
		else if (found)
		{
			if (current == root)
				deleteFromTree(root);
			else if (trailCurrent->data> deleteItem)
				deleteFromTree(trailCurrent->left);
			else
				deleteFromTree(trailCurrent->right);
		}
		else
			cout << "The item to be deleted is not in the tree\n";
	}
} //end deleteNode



