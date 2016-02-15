#include "CommunicationNetwork.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

CommunicationNetwork::CommunicationNetwork()
{
City *head = new City;
head->next = NULL;
}

CommunicationNetwork::~CommunicationNetwork()
{
    //dtor
}

void CommunicationNetwork::addCity(string name, string previous){
    City *current = head;
    City *tmp = new City(name,NULL,"");
    // If the new city is not to be the new head.
    while( current->next != NULL ){
        if( tail->cityName == previous ){
            tmp->next = NULL;
            tail->next = tmp;
            tail = tmp;
            break;
        }
        if( current->cityName == previous ){
            City *left = current->next;
            tmp->next = left;
            current->next = tmp;
        }
        current = current->next;
    }
}

void CommunicationNetwork::buildNetwork(){
    string cities[10] = {"Los Angeles","Phoenix","Denver","Dallas","St. Louis","Chicago","Atlanta","Washington, D.C.","New York","Boston"};

    head = new City(cities[0],NULL,"");
    City *current = head;
    for( int i=1; i<10; i++ ){
        City *tmp = new City(cities[i],NULL,"");
        current->next = tmp;
        current = current->next;
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
            cout<<current->cityName<<" "<<"received "<<current->message<<endl;
            current->message = "";
            current = current->next;
            if( current->next == NULL ){
                current->message = word;
                cout<<current->cityName<<" "<<"received "<<current->message<<endl;
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
