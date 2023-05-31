/*
* Added isEmpty function for BST traversal.
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include "SinglyLinkedList.h"

class Queue : private SinglyLinkedList
{
public:
    /*
    * pre:
    * post: adds Currency object to the back of the queue
    * return:
    */
    void enqueue(Currency* obj) { addCurrency(obj, countCurrency()); }

    /*
    * pre: count > 0
    * post: removes Currency object from the front of the queue, throws
    * exception if queue is empty
    * return: pointer to a copy of the Currency object that was removed.
    */
    Currency* dequeue() { return removeCurrency(0); }

    /*
    * pre:
    * post:
    * return: pointer to a copy of the Currency at the front of the
    * queue
    */
    Currency* peekFront() { return getStart(); }

    /*
    * pre:
    * post:
    * return: pointer to a copy of the Currency at the back of the
    * queue
    */
    Currency* peekRear() { return getEnd(); }

    /*
    * pre:
    * post:
    * return: string of contents of the queue, from the front to back.
    */
    std::string printQueue() { return printList(); }
    
    bool isEmpty() { return isListEmpty(); }
};

#endif
