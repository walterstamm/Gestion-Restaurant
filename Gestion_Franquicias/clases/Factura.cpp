#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
#include "Factura.h"
#include "Fecha.h"
#include "Ventas.h"
#include "Producto.h"

Factura::Factura(){
    cout<<"CONSTRUCTOR\n";
    Nro_Fact = 0;
    Fecha_Factura.Cargar_Fecha();
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
    Fecha_Factura.Cargar_Fecha();
    Total_Pagar=0;///FUNCION PARA SUMAR LA VENTA FALTA

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

int Factura::getFactura(){
    return Nro_Fact;
    /**cout<<"\nNro_Fact:      "<<Nro_Fact;
    cout<<"\nNro_Cliente:   "<<Nro_Cliente;
    cout<<"\nTotal_Factura: "<<Total_Pagar;*/
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

void Factura::setfecha(Fecha f){
    Fecha_Factura = f;
}

Fecha Factura::getfecha(){
    return Fecha_Factura;
}

void MENU_FACTURACION(){
    int Opcion;
    while(Opcion){
        title("MENÚ FACTURACIÓN", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

        cout<<"\n============================================";
        cout<<"\n01-Generar Factura..........................";
        cout<<"\n02-Eliminar Factura.........................";
        cout<<"\n03-Listar Facturas por fecha.(Bool false....";
        cout<<"\n04-Listar Facturas Eliminadas...............";
        cout<<"\n============================================";
        cout<<"\n00- Volver al MENÚ PRINCIPAL................";
        cout<<"\n============================================";
        cout<<"\nOpción: "; cin>>Opcion;
        cout<<"\n============================================";

    switch(Opcion){
        case 1:{

            Factura Nueva;
            Ventas Vent;
            Producto Prod;
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

            cout<<"\n=====================================================\n";

            int CodProducto, CantProducto;
            char Descrip[20];
            float Precios;
            Vent.setNro_Factura(Nueva.getFactura());///guardo el Nro_Fact en Ventas VERRRRRRRRRR
            cout<<"\nCodProducto: "; cin>>CodProducto;
            FILE *Pr = fopen("archivos/Producto.dat", "rb");
            if(Pr == NULL) {return; }
            while(fread(&Prod, sizeof(Producto), 1, Pr)){
                if(Prod.getID() == CodProducto){
                    strcpy(Descrip, Prod.getNombre());
                    Vent.setPrecio(Prod.getPrecio());
                }
            }
            cout<<"\nCantProducto: "; cin>>CantProducto;

            Vent.Cargar_Venta(CodProducto, CantProducto, Precios);
            Vent.getVentas();

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
