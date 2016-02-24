/*
*   Brandon Bell
*   Assignment5
*   Recitation: Th 1030am
*   Guogui Ding
*/

#include "Queue.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

Queue::Queue(int quesize)
{
    queueSize = quesize;
    queueHead = 0;
    queueTail = 0;
    queueCount = 0;
    arrayQueue = new string[queueSize];
}

Queue::~Queue()
{
    //dtor
}

//circular queue methods
void Queue::enqueue(string word){
    if( !(queueIsFull()) ){
        arrayQueue[queueTail] = word;
        queueCount++;
        queueTail = (queueTail+1) % queueSize;
        cout << "E: " << word << endl;
        cout << "H: " << queueHead << endl;
        cout << "T: " << queueTail << endl;
    }
}

void Queue::dequeue(){
    if( !queueIsEmpty() ){
        queueCount--;
        string tmp = arrayQueue[queueHead];
        queueHead = (queueHead+1) % queueSize;
        cout << "H: " << queueHead << endl;
        cout << "T: " << queueTail << endl;
        cout << "word: " << tmp << endl;
    }
}

void Queue::printQueue(){
    //while(print){
    //    if( queueHead < queueTail ){
    //        for(int i=queueHead; i<queueTail; i++){
    //            cout<<arrayQueue 
    int tmp = queueHead;
//    while(tmp != queueTail){
    int dex = queueTail;
    dex = (dex) % queueSize;
    while(tmp != dex){
        cout<<tmp<<": "<<arrayQueue[tmp]<<endl;
        tmp = (tmp+1) % queueSize;
    }
    if( queueCount == 0 ){
        cout<<"Empty"<<endl;
    }
}

bool Queue::queueIsFull(){
//    if( (queueCount + 1) == queueSize ){
    if( (queueCount) == queueSize ){
        cout << "Queue is full." << endl;
        return true;
    }
    return false;
}

bool Queue::queueIsEmpty(){
    if( queueCount == 0 ){
        cout << "Queue is empty." << endl;
        return true;
    }
    else{
        return false;
    }
}
