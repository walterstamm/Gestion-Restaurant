#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include "Factura.h"

class Ventas{
    private:
        Factura Nro_Factura;
        int Cod_Producto;
        char Descripcion[20];
        int Cant_Producto;
        float Precio;
        float Importe;

    public:
        Ventas();
        ~Ventas();
        void setNro_Factura(int);
        Factura getNro_Fact(Factura);
        void setCod_Producto();
        void setDescripcion();
        void setCant_Producto();
        void setPrecio(float);
        void setImporte();
        void Cargar_Venta(int, int , char *, int, float);
        void getVentas();
};

#endif // VENTAS_H_INCLUDED
