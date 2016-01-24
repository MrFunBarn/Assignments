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
#include <string>
using namespace std;

struct item
{           string type;
            float  price;
            bool   wantSale;
};

int main( int argv, char *argc[] )
{
    item itemArray[100];
    int  loopIterations = 0;

}
