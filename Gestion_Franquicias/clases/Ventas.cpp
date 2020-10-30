#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
#include "Ventas.h"
#include "Producto.h"

Ventas::Ventas(){
    Cod_Producto = 0;
    Descripcion[0]= {};
    Cant_Producto = 0;
    Precio = 0;
    Importe = 0;
}

Ventas::~Ventas(){

}

void Ventas::Cargar_Venta(int NroFact, int CodProd, char *Descr, int CantPr, float Prec){
        Nro_Factura.setNroFact(NroFact);
        Cod_Producto = CodProd;
        strcpy(Descripcion, Descr);
        Cant_Producto = CantPr;
        Precio = Prec;
        Importe = float(Precio * Cant_Producto);
}

void Ventas::setCod_Producto(){

}
void Ventas::setDescripcion(){

}
void Ventas::setCant_Producto(){

}
void Ventas::setPrecio(float PrecioProd){
    Precio = PrecioProd;
}
void Ventas::setImporte(){

}

///este get no retorna nada da otro error

void Ventas::getVentas(){
    cout<<"\nNro_Factura: "<<Nro_Factura.getNro_Factura();
    cout<<"\nCod_Produto: "<<Cod_Producto;
    cout<<"\nDescripción: "<<Descripcion;
    cout<<"\nCant_Producto:"<<Cant_Producto;
    cout<<"\nPrecio: "<<Precio;
    cout<<"\nSubtotal: "<<Importe;
}
