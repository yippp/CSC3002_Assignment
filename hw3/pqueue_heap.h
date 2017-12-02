/*
 * File: pqueue_list.h
 * --------------------------
 * This is the answer to question 3 of assignmet 3 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 * It is a class of queue wilt priority builded with heap
 */

#ifndef PQUEUE_HEAP_H
#define PQUEUE_HEAP_H

#include "vector.h"
using namespace std;

template <typename ValueType>
class PriorityQueue {

public:

    PriorityQueue();

    ~PriorityQueue();

    int size();

    bool isEmpty();

    void clear();

    void enqueue(ValueType value, double priority);

    ValueType dequeue();

    ValueType peek();

    PriorityQueue(const PriorityQueue<ValueType> & src);

    PriorityQueue<ValueType> & operator=(const PriorityQueue<ValueType> & src);

private:

    /* Type used for each heap entry */

    struct HeapEntry {
        ValueType value;
        double priority;
        long sequence;
    };

    /* Instance variables */

    Vector<HeapEntry> heap;
    long enqueueCount;
    int count;
    int capacity;
};


/*
 * Implementation notes: PriorityQueue constructor
 * --------------------------------------
 * The constructor must create an empty linked list and then
 * initialize the fields of the object.
 */

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue() {
    clear();
}

/*
 * Implementation notes: ~PriorityQueue destructor
 * --------------------------------------
 * The destructor frees any memory that is allocated by the implementation.
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
    count = 0;
    enqueueCount = 0;
    heap.clear();
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
    if (count == heap.size()) {
        heap.add(HeapEntry());
    }

    int current = count;
    count++;
    heap[current].value = value;
    heap[current].priority = priority;
    heap[current].sequence = enqueueCount++;

    while (current > 0) { // maintain the priority of min-heap
        int parent = (current - 1) / 2;
        if (heap[parent].priority < heap[current].priority ||
           (heap[parent].priority == heap[current].priority &&
            heap[parent].sequence < heap[current].sequence)) {
            break;
        } // check wheather it is necessary to exchange the current entry with its parent

        HeapEntry temp = heap[parent];
        heap[parent] = heap[current];
        heap[current] = temp;

        current = parent;
    }

    for (int i = 0; i < count; i++) {
        cout << heap[i].value;
    }
    cout << endl;
}

/*
 * Implementation notes: dequeue, peek
 * ----------------------------------
 * These methods must check for an empty queue and report an
 * error if there is no first element.
 */

template <typename ValueType>
ValueType PriorityQueue<ValueType>::dequeue() {
    if (isEmpty()) {
        error("dequeue: Attempting to dequeue an empty queue");
    }

    ValueType value = heap[0].value;

    heap[0] = heap[count - 1];
    count--;

    int current = 0; // maintain the priority of min-heap
    while (1) {
        int left = 2 * current + 1;
        int right = left + 1;
        if (left > count) break;
        int child;
        if (heap[right].priority < heap[left].priority ||
           (heap[left].priority == heap[right].priority &&
            heap[right].sequence < heap[left].sequence)) {
            child = right;
        } else {
            child = left;
        } // find the most break priority child
        if (!(heap[current].priority < heap[child].priority ||
           (heap[current].priority == heap[child].priority &&
            heap[child].sequence < heap[current].sequence))) {
            HeapEntry temp = heap[child];
            heap[child] = heap[current];
            heap[current] = temp;
        } // if the child break the priority, exchange it with parent
        current = child;
    }
    return value;
}

template <typename ValueType>
ValueType PriorityQueue<ValueType>::peek() {
    if (isEmpty()) {
        error("peek: Attempting to peek at an empty queue");
    }
    return heap[0].value;
}

/* Implementation notes: Stack constructor and destructor
 * ------------------------------------------------------
 * These methods are used to deep copy a priority queue from src.
 */
template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue(const PriorityQueue<ValueType> & src) {
    heap = src.heap;
    count = src.count;
    enqueueCount = src.enqueueCount;
    capacity = src.capacity;
}

template <typename ValueType>
PriorityQueue<ValueType> & PriorityQueue<ValueType>::operator=(const PriorityQueue<ValueType> & src) {
    if (this != &src) {
       heap = src.heap;
       count = src.count;
       enqueueCount = src.enqueueCount;
       capacity = src.capacity;
    }
    return *this;
}
#endif // PQUEUE_HEAP_H
