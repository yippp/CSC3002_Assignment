/*
 * File: q4.cpp
 * --------------------------
 * This is the answer to question 4 of assignmet 1 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#include <iostream>
#include "stack.h"
#include "queue.h"
using namespace std;

void reverseQueue(Queue<string> & queue){
    // Reverses the elements in the queue.
    Stack<string> temp;

    while (!queue.isEmpty()){ // put all the element in the queue into stack
        temp.push(queue.dequeue());
    }
    while (!temp.isEmpty()){ // // put all the element in the stack into queue
        queue.enqueue(temp.pop());
    }
    return ;
}


int q4() {
    Queue<string> queue_for_test{"a","b","c"};

    cout << "After applying function reverseQueue for queue {\"a\",\"b\",\"c\"}, the queue become:" << endl;
    reverseQueue(queue_for_test);
    while (!queue_for_test.isEmpty()){
        cout << queue_for_test.dequeue() << " ";
    }
    cout << endl;
    return 0;
}
