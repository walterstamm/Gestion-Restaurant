#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;



class Encabezado{
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

        char *getRazon_Social();///Fisica o Jurídica dependiendo de
        char *getCuit();
        char *getDireccion();///Calle Nro
        char *getLocalidad_Provincia();///LOCALIDAD - PROVINCIA
        char *getTelefono();///011-2222-2222


        void setCargar_Encabezado(char *, char *, char *, char *, char *);
        void getMostrar_Encabezado();
   ///     Fecha Fecha_Inicio_Activ(int, int, int);

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
}

class Factura{
    private:
        int Nro_Fact;
        Fecha Fecha_Venta;
        int Nro_Cliente;

    public:
        Factura();
        void setCrear_Factura(int);
        void getMostrar_Factura(int);

};

Factura::Factura(){
    Nro_Fact = NULL;
    Fecha_Venta = NULL;
    Nro_Cliente = NULL;
}

void Factura::setCrear_Factura( int Cliente){
    Nro_Fact=Nro_Factura();
    Fecha_Venta = xxx;
    Nro_Cliente = Cliente;
}

void Factura::getMostrar_Factura(int Nro){

    cout<<"Factura Nro: "<<Nro_Fact;
    FILE *Fact;
    Fact=fopen("Factura.dat", "rb");
    if(Fact==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO FACTURA.DAT";
        system("pause");
        return;
    }
    while(fread(Fact, sizeof(Factura), 1, Fact )){
        if(Nro_Fact == Nro){
            cout<<"MUESTRO LOS REGISTROS DE VENTAS [Nro fac,Cod_Prod, Descripcion, Cant, Precio_Unit, Sub_Total ";
            cout<<"MUESTRO TODO MENOS EL NRO FAC";
        }
    }




}
int Nro_Factura(){

    ///tengo que crear un numero que continue al ya existente
    return Numero=1;
}

///     VENTA DEBE SER HIJO DE FACTURA
class Venta{
    private:
        Nro_Factura()


};

int main(){
    Encabezado Empresa;

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
    Empresa.getMostrar_Encabezado();

    return 0;
}

