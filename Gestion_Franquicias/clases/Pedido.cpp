#include <iostream>
using namespace std;
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "Pedido.h"
#include "Fecha.h"

Pedido::Pedido(){
    Estado=true;
    cout<<"Se ha creado una clase"<<endl;
}
Pedido::~Pedido(){
cout<<"Se ha eliminado ese Pedido"<<endl;
}

void Pedido::setFecha(){
    Fecha _Fecha;
    cout<<"Cargue la Fecha de entrega del pedido"<<endl;
   bool valido= _Fecha.Cargar_Fecha();
   Fecha_Entrega=_Fecha;
}
bool Pedido::Cargar_Pedido(){
    cout<<"Ingrese el Codigo del Producto: "<<endl;
    cin>>Codigo_Producto;
    cout<<"Cantidad: "<<endl;
    cin>>Cantidad;
    ///desarrollar fecha////
    cout<<"Presione ENTER para generar el pedido...."<<endl;
    system("pause");
    Estado=true;
    return true;
}

void Pedido::Mostrar_Pedido(){};
void Pedido::setCodigo_Producto(int _Codigo_Producto){
    Codigo_Producto=_Codigo_Producto;
}
void Pedido::setCantidad(int _Cantidad){
    Cantidad=_Cantidad;
}
void Pedido::setEstado(bool _Estado){
    Estado=_Estado;
}
int Pedido::getCodigo_Producto(){
    return Codigo_Producto;
}

int Pedido::getCantidad(){
    return Cantidad;
}
bool Pedido::getEstado(){
    return Estado;
}
