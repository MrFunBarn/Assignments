/*    
 *    Brandon Bell
 *    Assignment2
 *    Recitation: Th 10:30am
 *    Guohui Ding
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

// Define the structure for holding words and their respective count numbers.
struct word_data
{       string word;
        int    count;
};

// Determine if the word is one of the 50 most common words in the english
// language and return a booliean value.
bool is_common_word(string x){
    string common[] =  {"the","be","to","of","and","a","in","that","have",
                        "I","it","for","not","on","with","he","as","you",
                        "do","at","this","but","his","by","from","they",
                        "we","say","her","she","or","an","will","my",
                        "one","all","would","there","their","what",
                        "so","up","out","if","about","who","get",
                        "which","go","me"};

    for( int i=0; i < 50; i++ ){
        if( x == common[i] ){ 
            return true;
        }
    }
    return false;
}

// Double the the size of a 1d input array. 
word_data *double_array( word_data original[], int &size ){
    int       newSize  = 2 * size;
    word_data *new_one = new word_data[newSize];

    for( int i=0; i < size; i++){
        new_one[i] = original[i];
    }
    delete []original;
    original = new_one;
    size*= 2;
    return original;
}


int main(int argc, char *argv[]){
    if( argc != 2 ){
        cout << "Incorect # of arguments." << endl;
        cout << "Usage: " << argv[0] << "FileToAnalyze" << endl;
    }
}
