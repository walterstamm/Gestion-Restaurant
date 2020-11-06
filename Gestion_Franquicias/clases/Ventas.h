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
        void setCod_Producto();
        void setDescripcion();
        void setCant_Producto();
        void setPrecio(float);
        void setImporte();
        void Cargar_Venta(int , int , char *, int , float , float );
        void getVentas();
        int getCod_Producto();
        char *getDescripcion();
        int getCant_Producto();
        float getPrecio();
        float getImporte();
        void getVentas(int);
        Factura getNro_Fact();
        int Leo_Ventas();
        int BuscarPosicion(int);
};

void Encabezado();

#endif // VENTAS_H_INCLUDED
