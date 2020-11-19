#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

void MenuPrincipal(){
    system("cls");
    ShowConsoleCursor(false);
    int opc, pos=1;
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(8,4,116,37); /// RECUADRO PRINCIPAL
    recuadro(26,10,80,25);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(27,32);
    for (int i=0; i <= 78; i++)cout << char (205);
    SetConsoleTextAttribute(hConsole, 4);
    logo(39, 7);
    while(true){
    switch(opc){
    case 80: //ABAJO
    pos++;
    if(pos>5){pos=1;}
    break;
    case 72: //ARRIBA
    pos--;
    if(pos<1){pos=5;}
    break;
    case 13: //ENTER
        switch(pos){
        case 1:
            menuCartelera();
        break;
        case 2:
            system("cls");
            SetConsoleTextAttribute(hConsole, 6);
            recuadro(8,4,116,37); /// RECUADRO PRINCIPAL
            SetConsoleTextAttribute(hConsole, 4);
            logoChico(100,16);
            SetConsoleTextAttribute(hConsole, 7);
            mostrarButacas();
            system("pause>NULL");
            MenuPrincipal();
        break;
        case 3:
            system("cls");
            gotoxy(55,21); cout << "ESTA FUNCION AUN NO ESTA CREADA";
            system("pause>NULL");
            MenuPrincipal();
        break;
        case 4:
            system("cls");
            gotoxy(55,21); cout << "ESTA FUNCION AUN NO ESTA CREADA";
            system("pause>NULL");
            MenuPrincipal();
        break;
        case 5:
            exit(0);
        break;
        }
        }
        switch(pos){
        case 1:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,14,70,2);
        gotoxy(60,15); cout << "VER CARTELERA";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,17,60,2);
        gotoxy(56,18); cout << "ASIENTOS DISPONIBLES";
        recuadro(36,20,60,2);
        gotoxy(59,21); cout << "COMPRAR ENTRADA";
        recuadro(36,23,60,2);
        gotoxy(59,24); cout << "RETIRAR COMPRA";
        recuadro(36,28,60,2);
        gotoxy(57,29);cout <<  "SALIR DEL PROGRAMA";
        break;
        case 2:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(60,15); cout << "VER CARTELERA";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,17,70,2);
        gotoxy(56,18); cout << "ASIENTOS DISPONIBLES";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,20,60,2);
        gotoxy(59,21); cout << "COMPRAR ENTRADA";
        recuadro(36,23,60,2);
        gotoxy(59,24); cout << "RETIRAR COMPRA";
        recuadro(36,28,60,2);
        gotoxy(57,29);cout <<  "SALIR DEL PROGRAMA";
        break;
        case 3:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(60,15); cout << "VER CARTELERA";
        recuadro(36,17,60,2);
        gotoxy(56,18); cout << "ASIENTOS DISPONIBLES";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,20,70,2);
        gotoxy(59,21); cout << "COMPRAR ENTRADA";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,23,60,2);
        gotoxy(59,24); cout << "RETIRAR COMPRA";
        recuadro(36,28,60,2);
        gotoxy(57,29);cout <<  "SALIR DEL PROGRAMA";
        break;
        case 4:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(60,15); cout << "VER CARTELERA";
        recuadro(36,17,60,2);
        gotoxy(56,18); cout << "ASIENTOS DISPONIBLES";
        recuadro(36,20,60,2);
        gotoxy(59,21); cout << "COMPRAR ENTRADA";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,23,70,2);
        gotoxy(59,24); cout << "RETIRAR COMPRA";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,28,60,2);
        gotoxy(57,29);cout <<  "SALIR DEL PROGRAMA";
        break;
        case 5:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(60,15); cout << "VER CARTELERA";
        recuadro(36,17,60,2);
        gotoxy(56,18); cout << "ASIENTOS DISPONIBLES";
        recuadro(36,20,60,2);
        gotoxy(59,21); cout << "COMPRAR ENTRADA";
        recuadro(36,23,60,2);
        gotoxy(59,24); cout << "RETIRAR COMPRA";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,28,70,2);
        gotoxy(57,29);cout <<  "SALIR DEL PROGRAMA";
        SetConsoleTextAttribute(hConsole, 7);
        break;
        }
        opc = getch();
    }
}

