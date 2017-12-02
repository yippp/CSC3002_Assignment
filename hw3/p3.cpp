/*
 * File: p3.cpp
 * --------------------------
 * This is used to test the answer to question 3 of assignmet 3 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#include "pqueue_heap.h"
using namespace std;

void p3() {
    PriorityQueue<string> q;
    q.enqueue("A", 5);
    q.enqueue("B", 2);
    q.enqueue("C", 9);
    q.enqueue("D", 2);
    q.enqueue("E", 7);

    cout << "size:" << q.size() << endl;
    cout << "isempty:" << q.isEmpty() << endl;

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << "size:" << q.size() << endl;

    q.enqueue("A", 5);
    q.enqueue("E", 7);


    PriorityQueue<string> copy = q;
    cout << "copy.peek: "<<copy.peek() << endl;

    PriorityQueue<string> copy2(q);
    cout << "copy2.size: "<< copy2.size() << endl;

    q.clear();
    cout << "q.isempty:" << q.isEmpty() << endl;

    copy.~PriorityQueue();
    cout << "copy.isempty:" << copy.isEmpty() << endl;
}
