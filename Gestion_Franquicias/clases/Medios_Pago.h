#ifndef MEDIOS_PAGO_H_INCLUDED
#define MEDIOS_PAGO_H_INCLUDED

class Medio_Pago{
    private:
        char Medio [10];
        float Monto, Descuento; ///habria que ingresar la fecha del dia que quiere realizar el descuento?
    public:
        Medio_Pago();
        void Cargar_Descuento();
        bool Guardar_Descuento();
        bool Quitar_Descuento();
        bool Buscar_Descuento_Memoria(int =0);
        void Listar_Descuentos();
};

#endif // MEDIOS_PAGO_H_INCLUDED
