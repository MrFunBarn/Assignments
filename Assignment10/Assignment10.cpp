/*
*   Brandon Bell
*   Assignment10
*   Recitation: Th 1030am
*   Guogui Ding
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Graph.h"
using namespace std;

// The basic structure of this main function was taken from my assignments 5.
int main(int argc, char *argv[]){
    // instantiate Graph instance, and menu selection variables.
    Graph zombies(argv[1]);
    int option = 0;

    // The main loop. runs until quit is selected.
    while( option != 4 ){
        // Print the main menu.
        cout<<"======Main Menu======"<< endl
            <<"1. Print vertices"<< endl
            <<"2. Find districts"<< endl
            <<"3. Find shortest path"<< endl
            <<"4. Quit"<< endl;

        // Grab the option and convert to int with stringstream.
        string s;
        // this get line prevents a stray \n from hanging around messing up
        // latter getline calls.
        getline( cin, s );
        stringstream ss(s);
        ss >> option;

        // Processes option and apply the relevent method.
        if( option == 1 ){
            zombies.displayEdges();
        }
        else if( option == 2 ){
            zombies.assignDistricts();
        }
        else if( option == 3 ){
        }
        else if( option == 4 ){
            cout << "Goodbye!" << endl;
        }
    }
return 0;
}
