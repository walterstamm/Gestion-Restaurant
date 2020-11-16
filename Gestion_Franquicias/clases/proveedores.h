#ifndef PROVEEDORES_H_INCLUDED

#include "Producto.h"

class proveedore{
private:
    int ID;
    char Nombre[50];
    int Telefono;
    char Nota[200];
    bool Estado;
public:
    proveedore(){ Telefono=0 ;};
    void Cargar_Proveedore();
    void Listar_Proveedores();
    bool Guardar_Proveedore();
    bool Guardar_Cambios();
    bool Eliminar_Proveedor();
    void setEstado(bool);
    bool getEstado();
    int getID();
    void setTelefono(int);
    int getTelefono();
    void setNombre(char *nuevoNombre);
    char *getNombre();
    void setNota(char *nuevaNota);
    char *getNota();
    int posicionProveedor(int);
    int CantidadProvedores();

};

#endif // PROVEEDORES_H_INCLUDED
