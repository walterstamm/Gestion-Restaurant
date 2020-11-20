#include <iostream>
using namespace std;
#include "../clases/Producto.h"
#include <map>///para clase vector con indice

void Reporte_Verde(){
    Producto uno;
    int pos=0;
    std::map<int, int> vexCant_Max;
    std::map<int, Producto> vexProducto;
    while(uno.LeerPos(pos)){
        vexCant_Max[uno.getID()-1]+=uno.getCantidad();
        vexProducto[uno.getID()-1]=uno;
        pos++;
    }
    uno.Encabezado_Alerta();
    for(int x=0;x<pos;x++){
        int porcentaje=(vexProducto[x].getCantidad_Minima()*100)/150;
        if(porcentaje<vexProducto[x].getCantidad_Minima() && vexProducto[x].getEstado()==true){
            ///alerta verde
            vexProducto[x].Mostrar_Alerta();
            cout<<endl;
        }
    }
    cout<<endl<<endl;
}

void Reporte_Amarillos(){
    Producto uno;
    int pos=0;
    std::map<int, int> vexCant_Max;
    std::map<int, Producto> vexProducto;
    while(uno.LeerPos(pos)){
        vexCant_Max[uno.getID()-1]+=uno.getCantidad();
        vexProducto[uno.getID()-1]=uno;
        pos++;
    }
    uno.Encabezado_Alerta();
    for(int x=0;x<pos;x++){
        int porcentaje=(vexProducto[x].getCantidad_Minima()*100)/150;
        if(porcentaje>=vexProducto[x].getCantidad_Minima() && vexCant_Max[x]<vexProducto[x].getCantidad_Minima() && vexProducto[x].getEstado()==true){
            ///alerta amarilla
            vexProducto[x].Mostrar_Alerta();
            cout<<endl;
        }
    }
    cout<<endl<<endl;
}

void Reporte_Rojos(){
    Producto uno;
    int pos=0;
    std::map<int, int> vexCant_Max;
    std::map<int, Producto> vexProducto;
    while(uno.LeerPos(pos)){
        vexCant_Max[uno.getID()-1]+=uno.getCantidad();
        vexProducto[uno.getID()-1]=uno;
        pos++;
    }
    uno.Encabezado_Alerta();
    for(int x=0;x<pos;x++){
        if (vexCant_Max[x]>=vexProducto[x].getCantidad_Minima() && vexProducto[x].getEstado()==true){
            ///los que estan en rojo
            vexProducto[x].Mostrar_Alerta();
            cout<<endl;
        }
    }
    cout<<endl<<endl;
}

void Alerta_Reportes(){
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
        if (vexCant_Max[x]>=vexProducto[x].getCantidad_Minima() && vexProducto[x].getEstado()==true){
            ///los que estan en rojo
            cout<<"*";
            return;
        }
        int porcentaje=(vexProducto[x].getCantidad_Minima()*100)/150;
        if(porcentaje>=vexProducto[x].getCantidad_Minima() && vexCant_Max[x]<vexProducto[x].getCantidad_Minima() && vexProducto[x].getEstado()==true){
            ///alerta amarilla
            cout<<"*";
            return;
        }
        if(porcentaje<vexProducto[x].getCantidad_Minima() && vexProducto[x].getEstado()==true){
            ///alerta verde
            cout<<"*";
            return;
        }
    }
}
