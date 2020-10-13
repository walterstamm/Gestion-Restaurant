#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

class Producto{
    private:
        int ID;
        char Nombre [30];
        float Precio;
        int Cantidad;
        int Cantidad_Minima;
    public:
        Producto();
        void setCargar_Nombre(char *);
        char *getMostrar_Nombre();

};

#endif // PRODUCTO_H_INCLUDED
