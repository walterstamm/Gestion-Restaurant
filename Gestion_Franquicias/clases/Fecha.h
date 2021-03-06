#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(bool =true);///cargara la fecha actual por defecto
        bool Cargar_Fecha();///retorna true si fue bien ingresada y false si fue mal ingresada
        bool Cargar_Fecha_Vencimiento();
        void Mostrar_Fecha();
        bool RetornarFechaVencimiento(); ///retorna si la fecha no paso de la fecha actual
        Fecha setFechaHoy();
        int getDia(){ return dia;}
        int getMes(){ return mes;}
        int getAnio(){ return anio;}
	///sobrecarga
        bool operator <(Fecha);
};

#endif // FECHA_H_INCLUDED
