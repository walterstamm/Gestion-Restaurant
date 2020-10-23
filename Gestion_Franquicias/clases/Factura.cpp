#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
#include "Factura.h"
#include "Fecha.h"

Factura::Factura(){
    cout<<"CONSTRUCTOR\n";
    Nro_Factura = 0;
///    Fecha_Venta = NULL;
    Nro_Cliente = 0;
    Total_Pagar=0;
}

Factura::~Factura(){
    cout<<"\nDESTRUCTOR\n";
}

void Factura::setFactura(int Cliente){
    cout<<"NUEVA FACTURA\n";
    Nro_Factura = Leo_Factura()+1;
    Nro_Cliente = Cliente;
    ///Fecha_Venta = xxx;
    Total_Pagar=0;

}

int Factura::Leo_Factura(){

    int Nuevo_Nro=0, Viejo_Nro;
    ///BUSCAR EN ARCHIVO EN EL ULTIMO REGISTRO EL NUMERO
    ///ME DEVUELVE EL NUMERO VIEJO
    Viejo_Nro=3;
    Nuevo_Nro = Viejo_Nro;
}

void Factura::getFactura(){
    cout<<"\nMUESTRO";
    cout<<"\nNro_Fact: "<<Nro_Factura;
    cout<<"\nNro_Cliente: "<<Nro_Cliente;
    cout<<"\nTotal_Factura: "<<Total_Pagar;

}

