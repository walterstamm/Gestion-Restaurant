#include <iostream>
using namespace std;
#include<cstdlib>
#include <cstring>
#include <cstdio>
#include "Producto.h"
#include "../Validaciones/Continuar.h"


bool Producto::Cargar(){
    cout<<"Ingrese el ID ";
    cin>>ID;
        while(ID<0 || ValidarID_Producto(ID)!=false){ ///validando id que no sea negativo y no se repita
            cout<<"Error ID";
                if(Continuar()==false){
                    system ("cls");
                    return false;
                }
            cout<<">> Ingrese el ID: ";
            cin>>ID;
        }
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
            cout<<endl<<"cantidad minima incorrecta, reingrese la cantidad mínima"<<endl<<endl;
            cout<<">> Ingrese el cantidad mínima: ";
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

void Producto::Listar(){
    cout<<"ID "<<ID<<endl;
    cout<<"Nombre "<<Nombre<<endl;
    cout<<"Precio $"<<Precio<<endl;
    cout<<"Cantidad "<<Cantidad<<endl;
    cout<<"Cantidad Minima "<<Cantidad_Minima<<endl;
    cout<<"Fecha de vencimiento "<<endl;
    Vencimiento.Mostrar_Fecha();
    cout<<endl<<"Fecha de ingreso "<<endl;
    Actual.Mostrar_Fecha();
    cout<<endl<<endl;
}

bool Producto::Guardar(){
    bool grabo;
    FILE *p=fopen("archivos/producto.dat","ab");
    if(p==NULL){
        return false;
    }
    grabo=fwrite(this, sizeof(Producto),1,p);
    fclose(p);
return grabo;
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

bool Producto::Modificar(int pos){
    bool estado;
    FILE *p=fopen("archivos/producto.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos*sizeof(Producto),SEEK_SET);
    estado=fwrite(this, sizeof(Producto),1,p);
    fclose(p);
return estado;

}

bool BuscarPoscicion_Producto(int _ID, int &pos){
    Producto uno;
    while(uno.LeerPos(pos++)){
        if(uno.getID()==_ID){
            return true;
        }
    }
return false;
}



bool ValidarID_Producto(int _ID){
    Producto uno;
    FILE *p=fopen("archivos/producto.dat","rb");
    if(p==NULL) return false;
    while(fread(&uno, sizeof(Producto),1,p)){
        if(uno.getID()==_ID){
            fclose(p);
            return true; ///retorna la posicion del archivo
        }
    }
    fclose(p);
return false; ///retorna -1 si no encontro el ID
}
