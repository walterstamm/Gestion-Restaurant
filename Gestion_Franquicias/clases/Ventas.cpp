#include <iostream>
#include <string.h>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <vector>
using namespace std;
#include "Ventas.h"
#include "Producto.h"

Ventas::Ventas(){
    Cod_Producto = 0;
    Descripcion[20]={0};
    Cant_Producto = 0;
    Precio = 0;
    Importe = 0;
}
Ventas::~Ventas(){
}
int Ventas::getNro_Fact(){
    return V_Nro_Fact;
}
void Ventas::Cargar_Venta(int NroFactura, int CodProducto, char *Descrip, int CantProducto, float Precios, float Importes){

        V_Nro_Fact = NroFactura;
        Cod_Producto = CodProducto;
        strcpy(Descripcion, Descrip);
        Cant_Producto = CantProducto;
        Precio = Precios;
        Importe = Importes;
}

int Ventas::Leo_Ventas(){
    int Cant_Ventas=-1;
    FILE *Ven=fopen("archivos/Ventas.dat", "rb");
    if(Ven == NULL){
        cout<<"No se abrio el Archivo Ventas.dat";
        return Cant_Ventas=0;
    }
    while(fread(this, sizeof(Ventas), 1, Ven)){
        Cant_Ventas ++;
    }
    getNro_Fact();
    return Cant_Ventas;
}

int Ventas::BuscarPosicion(int Numero){
    int Pos=-1;
    FILE *Ven=fopen("archivos/Ventas.dat", "rb");
    if(Ven == NULL){
        cout<<"No se abrio el Archivo Ventas.dat";
        return Pos;
    }
    while(fread(this, sizeof(Ventas), 1, Ven)){
        if(Numero == V_Nro_Fact){
            return Pos;
        }


    }
    return Pos;
}

void Ventas::setCod_Producto(int CodProducto){
    Cod_Producto = CodProducto;
}
int Ventas::getCod_Producto(){
    return Cod_Producto;
}
void Ventas::setDescripcion(char *Descrip){
    strcpy(Descripcion, Descrip);
}
char *Ventas::getDescripcion(){
    return Descripcion;
}

void Ventas::setCant_Producto(int CantProducto){
    Cant_Producto = CantProducto;
}

int Ventas::getCant_Producto(){
    return Cant_Producto;
}

void Ventas::setPrecio(float Precios){
    Precio = Precios;
}

float Ventas::getPrecio(){
    return Precio;
}

void Ventas::setImporte(){

}

float Ventas::getImporte(){
    return Importe;
}

///este get no retorna nada da otro error

void Ventas::getVentas(){
    cout<<"\nNro_Factura: "<<V_Nro_Fact;
    cout<<"\nCod_Produto: "<<Cod_Producto;
    cout<<"\nDescripción: "<<Descripcion;
    cout<<"\nCant_Producto:"<<Cant_Producto;
    cout<<"\nPrecio: "<<Precio;
    cout<<"\nSubtotal: "<<Importe;
}

void Ventas::MostrarVenta(){
    cout << right;
    cout << setw(4);
    cout << getNro_Fact();
    cout << setw(6);
    cout << getCod_Producto();
    cout << setw(3);
    cout << " ";
    cout << left;
    cout << setw(16);
    cout << getDescripcion();
    cout << right;
    cout << setw(5);
    cout << getCant_Producto();
    cout << setw(10);
    cout << getPrecio();
    cout << setw(13);
    cout << getImporte()<<endl;
}


