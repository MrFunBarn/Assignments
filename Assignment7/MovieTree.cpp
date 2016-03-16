/*
*   Brandon Bell
*   Assignment7
*   Recitation: Th 1030am
*   Guogui Ding
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "MovieTree.h"
using namespace std;

MovieTree::MovieTree(char *file){
    root = NULL;

    ifstream inFile(file);
    int ranking;
    string title;
    int year;
    int quantity;
    if( inFile.good() ){
        string line;
        while( getline( inFile, line ) ){
            string tmp;
            stringstream ss(line);
            getline( ss, tmp, ',' );
            stringstream t1(tmp);
            t1 >> ranking;
            getline( ss, tmp, ',' );
            title = tmp;
            getline( ss, tmp, ',' );
            stringstream t3(tmp);
            t3 >> year;
            getline( ss, tmp, ',' );
            stringstream t4(tmp);
            t4 >> quantity;
            //cout<<ranking<<' '<<title<<' '<<year<<' '<<quantity<<endl;
            this->addMovieNode(ranking,title,year,quantity);
        }
    }
}


MovieTree::~MovieTree(){
}


void MovieTree::printMovieInventory(){
    this->printMovieInventory(root);
}


void MovieTree::printMovieInventory(MovieNode *node){
    if( node->leftChild != NULL ){
        this->printMovieInventory(node->leftChild);
    }
    cout<<"Movie: "<<node->title<<endl;
    if( node->rightChild != NULL ){
        this->printMovieInventory(node->rightChild);
    }
}


void MovieTree::addMovieNode(int ranking, 
                             string title, 
                             int releaseYear, 
                             int quantity){
    //MovieNode *tmp = new MovieNode();
    MovieNode *tmp = root;
    MovieNode *parent = tmp; //new MovieNode();
    //parent = tmp;
    MovieNode *current = new MovieNode(ranking,title,releaseYear,quantity);
    current->parent = NULL;
    current->rightChild = NULL;
    current->leftChild = NULL;
    while( tmp != NULL ){
        parent = tmp;
        if( current->title.compare(tmp->title) < 0 ){
            tmp = tmp->leftChild;
        }
        else{
            tmp = tmp->rightChild;
        }
    }
    if( parent == NULL ){
        root = current;
    }
    else if( current->title.compare(parent->title) < 0 ){
        current->parent = parent;
        parent->leftChild = current;
    }
    else{
        current->parent = parent;
        parent->rightChild = current;
    }
}


void MovieTree::findMovie(string title){
    MovieNode *node = new MovieNode;
    node = root;
    while( node != NULL ){
        cout<<node->title<<" "<<title<<endl;
        if( node->title == title ){
            cout << "Movie Info:" << endl;
            cout << "===========" << endl;
            cout << "Ranking:" << node->ranking << endl;
            cout << "Title:" << node->title << endl;
            cout << "Year:" << node->year << endl;
            cout << "Quantity:" << node->quantity << endl;
            return;
        }
        else if( node->title.compare(title) < 0 ){
            node = node->rightChild;
        }
        else{
            node = node->leftChild;
        }
    }
    if( node == NULL ){
        cout << "Movie not found." << endl;
    }
}


void MovieTree::rentMovie(string title){
    MovieNode *node = new MovieNode;
    node = root;
    while( node != NULL ){
        if( node->title == title ){
            if( node->quantity > 0 ){
                node->quantity--;
                cout << "Movie has been rented." << endl;
                cout << "Movie Info:" << endl;
                cout << "===========" << endl;
                cout << "Ranking:" << node->ranking << endl;
                cout << "Title:" << node->title << endl;
                cout << "Year:" << node->year << endl;
                cout << "Quantity:" << node->quantity << endl;
                if( node->quantity == 0 ){
                    this->deleteMovieNode(node->title);
                }
                return;
            }
            else{
                cout << "Movie out of stock." << endl;
                return;
            }
        }
        else if( node->title.compare(title) < 0 ){
            node = node->rightChild;
        }
        else{
            node = node->leftChild;
        }
    }
    if( node == NULL ){
        cout << "Movie not found." << endl;
    }
}


int MovieTree::countMovieNodes(){
    int c = 0;
    int *co = &c;
    this->countMovieNodes(root, co);
    return c;
}


void MovieTree::countMovieNodes(MovieNode *node, int *c){
    if( node->leftChild != NULL ){
        this->countMovieNodes(node->leftChild, c);
    }
    *c = *c + 1;//(node->quantity);
    if( node->rightChild != NULL ){
        this->countMovieNodes(node->rightChild, c);
    }
}


void MovieTree::deleteMovieNode(string title){
    MovieNode *node = new MovieNode;
    MovieNode *tmp = new MovieNode;
    node = this->search(title);
    // If the Node has no children.
    if( node != root ){
        if( (node->rightChild==NULL) && (node->leftChild==NULL) ){
            tmp = node;
            if (node->title.compare(node->parent->title) < 0 ){
                cout<<"Deleting: "<<node->title<<endl;
                node->parent->leftChild = NULL;
                delete tmp;
            }
            else{
                cout<<"Deleting: "<<node->title<<endl;
                node->parent->rightChild = NULL;
                delete tmp;
           }
        }
        // Node has two children.
        else if( (node->rightChild!=NULL) && (node->leftChild!=NULL) ){
            tmp = node;
            if (node->title.compare(node->parent->title) < 0 ){
                cout<<"Deleting: "<<node->title<<endl;
                node->parent->leftChild = node->leftChild;
                delete tmp;
            }
            else{
                cout<<"Deleting: "<<node->title<<endl;
                node->parent->rightChild = node->rightChild;
                delete tmp;
           }
        }
        // Node has one child.
        else{
            tmp = node;
            if (node->leftChild!=NULL){
                cout<<"Deleting: "<<node->title<<endl;
                node->parent->leftChild = node->leftChild;
                delete tmp;
            }
            else{
                cout<<"Deleting: "<<node->title<<endl;
                node->parent->leftChild = node->leftChild;
                delete tmp;
           }
        }
    }
}


MovieNode* MovieTree::search(string title){
    MovieNode *node = new MovieNode;
    node = root;
    while( node != NULL ){
        if( node->title == title ){
                return node;
        }
        else if( node->title.compare(title) < 0 ){
            node = node->rightChild;
        }
        else{
            node = node->leftChild;
        }
    }
    if( node == NULL ){
        cout << "Movie not found." << endl;
        return root;
    }
}
