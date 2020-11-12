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
        void setEstado(bool);
        void setTotal_Pagar(float);
        float setImporte();

        void getFactura();
        int getNro_Factura();
        int getNros_Factura();
        Fecha getFecha();
        int getNroCliente();
        float getTotal_Pagar();
        bool getEstado();
        int Leo_Ultima_Factura();
        bool Guardo();
        void Muestro_Guardado();
        int BuscarPosicionFactura(int);


};

int GeneroNuevaFactura();
void Mostrar_ResumenVenta();
void Mostrar_TodaVenta();
void Mostrar_Facturas_Eliminadas();
void SumarVentas();
void Menu_Reportes();
void Mostrar_Rotulo_Factura();
void Mostrar_Comprobante();
void Facturas_Fecha();
void Ventas_Fecha();



#endif // FACTURA_H_INCLUDED
