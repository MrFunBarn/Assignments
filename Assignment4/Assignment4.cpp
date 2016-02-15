/*
*   Brandon Bell
*   Assignment4
*   Recitation: Th 1030am
*   Guogui Ding
*/

#include "CommunicationNetwork.h"
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    CommunicationNetwork network;
    int option = 0;
    ifstream inFile;

    // The main loop. runs until quit is selected.
    while( option != 7 ){
        // Print the main menu.
        cout<<"======Main Menu======"<< endl
            <<"1. Build Network"<< endl
            <<"2. Print Network Path"<< endl
            <<"3. Transmit Message Coast-To-Coast"<< endl
            <<"4. Add City"<< endl
            <<"5. Delete City"<< endl
            <<"6. Clear Network"<< endl
            <<"7. Quit"<< endl;

        // Grab the option and convert to int with stringstream.
        string s;
        getline( cin, s );
        stringstream ss(s);
        ss >> option;

        // Processes option and apply the relevent method.
        if( option == 1 ){
            network.buildNetwork();
            network.printNetwork();
        }
        else if( option == 2 ){
            network.printNetwork();
        }
        else if( option == 3 ){
            network.transmitMsg();
        }
        else if( option == 4 ){
            string name;
            string previous;
            cout<<"Enter a city name: "<<endl;
            getline( cin,name );
            cout<<"Enter a previous city name: "<<endl;
            getline( cin,previous );
            network.addCity(name,previous);
        }
        else if( option == 7 ){
            cout<<"Goodbye!"<<endl;
        }
    }
}
