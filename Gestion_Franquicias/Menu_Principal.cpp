#include <iostream>
using namespace std;
#include <cstdlib>
#include <clocale>
#include "Menu_Principal.h"
#include "InterfazGrafica/ui.h"
#include "Menu_Producto/Menu_Producto.h"
#include "Medio_Pago/Medio_Pago.h"
#include "menus/MenuDescuento.h"
#include "Clases/Comprobantes.h"

void MENU_PRODUCTO(){
    short opcion;
    do{
        title("MEN� PRODUCTO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<endl<<"--------------------------------------";
        cout<<endl<<"1) CARGAR PRODUCTO";
        cout<<endl<<"2) MODIFICAR CANTIDAD DEL PRODUCTOS";
        cout<<endl<<"3) MODIFICAR CANTIDAD MINIMA";
        cout<<endl<<"4) LISTAR TODOS LOS PRODUCTOS";
        cout<<endl<<"5) LISTAR PRODUCTO POR ID";
        cout<<endl<<"6) ELIMINAR PRODUCTO";
        cout<<endl<<"7) MODIFICAR PRECIO DEL PRODUCTO";
        cout<<endl<<"8) VOLVER AL MEN� PRINCIPAL";
        cout<<endl<<"9) VENDER";
        cout<<endl<<"--------------------------------------";
        cout<<endl<<"\t OPCI�N: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            Cargar_Producto();
            system("pause");
            system("cls");
        break;
        case 2:
            Modificar_Cantidad();
            system("pause");
            system("cls");
        break;
        case 3:
            Modificar_La_Cantidad_minima();
            system("pause");
            system("cls");
        break;
        case 4:
            Mostrar_Todos_Producto();
            system("pause");
            system("cls");
        break;
        case 5:
            Mostrar_X_Producto();
            system("pause");
            system("cls");
        break;
        case 6:
            Eliminar_Producto();
            system("pause");
            system("cls");
        break;
        case 7:
            Modificar_Precio();
            system("pause");
            system("cls");
        break;
        case 8:
        break;
        case 9:
            ventas();
            system("pause");
            system("cls");
        break;
        default:
            msj("OPCI�N INCORRECTA", 15, 3, 1, 1);
        break;
        }
    }while (opcion!=7);
}


void Menu_Medio_Pago(){
    short opcion;
    do{
        title("MEN� MEDIO PAGO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<endl<<"------------------------------------------";
        cout<<endl<<"1) CARGAR MEDIO PAGO";
        cout<<endl<<"2) ELIMINAR MEDIO DE PAGO";
        cout<<endl<<"3) LISTAR TODOS MEDIO DE PAGO";
        cout<<endl<<"5) LISTAR X MEDIO DE PAGO";
        cout<<endl<<"6) MODIFICAR MEDIO DE PAGO";
        cout<<endl<<"7) VOLVER AL MEN� PRINCIPAL";
        cout<<endl<<"------------------------------------------";
        cout<<endl<<"\t OPCI�N: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            Cargar_Medio_pago();
            system ("pause");
            system ("cls");
        break;
        case 2:
            Eliminar_Mpago();
            system ("pause");
            system ("cls");
        break;
        case 3:
            Mostar_TodosMpago();
            system ("pause");
            system ("cls");
        break;
        case 4:
            Mostar_TodosMpago();
            system ("pause");
            system ("cls");
        break;
        case 5:
            Mostrar_X_Mpago();
            system ("pause");
            system ("cls");
        break;
        case 6:
            Modificar_Mpago();
            system ("pause");
            system ("cls");
        break;
        case 7:
        break;
        default:
            msj("OPCI�N INCORRECTA", 15, 3, 1, 1);
        break;
        }
    }while (opcion!=7);
}

void Menu_Descuento(){
    short opcion;
    do{
        title("MEN� DESCUENTO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<endl<<"------------------------------------------";
        cout<<endl<<"1) CARGAR DESCUENTO";
        cout<<endl<<"2) ELIMINAR DESCUENTO";
        cout<<endl<<"3) LISTAR TODOS LOS DESCUENTOS";
        cout<<endl<<"4) LISTAR DESCUENTOS POR ID";
        cout<<endl<<"5) MODIFICAR DESCUENTO";
        cout<<endl<<"6) VOLVER AL MEN� PRINCIPAL";
        cout<<endl<<"------------------------------------------";
        cout<<endl<<"\t OPCI�N: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            CargarDescuento();
            system ("pause");
            system ("cls");
        break;
        case 2:
            ModificarEstadoDescuento();
            system ("pause");
            system ("cls");
        break;
        case 3:
            ListarTodosDescuento();
            system ("pause");
            system ("cls");
        break;
        case 4:
            Mostrar_x_Descuento();
            system ("pause");
            system ("cls");
        break;
        case 5:
            ModificarDescuento();
            system ("pause");
            system ("cls");
        break;
        case 6:
        break;
        default:
            msj("OPCI�N INCORRECTA", 15, 3, 1, 1);
        break;
        }
    }while (opcion!=6);
}

