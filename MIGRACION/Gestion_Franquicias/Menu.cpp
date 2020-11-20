#include <iostream>
using namespace std;
#include "Interfaz_Grafica/ui.h"
#include "Menu.h"
#include "Sub_Menus/Sub_Producto.h"

#include "Funciones/Fun_Reportes.h"///caso especial
#include "Interfaz_Grafica/rlutil.h"
using namespace rlutil;

void Menu_Compra(){
}

void Menu_Venta(){
    short opcion;
    do{
        title("MENU VENTAS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<endl<<"---------------------------"<<endl;
        cout<<endl<<"1) MENU PRODUCTO..........."<<endl;
        cout<<endl<<"2) MENU PROVEEDOR.........."<<endl;
        cout<<endl<<"3) MENU PEDIDOS............"<<endl;
        cout<<endl<<"4) SALIR..................."<<endl;
        cout<<endl<<"---------------------------"<<endl;
        cout<<endl<<"\t OPCION: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            Sub_Producto();
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        default:
            msj("OPCIÓN INCORRECTA", 15, 4, 15, 1);
        break;
        }
    }while (opcion!=4);
}

void Menu_Facturacion(){
}

void Menu_Reportes(){
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
            Reporte_Verde();
        break;
        case 2:
            Reporte_Amarillos();
        break;
        case 3:
            Reporte_Rojos();
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
