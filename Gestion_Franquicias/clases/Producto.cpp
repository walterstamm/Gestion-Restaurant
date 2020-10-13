#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include "Producto.h"

Producto::Producto(){}

bool Producto::Cargar_Producto(){
    cout<<"Ingrese el ID ";
    cin>>ID;
        while(ID<0){ ///validando id que no sea negativo
            cout<<endl<<"ID incorrecta, reingrese el ID"<<endl<<endl;
            cout<<">> Ingrese el ID: ";
            cin>>ID;
        }
    cout<<"Ingrese el nombre: ";
    cin.ignore();
    cin.getline(Nombre, 50, '\n');
        while(Nombre[0]==' '){///validando el nombre que el primer caracter no sea un espacio
            cout<<endl<<"Nombre incorrecta, reingrese el Nombre"<<endl<<endl;
            cout<<">> Ingrese el Nombre: ";
            cin.getline(Nombre, 30, '\n');
        }
    cout<<"Ingrese el precio: ";
    cin>>Precio;
        while(Precio<0){ ///validando Precio que no sea negativo
            cout<<endl<<"Precio incorrecta, reingrese el Precio"<<endl<<endl;
            cout<<">> Ingrese el Precio: ";
            cin>>Precio;
        }
    cout<<"Ingrese la cantidad: ";
    cin>>Cantidad;
        while(Cantidad<0){ ///validando Cantidad que no sea negativo
            cout<<endl<<"Cantidad incorrecta, reingrese el Cantidad"<<endl<<endl;
            cout<<">> Ingrese el Cantidad: ";
            cin>>Cantidad;
        }
    cout<<"Ingrese la cantidad minima: ";
    cin>>Cantidad_Minima;
        while(Cantidad_Minima<0){ ///validando minima incorrecta que no sea negativo
            cout<<endl<<"cantidad minima incorrecta, reingrese el cantidad minima"<<endl<<endl;
            cout<<">> Ingrese el cantidad minima: ";
            cin>>Cantidad_Minima;
        }
return true;
}

bool Producto::Cargar_Producto_Disco(){
    bool grabo;
    FILE *p=fopen("producto.dat","ab");
    if(p==NULL){
        return false;
    }
    grabo=fwrite(this, sizeof(Producto),1,p);
    fclose(p);
return grabo;
}

bool Producto::Sacar_Disco(int pos){
    bool grabo;
    FILE *p=fopen("producto.dat","rb");
    if(p==NULL){
        return false;
    }
    fseek(p, pos* sizeof(Producto), SEEK_SET);
    grabo=fread(this, sizeof(Producto),1,p);
return grabo;
}

void Producto::mostrar(){
    cout<<"ID "<<ID;
    cout<<"Nombre "<<Nombre;
    cout<<"Precio "<<Precio;
    cout<<"Cantidad "<<Cantidad;
    cout<<"Cantidad Minima "<<Cantidad_Minima;
}
