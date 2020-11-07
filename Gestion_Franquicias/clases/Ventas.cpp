#include <iostream>
#include <string.h>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
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

void Ventas::setCod_Producto(){
}
int Ventas::getCod_Producto(){
    return Cod_Producto;
}
void Ventas::setDescripcion(){

}
char *Ventas::getDescripcion(){
    return Descripcion;
}

void Ventas::setCant_Producto(){

}

int Ventas::getCant_Producto(){
    return Cant_Producto;
}

void Ventas::setPrecio(float PrecioProd){
    Precio = PrecioProd;
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

 /**   void Encabezado(){
        Ventas Vent;
        int i = 0;
        cout << left;
        cout << setw(12) << "FECHA" << setw(8) << "LEGAJO" << setw(6) << "NOTA" << setw(15) << "TIPO" << endl;
        while (aux.leerDeDisco(i++)){
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << aux.getFecha().getDia();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(2);
            cout << aux.getFecha().getMes();
            cout << "/";
            cout << setw(6);
            cout << aux.getFecha().getAnio();

            cout << setw(8);
            cout << aux.getLegajo();
            cout << setw(6);
            cout << aux.getNota();
            cout << setw(15);
            switch(aux.getTipo()){
                case 1:
                    cout << "Parcial";
                break;
                case 2:
                    cout << "Trabajo pr�ctico";
                break;
                case 3:
                    cout << "Final";
                break;
            }
            cout << endl;
        }
    }*/
