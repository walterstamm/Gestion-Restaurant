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




#endif // FACTURA_H_INCLUDED
