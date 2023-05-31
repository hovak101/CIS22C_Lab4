#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include "BSTNode.h"
#include "Currency.h"
#include "Krone.h"
#include "Queue.h"

class BST 
{
private:
	BSTNode* root;
	int count;

public:
	BST() { root = nullptr; count = 0; }

	void insertNode(Currency* insertee);
	bool deleteNode(Currency* removee);
	BSTNode* search(Currency* searchee) const;
	int getCount() const { return count; }
	bool isEmpty() const { return count == 0; }
	std::string printBreadthFirst() const;
	std::string printInOrder() const;
	std::string printPreOrder() const;
	std::string printPostOrder() const;
};
#endif
