#include <iostream>
using namespace std;
#include "Menu_Producto.h"
#include "../clases/Producto.h"

void Cargar_Producto(){
    Producto uno;
    if(uno.Cargar_Producto()==true){
        if(uno.Cargar_Producto_Disco()==true){
            cout<<endl<<"PRODUCTO CARGADO"<<endl;
        }
    }
}

void Mostrar_Todos_Producto(){
    int pos=0;
    Producto uno;
    while(uno.setSacar_Disco(pos)!=false){
        uno.mostrar_Producto();
        pos++;
    }
    cout<<endl<<"TODOS LOS PRODUCTO FUERON MOSTRADOS"<<endl;
}

void Mostrar_X_Producto(){
    ///Proximamente je je
}

void Modificar_Cantidad(){
    int pos=0;
    Producto uno;
    while(uno.setSacar_Disco(pos)!=false){
        uno.mostrar_Producto();
        pos++;
    }
    cout<<endl<<"TODOS LOS PRODUCTO FUERON MOSTRADOS"<<endl;
}

void Modificar_Cantidad_minima(){
    Producto uno;
    uno.Modificar_Cantidad();
}

void Modificar_La_Cantidad_minima(){
    Producto uno;
    uno.Modificar_Cantidad_Minima();
}
