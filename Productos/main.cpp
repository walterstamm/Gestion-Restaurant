#include <iostream>
using namespace std;

#include <vector>///para clase vector

#include "Producto.h"

int main(){
    Producto aux;
    int pos=0;
    vector <Producto> vex;
    while(aux.LeerPos(pos)){
        vex.push_back(aux);
        pos++;
    }
    //ordenamos
    int posmin;
    for(int x=0; x<pos; x++){
        posmin=x;
        for(int y=x+1; y<pos; y++){
            if(vex[y].getIDLote()<vex[posmin].getIDLote()){
                posmin=y;
            }
        }
        aux=vex[x];
        vex[x]=vex[posmin];
        vex[posmin]=aux;
    }
    ///mostramos
    for(int x=0;x<pos;x++){
        vex[x].Mostrar();
    }
return 0;
}
