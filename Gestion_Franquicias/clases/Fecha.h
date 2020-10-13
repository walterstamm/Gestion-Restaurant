#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha();///cargara la fecha actual por defecto
        bool Cargar_Fecha();///retorna true si fue bien ingresada y false si fue mal ingresada
        bool Cargar_Fecha_Vencimiento();
        void Mostrar_Fecha();
};

#endif // FECHA_H_INCLUDED
