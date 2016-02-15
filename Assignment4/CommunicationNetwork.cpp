/*
*   Brandon Bell
*   Assignment4
*   Recitation: Th 1030am
*   Guogui Ding
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "CommunicationNetwork.h"
using namespace std;

CommunicationNetwork::CommunicationNetwork()
{
City *head = new City;
head->next = NULL;
head->prev = NULL;
}

CommunicationNetwork::~CommunicationNetwork()
{
    //dtor
}

void CommunicationNetwork::addCity(string name, string previous){
    City *current = head;
    City *tmp = new City(name,NULL,NULL,"");
    // If the new city is not the new head.
    while( current->next != NULL ){
        // If the new city will be the new tail.
        if( tail->cityName == previous ){
            tmp->next  = NULL;
            tmp->prev  = tail;
            tail->next = tmp;
            tail       = tmp;
            break;
        }
        // If the new city lies somewhere in the list that's not the head or
        // tail.
        if( current->cityName == previous ){
            City *left = current->next;
            tmp->next  = left;
            tmp->prev  = current;
            current->next = tmp;
        }
        // iterates to the new element in the list.
        current = current->next;
    }
}

void CommunicationNetwork::buildNetwork(){
    // Loop throgh the starting array of city names to build the linked list and
    // define additional head and tail pointers.
    string cities[10] = {"Los Angeles","Phoenix","Denver","Dallas",
                         "St. Louis","Chicago","Atlanta",
                         "Washington, D.C.","New York","Boston"};

    head = new City(cities[0],NULL,NULL,"");
    City *current = head;
    for( int i=1; i<10; i++ ){
        City *tmp     = new City(cities[i],NULL,NULL,"");
        current->next = tmp;
        current       = current->next;
    }
    tail = current;
}

void CommunicationNetwork::transmitMsg(){
    ifstream inFile( "messageIn.txt");
    string word;
    string line;
    getline( inFile, line );
    stringstream l(line);
    while( getline( l, word, ' ' ) ){
            City *current = head;
        while( current->next != NULL ){
            current->message = word;
            cout << current->cityName << " " << "received " << current->message 
                 << endl;
            current->message = "";
            current = current->next;
            if( current->next == NULL ){
                current->message = word;
                cout << current->cityName << " " << "received " << current->message 
                     << endl;
                current->message = "";
            }
        }

    }
}

void CommunicationNetwork::printNetwork(){
    City *current = head;
    cout<<"===CURRENT PATH==="<<endl;
    while(current->next != NULL){
        cout<<current->cityName<<" -> ";
        current = current->next;
        if( current->next == NULL ){
            cout<<current->cityName<<" -> ";
        }
    }
    cout<<"NULL"<<endl;
    cout<<"=================="<<endl;
}
