#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
#include "Comprobantes.h"

///CONTRUCTOR DE LA CLASE COMPROBANTE
Encabezado::Encabezado(){
    cout<<"Razon social:           ";
    cin.getline(Razon_Social, 20);
    cout<<"Cuit:                   ";
    cin.getline(Ciut, 13);
    cout<<"Dirección: Calle y Nro: ";
    cin.getline(Direccion, 40);
    cout<<"Localidad y Provincia:  ";
    cin.getline(Localidad_Provincia, 30);
    cout<<"Telefono:               ";
    cin.getline(Telefono, 14);
    cout<<"Fecha:                  ";
    Fecha Cargar_Fecha();
}

