#include <iostream>
using namespace std;
#include "mozo.h"

mozo::mozo(){}

void mozo::Cargar(){
    cout<<"Ingrese el ID: ";
    cin>>ID;
    cout<<"Ingrese el nombre: ";
    cin.ignore();
    cin.getline(nombre, 30, '\n');
    cout<<"Ingrese el apellido: ";
    cin.getline(apellido, 30, '\n');
    CantidadVendida=0;
    estado=true;
}

void mozo::mostrar(){
    cout<<"ID "<<ID;
    cout<<"Nombre "<<nombre;
    cout<<"apellido "<<apellido;
    cout<<"Cantidad vendida "<<CantidadVendida;
    cout<<"Estado "<<estado;
}

char *mozo::getnombre(){
    return nombre;
}

char *mozo::getapellido(){
    return apellido;
}
