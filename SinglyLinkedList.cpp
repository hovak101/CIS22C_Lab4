#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() {
	count = 0;
	start = nullptr;
	end = nullptr;
}

SinglyLinkedList::~SinglyLinkedList() {
	while (count) {
		removeCurrency(0);
	}
}

/*
* pre: index >=0 and index <= count
* post: Currency object is added at the specified index in the list.
* Exception thrown if index is out of the range.
* return:
*/
void SinglyLinkedList::addCurrency(Currency* addee, int index) {
	if (index < 0 || index > count) {
		throw "Invalid index.";
	}

	// create new node.
	LinkNode* newNode = new LinkNode;
	newNode->data = new Krone(*addee);

	// special case for start.
	if (count == 0) {
		start = newNode;
		end = newNode;
	}
	else {
		// traverse list to find node before index location.
		LinkNode* curr = start;
		LinkNode* nextNode = nullptr;

		if (index == 0) {
			start = newNode;
			start->next = curr;
		}
		else {
			for (int i = 0; i < index - 1; i++) {
				curr = curr->next;
			}
			nextNode = curr->next;

			// insert node after curr.
			curr->next = newNode;
			newNode->next = nextNode;

			if (index == count) {
				end = newNode;
			}
		}
	}

	count++;
}

/*
* pre: count > 0, removee-valued Currency object must exist in the list.
* post: removes specified Currency object from the list. Exception thrown if
* the list is empty or if specified Currency object is not found.
* return: returns a pointer to a copy of the removed Currency object
*/
Currency* SinglyLinkedList::removeCurrency(Currency* removee) {
	if (count == 0) {
		throw "Cannot remove from empty list.";
	}

	LinkNode* curr = start;
	LinkNode* nextNode = nullptr;

	// special case for start.
	if (start->data->isEqual(removee)) {
		start = start->next;
		Currency* ret = new Krone(*(curr->data));
		delete curr;

		count--;
		if (count == 0) {
			end = nullptr;
		}
		return ret;
	}

	// traverse array to find node before removee-valued node.
	while (curr->next) {
		if (curr->next->data->isEqual(removee)) {
			nextNode = curr->next;

			// remove nextNode
			curr->next = nextNode->next;
			if (nextNode == end) {
				end = curr;
			}
			Currency* ret = new Krone(*(nextNode->data));
			delete nextNode;

			count--;
			return ret;
		}

		curr = curr->next;
	}

	throw "Could not find node with specified currency.";
}

/*
* pre: index >= 0 and index < count
* post: removes the Currency object at that index. Exception thrown if the
* index is out of range.
* return: returns a pointer to a copy of the removed Currency object.
*/
Currency* SinglyLinkedList::removeCurrency(int index) {
	if (index < 0 || index >= count) {
		throw "Invalid index.";
	}

	LinkNode* curr = start;
	LinkNode* nextNode = nullptr;

	if (index == 0) {
		start = start->next;
		Currency* ret = new Krone(*(curr->data));
		delete curr;

		count--;
		if (count == 0) {
			end = nullptr;
		}
		return ret;
	}

	for (int i = 0; i < index - 1; i++) {
		curr = curr->next;
	}

	nextNode = curr->next;
	curr->next = nextNode->next;
	nextNode->next = nullptr;

	Currency* ret = new Krone(*(nextNode->data));
	delete nextNode;

	count--;
	return ret;
}

/*
* pre:
* post:
* return: returns index of the first occurrence of the specified Currency
* object, returns -1 if the Currency object is not found in the list.
*/
int SinglyLinkedList::findCurrency(Currency* findee) const {
	int index = 0;
	LinkNode* curr = start;

	while (curr) {
		if (curr->data->isEqual(findee)) {
			return index;
		}

		curr = curr->next;
		index++;
	}

	return -1;
}

Currency* SinglyLinkedList::getCurrency(int index) const {
	if (index < 0 || index >= count) {
		throw "Invalid index.";
	}

	LinkNode* curr = start;

	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}

	return curr->data;
}

/*
* pre:
* post:
* return: returns a string of all the Currency objects in the list in the order
* of index
*/
std::string SinglyLinkedList::printList() const {
	LinkNode* curr = start;
	std::string ret = "";

	while (curr) {
		ret += curr->data->toString();
		ret += '\t';

		curr = curr->next;
	}

	return ret;
}