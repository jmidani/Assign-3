#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Queue{
    private:
    int max, front, back, counter;
    T *array;

    public:
    Queue(int); //Constructor initalizes empty queue
    Queue(T*,int); // Constructor creates a queue from preexisting array
    bool isEmpty(); // Checks if queue is empty
    bool isFull(); // Checks is queue is full
    void Push(T); // Enqueuing
    T Pop(); // Dequeueing
    T Peek(); // Returns last element in queue
    void Display(); // Displays entire queue from front->back
    ~Queue(); // Destructor
};
#endif