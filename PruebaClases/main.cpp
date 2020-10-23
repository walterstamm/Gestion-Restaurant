#include <iostream>
using namespace std;
#include "Clases/Producto.h"
#include "Factura.h"

int main(){
    /**Producto uno;
    uno.setCargar_Nombre("jorgito");
    cout<<endl<<endl;
    cout<<uno.getMostrar_Nombre();*/

    Factura Fact;

    int Cliente;
    cout<<"Ingrese Nro Cliente: "; cin>>Cliente;
    Fact.setFactura(Cliente);
    ///Fact.getMostrar_Factura(10);
    Fact.getFactura();

return 0;
}
