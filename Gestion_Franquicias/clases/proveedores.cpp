#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include "proveedores.h"

void proveedore::Cargar_Proveedore(){
    cout<<"Nombre del proveedor: ";
    cin.getline(Nombre, 50, '\n');
        while(Nombre[0]==' '){///validando el nombre que el primer caracter no sea un espacio
            cout<<endl<<"Nombre incorrecta, reingrese el Nombre"<<endl<<endl;
            cout<<">> Ingrese el Nombre: ";
            cin.getline(Nombre, 50, '\n');
        }
    cout<<"ID del producto vendido: ";///con memoria dinamica
    ///falta esta parte
    cout<<"Numero de telefono: ";
    cin>>Telefono;
        while(ID<1000000000){ ///validando telefono que no sea menor a 10 0000 0000
            cout<<endl<<"telefono incorrecta, reingrese el telefono"<<endl<<endl;
            cout<<">> Ingrese el telefono: ";
            cin>>Telefono;
        }
    cout<<"descripcion del proveedor: ";
    cin.ignore();
    cin.getline(Nota, 200, '\n');
        while(Nota[0]==' '){///validando la nota que el primer caracter no sea un espacio
            cout<<endl<<"Nota incorrecta, reingrese el Nota"<<endl<<endl;
            cout<<">> Ingrese el Nota: ";
            cin.getline(Nota, 200, '\n');
        }
}

bool proveedore::Guardar_Proveedore(){
    bool grabo;
    FILE *p=fopen("archivos/Proveedores.dat","ab");
    if(p==NULL){
        return false;
    }
    grabo=fwrite(this, sizeof(proveedore),1,p);
    fclose(p);
return grabo;
}
