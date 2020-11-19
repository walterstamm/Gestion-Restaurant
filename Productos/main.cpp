#include <iostream>
using namespace std;

#include <map>///para clase vector

#include "Producto.h"

int main(){
    Producto uno;

    int pos=0;
    std::map<int, int> vex;
    while(uno.LeerPos(pos)){
        vex[uno.getID()-1]+=uno.getCantidad();
        pos++;
    }
    for(int x=0;x<pos;x++){
        cout<<vex[x]<<endl;
    }
    cout<<endl<<vex.size();///tamaño del vector.
return 0;
}
