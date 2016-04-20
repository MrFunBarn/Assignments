/*
*   Brandon Bell
*   Assignment12
*   Recitation: Th 1030am
   Guogui Ding
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "HashTable.h"
using namespace std;

// The basic structure of this main function was taken from my assignments 5.
int main(int argc, char *argv[]){
    // instantiate Graph instance, and menu selection variables.
    HashTable Hash; 
    int option = 0;

    // The main loop. runs until quit is selected.
    while( option != 5 ){
        // Print the main menu.
        cout<<"======Main Menu======"<< endl
            <<"1. Insert movie"<< endl
            <<"2. Delete movie"<< endl
            <<"3. Find movie"<<endl
            <<"4. Print table contents"<<endl
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
            string title;
            string year;
            cout<<"Enter title:"<<endl;
            getline( cin, title );
            cout<<"Enter year:"<<endl;
            getline( cin, year );
            int y = stoi(year);
            Hash.insertMovie(title, y); 
        }
        else if( option == 2 ){
            string title;
            cout<<"Enter title:"<<endl;
            getline( cin, title );
            Hash.deleteMovie(title);
        }
        else if( option == 3 ){
            string title;
            cout<<"Enter title:"<<endl;
            getline( cin, title );
            Hash.findMovie(title);
        }
        else if( option == 4 ){
            Hash.printTableContents();
        }
        else if( option == 5 ){
            cout << "Goodbye!" << endl;
        }
    }
return 0;
}
