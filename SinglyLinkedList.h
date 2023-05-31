#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include <string>
#include "LinkNode.h"
#include "Currency.h"
#include "Krone.h"

class SinglyLinkedList
{
private:
	int count;
	LinkNode* start;
	LinkNode* end;

public:
	// Constructer and Destructer
	SinglyLinkedList();
	~SinglyLinkedList();

	// Getters
	/*
	* pre: getCurrency: index >= 0 and index < count
	* post: getCurrency: exception if the index is out of range
	* return: returns a pointer to a copy of the Currency at the start or end
	* of the linked list.
	*  returns the count of Currency objects in the list.
	*  getCurrency: returns currency object at the specified index
	*/
	Currency* getStart() const { return new Krone(*(start->data)); }
	Currency* getEnd() const { return new Krone(*(end->data)); }
	int countCurrency() const { return count; }
	Currency* getCurrency(int index) const;
	int findCurrency(Currency* findee) const;

	// Moderaters
	void addCurrency(Currency* addee, int index);
	Currency* removeCurrency(Currency* removee);
	Currency* removeCurrency(int index);

	// Other functions
	std::string printList() const;
	bool isListEmpty() const { return count == 0; }
};

#endif


