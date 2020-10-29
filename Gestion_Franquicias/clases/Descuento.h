#ifndef DESCUENTO_H_INCLUDED
#define DESCUENTO_H_INCLUDED
#include "Fecha.h"

class Descuento{
    private:
        bool Estado;
        float Monto, Porcentaje;
        int ID;
        Fecha Actual;
    public:
        Descuento();
        void Cargar_Descuento();
        void ListarDescuento();
        bool Guardar_Descuento();
        int Buscar_Descuento_ID(int =0);
        bool ModificarDescuento(int);
        bool getID(){return ID;}
        float getMonto(){return Monto;}
        float getPorcentaje(){return Porcentaje;}
};

bool Validar_ID_Descuento(int);


#endif // DESCUENTO_H_INCLUDED
