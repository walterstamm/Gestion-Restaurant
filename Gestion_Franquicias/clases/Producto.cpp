#include <iostream>
#include <iomanip>
using namespace std;
#include<cstdlib>
#include <cstring>
#include <cstdio>
#include "Producto.h"
#include "../Validaciones/SINO.h"

Producto::Producto(){
    Precio=0;
    estado=true;
    Estado_sublote=true;
}

bool Producto::Cargar_Producto(){
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
        if(Continuar()==false){
            system ("cls");
            return false;
        }
    }
return true;
}

void Producto::Mostrar_Producto(){
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
            cout << setw(10);
            Vencimiento.Mostrar_Fecha();
}

void Producto::Encabezado(){
    cout<<"==============================================================================="<<endl;
    cout << left;
    cout << setw(4) << "ID";
    cout << setw(18) << "Descripcion " << setw(9) << "  Precio " << setw(11) << " Cantidad" << setw(13) << "Cant Min" << setw(1) << "Fecha Vto" << endl;
    cout<<"==============================================================================="<<endl;
}

void Producto::Mostrar_Alerta(){
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

void Producto::Encabezado_Alerta(){
    cout<<"==============================================================================="<<endl;
    cout << left;
    cout << setw(4) << "ID";
    cout << setw(18) << "Descripcion " << setw(10) << "  Precio " << setw(11) << "Cantidad" << setw(18) << "Cant Min"<<endl;
    cout<<"==============================================================================="<<endl;
}

bool Producto::GuardarProducto(){
    bool grabo;
    FILE *p=fopen("archivos/producto.dat","ab");
    if(p==NULL){
        return false;
    }
    grabo=fwrite(this, sizeof(Producto),1,p);
    fclose(p);
return grabo;
}

int Producto::Buscar_Producto_ID(int _ID){
    int pos=0;
    FILE *p=fopen("archivos/producto.dat","rb");
        if(p==NULL){
            fclose(p);
            return -1;///retorna -1 si no encontro el ID
        }
    while(fread(this, sizeof(Producto),1,p)){
        if(ID==_ID){
            fclose(p);
            return pos; ///retorna la posicion del archivo
        }
        pos++;
    }
    fclose(p);
return -1; ///retorna -1 si no encontro el ID
}

bool Producto::ModificarProducto(int pos){
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

bool ValidarIDProducto(int _ID){
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

bool Producto::ValidarCantidadProducto(int _cantidad){
    if(_cantidad> Cantidad){
        cout<<"Cantidad excedida"<<endl;
        cout<<"usted cuenta con: "<<Cantidad<<endl;
        return false;
    }
return true;
}

int Producto::getCantidad_Cod(int cod){

    FILE *p=fopen("archivos/Producto.dat","rb");
        if(p==NULL){
            return -1;
        }
    int pos = Buscar_Producto_ID(cod);

    fseek(p, pos*sizeof(Producto), SEEK_SET);
    fwrite(this, sizeof(Producto), 1, p);
    int Cantidad = getCantidad();
    fclose(p);

    return Cantidad;
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

bool Producto::LeerPos(int pos){
    bool estado;
    FILE *p=fopen("archivos/producto.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos*sizeof(Producto),SEEK_SET);
    estado=fread(this, sizeof(Producto),1,p);
    fclose(p);
return estado;
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
