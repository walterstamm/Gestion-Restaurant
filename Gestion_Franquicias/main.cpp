#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <clocale>
#include <iostream>
using namespace std;
#include "InterfazGrafica/ui.h"
#include "Menu_Principal.h"

int main(){
    setlocale(LC_ALL, "spanish");

    short opcion;
    do{
        title("MEN�", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        system ("cls");
        title("MEN�", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<endl<<"---------------------------";
        cout<<endl<<"1) MEN� PRODUCTO";
        cout<<endl<<"2) MEN� PROVEDORES";
        cout<<endl<<"3) MEN� FACTURACION";
        cout<<endl<<"4) MEN� STOCK";
        cout<<endl<<"5) MEN� MEDIOS PAGO";
        cout<<endl<<"7) SALIR DEL PROGRAMA";
        cout<<endl<<"---------------------------";
        cout<<endl<<"\t OPCI�N: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            MENU_PRODUCTO();
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
            Menu_Medio_Pago();
        break;
        case 6:
        break;
        case 7:
        break;
        default:
            msj("OPCI�N INCORRECTA", 15, 3, 1, 1);
        break;
        }
    }while (opcion!=7);
return 0;
}
