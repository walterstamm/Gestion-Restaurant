#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include "Factura.h"

class Ventas{
    private:
        Factura Nro_Fact;
        int Cod_Producto;
        char Descripcion[20];
        int Cant_Producto;
        float Precio;
        float Importe;

    public:
             Ventas();
            ~Ventas();
        void setCod_Producto();
        void setDescripcion();
        void setCant_Producto();
        void setPrecio();
        void setImporte();
        void Cargar_Venta(int, int, float);
        void getVentas();
};

#endif // VENTAS_H_INCLUDED
