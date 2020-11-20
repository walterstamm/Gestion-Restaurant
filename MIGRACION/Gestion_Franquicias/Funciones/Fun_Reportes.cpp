#include <iostream>
using namespace std;
#include "../clases/Producto.h"
#include <map>///para clase vector con indice
#include "../Interfaz_Grafica/rlutil.h"
using namespace rlutil;

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
        int porcentaje=vexProducto[x].getCantidad_Minima()+(vexProducto[x].getCantidad_Minima()/2);
        if(porcentaje<vexProducto[x].getCantidad() && vexProducto[x].getEstado()==true){
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
        int porcentaje=vexProducto[x].getCantidad_Minima()+(vexProducto[x].getCantidad_Minima()/2);
        if(porcentaje>=vexProducto[x].getCantidad() && vexCant_Max[x]>vexProducto[x].getCantidad_Minima() && vexProducto[x].getEstado()==true){
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
        if (vexCant_Max[x]<=vexProducto[x].getCantidad_Minima() && vexProducto[x].getEstado()==true){
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
        if (vexCant_Max[x]<=vexProducto[x].getCantidad_Minima() && vexProducto[x].getEstado()==true){
            ///los que estan en rojo
            setColor(RED);
            cout<<"*";
            setBackgroundColor(WHITE);
            return;
        }
        int porcentaje=vexProducto[x].getCantidad_Minima()+(vexProducto[x].getCantidad_Minima()/2);
        if(porcentaje>=vexProducto[x].getCantidad() && vexCant_Max[x]>vexProducto[x].getCantidad_Minima() && vexProducto[x].getEstado()==true){
            ///alerta amarilla
            setBackgroundColor(YELLOW);
            cout<<"*";
            setBackgroundColor(WHITE);
            return;
        }
        if(porcentaje<vexProducto[x].getCantidad() && vexProducto[x].getEstado()==true){
            ///alerta verde
            setColor(GREEN);
            cout<<"*";
            setBackgroundColor(WHITE);
            return;
        }
    }
}
