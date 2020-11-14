#include <iostream>
using namespace std;
#include "Interfaz_Grafica/ui.h"
#include "Menu.h"
#include "Sub_Menus/Sub_Producto.h"

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
