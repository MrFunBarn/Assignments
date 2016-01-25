/*    
 *    Brandon Bell
 *    Assignment1
 *    Recitation: Th 10:30am
 *    Guohui Ding
*/


/* struct ,type, price, sale/wanted sale=0 wanted=1.
 *
 * take file as a cmd line argument.
 *
 * as file is parsed, compare against existing array for matches. if there is no
 * match add item to first available spot in the array. if a match is found,
 * stop at first match and delete matching element in the array and shift array
 * to fill void. Print the match to terminal.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct item
{           string type;
            float  price;
            bool   wantSale;
};

int main( int argc, char *argv[] )
{
    item      itemArray[100];
    int       loopIterations = 0;
    string    inFile;
    ifstream  file;
    string    line;


// Check for the correct number of cmd line arguments and if correct, atempt to
// open the specified file.
    if( argc != 2 ){
        cout << "Incorrect number of arguments" << endl;
        cout << "Usage: " << argv[0] << " filename" << endl;
        return 1;
    }
    else{
        ifstream inFile ( argv[1] );
        if( !inFile.is_open() ){
            cout << "Could not open file" << endl;
            return 1;
        }
    }

// Read in file.


}
