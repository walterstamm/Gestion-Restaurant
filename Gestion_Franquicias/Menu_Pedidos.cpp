#include<iostream>
#include<cstdlib>
#include<cstdio>
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
        cout<<endl<<"4) Modificar Provedores(dar baja a proveedor)";
        cout<<endl<<"5) Lista de Proveedores";
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
            DarBajaProveedor();
            break;
        case 5:
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
        system("cls");
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


bool ValidarIDProveedores(int _ID){
    proveedore reg;
    FILE *p=fopen("archivos/Proveedores.dat","rb");
    if(p==NULL){
        cout<<"Error";
        system("pause");
        return false;
    }
    while(fread(&reg,sizeof(proveedore),1,p)){
        if(_ID==reg.getID()){
            fclose(p);
            return false;
        }
    }
    fclose(p);
    return true;
}


void DarBajaProveedor(){
    int ID,Telefono;
    bool validacion;
    char respuesta,Nombres[50],Nota[200];
    proveedore reg;
    system("cls");
    cout<<"Ingrese el ID a modificar: "<<endl;
    cin>>ID;


    BuscarID(&reg,ID);
    if(reg.getID()!=ID){
        return;
    }
    cout<<"Veo que muestra el Estado"<<endl;
    cout<<"reg.getNombre()  "<<reg.getNombre()<<endl;
    cout<<"reg.getEstado()  "<<reg.getEstado();
    system("pause");
    system("pause");

    cout<<"Desea dar de baja a este Proveedor?(S/N)"<<endl;
    cin>>respuesta;
    if(respuesta=='s'||respuesta=='S'){
        reg.setEstado(false); ///puse este set estado que faltaba
        if(reg.Guardar_Cambios()){
        cout<<"Se dio de baja con exito!";
        system("pause");
        return;
    }
    cout<<endl<<"No se puedo guardar los cambios";
    system("pause");
    return;
    }

    reg.Listar_Proveedores();
    cout<<endl<<"Modificar el Nombre?(S/N)";
    cin>>respuesta;
    if(respuesta=='s'||respuesta=='S'){
        cout<<"Nombre del proveedor: ";
    cin.ignore();
    cin.getline(Nombres, 50, '\n');
        while(Nombres[0]==' '){///validando el nombre que el primer caracter no sea un espacio
            cout<<endl<<"Nombre incorrecta, reingrese el Nombre"<<endl<<endl;
            cout<<">> Ingrese el Nombre: ";
            cin.getline(Nombres, 50, '\n');
        }
        reg.setNombre(Nombres);
    }
    cout<<endl<<"Modificar numero de telefono?(S/N)";
    cin>>respuesta;
    if(respuesta=='s'||respuesta=='S'){
        cin>>Telefono;
        while(Telefono<1000000000){ ///validando telefono que no sea menor a 10 0000 0000
            cout<<endl<<"telefono incorrecta, reingrese el telefono"<<endl<<endl;
            cout<<">> Ingrese el telefono: ";
            cin>>Telefono;
        }
        reg.setTelefono(Telefono);
    }

    cout<<endl<<"Modificar la descripcion? S/N ";
    cin>>respuesta;
    if(respuesta=='s'||respuesta=='S'){
        cout<<"Descripcion del Proveedor: ";
        cin.ignore();
        cin.getline(Nota, 200, '\n');
        while(Nota[0]==' '){///validando la nota que el primer caracter no sea un espacio
            cout<<endl<<"Nota incorrecta, reingrese el Nota"<<endl<<endl;
            cout<<">> Ingrese el Nota: ";
            cin.getline(Nota, 200, '\n');
        }
        reg.setNota(Nota);
    }
    cout<<endl<<endl;
    reg.Listar_Proveedores();
    cout<<endl<<endl;
    validacion=reg.Guardar_Cambios();
    if(validacion){
        cout<<"Se guardaron los cambion con exito!";
        system("pause");
        return;
    }
    cout<<endl<<"No se puedo guardar los cambios";
    system("pause");
}



void BuscarID(proveedore *registro,int id){

    FILE *p=fopen("archivos/Proveedores.dat","rb");
    if(p==NULL){
        cout<<"Error";
        system("pause");
        return;
    }

    while(fread(registro,sizeof(proveedore),1,p)){
        if(id==registro->getID()){
            fclose(p);
            return;
        }
    }
    cout<<"No se encontro ese ID..."<<endl;
    fclose(p);
}