void menuCartelera(){
    system("cls");
    ShowConsoleCursor(false);
    int opc, pos=1;
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(8,4,116,37);  /// RECUADRO PRINCIPAL
    recuadro(26,10,80,25); ///
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(27,32);
    for (int i=0; i <= 78; i++)cout << char (205);
    SetConsoleTextAttribute(hConsole, 4);
    logo(39, 7);
    while(true){
    switch(opc){
    case 80: //ABAJO
    pos++;
    if(pos>4){pos=1;}
    break;
    case 72: //ARRIBA
    pos--;
    if(pos<1){pos=4;}
    break;
    case 13: //ENTER
        switch(pos){
        case 1:
            cargarPelicula();
        break;
        case 2:
            //Pverificador();
        break;
        case 3:
            //cargarSala();
        break;
        case 4:
            MenuPrincipal();
        break;
        }
        }
        switch(pos){
        case 1:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,14,70,2);
        gotoxy(54,15); cout << "CARGAR UNA NUEVA PELICULA";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,17,60,2);
        gotoxy(56,18); cout << "MODIFICAR UNA PELICULA";
        recuadro(36,20,60,2);
        gotoxy(58,21); cout << "MODIFICAR UNA SALA";
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER  ATRAS";
        break;
        case 2:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(54,15); cout << "CARGAR UNA NUEVA PELICULA";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,17,70,2);
        gotoxy(56,18); cout << "MODIFICAR UNA PELICULA";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,20,60,2);
        gotoxy(58,21); cout << "MODIFICAR UNA SALA";
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER  ATRAS";
        break;
        case 3:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(54,15); cout << "CARGAR UNA NUEVA PELICULA";
        recuadro(36,17,60,2);
        gotoxy(56,18); cout << "MODIFICAR UNA PELICULA";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,20,70,2);
        gotoxy(58,21); cout << "MODIFICAR UNA SALA";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER  ATRAS";
        break;
        case 4:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
       gotoxy(54,15); cout << "CARGAR UNA NUEVA PELICULA";
        recuadro(36,17,60,2);
        gotoxy(56,18); cout << "MODIFICAR UNA PELICULA";
        recuadro(36,20,60,2);
        gotoxy(58,21); cout << "MODIFICAR UNA SALA";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER  ATRAS";
        break;
        }
        opc = getch();
    }
}

