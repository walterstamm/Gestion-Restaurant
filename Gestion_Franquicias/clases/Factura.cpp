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

bool Factura::getEstado(){
    return Estado;
}

int Factura::BuscarPosicion(int Nro){

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

void Factura::setBajaEstado(){
    Estado=false;

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

int Factura::getNros_Factura(){
    return Nro_Fact;
}

int Factura::getNro_Factura(){
    return Leo_Factura();
}

Fecha Factura::getFecha(){
    return Fecha_Factura;
}

int Factura::getNroCliente(){
    return Nro_Cliente;
}

float Factura::setTotal_Pagar(float Suma){
    Total_Pagar = Suma;
}

int Factura::getTotal_Pagar(){
    return Total_Pagar;
}

void SumarVentas(){
    Ventas  V_Pago;
    Factura F_Pago;
    float Suma =0;
    ///     TRAIGO EL NUMERO DE LA ULTIMA FACTURA
    int NroFat = F_Pago.Leo_Factura();
    cout<<"NroFat:   "<<NroFat;
    system("pause");

    ///     ABRO ARCHIVOS FACTURAS
    FILE *F = fopen("archivos/Facturas.dat", "rb+");
    if(F == NULL){
        cout << "No se pudo abrir Facturas.dat ";
        return;
    }
    ///     ABRO ARCHIVOS VENTAS
    FILE *V = fopen("archivos/Ventas.dat", "rb");
    if ( V == NULL) {
        cout<< "No se pudo abrir Ventas.dat";
        fclose(F);
        return ;
    }
    ///     LEO VENTAS Y SI ES IGUAL QUE NROFAT LO SUMA A LA VARIABLE SUMA
    while( fread( &V_Pago, sizeof(Ventas), 1 , V)){
        if( NroFat == V_Pago.getNro_Fact() ){
            cout<<"V_Pago.getImporte():  "<<V_Pago.getImporte();
            system("pause");
            Suma += V_Pago.getImporte();
            cout<<"Suma:  "<<Suma;
            system("pause");
        }
    }
    ///     LE ENVIO A SETTOTAL_PAGAR LA SUMA Y LO GUARDA EN LA EL ATRIBUTO TOTAL_PAGAR
    F_Pago.setTotal_Pagar(Suma);
    ///     LO UBICA EN EL ULTIMO REGISTRO
    fseek(F, -1 * sizeof(Factura), SEEK_END);
    ///     LO REESCRIBE CON LA SUMA TOTAL DEL PAGO
    if(fwrite( &F_Pago, sizeof(Factura), 1, F) == 1 ){
        cout<<"Se Grabo Correctamente";
    }
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
        title("MENU FACTURACION", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<"\n============================================";
        cout<<"\n01-Generar Factura..........................";
        cout<<"\n02-Muestro Factura..........................";
        cout<<"\n03-Eliminar Factura.........................";
        cout<<"\n04-Listar Facturas Eliminadas...............";
        cout<<"\n05-Listar Facturas por Nro y Prod (todas)..."; ///RESUMEN DE NROS FACTURAS EMITIDAS CON SUS VENTAS

        cout<<"\n============================================";
        cout<<"\n00- Volver al MENU PRINCIPAL................";
        cout<<"\n============================================";
        cout<<"\nOpcion: "; cin>>Opcion;
        cout<<"============================================\n";

       switch(Opcion){
            case 1:
                int NroFactura, Pos;
                int CodProducto, CantProducto;
                char Descrip[20], Mas_Producto;
                float Precios, Importe;

                NroFactura = GeneroNuevaFactura();
                {   ///     CREO OBJETO PRODUCTO
                    Producto Prod;
                    ///     CREO OBJETO VENTAS
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
                        ///     GUARDO EN EL ARCHIVO VENTAS
                        FILE *V = fopen("archivos/Ventas.dat", "ab");
                        if(V == NULL) {return;}
                        if(fwrite(&Vent, sizeof(Ventas), 1, V)){
                            cout<<"se grabo. ";
                        }

                        cout<<" Continua ingresando Productos? S= si  N = no ";  cin>>Mas_Producto;
                        while(!(Mas_Producto=='S'||Mas_Producto=='N'||Mas_Producto=='s'||Mas_Producto=='n')){
                            cout<<">>> Debe Ingresar un valor correcto"; cin>>Mas_Producto;
                        }
                    fclose(V);
                    fclose(Pr);   ///     Cierro el while de Ventas
                    }
                    SumarVentas();
                    system("cls");
                }///        HASTA ACA LA ULTIMA LINEA
        break;

        case 2:
            Mostrar_ResumenVenta();
        break;

        case 3:
            {   ///     CREO UN OBJETO CLASE FACTURA
                Factura Baj;
                int Nro;
                cout<<"Ingrese el N�mero de Factura a eliminar: ";
                cin>>Nro;
                cout<<endl;

                int pos = Baj.BuscarPosicion(Nro); /// BUSCO LA POSICION QUE PIDO EN BUSCARPOSICION
                if(pos>-1){                     /// SI ESTA ME MUESTRA LA POSICION O -1 SI NO ESTA
                    FILE *P=fopen("archivos/Facturas.dat", "rb+");
                    if(P == NULL){
                        return;
                    }
                    fseek(P, pos * sizeof(Factura), SEEK_SET);
                    Baj.setBajaEstado();
                    bool Grabo = fwrite(P, sizeof(Factura), 1, P);
                    if(Grabo == true){
                        cout<<"El Numero de Factura requerido se Eliminó correctamente"<<endl;
                    }else{
                        cout<<"Upps!! Hubo un error"<<endl;
                    }
                }
            }
        break;

        case 4:
            Mostrar_Facturas_Eliminadas();
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
                    cout<<"==============================================================================="<<endl;
                    cout<<"\nRESUMEN DE NROS FACTURAS EMITIDAS CON SUS VENTAS: "<<endl;
                    cout<<"==============================================================================="<<endl;
                    cout << left;
                    cout << setw(6) << "NROF";
                    cout << setw(7) << "Codigo " << setw(18) << "Descripcion" << setw(6) << "Cant" << setw(15) << "P. Unidad" << setw(10) << "Importe" << endl;
                    cout<<"==============================================================================="<<endl;
                    FILE *V = fopen("archivos/Ventas.dat", "rb");
                    if(V == NULL) {
                        cout<<"No se pudo abrir Ventas.dat";
                        return;
                    }
                    while(fread(&ven, sizeof(Ventas), 1, V) ){
                        int veo = ven.getNro_Fact();
                        if(NroF == veo){
                             cout << left;
                            cout << setw(6);
                            cout << fac.getNro_Factura();
                            cout << setw(7);
                            cout << ven.getCod_Producto();
                            cout << setw(18);
                            cout << ven.getDescripcion();
                            cout << setw(6);
                            cout << ven.getCant_Producto();
                            cout << setw(15);
                            cout << ven.getPrecio();
                            cout << setw(10);
                            cout << ven.getImporte()<<endl;
                        }
                    }
                    cout<<"==============================================================================="<<endl;
                    cout<<"MOSTRO HASTA LA ULTIMA FILA"<<endl;
                    fclose(V);
                    system("pause");
                    system("cls");
}

void Mostrar_TodaVenta(){ ///de la Factura Actual
                Factura fac;
                Ventas ven;
                system("cls");
                    cout<<endl<<endl;
                ///     Muestro el resumen de ventas
                    cout<<"==============================================================================="<<endl;
                    cout<<"\nRESUMEN DE NROS FACTURAS EMITIDAS CON SUS VENTAS: "<<endl;
                    cout<<"==============================================================================="<<endl;
                    cout << left;
                    cout << setw(6) << "NROF";
                    cout << setw(7) << "Codigo " << setw(18) << "Descripcion" << setw(6) << "Cant" << setw(15) << "P. Unidad" << setw(10) << "Importe" << endl;
                    cout<<"==============================================================================="<<endl;
                    FILE *V = fopen("archivos/Ventas.dat", "rb");
                    if(V == NULL) {
                        cout<<"No se pudo abrir Ventas.dat";
                        return;
                    }
                    while(fread(&ven, sizeof(Ventas), 1, V) ){
                            cout << left;
                            cout << setw(6);
                            cout << ven.getNro_Fact();
                            cout << setw(7);
                            cout << ven.getCod_Producto();
                            cout << setw(18);
                            cout << ven.getDescripcion();
                            cout << setw(6);
                            cout << ven.getCant_Producto();
                            cout << setw(15);
                            cout << ven.getPrecio();
                            cout << setw(10);
                            cout << ven.getImporte()<<endl;
                    }
                    cout<<"==============================================================================="<<endl;
                    cout<<"MOSTRO HASTA LA ULTIMA FILA"<<endl;
                    system("pause");
                    fclose(V);
                    system("cls");

}

void Mostrar_Facturas_Eliminadas(){
    Factura Elim;

    system("cls");
    FILE *Fa= fopen("archivos/Facturas.dat", "rb");
    if(Fa == NULL){
        cout<<"No se pudo abrir Facturas.dat"<<endl;
        return;
    }
    cout<<"==============================================================================="<<endl;
    cout<<"\nRESUMEN DE NROS FACTURAS EMITIDAS Y ELIMINADAS: "<<endl;
    cout<<"==============================================================================="<<endl;
    cout << right;
    cout << setw(4) << "NROF";
    cout << setw(12) << "DD/MM/AAAA " << setw(10) << "Cliente   " << setw(12) << "Imp/Pagar" << setw(8) << "Estado" <<  endl;
    cout<<"==============================================================================="<<endl;

    while( fread(&Elim, sizeof(Factura), 1 ,Fa )  ){
        if(Elim.getEstado() != false){
            cout << right;
            cout << setw(3);
            cout << Elim.getNros_Factura();
            ///int dia; if(Elim.getFecha().getDia()<10){ dia=1; }else{ dia = 2;}
            cout << setw(3);
            cout << Elim.getFecha().getDia();
            cout << "/";
            cout << setw(2);
            cout << Elim.getFecha().getMes();
            cout << "/";
            cout << setw(4);
            cout << Elim.getFecha().getAnio();
            cout << setw(9);
            cout << Elim.getNroCliente();
            cout << setw(12);
            cout << Elim.getTotal_Pagar();
            cout << setw(8);
            cout << Elim.getEstado();
            cout << endl;
        }
    }
    cout<<"==============================================================================="<<endl;
    system("PAUSE");
    fclose(Fa);



}
