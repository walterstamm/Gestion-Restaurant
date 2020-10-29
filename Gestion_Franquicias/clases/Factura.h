#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED
#include "Fecha.h"
#include "ui.h"


class Factura{
    private:
        int Nro_Fact;
        Fecha Fecha_Factura;
        int Nro_Cliente;
        float Total_Pagar;

    public:
        Factura();
        ~Factura();
        void setFactura(int);
        int getFactura();
        int Leo_Factura();
        bool Guardo();
        void Muestro_Guardado();
        void setfecha(Fecha);
        Fecha getfecha();
};




#endif // FACTURA_H_INCLUDED
