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

MovieTree::MovieTree(){
    MovieNode *root = new MovieNode();
    root.parent = NULL;
    root.rightChild = NULL;
    root.leftChild = NULL;
}


MovieTree::~MovieTree(){
}

void MovieTree::printMovieInventory(){
    cout<<"print movies"<<endl;
}

void MovieTree::addMovieNode(int ranking, 
                             string title, 
                             int releaseYear, 
                             int quantity){
    MovieNode *tmp = root;
    MovieNode *current = new MovieNode(ranking,title,year,quantity);
    current.parrent = NULL;
    current.rightChild = NULL;
    current.leftChild = NULL;
    while( (tmp.rightChild != NULL) or (tmp.leftChild !=NULL) ){
    }
}

void MovieTree::findMovie(string title){
    cout<<"Find "<<title<<endl;
}

void MovieTree::rentMovie(string title){
    cout<<"Rent "<<title<<endl;
}
