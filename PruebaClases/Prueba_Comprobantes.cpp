#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;


/**class Encabezado{
    private:
        char Razon_Social[20];///Fisica o Jurídica dependiendo de
        char Cuit[13];
        char Direccion[40];///Calle Nro Localidad
        char Localidad_Provincia[30];
        char Telefono[14];
///        Fecha Fecha_Inicio_Activ;

    public:
        Encabezado();///CONSTRUCTOR
        ~Encabezado();///DESTRUCTOR
///        void setFecha_ini(Fecha);

        char *getRazon_Social();///Fisica o Jurídica dependiendo de
        char *getCuit();
        char *getDireccion();///Calle Nro
        char *getLocalidad_Provincia();///LOCALIDAD - PROVINCIA
        char *getTelefono();///011-2222-2222
///        Fecha getFecha_inic();


        void setCargar_Encabezado(char *, char *, char *, char *, char *);
        void getMostrar_Encabezado();
///        Fecha Fecha_Inicio_Activ(int, int, int);

};

///CONTRUCTOR DE LA CLASE ENCABEZADO
Encabezado::Encabezado(){///char R_Social, char cuit, char Direc, char Local, char Tel){
    cout<<"Los atributos de encabbezado estan vacios \n";
    strcpy(Razon_Social, "");
    strcpy(Cuit, "");
    strcpy(Direccion, "");
    strcpy(Localidad_Provincia, "");
    strcpy(Telefono, "");

}
Encabezado::~Encabezado(){ ///DESTRUCTOR
}
char *Encabezado::getRazon_Social(){
    return Razon_Social;
}
char *Encabezado::getCuit(){
    return Cuit;
}
char *Encabezado::getDireccion(){
    return Direccion;
}
char *Encabezado::getLocalidad_Provincia(){
    return Localidad_Provincia;
}
char *Encabezado::getTelefono(){
    return Telefono;
}
void Encabezado::setCargar_Encabezado(char *R_Social, char *cuit, char *Direc, char *Local, char *Tel){
    strcpy(Razon_Social, R_Social);
    strcpy(Cuit, cuit);
    strcpy(Direccion, Direc);
    strcpy(Localidad_Provincia, Local);
    strcpy(Telefono, Tel);
}
void Encabezado::getMostrar_Encabezado(){
    cout<<"Razon Social:      "<<getRazon_Social()<<endl;
    cout<<"Cuit:              "<<getCuit()<<endl;
    cout<<"Dirección Empresa: "<<getDireccion()<<endl;
    cout<<"Localidad y Prov:  "<<getLocalidad_Provincia()<<endl;
    cout<<"Telefono:          "<<getTelefono()<<endl;
}*/

class Factura{
    private:
        int Nro_Factura;
        ///Fecha Fecha_Venta;
        int Nro_Cliente;
        float Total_Pagar;

        int Nro_Fact;
///        Fecha Fecha_Venta

    public:
        Factura();
        ~Factura();
        void setFactura(int);
        void getFactura();
        int Leo_Factura();

};

Factura::Factura(){
    cout<<"CONSTRUCTOR\n";
    Nro_Factura = 0;
///    Fecha_Venta = NULL;
    Nro_Cliente = 0;
    Total_Pagar=0;
}

Factura::~Factura(){
    cout<<"\nDESTRUCTOR\n";
}

void Factura::setFactura(int Cliente){

    Nro_Factura = Leo_Factura()+1;
    Nro_Cliente = Cliente;
    ///Fecha_Venta = xxx;
    Total_Pagar=0;

}

int Factura::Leo_Factura(){
    cout<<"\nNro_Factura\n";
    int Nuevo_Nro=0, Viejo_Nro;
    ///BUSCAR EN ARCHIVO EN EL ULTIMO REGISTRO EL NUMERO
    ///ME DEVUELVE EL NUMERO VIEJO
    Viejo_Nro=3;
    Nuevo_Nro = Viejo_Nro+1;
}

void Factura::getFactura(){
    cout<<"\nFactura::getMostrar_Factura()";
    cout<<"\nNro_Fact: "<<Nro_Factura;
    cout<<"\nNro_Cliente: "<<Nro_Cliente;
    cout<<"\nTotal_Factura: "<<Total_Pagar;

}


///     VENTA DEBE SER HIJO DE FACTURA
/**class Venta{
    private:
        Nro_Factura();


};*/

int main(){


/**    Encabezado Empresa;

    Empresa.getMostrar_Encabezado();

    char R_Social[30], cuit[14], Direc[40], Local[30], Tel[14];
    cin.ignore();
    cout<<"Razon social:           ";
    cin.getline(R_Social, 30);
    cout<<"Cuit:                   ";
    cin.getline(cuit, 14);
    cout<<"Dirección: Calle y Nro: ";
    cin.getline(Direc, 40);
    cout<<"Localidad y Provincia:  ";
    cin.getline(Local, 30);
    cout<<"Telefono:               ";
    cin.getline(Tel, 14);


    ///Empresa.setCargar_Encabezado();
    Empresa.setCargar_Encabezado(R_Social, cuit, Direc, Local, Tel);

    cout<<"Mostrar encabezado \n"<<endl;
    Empresa.getMostrar_Encabezado();*/

    Factura Fact;

    int Cliente;
    cout<<"Ingrese Nro Cliente: "<<Cliente;
    Fact.setFactura(Cliente);
    ///Fact.getMostrar_Factura(10);
    Fact.getFactura();
    cout<<"Número: \n"<<Fact.Leo_Factura();

    ///Fact.getMostrar_Factura(10);

    cout<<"Número: \n"<<Fact.Leo_Factura();


    return 0;
}
