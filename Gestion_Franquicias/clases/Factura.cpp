#include<iostream>
#include<cstdlib>
#include<cstdio>
#include <stdio.h>
#include<cstring>
#include <iomanip>
using namespace std;
#include "Factura.h"
#include "Fecha.h"
#include "Ventas.h"
#include "Producto.h"

Factura::Factura(){
    Nro_Fact = 0;
    ///cout<<"Fecha 1\n";
    ///Fecha_Factura.Cargar_Fecha();
    Nro_Cliente = 0;
    Total_Pagar=0;
    Estado = true;
}

Factura::~Factura(){
}

void Factura::setNroFact(int Nro){
    Nro_Fact = Nro;
}

int Factura::BajaLogicaFactura(){
    int Nro;
    cout<<"Ingrese el N�mero de Factura a eliminar: ";
    cin>>Nro;
    cout<<endl;
    int pos=0;
    FILE *p=fopen("archivos/Facturas.dat","rb");
        if(p==NULL){
            return -1;
        }
    while(fread(this, sizeof(Factura),1,p)){
        if(Nro == Nro_Fact){
            fclose(p);
            return pos; ///retorna la posicion del archivo
        }
        pos++;
    }
    fclose(p);
    return pos = -1; ///retorna -1 si no encontro.
}

void Factura::setFactura(int Cliente){
    cout<<"NUEVA FACTURA\n";
    Nro_Fact = Leo_Factura()+1;
    Nro_Cliente = Cliente;
    Total_Pagar=0;///FUNCION PARA SUMAR LA VENTA FALTA
}



int Factura::Leo_Factura(){
    FILE *Fact=fopen("archivos/Facturas.dat", "rb");
    if(Fact == NULL){cout<<"No se abrio el Archivo Facturas.dat";}
    ///Vuelve 1 posici�n para leer el registro grabado
    fseek(Fact,-1*sizeof(Factura), SEEK_END); ///tiene un warning osea futuro error
    fread(this, sizeof(Factura), 1, Fact);///Muestro lo grabado recien
    return Nro_Fact;
}

int Factura::getNro_Factura(){
    return Leo_Factura();
}

void Factura::getFactura(){
    system("cls");
}

bool Factura::Guardo(){
    FILE *Fact=fopen("archivos/Facturas.dat", "ab");
    if(Fact == NULL){cout<<"No se abrió el Archivo Facturas.dat"; return false;}
    fwrite(this, sizeof(Factura),1,Fact);///Despues de guardar esta en la ultima posición
    fclose(Fact);
    return true;

}

void Factura::Muestro_Guardado(){///PARA VERIFICAR SI REALMENTE GRABÓ
    FILE *Fact=fopen("archivos/Facturas.dat", "rb");
    if(Fact == NULL){cout<<"No se abrio el Archivo Facturas.dat";}
    ///Vuelve 1 posición para leer el registro grabado
    fseek(Fact,-1*sizeof(Factura), SEEK_END);///tiene un warning osea futuro error
    fread(this, sizeof(Factura), 1, Fact);///Muestro lo grabado recien
}

