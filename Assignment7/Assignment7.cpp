/*
*   Brandon Bell
*   Assignment7
*   Recitation: Th 1030am
*   Guogui Ding
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "MovieTree.h"
using namespace std;

// The basic structure of this main function was taken from my assignments 5.
int main(int argc, char *argv[]){
    // instantiate MovieTree instance, menu selection variables.
    MovieTree blockbuster(argv[1]);
    int option = 0;

    // The main loop. runs until quit is selected.
    while( option != 6 ){
        // Print the main menu.
        cout<<"======Main Menu====="<< endl
            <<"1. Find Movie"<< endl
            <<"2. Rent a movie"<< endl
            <<"3. Print the inventory"<< endl
            <<"4. Delete a movie"<< endl
            <<"5. Count the movies"<< endl
            <<"6. Quit"<< endl;

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
            cout<<"Enter title:";
            getline( cin, word );
            blockbuster.findMovie(word);
        }
        else if( option == 2 ){
            string word;
            cout<<"Enter title:";
            getline( cin, word );
            blockbuster.rentMovie(word);
        }
        else if( option == 3 ){
            blockbuster.printMovieInventory();
        }
        else if( option == 4 ){
            string word;
            cout<<"Enter title:";
            getline( cin, word );
            blockbuster.rentMovie(word);
        }
        else if( option == 5 ){
            cout<<"Tree contains: "<<blockbuster.countMovieNodes()<<" movies"<<endl;
        }
        else if( option == 6 ){
            cout << "Goodbye!" << endl;
        }
    }
return 0;
}
