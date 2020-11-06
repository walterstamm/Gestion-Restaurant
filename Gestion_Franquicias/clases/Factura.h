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
        bool Estado;
    public:
        Factura();
        ~Factura();
        void setFactura(int);
        void setNroFact(int);
        void getFactura();
        int getNro_Factura();
        int Leo_Factura();
        bool Guardo();
        void Muestro_Guardado();
        int BajaLogicaFactura();
};

int GeneroNuevaFactura();
void Mostrar_ResumenVenta();
void Mostrar_TodaVenta();



#endif // FACTURA_H_INCLUDED
