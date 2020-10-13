#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include "Producto.h"

///Constructor que dice nuevo
Producto::Producto(){
    cout<<"Nuevo producto creado";
}


void Producto::setCargar_Nombre(char * _Nombre){
    strcpy(Nombre,_Nombre);
}

char *Producto::getMostrar_Nombre(){
    return Nombre;
}