void menuAdmin(){
    system("cls");
    ShowConsoleCursor(false);
    int opc, pos=1;
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(8,4,116,37);
    recuadro(26,10,80,25);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(27,32);
    for (int i=0; i <= 78; i++)cout << char (205);
    SetConsoleTextAttribute(hConsole, 4);
    logo(39, 7);
    while(true){
    switch(opc){
    case 80: //ABAJO
    pos++;
    if(pos>5){pos=1;}
    break;
    case 72: //ARRIBA
    pos--;
    if(pos<1){pos=5;}
    break;
    case 13: //ENTER
        switch(pos){
        case 1:
            //menuCartelera();
        break;
        case 2:
            system("cls");
            gotoxy(55,21); cout << "ESTA FUNCION AUN NO ESTA CREADA";
            system("pause>NULL");
            menuAdmin();
        break;
        case 3:
            system("cls");
            gotoxy(55,21); cout << "ESTA FUNCION AUN NO ESTA CREADA";
            system("pause>NULL");
            menuAdmin();
        break;
        case 4:
            //passConf();
        break;
        case 5:
            MenuPrincipal();
        break;
        }
        }
        switch(pos){
        case 1:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,14,70,2);
        gotoxy(60,15); cout << "MENU CARTELERA";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,17,60,2);
        gotoxy(62,18); cout << "MENU COMBOS";
        recuadro(36,20,60,2);
        gotoxy(62,21); cout << "CERRAR CAJA";
        recuadro(36,23,60,2);
        gotoxy(61,24); cout << "CONFIGURACION";
        recuadro(36,28,60,2);
        gotoxy(61,29);cout <<  "VOLVER  ATRAS";
        break;
        case 2:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(60,15); cout << "MENU CARTELERA";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,17,70,2);
        gotoxy(62,18); cout << "MENU COMBOS";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,20,60,2);
        gotoxy(62,21); cout << "CERRAR CAJA";
        recuadro(36,23,60,2);
        gotoxy(61,24); cout << "CONFIGURACION";
        recuadro(36,28,60,2);
        gotoxy(61,29);cout <<  "VOLVER  ATRAS";
        break;
        case 3:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(60,15); cout << "MENU CARTELERA";
        recuadro(36,17,60,2);
        gotoxy(62,18); cout << "MENU COMBOS";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,20,70,2);
        gotoxy(62,21); cout << "CERRAR CAJA";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,23,60,2);
        gotoxy(61,24); cout << "CONFIGURACION";
        recuadro(36,28,60,2);
        gotoxy(61,29);cout <<  "VOLVER  ATRAS";
        break;
        case 4:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(60,15); cout << "MENU CARTELERA";
        recuadro(36,17,60,2);
        gotoxy(62,18); cout << "MENU COMBOS";
        recuadro(36,20,60,2);
        gotoxy(62,21); cout << "CERRAR CAJA";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,23,70,2);
        gotoxy(61,24); cout << "CONFIGURACION";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,28,60,2);
        gotoxy(61,29);cout <<  "VOLVER  ATRAS";
        break;
        case 5:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(60,15); cout << "MENU CARTELERA";
        recuadro(36,17,60,2);
        gotoxy(62,18); cout << "MENU COMBOS";
        recuadro(36,20,60,2);
        gotoxy(62,21); cout << "CERRAR CAJA";
        recuadro(36,23,60,2);
        gotoxy(61,24); cout << "CONFIGURACION";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,28,70,2);
        gotoxy(61,29);cout <<  "VOLVER  ATRAS";
        break;
        }
        opc = getch();
    }
}

void menuCombos(){
    system("cls");
    ShowConsoleCursor(false);
    int opc, pos=1;
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(8,4,116,37);
    recuadro(26,10,80,25);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(27,32);
    for (int i=0; i <= 78; i++)cout << char (205);
    SetConsoleTextAttribute(hConsole, 4);
    logo(39, 7);
    while(true){
    switch(opc){
    case 80: //ABAJO
    pos++;
    if(pos>4){pos=1;}
    break;
    case 72: //ARRIBA
    pos--;
    if(pos<1){pos=4;}
    break;
    case 13: //ENTER
        switch(pos){
        case 1:
            system("cls");
            gotoxy(55,21); cout << "ESTA FUNCION AUN NO ESTA CREADA";
            system("pause>NULL");
            menuAdmin();
        break;
        case 2:
            system("cls");
            gotoxy(55,21); cout << "ESTA FUNCION AUN NO ESTA CREADA";
            system("pause>NULL");
            menuAdmin();
        break;
        case 3:
            gotoxy(55,21); cout << "ESTA FUNCION AUN NO ESTA CREADA";
            system("pause>NULL");
            menuAdmin();
        break;
        case 4:
            menuAdmin();
        break;
        }
        }
        switch(pos){
        case 1:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,14,70,2);
        gotoxy(60,15); cout << "AGREGAR COMBOS";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,17,60,2);
        gotoxy(61,18); cout << "CAMBIAR COMBOS";
        recuadro(36,20,60,2);
        gotoxy(60,21); cout << "QUITAR COMBOS";
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER  ATRAS";
        break;
        case 2:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(31,14,70,2);
        gotoxy(60,15); cout << "AGREGAR COMBOS";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(36,17,60,2);
        gotoxy(61,18); cout << "CAMBIAR COMBOS";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,20,60,2);
        gotoxy(60,21); cout << "QUITAR COMBOS";
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER  ATRAS";
        break;
        case 3:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(31,14,70,2);
        gotoxy(60,15); cout << "AGREGAR COMBOS";
        recuadro(36,17,60,2);
        gotoxy(61,18); cout << "CAMBIAR COMBOS";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(36,20,60,2);
        gotoxy(60,21); cout << "QUITAR COMBOS";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER  ATRAS";
        break;
        case 4:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(31,14,70,2);
        gotoxy(60,15); cout << "AGREGAR COMBOS";
        recuadro(36,17,60,2);
        gotoxy(61,18); cout << "CAMBIAR COMBOS";
        recuadro(36,20,60,2);
        gotoxy(60,21); cout << "QUITAR COMBOS";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER  ATRAS";
        break;
        }
        opc = getch();
    }
}

