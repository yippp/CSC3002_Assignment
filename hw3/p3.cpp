/*
 * File: p3.cpp
 * --------------------------
 * This is used to test the answer to question 3 of assignmet 3 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#include "pqueue_heap.h"
using namespace std;

void p3() {
    cout << "PriorityQueueHeap<string> q;" << endl;
    PriorityQueueHeap<string> q;
    cout << "enqueue A" << endl;
    q.enqueue("A", 5);
    cout << "enqueue B" << endl;
    q.enqueue("B", 2);
    cout << "enqueue C" << endl;
    q.enqueue("C", 9);
    cout << "enqueue D" << endl;
    q.enqueue("D", 2);
    cout << "enqueue E" << endl;
    q.enqueue("E", 7);

    cout << "size:" << q.size() << endl;
    cout << "isempty:" << q.isEmpty() << endl;

    double priority;
    cout << q.dequeue(priority) << priority << endl;
    cout << q.dequeue(priority) << priority << endl;
    cout << q.dequeue(priority) << priority << endl;
    cout << q.dequeue(priority) << priority << endl;
    cout << q.dequeue(priority) << priority << endl;

    cout << "size:" << q.size() << endl;

    cout << endl << "enqueue A" << endl;
    q.enqueue("A", 5);
    cout << "enqueue E" << endl;
    q.enqueue("E", 7);

    cout << endl << "PriorityQueue<string> copy = q;" << endl;
    PriorityQueueHeap<string> copy = q;
    cout << "copy.peek: "<<copy.peek(priority) << priority << endl;

    cout << endl << "PriorityQueue<string> copy2(q);" << endl;
    PriorityQueueHeap<string> copy2(q);
    cout << "copy2.size: "<< copy2.size() << endl;

    cout << endl << "q.clear();" << endl;
    q.clear();
    cout << "q.isempty:" << q.isEmpty() << endl;

    cout << endl << "copy.~PriorityQueue();" << endl;
    copy.~PriorityQueueHeap();
    cout << "copy.isempty:" << copy.isEmpty() << endl;
}
