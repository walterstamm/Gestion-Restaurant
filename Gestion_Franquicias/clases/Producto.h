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
        bool Cargar_Producto();///cargar los valores del producto
        bool Cargar_Producto_Disco();///cargar el producto en disco
        bool setSacar_Disco(int=0);///obtener x producto de disco con un contador
        void mostrar_Producto();///mostrar producto 1x1
        void Modificar_Cantidad();
        void Modificar_Cantidad_Minima();
        bool setModificar_Producto(int);///recive la posicion a modificar
        int setRetornar_ID(int);///retorna la posicion el producto o -1 si no existe el ID
        bool Eliminar_Producto();
};

#endif // PRODUCTO_H_INCLUDED
