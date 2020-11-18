#include <iostream>
using namespace std;

#include <vector>///para clase vector

#include "Producto.h"

int main(){
    Producto uno;
    int ID, pos=0;
    cout<<"ID del producto: ";
    cin>>ID;
    if(ID<0 && ValidarID_Producto(ID)==true){
        ///msj("ID incorrecto", 15, 3, 1, 1);
        return 0;
    }
    while(uno.LeerPos(pos++)){
        if(uno.getIDLote()==true && uno.getID()==true && uno.getID()==ID){
            uno.Mostrar();
        }
    }
return 0;
}
