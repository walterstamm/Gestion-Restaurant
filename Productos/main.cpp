#include <iostream>
using namespace std;

#include <map>///para clase vector

#include "Producto.h"


int main(){
    Producto uno;
    int pos=0;
    std::map<int, int> vexCant_Max;
    std::map<int, Producto> vexProducto;
    while(uno.LeerPos(pos)){
        vexCant_Max[uno.getID()-1]+=uno.getCantidad();
        vexProducto[uno.getID()-1]=uno;
        pos++;
    }
    for(int x=0;x<pos;x++){
        if (vexCant_Max[x]>=vexProducto[x].getCantidad_Minima()){
            ///los que estan en rojo
            ///Falta listar
            return 0;
        }
        int porcentaje=(vexProducto[x].getCantidad_Minima()*100)/150;
        if(porcentaje>=vexProducto[x].getCantidad_Minima() && vexCant_Max[x]<vexProducto[x].getCantidad_Minima()){
            ///alerta amarilla
            ///falta listar
            return 0;
        }
        if(porcentaje<vexProducto[x].getCantidad_Minima()){
            ///alerta verde
            ///falta listar
            return 0;
        }
    }





    cout<<endl<<vexCant_Max.size();///tamaño del vector.
return 0;
}
