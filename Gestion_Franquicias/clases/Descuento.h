#ifndef DESCUENTO_H_INCLUDED
#define DESCUENTO_H_INCLUDED
#include "Fecha.h"

class Descuento{
    private:
        bool Valides, Estado;
        float Monto;
        int ID;
        Fecha Actual;
    public:
        Descuento();
        void Cargar_Descuento();
        bool Guardar_Descuento();
        bool Buscar_Descuento(int =0);
};

#endif // DESCUENTO_H_INCLUDED
