//=========================================================================================================
// Program:		Binary Trees
// Author:		Holly Eaton
// Description:	Program that provides practice working with binary search trees.
//=========================================================================================================

#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include "Node.h"

class BTree
{
private:
	Node* root;
	void deleteTree(Node* myNode);
	void copyTree(Node* &copiedTreeRoot, Node* otherTreeRoot);
	void inorder(Node *p, int depth, void (*funcToCall)(string, int));
	void preorder(Node *p, int depth, void (*funcToCall)(string, int));
	void postorder(Node *p, int depth, void (*funcToCall)(string, int));
	void destroy(Node* &p);
	void deleteFromTree(Node* &p);
	
public:
	BTree();
	BTree(BTree& otherTree);
	~BTree();
	bool insert(string myData);
	bool isEmpty();
	void inorderTransversal(void (*funcToCall)(string, int));
	void preorderTransversal(void (*funcToCall)(string, int));
	void postorderTransversal(void (*funcToCall)(string, int));
	void destroyTree();
	void deleteNode(const string& deleteItem);	
};

#endif