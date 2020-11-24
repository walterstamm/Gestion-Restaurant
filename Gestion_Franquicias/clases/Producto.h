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
        bool Estado_sublote;
        Fecha Actual;
        Fecha Vencimiento;
    public:
        Producto();
        bool Cargar_Producto(); ///CUANDO SE CARGA POR PRIMERA VEZ
        void Mostrar_Producto();
        void Encabezado();
        bool GuardarProducto();
        int Buscar_Producto_ID(int); ///busca el producto por ID y devuelve la posicion del producto
        bool LeerPos(int);

        void Mostrar_Alerta();
        void Encabezado_Alerta();
        ///get
        int getID(){return ID;}
        char *getNombre(){return Nombre;}

        float getPrecio(){return Precio;}
        int getCantidad(){return Cantidad;}
        bool getEstado(){return estado;}
        bool getCantidad_Minima(){return Cantidad_Minima;}
        int getCantidad_Cod(int);
        bool ModificarProducto(int); ///recibe la posicion en memoria del producto
        ///set
        void setMod_Cantidad(int Modif) {Cantidad += Modif;}
        void setCantidad(int _cantidad){Cantidad=_cantidad;}
        void setCantidadMinima(int _cantidadMinima){Cantidad_Minima=_cantidadMinima;}
        void setEstado(int _estado){estado= _estado;}
        void setPrecio(float _Precio){Precio=_Precio;}
        bool ValidarCantidadProducto(int);///valida que la cantidad vendida no sobrepase la cantidad existente
};

bool ValidarIDProducto(int); ///validad que el ID no exista
int GenerarID();///Genera ID automatico

#endif // PRODUCTO_H_INCLUDED