void MENU_FACTURACION(){
    int Opcion;
    while(Opcion){
        title("MENÚ FACTURACIÓN", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

        cout<<"\n============================================";
        cout<<"\n01-Generar Factura..........................";
        cout<<"\n02-Eliminar Factura.........................";
        cout<<"\n03-Listar Facturas por fecha.(Bool false....";
        cout<<"\n04-Listar Facturas Eliminadas...............";
        cout<<"\n05-Muestro Factura..........................";
        cout<<"\n============================================";
        cout<<"\n00- Volver al MENÚ PRINCIPAL................";
        cout<<"\n============================================";
        cout<<"\nOpción: "; cin>>Opcion;
        cout<<"============================================\n";

       switch(Opcion){
            case 1:
                int NroFactura, Pos;
                int CodProducto, CantProducto;
                char Descrip[20], Mas_Producto;
                float Precios, Importe;

                NroFactura = GeneroNuevaFactura();
                {
                    ///     ABRO OBJETO PRODUCTO
                    Producto Prod;
                    ///     ABRO OBJETO VENTAS
                    Ventas Vent;
                    Mas_Producto='s';
                    while(Mas_Producto == 's' || Mas_Producto == 'S'){
                        cout<<"\nCodProducto: "; cin>>CodProducto;
                        Pos = Prod.Buscar_Producto_ID(CodProducto);
                        FILE *Pr = fopen("archivos/Producto.dat", "rb");
                        if(Pr == NULL){
                                cout<<"No se pudo abrir";
                                return;
                        }
                        ///     ME POSICIONO AL INICIO DEL REGISTRO
                        fseek(Pr, Pos * sizeof(Producto), SEEK_SET);
                        ///PREGUNTO SI CON FREAD SE CARGA EN LA MEORIA DE LA CLASE
                        fread(&Prod, sizeof(Producto), 1, Pr);
                        ///     COPIO EL NOMBRE Y EL PRECIO
                        strcpy(Descrip, Prod.getNombre());
                        Precios=(Prod.getPrecio());
                        ///     CARGO CANTIDAD Y ASIGNO A IMPORTE EL VALOR POR EL REGISTRO
                        cout<<"Ingrese Cantidad de Producto: "; cin>>CantProducto;
                        Importe = Precios * CantProducto;
                        ///     CARGO EL CONTENIDO DE LAS VARIABLES EN VENTAS
                        Vent.Cargar_Venta(NroFactura, CodProducto, Descrip, CantProducto, Precios, Importe);
                        ///GUARDO EN EL ARCHIVO VENTAS
                        FILE *V = fopen("archivos/Ventas.dat", "ab");
                        if(V == NULL) {return;}
                        if(fwrite(&Vent, sizeof(Ventas), 1, V)){
                            cout<<"se grabo. ";
                        }
                        cout<<"Muestro Lo Cargado: "<<endl;
                        cout<<"FacturaNro:  "<<Vent.getNro_Fact().getNro_Factura()<<endl;
                        cout<<"CodProducto: "<<Vent.getCod_Producto()<<endl;
                        cout<<"Descrip:     "<<Vent.getDescripcion()<<endl;
                        cout<<"Cantidad:    "<<Vent.getCant_Producto()<<endl;
                        cout<<"Precios:     "<<Vent.getPrecio()<<endl;
                        cout<<"Importe:     "<<Vent.getImporte()<<endl;
                        system("pause");

                        cout<<"Para ingresar otro producto S= si; N = no ";  cin>>Mas_Producto;
                        while(!(Mas_Producto=='S'||Mas_Producto=='N'||Mas_Producto=='s'||Mas_Producto=='n')){
                            cout<<">>> Debe Ingresar un valor correcto"; cin>>Mas_Producto;
                        }
                    fclose(V);
                    fclose(Pr);   ///     Cierro el while de Ventas
                    }
                    system("cls");
                }///        HASTA ACA LA ULTIMA LINEA
        break;

        case 2:
            {
                Factura Baj;
                int pos = Baj.BajaLogicaFactura();
                if(pos>-1){
                    FILE *P=fopen("archivos/Facturas.dat", "rb+");
                    if(P == NULL){
                        return;
                    }
                    fseek(P, pos * sizeof(Factura), SEEK_SET);
                    bool Grabo = fwrite(P, sizeof(Factura), 1, P);
                    if(Grabo == true){
                        cout<<"Se Elimin� la Factura correctamente"<<endl;
                    }else{
                        cout<<"Upps!! Hubo un error"<<endl;
                    }
                }
            }
        break;

        case 3:
            Mostrar_ResumenVenta();
        break;

        case 5:
            Mostrar_TodaVenta();
        break;

        case 0:
            return;
        break;

        default:
            cout<<"\nIngrese la opción correcta";
        break;
    }
    }
}


int GeneroNuevaFactura(){
    {
    ///     ABRO CLASE FACTURA
    Factura Nueva;
    int Cliente=-1;
    cout<<"\nINGRESE CLIENTE: "; cin>>Cliente;
    ///GENERO NRO FACTURA CON NRO CLIENTE EN LA MEMORIA.
    Nueva.setFactura(Cliente);
    ///Nueva.getFactura();
    Nueva.Guardo();
    cout<<"Guardo Factura";
    Nueva.getNro_Factura();///PERFECTO MUESTRA LA ULTIMA FACTURA
    return Nueva.getNro_Factura();
    }
}

void Mostrar_ResumenVenta(){ ///de la Factura Actual
                Factura fac;
                Ventas ven;
                int NroF = fac.Leo_Factura(); ///Traigo el ultimo numero
                ///int NroFactura = fac.Leo_Factura();

                ///     Muestro el resumen de ventas
                    cout<<"\nResumen de Factura Ventas: "<<endl;
                    cout << left;
                    cout << setw(4) << "NROF";
                    cout << setw(7) << "Código " << setw(12) << "Descripcion" << setw(6) << "Cant" << setw(15) << "P. Unidad" << setw(10) << "Importe" << endl;
                    FILE *V = fopen("archivos/Ventas.dat", "rb");
                    if(V == NULL) {
                        cout<<"No se pudo abrir Ventas.dat";
                        return;
                    }

                    while(fread(&ven, sizeof(Ventas), 1, V) ){
                        int veo = ven.getNro_Fact().getNro_Factura();
                        if(NroF == veo){
                            cout<<"ven.getNro_Fact().getNro_Factura()) "<<ven.getNro_Fact().getNro_Factura()<<endl;
                            cout << left;
                            cout << setw(4);
                            cout << ven.getNro_Fact().getNro_Factura(); ///veo.getNro_Fact().getNro_Factura(); ///Fact->getNro_Factura();
                            cout << setw(7);
                            cout << ven.getCod_Producto();
                            cout << setw(12);
                            cout << ven.getDescripcion();
                            cout << setw(6);
                            cout << ven.getCant_Producto();
                            cout << setw(15);
                            cout << ven.getPrecio();
                            cout << setw(10);
                            cout << ven.getImporte()<<endl;
                        }
                    }
                    fclose(V);
}

void Mostrar_TodaVenta(){ ///de la Factura Actual
                Factura fac;
                Ventas ven;
                int NroF = fac.Leo_Factura(); ///Traigo el ultimo numero
                ///int NroFactura = fac.Leo_Factura();

                ///     Muestro el resumen de ventas
                    cout<<"\nResumen de Factura Ventas: "<<endl;
                    cout << left;
                    cout << setw(4) << "NROF";
                    cout << setw(7) << "C�digo " << setw(12) << "Descripcion" << setw(6) << "Cant" << setw(15) << "P. Unidad" << setw(10) << "Importe" << endl;
                    FILE *V = fopen("archivos/Ventas.dat", "rb");
                    if(V == NULL) {
                        cout<<"No se pudo abrir Ventas.dat";
                        return;
                    }

                    while(fread(&ven, sizeof(Ventas), 1, V) ){
                            ///cout<<"ven.getNro_Fact().getNro_Factura()) "<<ven.getNro_Fact().getNro_Factura()<<endl;
                            cout << left;
                            cout << setw(4);
                            cout << ven.getNro_Fact().getNro_Factura(); ///veo.getNro_Fact().getNro_Factura(); ///Fact->getNro_Factura();
                            cout << setw(7);
                            cout << ven.getCod_Producto();
                            cout << setw(12);
                            cout << ven.getDescripcion();
                            cout << setw(6);
                            cout << ven.getCant_Producto();
                            cout << setw(15);
                            cout << ven.getPrecio();
                            cout << setw(10);
                            cout << ven.getImporte()<<endl;
                    }
                    fclose(V);
}
