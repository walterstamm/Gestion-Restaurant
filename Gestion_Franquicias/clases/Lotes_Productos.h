#ifndef LOTES_PRODUCTOS_H_INCLUDED
#define LOTES_PRODUCTOS_H_INCLUDED
#include "Fecha.h"

/*

class Lotes_Prod{
    private:
        int Id_Lote;
        int Id_CodProd;
        int Cantidad;
        Fecha Fe_Vto;
        bool Estado;
    ///HAY QUE TENER EN CUENTA SI EL PEDIDO INGRESO
    ///SI INGRESO SE TOMA EN CUENTA PARA SUMAR LA CNATIDAD DE PRODUCTO
    ///SI NO INGRESO EL PEDIDO Y SE ELIMINO POR MOTIVOS EXTAORDINARIOS EL ESTADO 0 Y TAMPOCO SE CARGA
    ///DESCONTAR AL EFECTUAR UNA VENTA
    public:
        Lotes_Prod(){   ///     CONSTRUCTOR
                    Id_Lote=0;
                    Id_CodProd=0;
                    Cantidad =0;
                    ///Fecha().Cargar_Fecha_Vencimiento();
                    Estado=false;}
        ~Lotes_Prod(){}  ///     DESTRUCTOR
        ///     SET

<<<<<<< Updated upstream
        void CargarAlgunosPrueba();
        bool Grabar_Lotes_Prod();

        void setId_Lote(int Id){ Id_Lote = Id;}
        void setId_CodProd(int CodProd){ Id_CodProd = CodProd;}
        void setCantidad(int Cant){ Cantidad = Cant; }
        Fecha setFe_Vto(Fecha){Fecha().Cargar_Fecha(); }
        void setEstado_true(){ Estado = true;}
        void setEstado_false(){ Estado = false;}
        ///     GET
        int getLid(){ return Id_Lote;}
        int getId_CodProd(){ return Id_CodProd;}
        int getCantidad(){ return Cantidad; }
        ///Fecha getFe_Vto(Fecha){ return Fecha().Mostrar_Fecha();}
        bool setEstado(){ return Estado;}
=======
*/

class Lotes_Prod{
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
>>>>>>> Stashed changes
};

void Lotes_Prod::CargarAlgunosPrueba(){
    cout<<" ID LOTE:     ";
    cin>>Id_Lote; ///       HACER QUE SE GENERE EL IDLOTE DE MANERA AUTOMATICA.
    cout<<" ID CODPROD:  ";
    cin>>Id_CodProd;
    cout<<" CANTIDAD:    ";
    cin>>Cantidad;
    cout<<"FECHA FE VTO  ";
    Fe_Vto.Cargar_Fecha();
    cout<<" ESTADO:      ";
    cin>>Estado;

    int Grabo = Grabar_Lotes_Prod();
    if(Grabo){cout<<"Grabo"; system("pause");}
}

bool Lotes_Prod::Grabar_Lotes_Prod(){
    FILE *P = fopen("archivos/Lotes_Prod.dat", "ab");
    if(P == NULL){ return false;}
    return (fwrite(this, sizeof(Lotes_Prod), 1, P));
}












#endif // LOTES_PRODUCTOS_H_INCLUDED
