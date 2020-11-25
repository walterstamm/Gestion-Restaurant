#include <iostream>
using namespace std;
#include<cstdlib>
#include <cstring>
#include <cstdio>
#include <iomanip>

#include <vector>///para clase vector
#include <map>///para clase vector con indice

#include "Producto.h"
#include "Lote.h"

Producto::Producto(){
    Estado=true;
    Cantidad=0;
}

bool Producto::Cargar(){
    ID=GenerarID();
    cout<<"ID del producto: "<<ID<<endl;
    cout<<"Ingrese el nombre: ";
    cin.ignore();
    cin.getline(Nombre, 50, '\n');
        while(Nombre[0]==' '){///validando el nombre que el primer caracter no sea un espacio
            cout<<endl<<"Nombre incorrecta, reingrese el Nombre"<<endl<<endl;
            cout<<">> Ingrese el Nombre: ";
            cin.getline(Nombre, 30, '\n');
        }
    cout<<"Ingrese el precio por unidad: $";
    cin>>Precio;
        while(Precio<0){ ///validando Precio que no sea negativo
            cout<<endl<<"Precio incorrecta, reingrese el Precio"<<endl<<endl;
            cout<<">> Ingrese el Precio por unidad: $";
            cin>>Precio;
        }
    cout<<"Ingrese la cantidad minima: ";
    cin>>Cantidad_Minima;
        while(Cantidad_Minima<0){ ///validando minima que no sea negativo
            cout<<endl<<"cantidad minima incorrecta, reingrese la cantidad mínima"<<endl<<endl;
            cout<<">> Ingrese el cantidad mínima: ";
            cin>>Cantidad_Minima;
        }
return true;
}

void Producto::cabecera(){
    cout<<"==============================================================================="<<endl;
    cout << left;
    cout << setw(4) << "ID";
    cout << setw(18) << "NOMBRE " << setw(10) << "  Precio " << setw(11) << "Cantidad" << setw(18) << "Cant Min"<<endl;
    cout<<"==============================================================================="<<endl;
}

void Producto::Mostrar(){
    cout << left;
    cout << setw(4);
    cout << ID;
    cout << setw(18);
    cout << Nombre;
    cout << right;
    cout << setw(6);
    cout << Precio;
    cout << setw(9);
    cout << Cantidad;
    cout << setw(10);
    cout << Cantidad_Minima;
}

void Producto::Cargar_Cantidad(){
    Lote_Produ uno;
    int pos=0, cant=GenerarID();
    for(int x=1;x<cant;x++){
        int cont=0;
        while(uno.LeerPos(pos++)){
            if(uno.getIDproducto()==ID){
                cont+=uno.getCantidad();
            }
        }
        setCantidad(cont);
        LeerPos(x-1);
        Guardar();
    }
}

bool Producto::Guardar(){
    bool Estado;
    FILE *p=fopen("archivos/Producto.dat","ab");
    if(p==NULL) return 0;
    Estado=fwrite(this,sizeof(Producto),1,p);
    fclose(p);
return Estado;
}

bool Producto::Modificar(int pos){
    bool correcto;
    FILE *p=fopen("archivos/Producto.dat","rb+");
        if(p==NULL){
            fclose(p);
            return false;
        }
    fseek(p, pos*sizeof(Producto), SEEK_SET);
    correcto= fwrite(this, sizeof(Producto), 1, p);
    fclose(p);
return correcto;
}

bool Producto::LeerPos(int pos){
    bool estado;
    FILE *p=fopen("archivos/producto.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos*sizeof(Producto),SEEK_SET);
    estado=fread(this, sizeof(Producto),1,p);
    fclose(p);
return estado;
}

int Producto::GenerarID(){
    int cantidad;
    FILE *p=fopen("archivos/Producto.dat","rb");
        if(p==NULL){
            fclose(p);
            return 1;
        }
    fseek(p, 0, SEEK_END);
    cantidad=ftell(p);
return (cantidad/sizeof(Producto))+1;
}

bool ValidarID_Producto(int _ID){
    Producto uno;
    FILE *p=fopen("archivos/producto.dat","rb");
    if(p==NULL) return false;
    while(fread(&uno, sizeof(Producto),1,p)){
        if(uno.getID()==_ID){
            fclose(p);
            return uno.getEstado(); ///retorna la posicion del archivo
        }
    }
    fclose(p);
return false; ///retorna -1 si no encontro el ID
}


void Modificar_Precio(){
    Producto uno;
    int ID, pos=0;
    float Precio;
    cout<<"ID del producto: ";
    cin>>ID;
    while(uno.LeerPos(pos++)){
        if(ID==uno.getID()){
            cout<<"Ingrese el precio: ";
            cin>>Precio;
            if(Precio<0){
                cout<<"Error precio negativo";
                return;
            }
            uno.setPrecio(Precio);
            uno.Modificar(pos-1);
            return;
        }
    }
    ///mensaje error
}

void Modificar_CantMin(){
    Producto uno;
    int ID, pos=0, cant;
    vector <int> vpos;
    cout<<"ID del producto: ";
    cin>>ID;
    while(uno.LeerPos(pos++)){
        if(ID==uno.getID()){
            cout<<"Ingrese el cantidad minima: ";
            cin>>cant;
            if(cant<0){
                cout<<"Error cantidad minima negativo";
                return;
            }
            uno.setCantidad_Minima(cant);
            uno.Modificar(pos-1);
            return;
        }
    }
    ///mensaje error
}

void Eliminar_Producto(){
    Producto uno;
    int ID, pos=0;
    vector <int> vpos;
    cout<<"ID del producto: ";
    cin>>ID;
    while(uno.LeerPos(pos++)){
        if(uno.getEstado()==true && uno.getID()==ID){
            uno.setEstado(false);
            uno.Modificar(pos-1);
            return;
        }
    }
    ///mensaje error
}

void Mostrar_Todos_Productos(){
    Producto uno;
    uno.Cargar_Cantidad();
    int pos=0;
    uno.cabecera();
    while(uno.LeerPos(pos++)){
        if(uno.getEstado()==true){
            uno.Mostrar();
        }
    }
}

void Mostrar_x_Producto(){
    Producto uno;
    uno.Cargar_Cantidad();
    int ID, pos=0;
    cout<<"ID del producto: ";
    cin>>ID;
    while(uno.LeerPos(pos++)){
        if(uno.getEstado()==true && uno.getID()==ID){
            uno.cabecera();
            uno.Mostrar();
            return;
        }
    }
    ///mensaje error
}

void alertas(){
    Producto uno;
    uno.Cargar_Cantidad();
    int pos=0;
    while(uno.LeerPos(pos++)){
        if(uno.getCantidad()>=uno.getCantidad_Minima()){
            ///alerta roja
        }
        int Porcentaje=(uno.getCantidad_Minima()*100)/150;
        if(uno.getCantidad()>=Porcentaje){
            ///alerta amarilla
        }
        if(uno.getCantidad()<Porcentaje){
            ///alerta verde
        }
    }
}
