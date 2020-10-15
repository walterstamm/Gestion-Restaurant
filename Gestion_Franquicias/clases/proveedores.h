#ifndef PROVEEDORES_H_INCLUDED
#define PROVEEDORES_H_INCLUDED

#include "Producto.h"

class proveedore{
private:
    int ID;
    char Nombre[50];
    Producto Uno;
    int Telefono;
    char Nota[200];
public:
    proveedores(){};
    void Cargar_Proveedore();
    bool Guardar_Proveedore();
    bool Eliminar_Proveedor();
};

#endif // PROVEEDORES_H_INCLUDED
