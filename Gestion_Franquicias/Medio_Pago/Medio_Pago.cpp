#include <iostream>
using namespace std;
#include "Medio_Pago.h"
#include "../clases/Medios_Pago.h"

void Cargar_Medio_pago(){
    Medio_Pago uno;
    uno.Cargar_Descuento();
    if(uno.Guardar_Descuento()==false){
        cout<<"Error descuento no guardado";
        return;
    }
    cout<<"Descuento guardado";
}

void Eliminar_Medio_pago(){
    Medio_Pago uno;
    if(uno.Quitar_Descuento()==false){
        cout<<"Error descuento no fue quitado";
        return;
    }
    cout<<"Descuento quitado";
}

void Listar_Medio_pago(){
    int pos=0;
    Medio_Pago uno;
    while(uno.Buscar_Descuento_Memoria(pos ++)){
        uno.Listar_Descuentos();
    }
}
