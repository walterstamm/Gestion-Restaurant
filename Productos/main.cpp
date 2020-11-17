#include <iostream>
using namespace std;
#include <vector>
#include "Producto.h"

int main(){
    int ID, pos=0;
    float Precio;
    vector <int> vnum;
    cout<<"ID del producto: ";
    cin>>ID;
    if(ID>0){
        ///msj("ID incorrecto", 15, 3, 1, 1);
        return 0;
    }
    Producto uno;
    while(uno.LeerPos(pos++)){
        if(uno.getIDLote()==ID){
            vnum.push_back(pos-1);
        }
    }
    if(vnum.size()==0)return 0;///si no encontro nada que retorne como falso
    if(uno.getEstado()==false){
        ///msj("Error archivo inexistente", 15, 3, 1, 1);
        return 0;
    }
    uno.LeerPos(pos);
    uno.Mostrar();
    cout<<"Ingrese el precio: $";
    cin>>Precio;
    while(Precio<0){ ///validando Cantidad que no sea negativo
        cout<<endl<<"precio incorrecta, reingrese el precio"<<endl<<endl;
        cout<<">> Ingrese el precio: $";
        cin>>Precio;
    }
    uno.setPrecio(Precio);
    for(int x=0;x<=vnum.size();x++){
        if(uno.Modificar(vnum.at(x))==false){
            ///msj("Error archivo no modificado", 15, 3, 1, 1);
            return 0;
        }
    }
    cout<<"Archivo modificado"<<endl;
return 0;
}
