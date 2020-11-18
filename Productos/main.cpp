#include <iostream>
using namespace std;

#include <vector>///para clase vector

#include "Producto.h"

int main(){
    Producto uno;
    int pos=0;
    vector <int> vex(0);
    while(uno.LeerPos(pos)){
        vex[uno.getIDLote()]+=uno.getCantidad();
        pos++;
    }
    for(int x=0;x<pos;x++){
        cout<<vex[x]<<endl;
    }
return 0;
}
