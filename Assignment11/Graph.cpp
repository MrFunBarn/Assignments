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
#include <vector>
#include <queue>
#include <stack>

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
    //int x = 14;
    //int y = 2;
    //cout<<vertices[x].name<<' '<<vertices[x].adj[y].v->name<<' '<<vertices[x].adj[y].weight<<endl;
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
        City.visited = false;
        City.district = -1;
        vertices.push_back(City);
    }
}


void Graph::displayEdges(){
    for( int i=0; i<vertices.size(); i++ ){
        cout<<vertices[i].district<<':'<<vertices[i].name<<"-->";
        for( int j=0; j<vertices[i].adj.size(); j++ ){
            cout<<vertices[i].adj[j].v->name;
            if( j != vertices[i].adj.size()-1 ){
                cout<<"***";
            }
        }
        cout<<endl;
    }
}


void Graph::assignDistricts(){
    // Reset all visited values to false in case the graph has changed.
    for( int i=0; i<vertices.size(); i++ )
    {
        vertices[i].visited = false;
        for( int j=0; j<vertices[i].adj.size(); j++ )
        {
            vertices[i].adj[j].v->visited = false;
        }
    }
    int ID = 1;
    for( int i=0; i < vertices.size(); i++ ){
        if( vertices[i].visited == false ){
            BFTraversalLabel( vertices[i].name, ID );
            ID++;
        }
    }
}


void Graph::shortestPath(std::string startingCity, std::string endingCity){
    vertex *v1;
    vertex *v2;
    bool f1 = false;
    bool f2 = false;
    // Reset visited to false for the tree for the next bredth first search
    // algorythm.
    for( int i=0; i<vertices.size(); i++ )
    {
        vertices[i].visited = false;
        for( int j=0; j<vertices[i].adj.size(); j++ )
        {
            vertices[i].adj[j].v->visited = false;
        }
    }
    // serach for the starting and ending vertexes.
    for( int i=0; i<vertices.size(); i++ ){
        if( vertices[i].name == startingCity ){
            v1 = &vertices[i];
            f1 = true;
        }
        if( vertices[i].name == endingCity ){
            v2 = &vertices[i];
            f2 = true;
        }
    }
    if( f1 == false || f2 == false ){
        cout<<"One or more cities doesn't exist"<<endl;
        return;
    }
    if( v1->district != v2->district ){
        cout<<"No safe path between cities"<<endl;
        return;
    }
    if( v1->district == 0 ){
        cout<<"Please identify the districts before checking distances"<<endl;
        return;
    }
    // Find shortest distance.
    v1->visited = true;
    v1->distance = 0;
    queue<vertex *> dist;
    dist.push(v1);
    vertex *n;
    while( !dist.empty() )
    {
       n = dist.front();
       dist.pop();
       for( int i=0; i < n->adj.size(); i++ )
       {
           if( !n->adj[i].v->visited )
           {
               n->adj[i].v->distance = n->distance + n->adj[i].weight;
               n->adj[i].v->visited = true;
               dist.push(n->adj[i].v);
               if( i == 0 )
               {
                  n->adj[i].v->parent = n;
               }
               else
               {
                   //n->adj[i].v->parent = n->adj[i-1].v;
                    n->adj[i].v->parent = dist.front()->parent;
               }
           }
       }
    }
    stack<vertex *> path;
    int x = 0;
    vertex *tmp = v2;
    if( v2->parent->name != v1->name)
    {
        //v2 = v2->parent->parent;
    }
    while( v2->name != v1->name )
    {
        //if( x=0 ) {v2 = v2->parent;x++;}
        path.push(v2);
        v2 = v2->parent;
    }
    cout<<path.size()<<','<<v1->name;
    while( !path.empty() )
    {
        cout<<','<<path.top()->name;
        path.pop();
    }
    cout<<','<<tmp->name<<endl;
}


//call this from within assignDistricts to label the districts.
//This method should implement a breadth first traversal from the startingCity
//and assign all cities encountered the distID value
void Graph::BFTraversalLabel(std::string startingCity, int distID){
    vertex *city;
    vertex *n;
    queue<vertex *>  beenTo;
    for( int i=0; i<vertices.size(); i++ ){
        if( vertices[i].name == startingCity ){
            city = &vertices[i];
        }
    }
    city->visited = true;
    city->district = distID;
    beenTo.push(city);
    while(!beenTo.empty()){
        n = beenTo.front(); // front gets referance.
        beenTo.pop();       // pop removes same elem from que.
        for( int i=0; i<n->adj.size(); i++ ){
            if( !n->adj[i].v->visited ){
                n->adj[i].v->visited = true;
                n->adj[i].v->district = distID;
                beenTo.push(n->adj[i].v);
            }
        }
    }
}
