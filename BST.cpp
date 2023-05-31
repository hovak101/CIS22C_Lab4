#include "BST.h"

bool BST::insertNode(Currency* insertee) {
	BSTNode* newNode = new BSTNode();
	newNode->data = new Krone(*insertee);

	if (count == 0) {
		root = newNode;
		return true;
	}

	BSTNode* curr = root;

	while (curr) {
		if (curr->data->isEqual(insertee)) {
			return false;
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
	return true;
}

bool BST::deleteNode(Currency* removee) {
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
				delete succ;
				if (prevSucc->left == succ) {
					prevSucc->left = nullptr;
				}
				else {
					prevSucc->right = nullptr;
				}
			}
			count--;
			return true;
		}

		par = curr;
		if (curr->data->isGreater(removee)) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}

	return false;
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
