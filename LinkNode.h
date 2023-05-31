#ifndef LINKNODE_H
#define LINKNODE_H

#include "Currency.h"

class LinkNode
{
public:
	Currency* data;
	LinkNode* next;

	LinkNode() {
		data = nullptr;
		next = nullptr;
	}

	~LinkNode() { delete data; }
};

#endif