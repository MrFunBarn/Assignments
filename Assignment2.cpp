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
#include <vector>

// Define the structure for holding words and thier respective count numbers.
struct word_data
{       string word;
        int    count;
};

// Determine if the word is one of the 50 most common words in the english
// language and return a booliean value.
bool is_common_word(){
    vector common = {"the","be","to","of","and","a","in","that","have",
                        "I","it","for","not","on","with","he","as","you",
                        "do","at","this","but","his","by","from","they",
                        "we","say","her","she","or","an","will","my",
                        "one","all","would","there","their","what",
                        "so","up","out","if","about","who","get",
                        "which","go","me"};
}

// Double the input array.
word_data double_array(){

}


int main(int argc, char *argv[]){
    if( argc != 2 ){
        //cout << "Incorect # of arguments." << endl;
        //cout << "Usage: " << argv[0] << "FileToAnalyze" << endl;
    }
}
