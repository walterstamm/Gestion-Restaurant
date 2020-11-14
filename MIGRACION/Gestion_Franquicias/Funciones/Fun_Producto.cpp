#include <iostream>
using namespace std;
#include "Fun_Producto.h"
#include "../clases/Producto.h"
#include "../Validaciones/Continuar.h"
#include "../Interfaz_Grafica/ui.h"

void Cargar_Producto(){
    Producto uno;
    if(uno.Cargar()==false){
        msj("Error de carga de datos", 15, 3, 1, 1);
        uno.~Producto();
        return;
    }
    if(uno.Guardar()==false){
        msj("Error de guardado de datos", 15, 3, 1, 1);
        uno.~Producto();
        return;
    }
    cout<<"Datos guardados correctamente"<<endl;
    uno.~Producto();
}

void Listar_Todos_Productos(){
    Producto uno;
    int pos=0;
    while(uno.LeerPos(pos++)){
        if(uno.getEstado()==true){
            uno.Listar();
        }
    }
    cout<<"Productos mostrados"<<endl;
}

void Listar_Producto_ID(){
    int ID, pos=0;
    cout<<"ID del producto: ";
    cin>>ID;
    if(ID<0){
        msj("ID incorrecto", 15, 3, 1, 1);
        return;
    }
    Producto uno;
    if(BuscarPoscicion_Producto(ID, pos)==false){
        msj("Error de archivo", 15, 3, 1, 1);
        return;
    }
    uno.LeerPos(pos);
    if(uno.getEstado()==true){
        uno.Listar();
    }
    else msj("Error archivo inexistente", 15, 3, 1, 1);
}

void Modificar_Precio_Producto(){
    int ID, pos=0;
    float Precio;
    cout<<"ID del producto: ";
    cin>>ID;
    if(ID>0){
        msj("ID incorrecto", 15, 3, 1, 1);
        return;
    }
    Producto uno;
    if(BuscarPoscicion_Producto(ID, pos)==false){
        msj("Error de archivo", 15, 3, 1, 1);
        return;
    }
    if(uno.getEstado()==false){
        msj("Error archivo inexistente", 15, 3, 1, 1);
        return;
    }
    uno.LeerPos(pos);
    uno.Listar();
    cout<<"Ingrese el precio: $";
    cin>>Precio;
    while(Precio<0){ ///validando Cantidad que no sea negativo
        cout<<endl<<"precio incorrecta, reingrese el precio"<<endl<<endl;
        cout<<">> Ingrese el precio: $";
        cin>>Precio;
    }
    uno.setPrecio(Precio);
    if(uno.Modificar(pos)==false){
        msj("Error archivo no modificado", 15, 3, 1, 1);
        return;
    }
    cout<<"Archivo modificado"<<endl;
}

void Modificar_Cantidad_Producto(){
    int ID, pos=0, Cantidad;
    cout<<"ID del producto: ";
    cin>>ID;
    if(ID>0){
        msj("ID incorrecto", 15, 3, 1, 1);
        return;
    }
    Producto uno;
    if(BuscarPoscicion_Producto(ID, pos)==false){
        msj("Error de archivo", 15, 3, 1, 1);
        return;
    }
    if(uno.getEstado()==false){
        msj("Error archivo inexistente", 15, 3, 1, 1);
        return;
    }
    uno.LeerPos(pos);
    uno.Listar();
    cout<<"Ingrese el Cantidad: ";
    cin>>Cantidad;
    while(Cantidad<0){ ///validando Cantidad que no sea negativo
        cout<<endl<<"Cantidad incorrecta, reingrese el Cantidad"<<endl<<endl;
        cout<<">> Ingrese el Cantidad: ";
        cin>>Cantidad;
    }
    uno.setCantidad(Cantidad);
    if(uno.Modificar(pos)==false){
        msj("Error archivo no modificado", 15, 3, 1, 1);
        return;
    }
    cout<<"Archivo modificado"<<endl;
}

void Modificar_CantidadMin_Producto(){
    int ID, pos=0, Cantidad;
    cout<<"ID del producto: ";
    cin>>ID;
    if(ID>0){
        msj("ID incorrecto", 15, 3, 1, 1);
        return;
    }
    Producto uno;
    if(BuscarPoscicion_Producto(ID, pos)==false){
        msj("Error de archivo", 15, 3, 1, 1);
        return;
    }
    uno.LeerPos(pos);
    if(uno.getEstado()==false){
        msj("Error archivo inexistente", 15, 3, 1, 1);
        return;
    }
    uno.Listar();
    cout<<"Ingrese el Cantidad minima: ";
    cin>>Cantidad;
    while(Cantidad<0){ ///validando Cantidad que no sea negativo
        cout<<endl<<"Cantidad minima incorrecta, reingrese el Cantidad minima"<<endl<<endl;
        cout<<">> Ingrese el Cantidad minima: ";
        cin>>Cantidad;
    }
    uno.setCantidad_Minima(Cantidad);
    if(uno.Modificar(pos)==false){
        msj("Error archivo no modificado", 15, 3, 1, 1);
        return;
    }
    cout<<"Archivo modificado"<<endl;
}

void Eliminar_Producto(){
    int ID, pos=0;
    cout<<"ID del producto: ";
    cin>>ID;
    if(ID>0){
        msj("ID incorrecto", 15, 3, 1, 1);
        return;
    }
    Producto uno;
    if(BuscarPoscicion_Producto(ID, pos)==false){
        msj("Error de archivo", 15, 3, 1, 1);
        return;
    }
    uno.LeerPos(pos);
    uno.Listar();
    uno.setEstado(false);
    if(uno.Modificar(pos)==false){
        msj("Error archivo no modificado", 15, 3, 1, 1);
        return;
    }
    cout<<"Archivo modificado"<<endl;
}















