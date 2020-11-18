#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include "Fecha.h"

class Producto{
private:
    int ID_Lote;
    int ID;
    bool Estado_Lote;
    bool Estado;
    char Nombre [50];
    float Precio;
    int Cantidad;
    int Cantidad_Minima;
    Fecha Actual;
    Fecha Vencimiento;
public:
    Producto();
    bool Cargar();
    void Mostrar();

    ///gets
    int getIDLote(){return ID_Lote;}
    bool getEstadoLote(){return Estado_Lote;}
    int getID(){return ID;}
    bool getEstado(){return Estado;}
    char *getNombre(){return Nombre;}
    float getPrecio(){return Precio;}
    int getCantidad(){return Cantidad;}
    int getCantidad_Minima(){return Cantidad_Minima;}

    ///sets
    void setIDLote(int _ID){ID_Lote=_ID;}
    void setID(int _ID){ID=_ID;}
    void setEstadoLote(int _Estados){Estado_Lote= _Estados;}
    void setEstado(int _Estado){Estado= _Estado;}
    void setCantidad(int _cantidad){Cantidad=_cantidad;}
    void setPrecio(float _Precio){Precio=_Precio;}
    void setCantidad_Minima(int _cantidadMinima){Cantidad_Minima=_cantidadMinima;}

    ///archivos
    bool Guardar();
    bool Modificar(int);
    int GenerarID(int);///Genera ID automatico
    bool LeerPos(int);
};


bool ValidarID_Producto(int);///validad ID (existe=true, no existe=false)

#endif // PRODUCTO_H_INCLUDED
