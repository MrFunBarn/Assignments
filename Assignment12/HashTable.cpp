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
}


void HashTable::insertMovie(std::string name, int year)
{
    int i = hashSum(name, year);
    HashElem *tmp = new HashElem( name, year );
    if( hashTable[i] == NULL )
    {
        hashTable[i] = tmp;
    }
    else if( name == hashTable->title )
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
    cout<<i<<endl;
}


void HashTable::deleteMovie(std::string name)
{
}


void HashTable::findMovie(std::string name)
{
}


int HashTable::hashSum(std::string x, int s)
{
    int sum = 0;
    for( int i=0; i < x.size(); i++ )
    {
        sum = sum + int( x[i] );
    }
    sum = sum % tableSize;
    return sum;
}
