#include <vector>
#include <cstring>
#include <iostream>
#include <cstdio> ///PARA USAR EL FOPEN ETC


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
        Descripcion[20]={};
        Cant_Producto = 0;
        Precio = 0;
        Importe = 0;};
        ~Ventas(){};
        void setNro_Factura(int);
        void setCod_Producto(int CodProducto){ Cod_Producto = CodProducto;};
        void setDescripcion(char *Descrip){ strcpy(Descripcion, Descrip);};
        void setCant_Producto(int CantProducto){ Cant_Producto = CantProducto;};
        void setPrecio(float Precios){Precio = Precios;};
        void setImporte(float Importes){Importe = Importes;};
        void Cargar_Venta(int NroFactura, int CodProducto, char *Descrip, int CantProducto, float Precios, float Importes){ V_Nro_Fact = NroFactura; Cod_Producto = CodProducto; strcpy(Descripcion, Descrip); Cant_Producto = CantProducto; Precio = Precios; Importe = Importes;}
        void getVentas();
        int getCod_Producto(){return Cod_Producto;}
        char *getDescripcion(){return Descripcion;};
        int getCant_Producto(){return Cant_Producto;};
        float getPrecio();
        float getImporte();
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

///

int main(){
    int i;
    vector <int> vnum; // Declaración de un vector de enteros
    vnum.push_back(10);
    vnum.push_back(50);
    vnum.push_back(70);
    vnum.push_back(80);
    vnum.push_back(100);
    vnum.push_back(120);
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

    Ventas Carmem;
    cout << endl << endl << "Carga de Ventas: " << endl;
    vector <Ventas> Vventas;
    /// Cargarmos las ventas en el vector

    for(i=1; i<=3; i++){
        cout << "Alumno #" << i << endl;
        Alumno aux;
        aux.cargar();
        valumnos.push_back(aux);
    }

    cout << endl << endl;
    cout << "Listado del vector de alumnos:  "<< endl;
    for(i=0; i<valumnos.size(); i++){
        valumnos.at(i).mostrar();
    }



    return 0;
}
