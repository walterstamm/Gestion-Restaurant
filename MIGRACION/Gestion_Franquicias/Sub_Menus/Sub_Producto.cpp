#include <iostream>
using namespace std;
#include "Sub_Producto.h"
#include "../Interfaz_Grafica/ui.h"
#include "../Funciones/Fun_Producto.h"

void Sub_Producto(){
    short opcion;
    do{
        title("MENU PRODUCTO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<endl<<"---------------------------------------"<<endl;
        cout<<endl<<"1) CARGAR PRODUCTO....................."<<endl;
        cout<<endl<<"2) LISTAR TODOS LOS PRODUCTOS.........."<<endl;
        cout<<endl<<"3) LISTAR PRODUCTO POR ID.............."<<endl;
        cout<<endl<<"4) MODIFICAR PRECIO DEL PRODUCTO......."<<endl;
        cout<<endl<<"5) MODIFICAR CANTIDAD DEL PRODUCTOS...."<<endl;
        cout<<endl<<"6) MODIFICAR CANTIDAD MINIMA..........."<<endl;
        cout<<endl<<"7) ELIMINAR PRODUCTO..................."<<endl;
        cout<<endl<<"8) VOLVER AL MENU COMPRA..............."<<endl;
        cout<<endl<<"---------------------------------------"<<endl;
        cout<<endl<<"\t OPCION: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            Cargar_Producto();
            system("pause");
            system("cls");
        break;
        case 2:
            Listar_Todos_Productos();
            system("pause");
            system("cls");
        break;
        case 3:
            Listar_Producto_ID();
            system("pause");
            system("cls");
        break;
        case 4:
            Modificar_Precio_Producto();
            system("pause");
            system("cls");
        break;
        case 5:
            Modificar_Cantidad_Producto();
            system("pause");
            system("cls");
        break;
        case 6:
            Modificar_CantidadMin_Producto();
            system("pause");
            system("cls");
        break;
        case 7:
            Eliminar_Producto();
            system("pause");
            system("cls");
        break;
        case 8:
        break;
        default:
            msj("OPCIÓN INCORRECTA", 15, 3, 1, 1);
        break;
        }
    }while (opcion!=7);
}
