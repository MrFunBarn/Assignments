/*
*   Brandon Bell
*   Assignment12
*   Recitation: Th 1030am
*   Guogui Ding
*/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "HashTable.h"
using namespace std;

HashTable::HashTable()
{
    for( int i=0; i<tableSize; i++ )
    {
        hashTable[i] = NULL;
    }
}


HashTable::~HashTable()
{
}


void HashTable::printTableContents()
{
    bool empty = true;
    for( int i=0; i<tableSize; i++ )
    {
        if( hashTable[i] != NULL ) {
            empty = false;
            }
    }
    if( empty == true )
    {
        cout<<"empty"<<endl;
        return;
    }
    for( int i=0; i<tableSize; i++ )
    {
        if( hashTable[i] != NULL ){
            HashElem *tmp = hashTable[i];
            cout<<tmp->title<<":"<<tmp->year<<endl;
            while( tmp->next != NULL )
            {
                tmp = tmp->next;
                cout<<tmp->title<<":"<<tmp->year<<endl;
            }
        }
    }
}


void HashTable::insertMovie(std::string name, int year)
{
    int i = hashSum(name);
    HashElem *tmp = new HashElem( name, year );
    if( hashTable[i] == NULL )
    {
        hashTable[i] = tmp;
    }
    else if( name == hashTable[i]->title )
    {
        return;
    }
    else
    {
        HashElem *par = hashTable[i];
        if( par->next == NULL )
        {
            tmp->previous = hashTable[i];
            hashTable[i]->next = tmp;
            return;
        }
        while( par->next != NULL )
        {
            par = par->next;
        }
        tmp->previous = par;
        par->next = tmp;
    }
}


void HashTable::deleteMovie(std::string name)
{
    int i = hashSum(name);
    HashElem *tmp = hashTable[i];
    if( tmp == NULL )
    {
        return;
    }
    else if( tmp->title == name && tmp->next == NULL )
    {
        //delete hashTable[i];
        //tmp = NULL;
        delete tmp;
        hashTable[i] = NULL;
    }
    else if( tmp->title == name && tmp->next != NULL )
    {
        hashTable[i] = tmp->next; 
        hashTable[i]->previous = NULL;
        delete tmp;
    }
    else if( tmp->title != name && tmp->next != NULL )
    {
        while( tmp->next != NULL )
        {
            tmp = tmp->next;
            if( tmp->title == name )
            {
                tmp->previous->next = tmp->next;
                delete tmp;
                return;
            }
        }
    }
}


void HashTable::findMovie(std::string name)
{
    int i = hashSum(name);
    HashElem *tmp = hashTable[i];
    if( tmp == NULL )
    {
        cout<<"not found"<<endl;
    }
    else if( tmp->title == name && tmp->next == NULL )
    {
        cout<<i<<":"<<name<<":"<<tmp->year<<endl;
    }
    else if( tmp->title == name && tmp->next != NULL )
    {
        cout<<i<<":"<<name<<":"<<tmp->year<<endl;
    }
    else if( tmp->title != name && tmp->next != NULL )
    {
        while( tmp->next != NULL )
        {
            tmp = tmp->next;
            if( tmp->title == name )
            {
                cout<<i<<":"<<name<<":"<<tmp->year<<endl;
            }
        }
    }
    else
    {
        cout<<"not found"<<endl;
    }
}


int HashTable::hashSum(std::string x)
{
    int sum = 0;
    for( int i=0; i < x.size(); i++ )
    {
        sum = sum + int( x[i] );
    }
    sum = sum % tableSize;
    return sum;
}
