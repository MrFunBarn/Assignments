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
    getline( inFile, line );
    stringstream vert(line);
    // Build the vector of vertex structs.
    while( getline( vert, city, ',' ) ){
        // skip the cities label at the start of the line.
        if( city == "cities" ){
            continue;
        }
        addVertex(city);
    }
    // Loop through matrix lines and find the edges for City.
    while( getline( inFile, Edges ) ){
        // parse the line to translate the edge values into the adjVertex
        // vector.
        stringstream edges(Edges);
        int i = 0;
        string cityedge;
        while( getline( edges, edge, ',' ) ){
            // grab the name of the city on the start of this row.
            if( i ==0 ){
                cityedge = edge;
            }
            else{
                // convert weight to int.
                int ed;
                stringstream eds(edge);
                eds >> ed;
                // only grab edges with weights > than 0.
                if( ed > 0 ){
                    addEdge(cityedge,vertices[i-1].name,ed);
                }
            }
            i++;
        }
    }
    int x = 14;
    int y = 2;
    cout<<vertices[x].name<<' '<<vertices[x].adj[y].v->name<<' '<<vertices[x].adj[y].weight<<endl;
}


Graph::~Graph(){
}


void Graph::addEdge(std::string v1, std::string v2, int weight){
    for( int i=0; i < vertices.size(); i++ ){
        if( vertices[i].name == v1 ){
            for( int j=0; j < vertices.size(); j++ ){
                if( vertices[j].name == v2 && i != j ){
                    adjVertex tmp;
                    tmp.v = &vertices[j];
                    tmp.weight = weight;
                    vertices[i].adj.push_back(tmp);
                }
            }
        }
    }
}


void Graph::addVertex(std::string name){
    bool found = false;
    for( int i=0; i < vertices.size(); i++ ){
        if( vertices[i].name == name ){
            found = true;
            break;
        }
    }
    if( found == false ){
        vertex City;
        City.name = name;
        vertices.push_back(City);
    }
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
