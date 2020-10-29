#ifndef PROVEEDORES_H_INCLUDED
#define PROVEEDORES_H_INCLUDED

#include "Producto.h"

class proveedore{
private:
    int ID;
    char Nombre[50];
    int Telefono;
    char Nota[200];
public:
    proveedore(){ Telefono=0;};
    void Cargar_Proveedore();
    void Listar_Proveedores();
    bool Guardar_Proveedore();
    bool Eliminar_Proveedor();
};

#endif // PROVEEDORES_H_INCLUDED
