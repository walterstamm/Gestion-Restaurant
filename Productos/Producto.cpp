#include <iostream>
using namespace std;
#include "Producto.h"

bool Producto::Cargar(){
    cout<<"Ingrese el ID ";
    cin>>ID;
        while(ID<0 || ValidarID_Producto(ID)!=false){ ///validando id que no sea negativo y no se repita
            cout<<"Error ID";
                /*if(Continuar()==false){
                    system ("cls");
                    return false;
                }*/
            cout<<">> Ingrese el ID: ";
            cin>>ID;
        }
    Productos.setID(GenerarID(ID));
    if(Productos.Cargar()==false){
        return false;
    }
return true;
}

void Producto::Mostrar(){
    cout<<"ID "<<ID<<endl;
    Productos.Mostrar();
}

bool Producto::Guardar(){
    bool Estado;
    FILE *p=fopen("archivos/Producto.dat","ab");
    if(p==NULL) return 0;
    Estado=fwrite(this,sizeof(Producto),1,p);
    fclose(p);
return Estado;
}

int Producto::GenerarID(int _ID){ ///GENERA UN ID AUTOMATICO
    int total;
    FILE *p=fopen("archivos/Producto.dat","rb");
    if(p==NULL) return 0;
    while(fread(this,sizeof(Producto),1,p)){
        if(_ID==ID){
            total=Productos.getID();
        }
    }
    fclose(p);
return total;
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

bool BuscarPoscicion_Producto(int _ID, int &pos){
    Producto uno;
    while(uno.LeerPos(pos++)){
        if(uno.getID()==_ID){
            return true;
        }
    }
return false;
}

bool Producto::ventas(char &_Nombre, int &_Cantidad, float &_Precio){
    cout<<"Ingrese el ID ";
    cin>>ID;
        while(ID<0 || ValidarID_Producto(ID)!=true){ ///validando id que no sea negativo y no se repita
            cout<<"Error ID";
                /*if(Continuar()==false){
                    system ("cls");
                    return false;
                }*/
            cout<<">> Ingrese el ID: ";
            cin>>ID;
        }
    int pos=0;
    BuscarPoscicion_Producto(ID, pos);
    cout<<endl<<pos;
    Productos.Mostrar();
return true;
}
