#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
#include "Factura.h"
#include "Fecha.h"
#include "Ventas.h"

Factura::Factura(){
    cout<<"CONSTRUCTOR\n";
    Nro_Fact = 0;
///    Fecha_Venta = NULL;
    Nro_Cliente = 0;
    Total_Pagar=0;
}

Factura::~Factura(){
    cout<<"\nDESTRUCTOR\n";
}

void Factura::setFactura(int Cliente){
    cout<<"NUEVA FACTURA\n";
    Nro_Fact = Leo_Factura();
    Nro_Cliente = Cliente;
    ///Fecha_Venta = 0;
    Total_Pagar=0;

}

int Factura::Leo_Factura(){
    int Nuevo_Nro=0;
    FILE *Fact=fopen("archivos/Facturas.dat", "rb");
    if(Fact == NULL){cout<<"No se abrio el Archivo Facturas.dat";}
    ///Vuelve 1 posición para leer el registro grabado
    fseek(Fact,-1*sizeof(Factura), SEEK_END); ///tiene un warning osea futuro error
    fread(this, sizeof(Factura), 1, Fact);///Muestro lo grabado recien
    Nuevo_Nro = Nro_Fact+1;
    return Nuevo_Nro;
}

void Factura::getFactura(){
    cout<<"\nNro_Fact:      "<<Nro_Fact;
    cout<<"\nNro_Cliente:   "<<Nro_Cliente;
    cout<<"\nTotal_Factura: "<<Total_Pagar;
}

bool Factura::Guardo(){
    FILE *Fact=fopen("archivos/Facturas.dat", "ab");
    if(Fact == NULL){cout<<"No se abrió el Archivo Facturas.dat"; return false;}
    fwrite(this, sizeof(Factura),1,Fact);///Despues de guardar esta en la ultima posición
    fclose(Fact);
    return true;

}

void Factura::Muestro_Guardado(){///PARA VERIFICAR SI REALMENTE GRABÓ
    FILE *Fact=fopen("archivos/Facturas.dat", "rb");
    if(Fact == NULL){cout<<"No se abrio el Archivo Facturas.dat";}
    ///Vuelve 1 posición para leer el registro grabado
    fseek(Fact,-1*sizeof(Factura), SEEK_END);///tiene un warning osea futuro error
    fread(this, sizeof(Factura), 1, Fact);///Muestro lo grabado recien
}

void MENU_FACTURACION(){
    int Opcion;
    while(Opcion){
        title("MENÚ FACTURACIÓN", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

        cout<<"\n============================================";
        cout<<"\n01-Ingresar Producto........................";
        cout<<"\n02-";
        cout<<"\n============================================";
        cout<<"\n00- Volver al MENÚ PRINCIPAL................";
        cout<<"\n============================================";
        cout<<"\nOpción: "; cin>>Opcion;
        cout<<"\n============================================";

    switch(Opcion){
        case 1:{
            /*
            Factura Nueva;
            Ventas Nueva_V;
            int Cliente=-1;
            cout<<"\nINGRESE CLIENTE: "; cin>>Cliente;
            Nueva.setFactura(Cliente);
            if(Nueva.Guardo()){
                cout<<"Se grabó correctamente";
            }
            cout<<"\nBusco\n";
            Nueva.Muestro_Guardado();
            cout<<"\nMuestro\n";
            Nueva.getFactura();

            int CodProducto, CantProducto;
            char Descrip[20];
            float Precios;
            cout<<"\nCodProducto: "; cin>>CodProducto;
            cout<<"\nCantProducto: "; cin>>CantProducto;

            Nueva_V.Cargar_Venta(CodProducto, CantProducto, Precios);
            Nueva_V.getVentas();
        */
        /// esto tiene que estar dentro de una funcion -- linea 102 error no esta definido
        }

        break;
        case 2:

        break;
        case 0:
            return;
        break;
        default:
            cout<<"\nIngrese la opción correcta";
        break;



    }

    }


}
