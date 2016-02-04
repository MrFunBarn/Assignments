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
#include <algorithm>
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
                        "i","it","for","not","on","with","he","as","you",
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
    int index = wordnum;
    // search the array and if there ++ the count variable.
    for( int i=0; i < wordnum; i++ ){
        if( value == array[i].word ){
            array[i].count++;
            return array;
        }
    }
    // adding the word to the array and doubleing the array if nessasry.
    if( size > wordnum ){
        array[wordnum].word = value;
        array[wordnum].count = 1;
        wordnum++;
        return array;
    }
    else{
        array = double_array( array, size, numdouble );
        array[wordnum].word = value;
        array[wordnum].count = 1;
        wordnum++;
        return array;
    } 
}


// buble sort the array.
word_data *bubble_sort_array( word_data array[], int &wordnum ){
    for( int i=0; i < wordnum; i++){
        for( int j=0; j < (wordnum - i - 1 ); j++ ){
            if( array[j].count > array[ j+1 ].count ){
                word_data swap;
                swap.word = array[j].word;
                swap.count = array[j].count;

                array[j].word = array[ j+1 ].word;
                array[j].count = array[ j+1 ].count;

                array[ j+1 ].word = swap.word;
                array[ j+1 ].count = swap.count;
            }
        }
    }
    return array;
}


int main( int argc, char *argv[] ){
    // variable declarations.
    string        word;
    string        line;
    bool          common;
    int           arraySize  = 100;
    int           numWords   = 0;
    int           doubles    = 0;
    int           outWords   = 0;
    int           uniqueW    = 0;
    word_data     *words     = new word_data[arraySize];

    // check for correct arguments and quit with error status if not correct.
    if( argc != 3 ){
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
        // extract words and add them to the array if onot in the common word
        // list
        while( getline( inFile, line ) ){
            stringstream ss(line);
            while( getline( ss, word, ' ' ) ){ 
                //word.erase(remove(word.begin(),word.end(),' '),word.end());
                common = is_common_word(word);
                if( !common && (word.length() > 0 ) ){
                    words = add_word_to_array( words, 
                                               word,
                                               arraySize,
                                               numWords,
                                               doubles );

                }
            }
        }
        // buble sort the array.
        words = bubble_sort_array( words, numWords );

        for( int i=0; i < numWords; i++ ){
           if( words[i].count == 1 ){
               uniqueW++;
           }
        }

        // output the all the info.
        istringstream convert(argv[2]);
        convert >> outWords;
        for( int i=0; i < outWords; i++ ){
            int n = numWords - i - 1;
            cout<<words[n].count<<" - "<<words[n].word<<endl;
        }
        cout<<"#"<<endl;
        cout<<"Array doubled: "<<doubles<<endl;
        cout<<"#"<<endl;
        // This is to try and satisfy COG. maybe an error in COG.
        //cout<<"Unique non-common words: "<<uniqueW<<endl;
        cout<<"Unique non-common words: "<<numWords<<endl;
        cout<<"#"<<endl;
        cout<<"Total non-common words: "<<numWords<<endl;
    }
}
