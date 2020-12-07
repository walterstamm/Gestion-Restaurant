#ifndef MENU_PEDIDOS_H_INCLUDED
#define MENU_PEDIDOS_H_INCLUDED
#include "clases/proveedores.h"

void Menu_Pedidos();
void Carga_Provedores();///Carga nuevos Provedores
void Mostrar_Proveedores();
bool ValidarIDProveedores(int);//valida si el ID existe
void DarBajaProveedor();
void BuscarID(proveedore *,int);
void GeneraPedido();///genera pedido
void ConfirmarPedido();///Confirma pedido realizado o da de baja pedido


#endif // MENU_PEDIDOS_H_INCLUDED