void cargarPelicula(){

    system("cls");
    ShowConsoleCursor(true);
    SetConsoleTextAttribute(hConsole, 4);
    recuadro(8,4,116,37);  /// RECUADRO PRINCIPAL
    logo(65,6);
                                                    /// RECUADRO TITULO Y DESCRIPCIÓN
    SetConsoleTextAttribute(hConsole, 7);
    recuadro(10,6,50,33);
    gotoxy(14,8); cout << "TITULO: ";
    gotoxy(12,9); for (int i=0; i <= 45; i++)cout << char (205);
    gotoxy(14,10); cout << "DESCRICION: ";
                                                    /// SALA Y HORARIOS
    gotoxy(65,14); cout << "NOMBRE DIRECTOR: ";
    recuadro(90,13,30,2);
    gotoxy(65,17); cout << "CLASIFICACION: ";
    recuadro(90,16,14,2);
    recuadro(106,16,14,2);
    gotoxy(65,20); cout << "INGRESE SALA: ";
    recuadro(90,19,14,2);
    gotoxy(65,23); cout << "HORARIOS FUNCION: ";
    recuadro(90,22,14,2);
    gotoxy(65,29); cout << "INGRESE EL NOMBRE DE LA RUTA PARA LA PORTADA 'P/NAME'";
    recuadro(65,31,55,2);
    SetConsoleTextAttribute(hConsole, 4);
    gotoxy(97,23); cout << ":";
    recuadro(65,35,55,4);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(70,37); cout << "GUARDAR PELICULA?";
    recuadro(90,36,13,2);
    gotoxy(96,37); cout << "SI";
    recuadro(106,36,13,2);
    gotoxy(112,37); cout << "NO";
    opciones();

}


void opciones(){

    ShowConsoleCursor(false);
    int opc, pos=1;
    while(true){
    switch(opc){
    case 75: //ABAJO
    pos++;
    if(pos>2){pos=1;}
    break;
    case 77: //ARRIBA
    pos--;
    if(pos<1){pos=2;}
    break;
    case 13: //ENTER
        switch(pos){
        case 1:
            menuCartelera();
        break;
        case 2:
            menuCartelera();
        break;
        }
        }
        switch(pos){
        case 1:
                SetConsoleTextAttribute(hConsole, 2);
                recuadro(90,36,13,2);
                gotoxy(96,37); cout << "SI";
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(106,36,13,2);
                gotoxy(112,37); cout << "NO";
        break;
        case 2:
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(90,36,13,2);
                gotoxy(96,37); cout << "SI";;
                SetConsoleTextAttribute(hConsole, 4);
                recuadro(106,36,13,2);
                gotoxy(112,37); cout << "NO";
        break;
        }
        opc = getch();
    }


}


#endif // MENUES_H_INCLUDED
