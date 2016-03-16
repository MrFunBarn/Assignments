/*
*   Brandon Bell
*   Assignment6
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
    MovieTree blockbuster;
    int option = 0;
    int ranking;
    string title;
    int year;
    int quantity;
    ifstream inFile(argv[1]);

    // Build the tree by calling addMovieNode on each line in the file.
    if( inFile.good() ){
        string line;
        while( getline( inFile, line ) ){
            string tmp;
            stringstream ss(line);
            getline( ss, tmp, ',' );
            stringstream t1(tmp);
            t1 >> ranking;
            getline( ss, tmp, ',' );
            stringstream t2(tmp);
            t2 >> title;
            getline( ss, tmp, ',' );
            stringstream t3(tmp);
            t3 >> year;
            getline( ss, tmp, ',' );
            stringstream t4(tmp);
            t4 >> quantity;
            blockbuster.addMovieNode(ranking,title,year,quantity);
        }
    }



    // The main loop. runs until quit is selected.
    while( option != 4 ){
        // Print the main menu.
        cout<<"======Main Menu====="<< endl
            <<"1. Find Movie"<< endl
            <<"2. Rent a movie"<< endl
            <<"3. Print the inventory"<< endl
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
            string word;
            cout<<"word: ";
            getline( cin, word );
            blockbuster.findMovie(word);
        }
        else if( option == 2 ){
            string word;
            cout<<"word: ";
            getline( cin, word );
            blockbuster.rentMovie(word);
        }
        else if( option == 3 ){
            blockbuster.printMovieInventory();
        }
        else if( option == 4 ){
            cout << "Goodbye!" << endl;
        }
    }
return 0;
}
