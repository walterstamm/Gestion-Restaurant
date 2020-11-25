#ifndef LOTE_H_INCLUDED
#define LOTE_H_INCLUDED

#include "Fecha.h"

class Lote_Produ{
    private:
        int IDlote, IDproducto, Cantidad;
        bool Estado;
        Fecha Vencimiento;
    public:
        Lote(){Estado=true;}

        ///gets
        int getIDlote(){return IDlote;}
        int getIDproducto(){return IDproducto;}
        int getCantidad(){return Cantidad;}
        bool getEstado(){return Estado;}

        ///sets
        void setIDlote(int _IDlote){IDlote=_IDlote;}
        void setIDproducto(int _IDproducto){IDproducto= _IDproducto;}
        void setCantidad(int _cantidad){Cantidad=_cantidad;}
        void setEstado(int _Estado){Estado= _Estado;}

        ///memoria
        bool Guardar();
        bool Modificar(int);
        bool LeerPos(int);
        int GenerarID();
};

#endif // LOTE_H_INCLUDED
