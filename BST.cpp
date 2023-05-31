#include "BST.h"

void BST::insertNode(Currency* insertee) {
	BSTNode* newNode = new BSTNode();
	newNode->data = new Krone(*insertee);

	if (count == 0) {
		root = newNode;
		count++;
	}
	else {

		BSTNode* curr = root;

		while (curr) {
			if (curr->data->isEqual(insertee)) {
				throw "Cannot insert duplicate node.";
			}

			if (curr->data->isGreater(insertee)) {
				if (curr->left) {
					curr = curr->left;
				}
				else {
					curr->left = newNode;
					curr = nullptr;
				}
			}
			else {
				if (curr->right) {
					curr = curr->right;
				}
				else {
					curr->right = newNode;
					curr = nullptr;
				}
			}
		}

		count++;
	}
}

void BST::deleteNode(Currency* removee) {
	BSTNode* curr = root;
	BSTNode* par = nullptr;

	while (curr) {
		if (curr->data->isEqual(removee)) {
			// remove node
			if (curr->left == nullptr) {
				if (par == nullptr) {
					root = curr->right;
				}
				else if (par->right == curr){
					par->right = curr->right;
				}
				else {
					par->left = curr->right;
				}
				delete curr;
			}
			else if (curr->right == nullptr) {
				if (par == nullptr) {
					root = curr->left;
				}
				else if (par->right == curr) {
					par->right = curr->left;
				}
				else {
					par->left = curr->left;
				}
				delete curr;
			}
			else {
				// find successor
				BSTNode* prevSucc = curr;
				BSTNode* succ = curr->right;
				while (succ->left) {
					prevSucc = succ;
					succ = succ->left;
				}

				// swap succesor data with current data
				delete curr->data;
				curr->data = new Krone(*succ->data);

				if (prevSucc->left == succ) {
					prevSucc->left = succ->right;
				}
				else {
					prevSucc->right = succ->right;
				}

				delete succ;
			}

			count--;
			return;
		}

		par = curr;
		if (curr->data->isGreater(removee)) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}

	throw "Cannot remove a node that doesn't exist.";
}

BSTNode* BST::search(Currency* searchee) const {
	BSTNode* curr = root;

	while (curr) {
		if (curr->data->isEqual(searchee)) {
			return curr;
		}
		else if (curr->data->isGreater(searchee)) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}

	return nullptr;
}

std::string BST::printBreadthFirst() const {
	std::string output = "";

	if (root == nullptr) {
		return output;
	}

	Queue nodeQueue;
	BSTNode* currNode = nullptr;
	Currency* currData = nullptr;
	nodeQueue.enqueue(root->data);
	
	while (!nodeQueue.isEmpty()) {
		currData = nodeQueue.dequeue();
		currNode = search(currData);
		output += currNode->data->toString();
		output += " ";
		if (currNode->left) {
			nodeQueue.enqueue(currNode->left->data);
		}
		if (currNode->right) {
			nodeQueue.enqueue(currNode->right->data);
		}

		delete currData;
	}

	return output;	
}

std::string BST::printInOrderRecur(BSTNode* curr) const {
	if (curr == nullptr) {
		return "";
	}
	
	return printInOrderRecur(curr->left) + curr->data->toString() + " " +
		printInOrderRecur(curr->right);
}

std::string BST::printPreOrderRecur(BSTNode* curr) const {
	if (curr == nullptr) {
		return "";
	}

	return curr->data->toString() + " " + printPreOrderRecur(curr->left) +
		printPreOrderRecur(curr->right);
}

std::string BST::printPostOrderRecur(BSTNode* curr) const {
	if (curr == nullptr) {
		return "";
	}

	return printPostOrderRecur(curr->left) + printPostOrderRecur(curr->right) + 
		curr->data->toString() + " ";
}

BST::~BST() {
	while (count != 0) {
		deleteNode(root->data);
	}
}