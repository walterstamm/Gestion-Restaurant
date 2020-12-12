#include <iostream>
using namespace std;
#include "Lote.h"

bool Lote_Produ::Guardar(){
    bool Estado;
    FILE *p=fopen("archivos/Lote_Produ.dat","ab");
    if(p==NULL) return 0;
    Estado=fwrite(this,sizeof(Lote_Produ),1,p);
    fclose(p);
return Estado;
}

bool Lote_Produ::Modificar(int pos){
    bool correcto;
    FILE *p=fopen("archivos/Lote_Produ.dat","rb+");
        if(p==NULL){
            fclose(p);
            return false;
        }
    fseek(p, pos*sizeof(Lote_Produ), SEEK_SET);
    correcto= fwrite(this, sizeof(Lote_Produ), 1, p);
    fclose(p);
return correcto;
}

bool Lote_Produ::LeerPos(int pos){
    bool estado;
    FILE *p=fopen("archivos/Lote_Produ.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos*sizeof(Lote_Produ),SEEK_SET);
    estado=fread(this, sizeof(Lote_Produ),1,p);
    fclose(p);
return estado;
}

int Lote_Produ::GenerarID(){
    int cantidad;
    FILE *p=fopen("archivos/Lote_Produ.dat","rb");
        if(p==NULL){
            fclose(p);
            return 1;
        }
    fseek(p, 0, SEEK_END);
    cantidad=ftell(p);
return (cantidad/sizeof(Lote_Produ))+1;
}
