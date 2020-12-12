#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include "Fecha.h"

class Producto{
    private:
        int ID;
        bool Estado;
        char Nombre [50];
        float Precio;
        int Cantidad;
        int Cantidad_Minima;
    public:
        Producto();
        bool Cargar();
        void cabecera();
        void Mostrar();
        void Cargar_Cantidad();

        ///gets
        int getID(){return ID;}
        bool getEstado(){return Estado;}
        char *getNombre(){return Nombre;}
        float getPrecio(){return Precio;}
        int getCantidad(){return Cantidad;}
        int getCantidad_Minima(){return Cantidad_Minima;}

        ///sets
        void setID(int _ID){ID=_ID;}
        void setEstado(int _Estado){Estado= _Estado;}
        void setCantidad(int _cantidad){Cantidad=_cantidad;}
        void setPrecio(float _Precio){Precio=_Precio;}
        void setCantidad_Minima(int _cantidadMinima){Cantidad_Minima=_cantidadMinima;}

        ///archivos
        bool Guardar();
        bool Modificar(int);
        bool LeerPos(int);
        int GenerarID();
};


bool ValidarID_Producto(int);///validad ID (existe=true, no existe=false)

#endif // PRODUCTO_H_INCLUDED
