#include <vector>
#include <cstring>
#include <iostream>
#include <cstdio> ///PARA USAR EL FOPEN ETC
#include <cstdlib> /// PARA USAR SYSEM("PAUSE")....
#include <iomanip> ///PARA TRABAJAR CON SETW

using namespace std;

class Alumno{
    private:
    int legajo;
    char apenom[50];

    public:
        void cargar(){
            cout << "> Legajo: ";
            cin >> this->legajo;
            cout << "> Apellido y nombre: ";
            cin.ignore();
            cin.getline(this->apenom, 50);
        }
        void mostrar(){
            cout << "Legajo: " << legajo << endl;
            cout << "Apellido y nombre: " << apenom << endl;
        }
};

class Ventas{
    private:
        int V_Nro_Fact;
        int Cod_Producto;
        char Descripcion[20];
        int Cant_Producto;
        float Precio;
        float Importe;
    public:
        Ventas(){
        Cod_Producto = 0;
        Descripcion[20]={0};
        Cant_Producto = 0;
        Precio = 0;
        Importe = 0;};
        ~Ventas(){};
        void MostrarVenta();
        void setNro_Factura(int);
        void setCod_Producto(int CodProducto){ Cod_Producto = CodProducto;};
        void setDescripcion(char *Descrip){ strcpy(Descripcion, Descrip);};
        void setCant_Producto(int CantProducto){ Cant_Producto = CantProducto;};
        void setPrecio(float Precios){Precio = Precios;};
        void setImporte(float Importes){Importe = Importes;};
        void Cargar_Venta(int NroFactura, int CodProducto, char *Descrip, int CantProducto, float Precios, float Importes){
                        V_Nro_Fact = NroFactura;
                        Cod_Producto = CodProducto;
                        strcpy(Descripcion, Descrip);
                        Cant_Producto = CantProducto;
                        Precio = Precios;
                        Importe = Importes;}
        void getVentas();
        int getCod_Producto(){return Cod_Producto;}
        char *getDescripcion(){return Descripcion;};
        int getCant_Producto(){return Cant_Producto;};
        float getPrecio(){ return Precio;};
        float getImporte(){return Importe;};
        void getVentas(int);
        int getNro_Fact(){return V_Nro_Fact;}
        int Leo_Ventas(){int Cant_Ventas=-1;
                         FILE *Ven=fopen("archivos/Ventas.dat", "rb");
                         if(Ven == NULL){
                             cout<<"No se abrio el Archivo Ventas.dat";
                             return Cant_Ventas=0;}
                         while(fread(this, sizeof(Ventas), 1, Ven)){
                             Cant_Ventas ++;}
                         getNro_Fact();
                         return Cant_Ventas;}
        int BuscarPosicion(int Numero){ int Pos=-1;
                                        FILE *Ven=fopen("archivos/Ventas.dat", "rb");
                                        if(Ven == NULL){
                                            cout<<"No se abrio el Archivo Ventas.dat";
                                            return Pos;}
                                        while(fread(this, sizeof(Ventas), 1, Ven)){
                                            if(Numero == V_Nro_Fact){return Pos;}}
                                        return Pos;}
};

void Ventas::MostrarVenta(){
    cout << right;
    cout << setw(4);
    cout << getNro_Fact();
    cout << setw(6);
    cout << getCod_Producto();
    cout << setw(3);
    cout << " ";
    cout << left;
    cout << setw(16);
    cout << getDescripcion();
    cout << right;
    cout << setw(5);
    cout << getCant_Producto();
    cout << setw(10);
    cout << getPrecio();
    cout << setw(13);
    cout << getImporte()<<endl;
}

///

