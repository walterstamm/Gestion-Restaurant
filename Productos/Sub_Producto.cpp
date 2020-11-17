#include <iostream>
using namespace std;
#include<cstdlib>
#include <cstring>
#include <cstdio>
#include "Sub_Producto.h"

Sub_Producto::Sub_Producto(){
    Estado=true;
}

bool Sub_Producto::Cargar(){
    cout<<"Ingrese el nombre: ";
    cin.ignore();
    cin.getline(Nombre, 50, '\n');
        while(Nombre[0]==' '){///validando el nombre que el primer caracter no sea un espacio
            cout<<endl<<"Nombre incorrecta, reingrese el Nombre"<<endl<<endl;
            cout<<">> Ingrese el Nombre: ";
            cin.getline(Nombre, 30, '\n');
        }
    cout<<"Ingrese el precio por unidad: $";
    cin>>Precio;
        while(Precio<0){ ///validando Precio que no sea negativo
            cout<<endl<<"Precio incorrecta, reingrese el Precio"<<endl<<endl;
            cout<<">> Ingrese el Precio por unidad: $";
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
        while(Cantidad_Minima<0){ ///validando minima que no sea negativo
            cout<<endl<<"cantidad minima incorrecta, reingrese la cantidad mínima"<<endl<<endl;
            cout<<">> Ingrese el cantidad mínima: ";
            cin>>Cantidad_Minima;
        }
    ///bool verificacion=Vencimiento.Cargar_Fecha_Vencimiento();
    while(Vencimiento.Cargar_Fecha_Vencimiento()!=true){
        cout<<endl<<"Fecha de vencimiento incorrecta"<<endl<<endl;
        /*if(Continuar()==false){
            system ("cls");
            return false;
        }*/
    }
return true;
}

void Sub_Producto::Mostrar(){
    cout<<"Nombre "<<Nombre<<endl;
    cout<<"Precio $"<<Precio<<endl;
    cout<<"Cantidad "<<Cantidad<<endl;
    cout<<"Cantidad Minima "<<Cantidad_Minima<<endl;
    cout<<"Fecha de vencimiento "<<endl;
    Vencimiento.Mostrar_Fecha();
    cout<<endl<<"Fecha de ingreso "<<endl;
    Actual.Mostrar_Fecha();
    cout<<endl<<endl;
}
