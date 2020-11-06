#include<iostream>
#include<cstdlib>
#include<cstdio>
#include <stdio.h>
#include<cstring>
#include <iomanip>
using namespace std;
#include "Comprobantes.h"
#include "Factura.h"

///CONTRUCTOR DE LA CLASE ENCABEZADO
Encabezado::Encabezado(){///char R_Social, char cuit, char Direc, char Local, char Tel){
    cout<<"Los atributos de encabbezado estan vacios \n";
    strcpy(Razon_Social, "");
    strcpy(Cuit, "");
    strcpy(Direccion, "");
    strcpy(Localidad_Provincia, "");
    strcpy(Telefono, "");

}
Encabezado::~Encabezado(){
}

void Encabezado::setRazon_Social(){///Fisica o Jurídica dependiendo de
    cout<<"Ingrese la Razon Social"<<endl;
    cin.ignore();
    cin.getline(Razon_Social, 30);
}

///PREGUNTAR SI CONVIENE O SOLO INGRESAMOS LOS 11 DIGITOS DIRECTAMENTE PUEDO
///HACER CON UN WHILE QUE CONFIRME LO INGRESADO O VOLVER A INGRESAR.
void Encabezado::setCuit(){
    cout<<"Ingrese el CUIT: ejemplo 00-00000000-0"<<endl;
    cin.ignore();
    cin.getline(Cuit, 15);
    /**cout<<"Ingrese el tipo de cuit:";
    cout<<"Fisica: Hombre 20, Mujer 23, Repetido 24"<<endl;
    cout<<"Jurídica: Empresa 30, Repetido 33"<<endl;
    cin.getline(Tipo, 2);
    cout<<"Ingrese dique el Número sin puntos:";
    cin.getline(Numero, 8);
    cout<<"Ingrese el Digito Verificador:";
    cin.getline(Dig, 1);*/

}
void Encabezado::setDireccion(){///Calle Nro
    cout<<"Ingrese la Calle/Avenida y Nro/ Referencias: "<<endl;
    cin.ignore();
    cin.getline(Direccion, 40);
}
void Encabezado::setLocalidad_Provincia(){ ///LOCALIDAD - PROVINCIA
    cout<<"Ingrese la Localidad y Provincia: "<<endl;
    cin.ignore();
    cin.getline(Localidad_Provincia, 40);

}
void Encabezado::setTelefono(){ ///011-2222-2222
    cout<<"Ingrese el Telefono: "<<endl;
    cin.ignore();
    cin.getline(Telefono, 40);
}

void Encabezado::setOtros(){ ///PARA EL MAIL - PAGINA - ETC
    cout<<"Ingrese otra informacion de relevancia: "<<endl;
    cin.ignore();
    cin.getline(Otros, 50);
}

/**Fecha Encabezado::setFecha_inic(){
    return -1;
}*/





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

    ///cout << setw(4) << "NROF";
    ///cout << setw(7) << "C�digo " << setw(12) << "Descripcion" << setw(6) << "Cant" << setw(15) << "P. Unidad" << setw(10) << "Importe" << endl;

    cout<<"EMPRESA:           "<<getRazon_Social()<<endl;
    cout<<"Cuit:              "<<getCuit()<<endl;
    cout<<"Dirección:         "<<getDireccion()<<endl;
    cout<<"Localidad y Prov:  "<<getLocalidad_Provincia()<<endl;
    cout<<"Telefono:          "<<getTelefono()<<endl;
}

void Guardar_Archvo(){
    Encabezado Guardar;










}

void Menu_Encabezado(){
    Encabezado Enc;
    int Opcion;
    while(Opcion){
        title("MENU ENCABEZADO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

        cout<<"\n============================================";
        cout<<"\n01-Ingresar Razon Social....................";///<<Enc.getRazon_Social();
        cout<<"\n02-Ingresar Cuit............................";///<<Enc.getCuit();
        cout<<"\n03-Ingresar Dirección Empresa...............";///<<Enc.getDireccion();
        cout<<"\n04-Localidad y Provincia....................";///<<Enc.getLocalidad_Provincia();
        cout<<"\n05-Telefono.................................";///<<Enc.getTelefono();
        cout<<"\n06-Fecha de inicio actividad................"; ///<<Enc.getFecha_inic()
        cout<<"\n07-Mostrar Rotulo de empresa................";
        /// LA IDEA ES QUE SOLO SE CARGUE UNA SOLA VEZ
        cout<<"\n08-Desbloqueo...............................";
        cout<<"\n============================================";
        cout<<"\n00- Volver al MENU PRINCIPAL................";
        cout<<"\n============================================";
        cout<<"\nOpcion: "; cin>>Opcion;
        cout<<"============================================\n";

       switch(Opcion){
            case 1:
                Enc.setRazon_Social();
            break;

            case 2:
                Enc.setCuit();
            break;

            case 3:
                Enc.setDireccion();
            break;

            case 4:
                Enc.setLocalidad_Provincia();
            break;

            case 5:
                Enc.setTelefono();
            break;

            case 6:

            break;

            case 7:
                cout<<"\nRazon Social         : "<<  Enc.getRazon_Social();
                cout<<"\nCuit                 : "<<  Enc.getCuit();
                cout<<"\nDireccion            : "<<  Enc.getDireccion();
                cout<<"\nLocalidad y Provincia: "<<  Enc.getLocalidad_Provincia();
                cout<<"\nTelefono             : "<<  Enc.getTelefono();
///                cout<<"\nFecha Inicio Activ   : "<<  Enc.getFecha_inic();
                cout<<endl;
                system("pause");
            break;

            case 8:

            break;

            case 0:
                return;
            break;

            default :
                cout<<"Debe ingresar un valor del MENU"<<endl;
                system("PAUSE");
            break;


        }
        system("cls");
    }
}


