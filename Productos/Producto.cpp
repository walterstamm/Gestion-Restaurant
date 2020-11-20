#include <iostream>
using namespace std;
#include<cstdlib>
#include <cstring>
#include <cstdio>

#include <vector>///para clase vector
#include <map>///para clase vector con indice

#include "Producto.h"

Producto::Producto(){
    Estado=true;
    Estado_Lote=true;
    ID=1;
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
    cout<<"Ingrese la cantidad: ";
    cin>>Cantidad;
        while(Cantidad<0){ ///validando Cantidad que no sea negativo
            cout<<endl<<"Cantidad incorrecta, reingrese el Cantidad"<<endl<<endl;
            cout<<">> Ingrese el Cantidad: ";
            cin>>Cantidad;
        }
    cout<<"Ingrese la cantidad minima: ";
    cin>>Cantidad_Minima;
        while(Cantidad_Minima<0){ ///validando minima que no sea negativo
            cout<<endl<<"cantidad minima incorrecta, reingrese la cantidad m�nima"<<endl<<endl;
            cout<<">> Ingrese el cantidad m�nima: ";
            cin>>Cantidad_Minima;
        }
    ///bool verificacion=Vencimiento.Cargar_Fecha_Vencimiento();
    while(Vencimiento.Cargar_Fecha_Vencimiento()!=true){
        cout<<endl<<"Fecha de vencimiento incorrecta"<<endl<<endl;
        /*if(Continuar()==false){
            system ("cls");
            return false;
        }*/
    }
return true;
}

void Producto::Mostrar(){
    cout<<"ID "<<ID<<endl;
    cout<<"Nombre "<<Nombre<<endl;
    cout<<"Precio $"<<Precio<<endl;
    cout<<"Cantidad "<<Cantidad<<endl;
    cout<<"Cantidad Minima "<<Cantidad_Minima<<endl;
    cout<<"Fecha de vencimiento ";
    Vencimiento.Mostrar_Fecha();
    cout<<endl<<"Fecha de ingreso ";
    Actual.Mostrar_Fecha();
    cout<<endl<<endl;
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

int GenerarID(){ ///GENERA UN ID AUTOMATICO
    int pos=0, ID=0;
    Producto uno;
    while(uno.LeerPos(pos)){
        if(ID<uno.getID())ID=uno.getID();
        pos++;
    }
return ID+1;
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

bool ValidarID_Producto(int _ID){
    Producto uno;
    FILE *p=fopen("archivos/producto.dat","rb");
    if(p==NULL) return false;
    while(fread(&uno, sizeof(Producto),1,p)){
        if(uno.getID()==_ID){
            fclose(p);
            return uno.getID(); ///retorna la posicion del archivo
        }
    }
    fclose(p);
return false; ///retorna -1 si no encontro el ID
}


void Modificar_Precio(){
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

void Modificar_CantMin(){
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
        uno.setPrecio(cant);
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
        uno.setEstadoLote(false);
        uno.Modificar(vpos[x]);
    }
}

void Mostrar_Todos_Productos(){
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

void Mostrar_x_Producto(){
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

void alertas(){
    Producto uno;
    int pos=0;
    std::map<int, int> vexCant_Max;
    std::map<int, Producto> vexProducto;
    while(uno.LeerPos(pos)){
        vexCant_Max[uno.getID()-1]+=uno.getCantidad();
        vexProducto[uno.getID()-1]=uno;
        pos++;
    }
    for(int x=0;x<pos;x++){
        if (vexCant_Max[x]>=vexProducto[x].getCantidad_Minima()){
            ///los que estan en rojo
            ///Falta listar
            return;
        }
        int porcentaje=(vexProducto[x].getCantidad_Minima()*100)/150;
        if(porcentaje>=vexProducto[x].getCantidad_Minima() && vexCant_Max[x]<vexProducto[x].getCantidad_Minima()){
            ///alerta amarilla
            ///falta listar
            return;
        }
        if(porcentaje<vexProducto[x].getCantidad_Minima()){
            ///alerta verde
            ///falta listar
            return;
        }
    }
}
