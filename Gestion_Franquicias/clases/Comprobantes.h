#ifndef COMPROBANTES_H_INCLUDED
#define COMPROBANTES_H_INCLUDED
#include "Fecha.h"


class Encabezado{
    private:
        char Razon_Social[20];///Fisica o Jurídica dependiendo de
        char Cuit[13];
        char Direccion[40];///Calle Nro Localidad
        char Localidad_Provincia[30];
        char Telefono[14];
        Fecha Fecha_Inicio_Activ;

    public:
        Encabezado();///CONSTRUCTOR
        ~Encabezado();///DESTRUCTOR
        void setFecha_ini(Fecha);

        char *getRazon_Social();///Fisica o Jurídica dependiendo de
        char *getCuit();
        char *getDireccion();///Calle Nro
        char *getLocalidad_Provincia();///LOCALIDAD - PROVINCIA
        char *getTelefono();///011-2222-2222
        Fecha getFecha_inic();

        void setCargar_Encabezado(char *, char *, char *, char *, char *);
        void getMostrar_Encabezado();
        ///Fecha Fecha_Inicio_Activ(int, int, int);

};


#endif // COMPROBANTES_H_INCLUDED
