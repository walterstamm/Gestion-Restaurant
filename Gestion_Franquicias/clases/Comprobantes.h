#ifndef COMPROBANTES_H_INCLUDED
#define COMPROBANTES_H_INCLUDED
#include "Fecha.h"


class Encabezado{
    private:
        char Razon_Social[20];///Fisica o Jurídica dependiendo de
        char Ciut[13];
        char Direccion[40];///Calle Nro Localidad
        char Localidad_Provincia[30];
        char Telefono[14];
        Fecha Fecha_Inicio_Activ;

    public:
        Encabezado();
        void setRazon_Social(char);
        void setCiut(char);
        void setDireccion(char);///Calle Nro Localidad
        void setLocalidad_Provincia(char);
        void setTelefono(char);
        Fecha fecha_Inicio_Activ(int, int, int);

};

class Factura:public Encabezado{
    private:


    public:


};


#endif // COMPROBANTES_H_INCLUDED
