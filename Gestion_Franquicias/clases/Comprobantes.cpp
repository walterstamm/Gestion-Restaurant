#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
#include "Comprobantes.h"

///CONTRUCTOR DE LA CLASE ENCABEZADO
Encabezado::Encabezado(){///char R_Social, char cuit, char Direc, char Local, char Tel){
    cout<<"Los atributos de encabbezado estan vacios \n";
    strcpy(Razon_Social, "");
    strcpy(Cuit, "");
    strcpy(Direccion, "");
    strcpy(Localidad_Provincia, "");
    strcpy(Telefono, "");

}
Encabezado::~Encabezado(){ ///DESTRUCTOR
}
char *Encabezado::getRazon_Social(){
    return Razon_Social;
}
char *Encabezado::getCuit(){
    return Cuit;
}
char *Encabezado::getDireccion(){
    return Direccion;
}
char *Encabezado::getLocalidad_Provincia(){
    return Localidad_Provincia;
}
char *Encabezado::getTelefono(){
    return Telefono;
}
void Encabezado::setCargar_Encabezado(char *R_Social, char *cuit, char *Direc, char *Local, char *Tel){
    strcpy(Razon_Social, R_Social);
    strcpy(Cuit, cuit);
    strcpy(Direccion, Direc);
    strcpy(Localidad_Provincia, Local);
    strcpy(Telefono, Tel);
}
void Encabezado::getMostrar_Encabezado(){
    cout<<"Razon Social:      "<<getRazon_Social()<<endl;
    cout<<"Cuit:              "<<getCuit()<<endl;
    cout<<"Dirección Empresa: "<<getDireccion()<<endl;
    cout<<"Localidad y Prov:  "<<getLocalidad_Provincia()<<endl;
    cout<<"Telefono:          "<<getTelefono()<<endl;
}
///     CLASE FACTURA
Factura::Factura(){ ///CONSRUCTOR
    Nro_Fact = NULL;
    Fecha_Venta = NULL;
    Nro_Cliente = NULL;
}

void Factura::setCrear_Factura( int Cliente){
    Nro_Fact=Nro_Factura();
    Fecha_Venta = xxx;
    Nro_Cliente = Cliente;
}

void Factura::getMostrar_Factura(int Nro){

    cout<<"Factura Nro: "<<Nro_Fact;
    FILE *Fact;
    Fact=fopen("Factura.dat", "rb+");
    if(Fact==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO FACTURA.DAT";
        system("pause");
        return;
    }
    while(fread(Fact, sizeof(Factura), 1, Fact )){
        if(Nro_Fact == Nro){
            cout<<"MUESTRO LOS REGISTROS DE VENTAS [Nro fac,Cod_Prod, Descripcion, Cant, Precio_Unit, Sub_Total ";
            cout<<"MUESTRO TODO MENOS EL NRO FAC";
        }
    }




}
int Nro_Factura(){

    ///tengo que crear un numero que continue al ya existente
    return Numero=1;
}

///     VENTA DEBE SER HIJO DE FACTURA
class Venta{
    private:
        Nro_Factura()


};
