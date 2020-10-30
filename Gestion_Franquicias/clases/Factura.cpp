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
    Nro_Fact = 0;
    ///cout<<"Fecha 1\n";
    ///Fecha_Factura.Cargar_Fecha();
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
    Total_Pagar=0;///FUNCION PARA SUMAR LA VENTA FALTA

}

void Factura::getFactura(){
    Fecha *p;
    p = new Fecha;
    cout<<"Nro_Fact: "<<Nro_Fact<<endl;
    cout<<"Fecha_Factura: ";
    p->Mostrar_Fecha();
    cout<<"\nNro_Cliente: "<<Nro_Cliente<<endl;
    cout<<"Total_Pagar: "<<Total_Pagar<<endl;
    system("pause");
    system("cls");
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

int Factura::getNro_Factura(){
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
        cout<<"============================================\n";

    switch(Opcion){
        case 1:{
            Factura Nueva;
            ///Ventas Vent;
            ///Producto Prod;
            int Cliente=-1;
            cout<<"\nINGRESE CLIENTE: "; cin>>Cliente;
            ///GENERO NRO FACTURA CON NRO CLIENTE EN LA MEMORIA.
            Nueva.setFactura(Cliente);
            Nueva.getFactura();
            }
            ///GUARDO EN EL ARCHIVO EL NUMERO DE FACTRA Y NRO CLIENTE
            /**if(Nueva.Guardo()){
                cout<<"Se grabó correctamente";
            }
            cout<<"\nBusco\n";
            Nueva.Muestro_Guardado();
            cout<<"\nMuestro\n";
            Nueva.getNro_Factura();*/
            /**{
            int CodProducto, CantProducto;
            char Descrip[20];
            float Precios;
            Vent.setNro_Factura(Nueva.getNro_Factura());///guardo el Nro_Fact en Ventas VERRRRRRRRRR
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
            Nueva.~Factura();
            Vent.~Ventas();
            Prod.~Producto();
        }*/
        break;
        case 2:{
            Factura Nueva;
            ///Ventas Vent;
            int Cliente=-1;
            cout<<"\nINGRESE CLIENTE: "; cin>>Cliente;
            ///Vent.getVentas();
            Nueva.~Factura();
            ///Vent.~Ventas();
        }

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
