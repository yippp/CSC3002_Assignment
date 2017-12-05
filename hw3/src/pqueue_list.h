/*
 * File: pqueue_list.h
 * --------------------------
 * This is the answer to question 2 of assignmet 3 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 * It is a class of queue wilt priority builded with linked-list
 */

#ifndef PQUEUE_LIST_H
#define PQUEUE_LIST_H

#include "error.h"

template <typename ValueType>
class PriorityQueue {

public:

    PriorityQueue();

    ~PriorityQueue();

    int size();

    bool isEmpty();

    void clear();

    void enqueue(ValueType value, double priority);

    ValueType dequeue(double & priority);

    ValueType peek(double & priority);

    PriorityQueue(const PriorityQueue<ValueType> & src);

    PriorityQueue<ValueType> & operator=(const PriorityQueue<ValueType> & src);

private:

/* Type for linked list cell */

   struct Cell {
      ValueType data; // The data value
      double priority; // The priority of this value
      Cell *link; // Link to the next cell
   };

/* Instance variables */

   Cell *head; // Pointer to the cell at the head
   int count;  // Number of elements in the queue

/* Private method prototypes */

   void deepCopy(const PriorityQueue<ValueType> & src);

};

/*
 * Implementation notes: PriorityQueue constructor
 * --------------------------------------
 * The constructor must create an empty linked list and then
 * initialize the fields of the object.
 */

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue() {
    head = nullptr;
    count = 0;
}

/*
 * Implementation notes: ~PriorityQueue destructor
 * --------------------------------------
 * The destructor frees any memory that is allocated by the implementation.
 * Freeing this memory guarantees the client that the queue abstraction
 * will not "leak memory" in the process of running an application.
 * Because clear frees each element it processes, this implementation
 * of the destructor simply calls that method.
 */

template <typename ValueType>
PriorityQueue<ValueType>::~PriorityQueue() {
}

/*
 * Implementation notes: size
 * -------------------------
 * In order to return the size in constant time, it is necessary
 * to store the count in the data structure and keep it updated
 * on each call to enqueue and dequeue.
 */

template <typename ValueType>
int PriorityQueue<ValueType>::size() {
    return count;
}

/*
 * Implementation notes: isEmpty
 * ----------------------------
 * This code uses the traditional count == 0 test for an empty
 * stack; testing the value of count would work just as well.
 */

template <typename ValueType>
bool PriorityQueue<ValueType>::isEmpty() {
    return count == 0;
}

/*
 * Implementation notes: clear
 * --------------------------
 * This code calls dequeue to make sure the cells are freed.
 */

template <typename ValueType>
void PriorityQueue<ValueType>::clear() {
    while (count > 0) {
        double useless;
        dequeue(useless);
    }
}

/*
 * Implementation notes: enqueue
 * ----------------------------
 * This method allocates a new cell at appropriate position of the queue.
 * If the queue is currently empty,
 * the new cell must also become the head pointer in the queue.
 */

template <typename ValueType>
void PriorityQueue<ValueType>::enqueue(ValueType value, double priority) {
    Cell *current = head;
    bool toBeHead = true;
    Cell *parent;
    while (current != nullptr && priority >= (current)->priority) {
        parent = current;
        current = (current)->link;
        toBeHead = false;
    }

    Cell *cell = new Cell;
    cell->data = value;
    cell->priority = priority;
    cell->link = current;
    count++;

    if (toBeHead) { // when the head cell is change, modify the head pointer
        head = cell;
    } else {
        parent->link = cell;
    }
}
/*
 * Implementation notes: dequeue, peek
 * ----------------------------------
 * These methods must check for an empty queue and report an
 * error if there is no first element. The dequeue method
 * must also check for the case in which the queue becomes
 * empty and set the head pointer to NULL.
 */

template <typename ValueType>
ValueType PriorityQueue<ValueType>::dequeue(double & priority) {
    if (isEmpty()) {
        error("dequeue: Attempting to dequeue an empty queue");
    }
    Cell *cell = head;
    ValueType value = cell->data;
    head = cell->link;
    priority = cell->priority;
    count--;
    delete cell;
    return value;
}

template <typename ValueType>
ValueType PriorityQueue<ValueType>::peek(double & priority) {
    if (isEmpty()) {
        error("peek: Attempting to peek at an empty queue");
    }
    priority = head->priority;
    return head->data;
}

/* Implementation notes: Stack constructor and destructor
 * ------------------------------------------------------
 * These methods are used to deep copy a priority queue from src.
 */
template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue(const PriorityQueue<ValueType> & src) {
   deepCopy(src);
}

template <typename ValueType>
PriorityQueue<ValueType> & PriorityQueue<ValueType>::operator=(const PriorityQueue<ValueType> & src) {
   if (this != &src) {
      clear();
      deepCopy(src);
   }
   return *this;
}

/*
 * Implementation notes: deepCopy
 * ------------------------------
 * This function copies the data from the src parameter into the current
 * object.  All dynamic memory is reallocated to create a "deep copy" in
 * which the current object and the source object are independent.
 * The capacity is set so that the stack has some room to expand.
 */

template <typename ValueType>
void PriorityQueue<ValueType>::deepCopy(const PriorityQueue<ValueType> & src) {
    head = nullptr;
    Cell *previous;

    bool i = true;
    for (Cell *cell = src.head; cell != nullptr; cell = cell->link) {
        Cell *cp = new Cell;
        cp->data = cell->data;
        cp->priority = cell->priority;
        if (i) {
            head = cp;
            i = false;
        } else {
            previous->link = cp;
        }
        previous = cp;

    }
    count = src.count;
}

#endif // PQUEUE_LIST_H
