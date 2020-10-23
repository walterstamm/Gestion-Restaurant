#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED

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


#endif // FACTURA_H_INCLUDED
