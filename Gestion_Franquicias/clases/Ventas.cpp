#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
#include "Ventas.h"
#include "Producto.h"

Ventas::Ventas(){

    Cod_Producto = 0;
    ///strcpy(Descripcion, '\0');///strcpy(aux,"\0"); ///me da error
    Cant_Producto = 0;
    Precio = 0;
    Importe = 0;
}

Ventas::~Ventas(){

}

void Ventas::Cargar_Venta(int CodProducto, int CantProducto, float Precios){

        Cod_Producto = CodProducto;
        {   ///OJO BUSCAR POR CODIGO
            FILE *Venta=fopen("archivos/Producto.dat", "rb");
            if(Venta == NULL){
                return;
            }
            while(fread(this, sizeof(Producto), 1, Venta)){
               /* if(ID == Cod_Producto){
                    strcpy(Producto.Nombre, Ventas.Descripcion);
                    Ventas.Precio == Producto.Precio;
                }*/
                ///ID no esta declarado
            }
        }
        Importe = Precio * Cant_Producto;
}

void Ventas::setNro_Factura(int Nro_F){
///    Nro_Factura = Nro_F;
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
    cout<<"\nNro_Factura: "<<Nro_Factura.getFactura();
    cout<<"\nCod_Produto: "<<Cod_Producto;
    cout<<"\nDescripción: "<<Descripcion;
    cout<<"\nCant_Producto:"<<Cant_Producto;
    cout<<"\nPrecio: "<<Precio;
    cout<<"\nSubtotal: "<<Importe;
}
