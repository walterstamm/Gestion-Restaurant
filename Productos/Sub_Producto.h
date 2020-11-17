#ifndef SUB_PRODUCTO_H_INCLUDED
#define SUB_PRODUCTO_H_INCLUDED

#include "Fecha.h"

class Sub_Producto{
    private:
        int ID;
        char Nombre [50];
        float Precio;
        int Cantidad;
        int Cantidad_Minima;
        bool Estado;
        Fecha Actual;
        Fecha Vencimiento;
    public:
        Sub_Producto();
        bool Cargar();
        void Mostrar();

        ///gets
        int getID(){return ID;}
        char *getNombre(){return Nombre;}
        float getPrecio(){return Precio;}
        int getCantidad(){return Cantidad;}
        int getCantidad_Minima(){return Cantidad_Minima;}
        bool getEstado(){return Estado;}

        ///sets
        void setID(int _ID){ID=_ID;}
        void setCantidad(int _cantidad){Cantidad=_cantidad;}
        void setPrecio(float _Precio){Precio=_Precio;}
        void setCantidad_Minima(int _cantidadMinima){Cantidad_Minima=_cantidadMinima;}
        void setEstado(int _Estado){Estado= _Estado;}
};

#endif // SUB_PRODUCTO_H_INCLUDED
