#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include "Sub_Producto.h"

class Producto{
private:
    int ID;
    bool Estados;
    Sub_Producto Productos;
public:
    Producto(){Estados=true;}
    bool Cargar();
    void Mostrar();

    ///gets
    int getID(){return ID;}
    bool getEstados(){return Estados;}

    ///sets
    void setID(int _ID){ID=_ID;}
    void setEstados(int _Estados){Estados= _Estados;}

    ///archivos
    bool Guardar();
    int GenerarID(int);
    bool LeerPos(int);
    bool Modificar(int);

    ///Ventas
    bool ventas(char &, int &, float &); ///por referencia nombre, cantidad, precio
};


bool ValidarID_Producto(int);///validad ID (existe=true, no existe=false)
bool BuscarPoscicion_Producto(int, int &);///Buscar Posicion archivo

#endif // PRODUCTO_H_INCLUDED
