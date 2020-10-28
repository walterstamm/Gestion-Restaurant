#ifndef PEDIDO_H_INCLUDED
#define PEDIDO_H_INCLUDED
#include "Fecha.h"
class Pedido{

    private:
        ///hereda ID de provedor
        int Codigo_Producto;
        int Cantidad;
        Fecha Fecha_Entrega;
        bool Estado;
    public:
        Pedido();///Constructor
        ~Pedido();///Destructor

        void setFecha();///establece la fecha

        bool Cargar_Pedido();///carga todos los valores del pedido
        void Mostrar_Pedido();///muestra el pedido
        void setCodigo_Producto(int);
        void setCantidad(int);
        void setEstado(bool);
        int getCodigo_Producto();
        int getCantidad();
        bool getEstado();

};

#endif // PEDIDO_H_INCLUDED
