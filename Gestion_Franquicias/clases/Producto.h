#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

class Producto{
    private:
        int ID;
        char Nombre [50];
        float Precio;
        int Cantidad;
        int Cantidad_Minima;
    public:
        Producto();
        bool Cargar_Producto();///cargar los valores del producto
        bool Cargar_Producto_Disco();///cargar el producto en disco
        bool Sacar_Disco(int=0);///obtener x producto de disco con un contador
        void mostrar();///mostrar producto 1x1
};

#endif // PRODUCTO_H_INCLUDED
