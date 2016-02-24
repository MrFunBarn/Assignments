/*
*   Brandon Bell
*   Assignment5
*   Recitation: Th 1030am
*   Guogui Ding
*/

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

class Queue
{
    public:
        Queue(int);
        ~Queue();
        //circular queue methods
        void enqueue(std::string);
        void dequeue(); 
        void printQueue();
        bool queueIsFull();
        bool queueIsEmpty();

    protected:
    private:
        int queueSize;
        int queueHead;
        int queueTail;
        int queueCount;
        std::string *arrayQueue;
};

#endif // QUEUE_H
