#include<iostream>
#include<cstdlib>
#include<cstdio>
#include "Menu_Pedidos.h"
#include "clases/proveedores.h"
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
            Mostrar_Proveedores();
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

void Carga_Provedores(){
    proveedore provedor;
    bool Valido;
    provedor.Cargar_Proveedore();
    Valido=provedor.Guardar_Proveedore();
    if(Valido){
        cout<<endl<<"Se ha guardado exitosamente el nuevo Proveedor";
        system("pause");
        return;
    }
    cout<<endl<<"No se ha podido guardar....";
    system("pause");
}


void Mostrar_Proveedores(){
    proveedore reg;
    FILE *Registros=fopen("archivos/Proveedores.dat","rb");
    if(Registros==NULL){
        cout<<"Error al abrir registro";
        system("pause");
        return;
    }
    while(fread(&reg,sizeof(proveedore),1,Registros)){
    reg.Listar_Proveedores();
    }
    system("pause");
    system("cls");
}
