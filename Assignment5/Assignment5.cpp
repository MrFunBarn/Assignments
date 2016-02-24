/*
*   Brandon Bell
*   Assignment5
*   Recitation: Th 1030am
*   Guogui Ding
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Queue.h"
using namespace std;

int main(int argc, char *argv[]){
    // instantiate Queue instance and menu selection variables.
    Queue myQue(10);
    int option = 0;
    ifstream inFile;

    // The main loop. runs until quit is selected.
    while( option != 5 ){
        // Print the main menu.
        cout<<"======Main Menu====="<< endl
            <<"1. Enqueue word"<< endl
            <<"2. Dequeue word"<< endl
            <<"3. Print queue"<< endl
            <<"4. Enqueue sentence"<< endl
            <<"5. Quit"<< endl;

        // Grab the option and convert to int with stringstream.
        string s;
        // this get line prevents a stray \n from hanging around messing up
        // latter getline calls.
        getline( cin, s );
        stringstream ss(s);
        ss >> option;

        // Processes option and apply the relevent method.
        if( option == 1 ){
            string word;
            cout<<"word: ";
            getline( cin, word );
            myQue.enqueue(word);
        }
        else if( option == 2 ){
            myQue.dequeue();
        }
        else if( option == 3 ){
            myQue.printQueue();
        }
        else if( option == 4 ){
            string sentence;
            string word;
            cout<<"sentence: ";
            getline( cin, sentence );
            stringstream ss(sentence);
            while( getline( ss, word, ' ' ) ){
                myQue.enqueue(word);
            }
        }
        else if( option == 5 ){
            cout << "Goodbye!" << endl;
        }
    }
return 0;
}
