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
        bool Cargar_Descuento();
        void ListarDescuento();
        bool Guardar_Descuento();
        int Buscar_Descuento_ID(int =0);
        bool ModificarDescuento(int);
        int getID(){return ID;}
        float getMonto(){return Monto;}
        float getPorcentaje(){return Porcentaje;}
        bool getEstado(){return Estado;}
        void setMonto(float _Monto){Monto=_Monto;}
        void setPorcentaje(float _Porcentaje){Porcentaje=_Porcentaje;}
        void setEstado(bool _Estado){Estado=_Estado;}
        float GenerarDescuento(float);
};

bool Validar_ID_Descuento(int);
float GenerarDescuento(float);

#endif // DESCUENTO_H_INCLUDED
