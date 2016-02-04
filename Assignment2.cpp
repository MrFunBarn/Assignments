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

// Double the the size of a 1d input array of word_data structs. 
word_data *double_array( word_data original[], int &size, int &doubles ){
    int       newSize  = 2 * size;
    word_data *new_one = new word_data[newSize];

    for( int i=0; i < size; i++ ){
        new_one[i] = original[i];
    }
    delete []original;
    original = new_one;
    size*= 2;
    doubles++;
    return original;
}

// Find or add word to word_data array. If a word is allready in the word data
// array, increment it's count value.
word_data *add_word_to_array( word_data array[], 
                              string value, 
                              int &size, 
                              int &wordnum, 
                              int &numdouble ){
    bool isThere = true;
    // search the array and if there ++ the count variable.
    for( int i=0; i < wordnum; i++ ){
        if( value == array[i].word ){
            array[i].count++;
            isThere = true;
            break;
        }
    }
    // adding the word to the array and doubleing the array if nessasry.
    if( (size > wordnum) && isThere == false ){
        cout << size << endl;
        cout << wordnum << endl;
        array[wordnum].word = value;
        array[wordnum].count = 1;
        wordnum++;
    cout << array[wordnum].word << endl;
    cout << "this far" << endl;
    }
    else if( isThere == false ){
        cout << "this far" << endl;
        array = double_array( array, size, numdouble );
        array[wordnum].word = value;
        array[wordnum].count = 1;
        wordnum++;
    } 
}

int main( int argc, char *argv[] ){
    // variable declarations.
    string        word;
    string        line;
    bool          common;
    int           arraySize  = 2;
    int           numWords   = 0;
    int           doubles    = 0;
    word_data     *words     = new word_data[arraySize];

    // check for correct arguments and quit with error status if not correct.
    if( argc != 2 ){
        cout << "Incorect # of arguments." << endl;
        cout << "Usage: " << argv[0] << "FileToAnalyze" 
             << " #number of words" << endl;
             return 1;
    }
    else{
        // open file, check that it's good and read it.
        ifstream inFile ( argv[1] );
        if( !inFile.is_open() ){
            cout << "Could not open file" << endl;
            return 1;
        }
        // extract words and do the stuff with them.
        while( getline( inFile, line ) ){
            stringstream ss(line);
            while( getline( ss, word, ' ' ) ){ 
                common = is_common_word(word);
                if( !common ){
                    words = add_word_to_array( words, 
                                               word,
                                               arraySize,
                                               numWords,
                                               doubles );
                }
            }
        }
    }
}
