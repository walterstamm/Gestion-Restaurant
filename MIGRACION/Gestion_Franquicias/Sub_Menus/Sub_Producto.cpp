#include <iostream>
using namespace std;
#include "Sub_Producto.h"
#include "../Interfaz_Grafica/ui.h"

void Sub_Producto(){
    short opcion;
    do{
        title("MENÚ PRODUCTO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<endl<<"--------------------------------------";
        cout<<endl<<"1) CARGAR PRODUCTO";
        cout<<endl<<"2) MODIFICAR CANTIDAD DEL PRODUCTOS";
        cout<<endl<<"3) MODIFICAR CANTIDAD MINIMA";
        cout<<endl<<"4) LISTAR TODOS LOS PRODUCTOS";
        cout<<endl<<"5) LISTAR PRODUCTO POR ID";
        cout<<endl<<"6) ELIMINAR PRODUCTO";
        cout<<endl<<"7) MODIFICAR PRECIO DEL PRODUCTO";
        cout<<endl<<"8) VOLVER AL MENÚ PRINCIPAL";
        cout<<endl<<"9) VENDER";
        cout<<endl<<"--------------------------------------";
        cout<<endl<<"\t OPCIÓN: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:

            system("pause");
            system("cls");
        break;
        case 2:

            system("pause");
            system("cls");
        break;
        case 3:

            system("pause");
            system("cls");
        break;
        case 4:

            system("pause");
            system("cls");
        break;
        case 5:

            system("pause");
            system("cls");
        break;
        case 6:

            system("pause");
            system("cls");
        break;
        case 7:

            system("pause");
            system("cls");
        break;
        case 8:
        break;
        case 9:

            system("pause");
            system("cls");
        break;
        default:
            msj("OPCIÓN INCORRECTA", 15, 3, 1, 1);
        break;
        }
    }while (opcion!=7);
}
