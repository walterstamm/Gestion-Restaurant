#include <iostream>
using namespace std;
#include "Lote.h"

bool Lote::Guardar(){
    bool Estado;
    FILE *p=fopen("archivos/Lote.dat","ab");
    if(p==NULL) return 0;
    Estado=fwrite(this,sizeof(Lote),1,p);
    fclose(p);
return Estado;
}

bool Lote::Modificar(int pos){
    bool correcto;
    FILE *p=fopen("archivos/Lote.dat","rb+");
        if(p==NULL){
            fclose(p);
            return false;
        }
    fseek(p, pos*sizeof(Lote), SEEK_SET);
    correcto= fwrite(this, sizeof(Lote), 1, p);
    fclose(p);
return correcto;
}

bool Lote::LeerPos(int pos){
    bool estado;
    FILE *p=fopen("archivos/Lote.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos*sizeof(Lote),SEEK_SET);
    estado=fread(this, sizeof(Lote),1,p);
    fclose(p);
return estado;
}
