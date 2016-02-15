#include <iostream>
#include <string>
using namespace std;

struct Fruit{
  string name;
  int price;
};

void Printnames( Fruit array[], int size, int Realprice ){
    for( int i=0; i<size; i++ ){
        if( array[i].price < Realprice ){
            cout << array[i].name << endl;
        }
    }
}

int main(){
    Fruit x[2];
    x[0].name = "one";
    x[0].price = 1;
    x[1].name = "two";
    x[1].price = 2;

    int size = 1;
    int p = 2;

    Printnames(x, size, p);
}
