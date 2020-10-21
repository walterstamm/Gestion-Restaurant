#include <iostream>
using namespace std;
#include "Descuento.h"

Descuento::Descuento(){}

void Descuento::Cargar_Descuento(){}

bool Descuento::Guardar_Descuento(){
    bool grabo;
    FILE *p=fopen("archivos/descuento.dat","ab");
    if(p==NULL){
        return false;
    }
    grabo=fwrite(this, sizeof(Descuento),1,p);
    fclose(p);
return grabo;
}

bool Descuento::Buscar_Descuento(int pos){
    bool grabo;
    FILE *p=fopen("archivos/producto.dat","rb");
    if(p==NULL){
        return false;
    }
    fseek(p, pos* sizeof(Descuento), SEEK_SET);
    grabo=fread(this, sizeof(Descuento),1,p);
return grabo;
}
