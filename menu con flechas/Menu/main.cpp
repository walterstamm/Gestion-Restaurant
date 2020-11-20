#include <iostream>
using namespace std;
#include <windows.h>
#include "rlutil.h"
using namespace rlutil;

#define ARRIBA 'w'
#define ABAJO 's'
#define ENTER 13


char getch2 ()
{
   char c=0;
   DWORD modo, contador;
   HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);

   // Desactivamos escritura en terminal
   SetConsoleMode (ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

   ReadConsoleA (ih, &c, 1, &contador, NULL);

   if (c == 0) {
      ReadConsoleA (ih, &c, 1, &contador, NULL);
   }

   SetConsoleMode (ih, modo); // Devolvemos control normal

   return c;
}


int menu(const char *opciones[], int n);
void menu_principal();
void menu_suma();
void menu_resta();
void menu_producto();
void menu_division();

int main()
{
   menu_principal();

   return 0;
}

void menu_principal()
{
   bool repite = true;
   int opcion;
   // Titulo del menú y nombres de las opciones
   const char *opciones[] = {"Sumar", "Restar", "Multiplicar", "Dividir", "Salir"}; ///ACA MUESTRO LAS OPCIONES DEL MENU
   int n = 5;  /// CANTIDAD DE OPCIONES

   do {
      opcion = menu(opciones, n);

      switch (opcion) {
         case 1:
            cout<<"Opcion uno";
            system("pause");
            break;


         case 2:
            break;

         case 3:
            break;

         case 4:
            break;

         case 5:
            cout << "\nEl programa se cerrara!! ADIOS" << endl;
            repite = false;
            system("pause>nul");
            break;
      }

   } while(repite);
}



int menu(const char *opciones[], int n)
{
   int opcionSeleccionada = 1;  // Indica la opcionSeleccionada

   int tecla;

   bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER

   do {
      system("cls");
      locate(5, 3 + opcionSeleccionada); cout << "==>" << endl;

      // Imprime las opciones del menú
      for (int i = 0; i < n; ++i) {
         locate(10, 4 + i); cout << opciones[i];
      }

      // Solo permite que se ingrese ARRIBA, ABAJO o ENTER

      do {
        tecla = getch2();

      } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

      switch (tecla) {

         case ARRIBA:   // En caso que se presione ARRIBA

            opcionSeleccionada--;

            if (opcionSeleccionada < 1) {
               opcionSeleccionada = n;
            }

            break;

         case ABAJO:
            opcionSeleccionada++;

            if (opcionSeleccionada > n) {
               opcionSeleccionada = 1;
            }

            break;

         case ENTER:
            repite = false;
            break;
      }

   } while (repite);

   return opcionSeleccionada;
}
