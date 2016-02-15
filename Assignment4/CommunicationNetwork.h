/*
*   Brandon Bell
*   Assignment4
*   Recitation: Th 1030am
*   Guogui Ding
*/

#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H
#include <iostream>
struct City{
    std::string cityName;
    std::string message;
    City *prev;
    City *next;

    City(){}; // default constructor

    City(std::string initName, City *initNext, City *initPrev, std::string initMessage)
    {
        cityName = initName;
        next = initNext;
        prev = initPrev;
        message = initMessage;
    }

};

class CommunicationNetwork
{
    public:
        CommunicationNetwork();
        ~CommunicationNetwork();
        void addCity(std::string, std::string);
        void buildNetwork();
        void transmitMsg(); //this is like a string
        void printNetwork();
    protected:
    private:
        City *head;
        City *tail;
};

#endif // COMMUNICATIONNETWORK_H
