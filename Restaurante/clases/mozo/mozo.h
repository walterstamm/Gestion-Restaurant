#ifndef MOZO_H_INCLUDED
#define MOZO_H_INCLUDED

class mozo{
    private:
        int ID;
        char nombre[30];
        char apellido [30];
        int CantidadVendida;
        bool estado;
    public:
        mozo();
        void Cargar();
        void mostrar();
        char *getnombre();
        char *getapellido();
};

#endif // MOZO_H_INCLUDED
