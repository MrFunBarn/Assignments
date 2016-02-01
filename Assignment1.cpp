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
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct item
{           string type;
            int price;
            int wantSale; // 0=forsale, 1=wanted.
};

void del_element(item (&array)[100], int &numElem, int index,
                 int &numElements){
    for( index; index <= (numElem-2); index++){
        array[index] = array[index + 1];
    }
    numElem--;
}

void search_array(item search, item (&board)[100], 
                  int &i1, int &loopIterations,
                  int &numElements){
    bool found   = false;
    int searchI = i1 - 1;
    int i = 0;
    while( !found && i < i1 ){
        if( (search.wantSale != board[i].wantSale) &&
            (search.type == board[i].type) &&
            (search.price >= board[i].price) ){
            found = true;
            del_element(board, i1, i, numElements);
            numElements++;
            break;
        }
        i++;
        loopIterations++;
        }
    board[i1].type = search.type;
    board[i1].price = search.price;
    board[i1].wantSale = search.wantSale;
        
    
}

void output(item (&itemArray)[100], int &i1, int &loop, int &so){
        cout << "Number of items sold:" << endl;
        cout << so << endl;
        string sale;
        for( int n = 0; n<i1; n++){
            if( itemArray[n].wantSale == 0 ){
                sale = "For Sale";
            }
            else{
                sale = "Wanted";
            }
            cout<< itemArray[n].type << ' ' << sale
                << ' ' << itemArray[n].price << endl;
    }
    cout << "Loop Iterations: " << loop << endl;
}

int main( int argc, char *argv[] )
{
    item      itemArray[100];
    item      *itemPtr = &itemArray[100];
    item      temp;
    int       loopIterations = 0;
    int       i1             = 0;
    int       commaI         = 0;
    ifstream  inFile;
    string    line;
    int numElements          = 0;


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
    if( inFile.good() ){
        // Loop throgh file stream and break out each line.
        while( getline(inFile, line) ){
            commaI = 0;
            stringstream lineStream(line);
            string feild;
            // Loop through lines and separate feilds to insert into itemArray.
            while( getline(lineStream, feild, ',') ){
                // don't want some trailing or leading space to mess things up.
                stringstream ss(feild);
                feild.erase(remove(feild.begin(),feild.end(),' '),feild.end());
                if( commaI == 0 ){
                    temp.type = feild;
                }
                else if( commaI == 1 ){
                    if( feild == "forsale" ){
                        temp.wantSale = 0;
                    }
                    else{
                        temp.wantSale = 1;
                    }
                }
                else{
                    ss >> temp.price;
                    // here I asume that temp is correctly populated.
                    // add first element to itemArray.
                    if( i1 == 0 ){
                        itemArray[i1].type = temp.type;
                        itemArray[i1].price = temp.price;
                        itemArray[i1].wantSale = temp.wantSale;
                    }
                    search_array(temp,itemArray, i1, loopIterations,
                                 numElements);
                }
                commaI++;
            }
        //    cout<< itemArray[i1].wantSale << itemArray[i1].type;
         //   cout << itemArray[i1].price << endl;
            i1++;
            loopIterations++;
        }
    output(itemArray, i1, loopIterations, numElements);
    }
    }
}
