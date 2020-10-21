#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include "Medios_Pago.h"

Medio_Pago::Medio_Pago(){
    Descuento=0;
}

void Medio_Pago::Cargar_Descuento(){
    cout<<"Cargar medio de pago que obtendra el descuento: ";
    cin.ignore();
    cin.getline(Medio, 10, '\n');
        while(Medio[0]==' '){///faltan validaciones
            cout<<endl<<"Medio incorrecta, reingrese el Medio"<<endl<<endl;
            cout<<">> Ingrese el medio: ";
            cin.getline(Medio, 10, '\n');
        }
    cout<<"Ingrese el monto que obtendra el desucento: ";
    cin>>Monto;
        while(Monto<0){ ///validando monto que no sea negativo
            cout<<endl<<"Monto incorrecta, reingrese el Monto"<<endl<<endl;
            cout<<">> Ingrese el monto: ";
            cin>>Monto;
        }
    cout<<"Ingrese el porcentaje de descuento: ";
    cin>>Descuento;
        while(Descuento<0){ ///validando Precio que no sea negativo
            cout<<endl<<"Porcentaje incorrecta, reingrese el Porcentaje"<<endl<<endl;
            cout<<">> Ingrese el porcentaje: ";
            cin>>Descuento;
        }
}

bool Medio_Pago::Guardar_Descuento(){
    bool grabo;
    FILE *p=fopen("archivos/Medios_Pago.dat","ab");
    if(p==NULL){
        return false;
    }
    grabo=fwrite(this, sizeof(Medio_Pago),1,p);
    fclose(p);
return grabo;
}

bool Medio_Pago::Quitar_Descuento(){
    bool grabo;
    FILE *p=fopen("archivos/Medios_Pago.dat","wb");///lo deja en 0 al descuento
    if(p==NULL){
        return false;
    }
    grabo=fwrite(this, sizeof(Medio_Pago),1,p);
    fclose(p);
return grabo;
}
