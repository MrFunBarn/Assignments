/*
*   Brandon Bell
*   Assignment10
*   Recitation: Th 1030am
*   Guogui Ding
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include<vector>

#include "Graph.h"
using namespace std;

// The constructor will read in the the file and build the 
Graph::Graph(char *file){
    string line;
    string city;
    string Edges;
    string edge;

    ifstream inFile(file);
    ifstream infile(file);
    getline( inFile, line );
    stringstream vert(line);
    // Build the vector of vertex structs.
    int id = 0;
    while( getline( vert, city, ',' ) ){
        // skip the cities label at the start of the line.
        if( city == "cities" ){
            id++;
            continue;
        }
        vertex City;
        City.name = city;
        City.ID = id;
        // Loop through matrix lines and find the edges for City.
        int j = 0;
        while( getline( infile, Edges ) ){
            // parse the line to translate the edge values into the adjVertex
            // vector.
            stringstream edges(Edges);
            int i = 0;
            string cityedge;
            while( getline( edges, edge, ',' ) ){
                if( i ==0 ){
                    cityedge = edge;
                }
                if( i != id ){
                    i++;
                    continue;
                }
                int ed;
                stringstream eds(edge);
                eds >> ed;
                if( ed >=0 ){
                    adjVertex tmp;
                    tmp.weight = ed;
                    //tmp.v->name = cityedge;
                    //tmp.v->ID = j+1; // +1 to comp for first line in file.
                    cout<<City.name<<' '<<cityedge<<' '<<ed<<endl;
                    City.adj.push_back(tmp);
                }
                i++;
            }
            j++;
        }
        vertices.push_back(City);
        //cout<<vertices[id-1].name<<endl;
        //cout<<vertices[id-1].adj[0].weight<<endl;
        id++;
    }
    //cout<<vertices[1].adj[0].weight<<endl;
    //cout<<vertices[1].adj[1].weight<<endl;
}


Graph::~Graph(){
}


void Graph::addEdge(std::string v1, std::string v2, int weight){
}


void Graph::addVertex(std::string name){
}


void Graph::displayEdges(){
}


void Graph::assignDistricts(){
}


void Graph::shortestPath(std::string startingCity, std::string endingCity){
}


//call this from within assignDistricts to label the districts.
//This method should implement a breadth first traversal from the startingCity
//and assign all cities encountered the distID value
void Graph::BFTraversalLabel(std::string startingCity, int distID){
}
