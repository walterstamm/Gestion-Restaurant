#include <iostream>
using namespace std;

#include <vector>///para clase vector
#include <map>///para clase vector con indice

#include "Fun_Producto.h"
#include "../clases/Producto.h"
#include "../Validaciones/Continuar.h"
#include "../Interfaz_Grafica/ui.h"

void Cargar_Producto(){
    Producto uno;
    if(uno.Cargar()==false){
        msj("Error de carga de datos", 15, 3, 1, 1);
        return;
    }
    if(uno.Guardar()==false){
        msj("Error de guardado de datos", 15, 3, 1, 1);
        return;
    }
    cout<<"Datos guardados correctamente"<<endl;
}

void Listar_Todos_Productos(){
    Producto aux;
    int pos=0;
    vector <Producto> vex;
    while(aux.LeerPos(pos)){
        vex.push_back(aux);
        pos++;
    }
    ///ordenamos
    int posmin;
    for(int x=0; x<pos; x++){
        posmin=x;
        for(int y=x+1; y<pos; y++){
            if(vex[y].getID()<vex[posmin].getID()){
                posmin=y;
            }
        }
        aux=vex[x];
        vex[x]=vex[posmin];
        vex[posmin]=aux;
    }
    ///mostramos
    for(int x=0;x<pos;x++){
        if(vex[x].getEstado()==true){
            vex[x].Mostrar();
        }
    }
}

void Listar_Producto_ID(){
    Producto uno;
    int ID, pos=0;
    cout<<"ID del producto: ";
    cin>>ID;
    if(ID<0 && ValidarID_Producto(ID)==true){
        ///msj("ID incorrecto", 15, 3, 1, 1);
        return;
    }
    while(uno.LeerPos(pos++)){
        if(uno.getEstado()==true && uno.getID()==ID){
            uno.Mostrar();
        }
    }
}

void Modificar_Precio_Producto(){
    Producto uno;
    int ID, pos=0;
    float Precio;
    vector <int> vpos;
    cout<<"ID del producto: ";
    cin>>ID;
    if(ID<0 && ValidarID_Producto(ID)==true){
        ///msj("ID incorrecto", 15, 3, 1, 1);
        return;
    }
    while(uno.LeerPos(pos)){
        if(uno.getID()==ID){
            vpos.push_back(pos);
        }
        pos++;
    }
    uno.LeerPos(vpos[0]);
    cout<<"Ingrese el precio: ";
    cin>>Precio;
    if(Precio<0){
        cout<<"Error precio negativo";
        return;
    }
    for(int x=0;x<vpos.size();x++){
        uno.setPrecio(Precio);
        uno.Modificar(vpos[x]);
    }
}

void Modificar_CantidadMin_Producto(){
    Producto uno;
    int ID, pos=0, cant;
    vector <int> vpos;
    cout<<"ID del producto: ";
    cin>>ID;
    if(ID<0 && ValidarID_Producto(ID)==true){
        ///msj("ID incorrecto", 15, 3, 1, 1);
        return;
    }
    while(uno.LeerPos(pos)){
        if(uno.getID()==ID){
            vpos.push_back(pos);
        }
        pos++;
    }
    uno.LeerPos(vpos[0]);
    cout<<"Ingrese el cantidad minima: ";
    cin>>cant;
    if(cant<0){
        cout<<"Error cantidad minima negativo";
        return;
    }
    for(int x=0;x<vpos.size();x++){
        uno.setCantidad(cant);
        uno.Modificar(vpos[x]);
    }
}

void Eliminar_Producto(){
    Producto uno;
    int ID, pos=0;
    vector <int> vpos;
    cout<<"ID del producto: ";
    cin>>ID;
    if(ID<0 && ValidarID_Producto(ID)==true){
        ///msj("ID incorrecto", 15, 3, 1, 1);
        return;
    }
    while(uno.LeerPos(pos)){
        if(uno.getID()==ID){
            vpos.push_back(pos);
        }
        pos++;
    }
    uno.LeerPos(vpos[0]);
    for(int x=0;x<vpos.size();x++){
        uno.setEstado(false);
        uno.Modificar(vpos[x]);
    }
}















