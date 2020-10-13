#include <iostream>
using namespace std;
#include "Clases/Producto.h"

int main(){
    Producto uno;
    uno.setCargar_Nombre("jorgito");
    cout<<endl<<endl;
    cout<<uno.getMostrar_Nombre();
return 0;
}
