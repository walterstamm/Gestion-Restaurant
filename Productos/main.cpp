#include <iostream>
using namespace std;
#include <vector>
#include "Producto.h"

int main(){
    Producto uno;
    int ID, pos=0;
    float Precio;
    while(uno.LeerPos(pos++)){
        uno.Mostrar();
    }
    vector <int> vpos;
    cout<<"ID del producto: ";
    cin>>ID;
    if(ID<0 && ValidarID_Producto(ID)==true){
        ///msj("ID incorrecto", 15, 3, 1, 1);
        return 0;
    }
    pos=0;
    while(uno.LeerPos(pos)){
        if(uno.getIDLote()==ID){
            vpos.push_back(pos);
        }
        pos++;
    }
    uno.LeerPos(vpos[0]);
    cout<<"Ingrese el precio: ";
    cin>>Precio;
    if(Precio<0){
        cout<<"Error precio negativo";
        return 0;
    }
    for(int x=0;x<vpos.size();x++){
        uno.setPrecio(Precio);
        uno.Modificar(vpos[x]);
    }

return 0;
}
