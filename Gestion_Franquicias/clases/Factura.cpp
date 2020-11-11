#include <vector>
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

int Factura::BuscarPosicionFactura(int Nro){

    int pos=0;
    FILE *p = fopen("archivos/Facturas.dat" , "rb");
        if(p == NULL){
            cout<<"No se pudo abrir Facturas.dat.....\n";
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

void Factura::setEstado(bool Est){
    Estado = Est;

}

void Factura::setFactura(int Cliente){
    cout<<"NUEVA FACTURA\n";
    Nro_Fact = Leo_Ultima_Factura()+1;
    Nro_Cliente = Cliente;
    Total_Pagar=0;///FUNCION PARA SUMAR LA VENTA FALTA
}



int Factura::Leo_Ultima_Factura(){
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
    return Leo_Ultima_Factura();
}

Fecha Factura::getFecha(){
    return Fecha_Factura;
}

int Factura::getNroCliente(){
    return Nro_Cliente;
}

void Factura::setTotal_Pagar(float Suma){
    Total_Pagar = Suma;
}

float Factura::getTotal_Pagar(){
    return Total_Pagar;
}

void SumarVentas(){
    Ventas  V_Pago;
    Factura F_Pago;
    float Suma =0;
    ///     TRAIGO EL NUMERO DE LA ULTIMA FACTURA
    int NroFat = F_Pago.Leo_Ultima_Factura();

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
            Suma += V_Pago.getImporte();
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
    fclose(V);
    fclose(F);
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
    fseek(Fact,-1*sizeof(Factura), SEEK_END);
    fread(this, sizeof(Factura), 1, Fact);///Muestro lo grabado recien
    fclose(Fact);
}

void MENU_FACTURACION(){
    int Opcion;
    while(Opcion){
        system("cls");
        title("MENU FACTURACION", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<"\n============================================";
        cout<<"\n01-Generar Factura..........................";
        cout<<"\n02-Muestro Factura..........................";
        cout<<"\n03-Eliminar Factura.........................";
        cout<<"\n04-Listar Facturas Eliminadas...............";
        cout<<"\n05-Listar Facturas por Nro y Prod (todas)..."; ///RESUMEN DE NROS FACTURAS EMITIDAS CON SUS VENTAS
        cout<<"\n06-Reportes a eleccion por el usuario.......";
        cout<<"\n============================================";
        cout<<"\n00- Volver al MENU PRINCIPAL................";
        cout<<"\n============================================";
        cout<<"\nOpcion: "; cin>>Opcion;
        cout<<"============================================\n";

       switch(Opcion){
            case 1:
            {
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
            }
        break;

        case 2:///      02-Muestro Factura..........................";
            {
            Mostrar_ResumenVenta();
            }
        break;

        case 3:///      03-Eliminar Factura.........................";
            {   ///     CREO UN OBJETO CLASE FACTURA
                Factura Baj;
                int Nro;
                cout<<"Ingrese el Número de Factura a eliminar: ";
                cin>>Nro;
                cout<<endl;

                int pos = Baj.BuscarPosicionFactura(Nro); /// BUSCO LA POSICION QUE PIDO EN BUSCARPOSICION

                cout<<"pos:  "<<pos;
                system("pause");
                if( pos != -1 ){                     /// SI ESTA ME MUESTRA LA POSICION O -1 SI NO ESTA
                    FILE *B = fopen("archivos/Facturas.dat", "rb+");
                    if(B == NULL){
                        cout<<"No se pudo abrir Facturas.dat ";
                        return;
                    }

                    fseek(B, pos *sizeof(Factura), SEEK_SET);
                    ///fread(&Baj, sizeof(Factura), 1, B);

                    bool Est = false;
                    Baj.setEstado(Est);
                    cout<<"Baj.getEstado(): "<<Baj.getEstado();
                    system("pause");

                    int Grabo = fwrite(&Baj, sizeof(Factura), 1, B);
                    if(Grabo == 1){
                        cout<<"El Numero de Factura requerido se Eliminó correctamente"<<endl;
                    }else{
                        cout<<"Upps!! Hubo un error"<<endl;
                    }
                    fclose(B);
                }
            }
        break;

        case 4:///      04-Listar Facturas Eliminadas...............";
            {
            Mostrar_Facturas_Eliminadas();
            }
        break;

        case 5:///      n05-Listar Facturas por Nro y Prod (todas)...";
            {
            Mostrar_TodaVenta();
            }
        break;

        case 6:
            {
            Menu_Reportes();

            }
        break;

        case 0:///      00- Volver al MENU PRINCIPAL................";
            {
            return;

            }
        break;

        default:
            {
            msj("           DEBERA ELEGIR UNA OPCION CORRECTA", 15, 4, 15, 1);
            }
        break;
    }
    }
}


void Menu_Reportes(){
    int Opcion;
    while(Opcion){
        system("cls");
        title("MENU REPORTES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<"\n============================================";
        cout<<"\n01-Facturas emitidas en mismo dia...........";
        cout<<"\n02-Ventas realizadas en el mismo dia........";
        cout<<"\n03-Ventas realizadas en el mes..............";
        cout<<"\n04-Importes recaudado en el mes.............";
        cout<<"\n05-Importes recaudados en el dia............"; ///RESUMEN DE NROS FACTURAS EMITIDAS CON SUS VENTAS
        cout<<"\n06-Totales de cada Producto vencido.........";
        cout<<"\n============================================";
        cout<<"\n00- Volver al MENU PRINCIPAL................";
        cout<<"\n============================================";
        cout<<"\nOpcion: "; cin>>Opcion;
        cout<<"============================================\n";

        switch(Opcion){
            case 1:
            {

            }
            break;

            case 2:
            {

            }
            break;

            case 3:
            {

            }
            break;

            case 4:
            {

            }
            break;

            case 5:
            {

            }
            break;

            case 6:
            {

            }
            break;

            case 0:
            {

            }
            break;

            default:
            {
                msj("           DEBERÁ ELEGIR UNA OPCIÓN CORRECTA", 15, 4, 15, 1);
            }
            break;
        }
    }
}

int GeneroNuevaFactura(){
    {
    ///     CREO OBJETO FACTURA
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
                system("cls");
                int NroF = fac.Leo_Ultima_Factura(); ///Traigo el ultimo numero


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
                    }
                    cout<<"==============================================================================="<<endl;
                    cout<<"MOSTRO HASTA LA ULTIMA FILA"<<endl;
                    fclose(V);
                    system("pause");
                    system("cls");
}

void Mostrar_TodaVenta(){ ///de la Factura Actual
        Ventas Aux;
        system("cls");
        FILE *Veo=fopen("archivos/Ventas.dat", "rb");
        if(Veo == NULL){
            cout<<"No se pudo abrir Venas.dat ";
            return;
        }
        cout<<"==============================================================================="<<endl;
        cout<<"\nRESUMEN DE NROS FACTURAS EMITIDAS CON SUS VENTAS: "<<endl;
        cout<<"==============================================================================="<<endl;
        cout << left;
        cout << setw(6) << "NROF";
        cout << setw(7) << "Codigo " << setw(18) << "Descripcion" << setw(6) << "Cant" << setw(15) << "P. Unidad" << setw(10) << "Importe" << endl;
        cout<<"==============================================================================="<<endl;

        while (fread(&Aux, sizeof(Ventas), 1, Veo)){
                cout << left;
                cout << setw(6);
                cout << Aux.getNro_Fact();
                cout << setw(7);
                cout << Aux.getCod_Producto();
                cout << setw(18);
                cout << Aux.getDescripcion();
                cout << setw(6);
                cout << Aux.getCant_Producto();
                cout << setw(15);
                cout << Aux.getPrecio();
                cout << setw(10);
                cout << Aux.getImporte()<<endl;

        }

        cout<<"==============================================================================="<<endl;
        cout<<"MOSTRO HASTA LA ULTIMA FILA"<<endl;
        system("pause");
        fclose(Veo);
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
        if(Elim.getEstado() == false){
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
    system("cls");
    fclose(Fa);
}
