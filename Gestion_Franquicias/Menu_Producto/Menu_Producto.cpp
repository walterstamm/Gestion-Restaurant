#include <iostream>
using namespace std;
#include "Menu_Producto.h"
#include "../clases/Producto.h"

void Cargar_Producto(){
    Producto uno;
    if(uno.Cargar_Producto()==false){
        cout<<"Error de carga de producto"<<endl;
        return;
    }
    if(uno.GuardarProducto()==false){
        cout<<"Error al guardar el producto de producto"<<endl;
        return;
    }
    cout<<"Producto cargado"<<endl;
return;
}

bool Mostrar_Todos_Producto(){
    Producto uno;
    bool mostro=false;
    FILE*p=fopen("archivos/producto.dat","rb");
        if(p==NULL){
            fclose(p);
            return false;
        }
    while(fread(&uno, sizeof(Producto),1,p)){
        if(uno.getEstado()==true){
            mostro=true;
            uno.Mostrar_Producto();
        }
    }
    fclose(p);
return mostro;
}

void Mostrar_X_Producto(){
    int ID;
    cout<<"ID del producto: ";
    cin>>ID;
    Producto uno;
    if(uno.Buscar_Producto_ID(ID)==-1){
        cout<<"Producto inexistente";
        return;
    }
    uno.Mostrar_Producto();
}

void Modificar_Cantidad(){
    int ID;
    cout<<"ID del producto: ";
    cin>>ID;
    Producto uno;
    int pos=uno.Buscar_Producto_ID(ID);
    if(pos==-1){
        cout<<"Producto inexistente";
        return;
    }
    uno.Mostrar_Producto();
    cout<<"Ingrese la cantidad: ";
    cin>>ID;
    while(ID<0){ ///validando Cantidad que no sea negativo
       cout<<endl<<"Cantidad incorrecta, reingrese el Cantidad"<<endl<<endl;
        cout<<">> Ingrese el Cantidad: ";
        cin>>ID;
    }
    uno.setCantidad(ID);
    if(uno.ModificarProducto(pos)==false){
        cout<<"Producto no guardado";
        return;
    }
    cout<<"Producto guardado";
}

void Modificar_La_Cantidad_minima(){
    int ID;
    cout<<"ID del producto: ";
    cin>>ID;
    Producto uno;
    int pos=uno.Buscar_Producto_ID(ID);
    if(pos==-1){
        cout<<"Producto inexistente";
        return;
    }
    uno.Mostrar_Producto();
    cout<<"Ingrese la cantidad minima: ";
    cin>>ID;
    while(ID<0){ ///validando Cantidad que no sea negativo
       cout<<endl<<"Cantidad minima incorrecta, reingrese el Cantidad minima"<<endl<<endl;
        cout<<">> Ingrese el Cantidad minima: ";
        cin>>ID;
    }
    uno.setCantidadMinima(ID);
    if(uno.ModificarProducto(pos)==false){
        cout<<"Producto no guardado";
        return;
    }
    cout<<"Producto guardado";
}

void Eliminar_Producto(){
    int ID;
    cout<<"ID del producto: ";
    cin>>ID;
    Producto uno;
    int pos=uno.Buscar_Producto_ID(ID);
    if(pos==-1){
        cout<<"Producto inexistente";
        return;
    }
    uno.Mostrar_Producto();
    uno.setEstado(false);
    if(uno.ModificarProducto(pos)==false){
        cout<<"Producto no guardado";
        return;
    }
    cout<<"Producto guardado";
}
