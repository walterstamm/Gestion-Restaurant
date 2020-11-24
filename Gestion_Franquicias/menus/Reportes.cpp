#include <iostream>
#include <cstdlib> ///system

using namespace std;
#include <map>///para clase vector con indice
#include "../InterfazGrafica/ui.h"
#include "../clases/Producto.h"

void Menu_Reportess(){
    short opcion;
    do{
        title("MENU REPORTES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<endl<<"---------------------------"<<endl;
        cout<<endl<<"1) REPORTES VERDES........."<<endl;
        cout<<endl<<"2) REPORTES AMARILLOS......"<<endl;
        cout<<endl<<"3) REPORTES ROJOS.........."<<endl;
        cout<<endl<<"4) SALIR..................."<<endl;
        cout<<endl<<"---------------------------"<<endl;
        cout<<endl<<"\t OPCION: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            //Reporte_Verde();
        break;
        case 2:
            //Reporte_Amarillos();
        break;
        case 3:
            //Reporte_Rojos();
        break;
        case 4:
        break;
        default:
            msj("OPCIÓN INCORRECTA", 15, 4, 15, 1);
        break;
        }
    system("pause");
    system ("cls");
    }while (opcion!=4);
}

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