int main(){
    int i;
    /**vector <int> vnum; // Declaración de un vector de enteros
    vnum.push_back(10);
    vnum.push_back(50);
    vnum.push_back(70);

    cout<<"QUE PASO"<<endl;
    cout << "Listado del vector de números:  "<< endl;
    for(i=0; i<vnum.size(); i++){
        cout << vnum.at(i) << " ";
    }


    cout << endl << endl << "Carga de alumnos: " << endl;
    vector <Alumno> valumnos;
    /// Cargarmos tres alumnos en el vector

    for(i=1; i<=3; i++){
        cout << "Alumno #" << i << endl;
        Alumno aux;
        aux.cargar();
        valumnos.push_back(aux);
    }

    cout << endl << endl << "Muestro Carga de alumnos: " << endl;
    cout << endl << endl;
    cout << "Listado del vector de alumnos:  "<< endl;
    for(i=0; i<valumnos.size(); i++){
        valumnos.at(i).mostrar();
    }*/


    cout<<" ==== INICIO LO DE VENTAS ========="<<endl;
    int Vuelta=0, Cant_Total=0, Pr01=0, Pr02=0, Pr03=0, Pr04=0, Pr05=0, Pr06=0, Pr07=0, Pr08=0, Pr09=0;
    int Imp01=0, Imp02=0, Imp03=0, Imp04=0, Imp05=0, Imp06=0, Imp07=0, Imp08=0, Imp09=0;
    cout << "CREO OBJETO VENTAS: " << endl;
    Ventas Leo;
    FILE *L = fopen("Ventas.dat", "rb");
    if(L == NULL){
        cout<<"NO FUNCIONO";
        return 0;
    }

    cout << "CARGO LA VENTA EN EL VECTOR: " << endl;
    vector <Ventas> Vec;

    cout << "LEO EL ARCHIVO VENTAS: " << endl;
    while(fread(&Leo, sizeof(Ventas), 1, L)){
        Cant_Total += Leo.getCant_Producto();

        switch(Leo.getCod_Producto()){
        case 1:
            Pr01 += Leo.getCant_Producto();
            Imp01 += Leo.getImporte();
        break;
        case 2:
            Pr02 += Leo.getCant_Producto();
            Imp02 += Leo.getImporte();
        break;
        case 3:
            Pr03 += Leo.getCant_Producto();
            Imp03 += Leo.getImporte();
        break;
        case 4:
            Pr04 += Leo.getCant_Producto();
            Imp04 += Leo.getImporte();
        break;
        case 5:
            Pr05 += Leo.getCant_Producto();
            Imp05 += Leo.getImporte();
        break;
        case 6:
            Pr06 += Leo.getCant_Producto();
            Imp06 += Leo.getImporte();
        break;
        case 7:
            Pr07 += Leo.getCant_Producto();
            Imp07 += Leo.getImporte();
        break;
        case 8:
            Pr08 += Leo.getCant_Producto();
            Imp08 += Leo.getImporte();
        break;
        case 9:
            Pr09 += Leo.getCant_Producto();
            Imp09 += Leo.getImporte();
        break;
        }
        Vuelta++;
        Ventas Cargo;
        Cargo.Cargar_Venta(Leo.getNro_Fact(), Leo.getCod_Producto(), Leo.getDescripcion(), Leo.getCant_Producto(), Leo.getPrecio(), Leo.getImporte());
        Vec.push_back(Cargo);
    }

    cout<<"Cantidad Total de Productos Vendidos: "<< Cant_Total<<endl;
    cout<<"Cantidad por Producto:  "<<endl;
    cout<<"Producto coddigo 01:                  "<<Pr01<<endl;
    cout<<"Producto coddigo 02:                  "<<Pr02<<endl;
    cout<<"Producto coddigo 03:                  "<<Pr03<<endl;
    cout<<"Producto coddigo 04:                  "<<Pr04<<endl;
    cout<<"Producto coddigo 05:                  "<<Pr05<<endl;
    cout<<"Producto coddigo 06:                  "<<Pr06<<endl;
    cout<<"Producto coddigo 07:                  "<<Pr07<<endl;
    cout<<"Producto coddigo 08:                  "<<Pr08<<endl;
    cout<<"Producto coddigo 09:                  "<<Pr09<<endl<<endl;

    cout << left;
    cout << setw(1);
    cout << "Pr01 + Pr02 + Pr03 + Pr04 + Pr05 + Pr06 + Pr07 + Pr08 + Pr09 =           ";
    ///cout << right;
    cout << setw(75);
    cout << Pr01 + Pr02 + Pr03 + Pr04 + Pr05 + Pr06 + Pr07 + Pr08 + Pr09<<endl;
    cout << left;
    cout << setw(1);
    cout<<"Imp01 + Imp02 + Imp03 + Imp04 + Imp05 + Imp06 + Imp07 + Imp08 + Imp09 =  ";
    ///cout << right;
    cout << setw(75);
    cout << Imp01 + Imp02 + Imp03 + Imp04 + Imp05 + Imp06 + Imp07 + Imp08 + Imp09<<endl;

    cout << ">>>>>Venta #" << Vuelta << endl;
    ///     Muestro las ventas de la facturael resumen de ventas
        cout<<"==============================================================================="<<endl;
        cout << left;
        cout << setw(6) << "NROF";
        cout << setw(7) << "Codigo " << setw(18) << "Descripcion" << setw(6) << "Cant" << setw(15) << "P. Unidad" << setw(10) << "Importe" << endl;
        cout<<"==============================================================================="<<endl;
        for(i=0; i<Vec.size(); i++){
            Vec.at(i).MostrarVenta();
    }



    return 0;
}
