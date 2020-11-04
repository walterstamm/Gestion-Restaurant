#include <iostream>
using namespace std;
#include<cstdlib>
#include <cstring>
#include <cstdio>
#include "proveedores.h"

void proveedore::Cargar_Proveedore(){
    cout<<"Ingrese ID: ";
    cin>>ID;
    while(ID<0 /*|| ValidarIDProveedores(ID)*/){ ///Comente validar ID porque no se bien que pasa intente descular el error y no se
        cout<<endl<<"ID invalido, reingrese ID: ";
        cin>>ID;
    }

    cout<<"Nombre del proveedor: ";
    cin.ignore();
    cin.getline(Nombre, 50, '\n');
        while(Nombre[0]==' '){///validando el nombre que el primer caracter no sea un espacio
            cout<<endl<<"Nombre incorrecta, reingrese el Nombre"<<endl<<endl;
            cout<<">> Ingrese el Nombre: ";
            cin.getline(Nombre, 50, '\n');
        }
        cout<<"Numero de telefono: ";
    cin>>Telefono;
        while(Telefono<1000000000){ ///validando telefono que no sea menor a 10 0000 0000
            cout<<endl<<"telefono incorrecta, reingrese el telefono"<<endl<<endl;
            cout<<">> Ingrese el telefono: ";
            cin>>Telefono;
        }
    cout<<"Descripcion del Proveedor: ";
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


void proveedore::Listar_Proveedores(){
   cout<<"ID: "<<ID<<endl;
   cout<<"Nombre del proveedor: "<<Nombre<<endl;
   cout<<"Telefono: "<<Telefono<<endl;
   cout<<"Nota: "<<Nota<<endl;
   cout<<endl<<endl;

}

int proveedore::getID(){
    return ID;
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
