#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED
#include "Fecha.h"
#include "ui.h"


class Factura{
    private:
        int Nro_Fact;
        ///Fecha Fecha_Venta;
        int Nro_Cliente;
        float Total_Pagar;

    public:
        Factura();
        ~Factura();
        void setFactura(int);
        void getFactura();
        int Leo_Factura();
        bool Guardo();
        void Muestro_Guardado();
};



void MENU_FACTURACION(){
    int Opcion;
    while(Opcion){
        title("MEN� FACTURACI�N", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

        cout<<"\n============================================";
        cout<<"\n01-Ingresar Producto........................";
        cout<<"\n02-";
        cout<<"\n============================================";
        cout<<"\n00- Volver al MEN� PRINCIPAL................";
        cout<<"\n============================================";
        cout<<"\nOpci�n: "; cin>>Opcion;
        cout<<"\n============================================";

    switch(Opcion){
        case 1:{
            Factura Nueva;
            int Cliente=-1;
            cout<<"\nINGRESE CLIENTE: "; cin>>Cliente;
            Nueva.setFactura(Cliente);
            if(Nueva.Guardo()){
                cout<<"Se grab� correctamente";
            }
            cout<<"\nBusco\n";
            Nueva.Muestro_Guardado();
            cout<<"\nMuestro\n";
            Nueva.getFactura();

        }
        break;
        case 2:

        break;
        case 0:
            return;
        break;
        default:
            cout<<"\nIngrese la opci�n correcta";
        break;



    }

    }


}

#endif // FACTURA_H_INCLUDED
