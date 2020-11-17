#include <iostream>
using namespace std;
#include "Producto.h"

int main(){
    Producto uno;
    uno.Cargar();
    uno.Guardar();
    cout<<endl;
    uno.Cargar();
    uno.Guardar();
    cout<<endl;
    uno.Cargar();
    uno.Guardar();
    return 0;
}
