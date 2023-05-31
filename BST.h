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

	std::string printInOrderRecur(BSTNode* curr) const;
	std::string printPreOrderRecur(BSTNode* curr) const;
	std::string printPostOrderRecur(BSTNode* curr) const;

public:
	BST() { root = nullptr; count = 0; }
	~BST();

	void insertNode(Currency* insertee);
	void deleteNode(Currency* removee);
	BSTNode* search(Currency* searchee) const;
	int getCount() const { return count; }
	bool isEmpty() const { return count == 0; }
	std::string printBreadthFirst() const;
	std::string printInOrder() const { return printInOrderRecur(root); }
	std::string printPreOrder() const { return printPreOrderRecur(root); }
	std::string printPostOrder() const { return printPostOrderRecur(root); }
};
#endif
