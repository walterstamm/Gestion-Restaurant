#include<iostream>
#include<cstdlib>
#include "Menu_Pedidos.h"
using namespace std;

void Menu_Pedidos(){
    int opcion;
    while(true){
        cout<<"\t USUARIOS";
        cout<<endl<<"---------------------------";
        cout<<endl<<"1) Carga de Provedores";
        cout<<endl<<"2) Generar Pedidos";
        cout<<endl<<"3) Pedidos pendientes de Recepcion";
        cout<<endl<<"4) Lista de Proveedores";
        cout<<endl<<"0) SALIR";
        cout<<endl<<"---------------------------";
        cout<<endl<<"\t opcion: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            Carga_Provedores();
        break;
        case 2:

        break;
        case 3:

        break;
        case 4:
            break;
        case 0:
            return;
        default:
            cout<<endl<<"\t Opcion incorrecta"<<endl<<endl;
            system ("pause");
            system ("cls");
        break;
        }
    }
}
