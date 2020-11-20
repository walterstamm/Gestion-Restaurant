#include <iostream>
using namespace std;
#include "Interfaz_Grafica/ui.h"
#include "Menu.h"

int main(){
    short opcion;
    do{
        title("MENU PRINCIPAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        system ("cls");
        title("MENU PRINCIPAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<endl<<"---------------------"<<endl;
        cout<<endl<<"1) COMPRA............"<<endl;
        cout<<endl<<"2) VENTAS............"<<endl;
        cout<<endl<<"3) FACTURACION......."<<endl;
        cout<<endl<<"4) REPORTES.........."<<endl;
        cout<<endl<<"5) SALIR............."<<endl;
        cout<<endl<<"---------------------"<<endl;
        cout<<endl<<"\t OPCION: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            Menu_Compra();
        break;
        case 2:
            Menu_Venta();
        break;
        case 3:
            Menu_Facturacion();
        break;
        case 4:
            Menu_Reportes();
        break;
        case 5:
        break;
        default:
            msj("OPCIÓN INCORRECTA", 15, 4, 15, 1);
        break;
        }
    }while (opcion!=4);
return 0;
}
