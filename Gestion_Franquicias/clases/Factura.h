#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED
#include "Fecha.h"
#include "ui.h"
///#include "Menu_Principal.h"

class Factura{
    private:
        int Nro_Factura;
        ///Fecha Fecha_Venta;
        int Nro_Cliente;
        float Total_Pagar;
        int Nro_Fact;
        ///Fecha Fecha_Venta
    public:
        Factura();
        ~Factura();
        void setFactura(int);
        void getFactura();
        int Leo_Factura();

};



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
        case 1:

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

#endif // FACTURA_H_INCLUDED
