#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include "Fecha.h"

class Producto{
    private:
        int ID;
        char Nombre [50];
        float Precio;
        int Cantidad;
        int Cantidad_Minima;
        bool estado;
        Fecha Actual;
        Fecha Vencimiento;
    public:
        Producto();
        bool Cargar_Producto();
        void Mostrar_Producto();
        bool GuardarProducto();
        int Buscar_Producto_ID(int); ///busca el producto por ID y devuelve la posicion del producto
        char *getNombre(){return Nombre;}
        float getPrecio(){return Precio;}
        int getCantidad(){return Cantidad;}
        bool getEstado(){return estado;}
        bool ModificarProducto(int); ///recibe el ID de la posicion en memoria del producto
        void setCantidad(int _cantidad){Cantidad=_cantidad;}
        void setCantidadMinima(int _cantidadMinima){Cantidad_Minima=_cantidadMinima;}
        void setEstado(int _estado){estado= _estado;}

};


#endif // PRODUCTO_H_INCLUDED
