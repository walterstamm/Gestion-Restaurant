#ifndef VISUALES_H_INCLUDED
#define VISUALES_H_INCLUDED





void ShowConsoleCursor(bool showFlag){                                          //MOSTRARA DONDE SE ENCUENTRA EL CURSOR EN LA CONSOLA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void recuadro(short iniX, short iniY, short ancho, short alto){                 //CON ESTA FUNCION NOS PERMITIRA CREAR UN RECUADRO
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            if(i==iniX && j==iniY){cout << (char) 201;                          ///ARRIBA  - IZQUIERDA
            }
            else if(i==iniX+ancho && j==iniY){cout << (char) 187;               ///ARRIBA  - DERECHA
            }
            else if(i==iniX && j==iniY+alto){cout << (char) 200;                ///ABAJO   - IZQUIERDA
            }
            else if(i==iniX+ancho && j==iniY+alto){cout << (char) 188;          ///ABAJO   - DERECHA
            }
            else if(j==iniY || j==iniY+alto){cout << (char) 205;                ///ARRIBA  - ABAJO
            }
            else if(i==iniX || i==iniX+ancho){cout << (char) 186;               ///DERECHA - IZQUIERDA
            }
            else{cout << " ";                                                   ///DENTRO DEL RECUADRO
            }
        }
    }
}

void logo(int x, int y){

gotoxy(x, y);
cout << " " << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << " " << char(219) << char(219);
cout << char(187) << char(219) << char(219) << char(219) << char(187) << " " << " " << char(219) << char(219) << char(187);
cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(219) << char(219);
cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(219) << char(219) << char(187) << " ";
cout << " " << " " << " " << " " << char(219) << char(219) << char(187) << char(219) << char(219) << char(187);
cout << " " << " " << char(219) << char(219) << char(187) << endl;

gotoxy(x, y+1);
cout << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) << char(219) << char(219);
cout << char(186) << char(219) << char(219) << char(219) << char(219) << char(187) << " " << char(219) << char(219) << char(186);
cout << char(219) << char(219) << char(201) << char(205) << char(205) << char(205) << char(205) << char(188) << char(219) << char(219);
cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(188) << char(219) << char(219) << char(186) << " ";
cout << " " << " " << " " << " " << char(219) << char(219) << char(186) << char(200) << char(219) << char(219);
cout << char(187) << char(219) << char(219) << char(201) << char(188) << endl;

gotoxy(x, y+2);
cout << char(219) << char(219) << char(186) << " " << " " << char(200) << char(205) << char(188) << char(219) << char(219);
cout << char(186) << char(219) << char(219) << char(201) << char(219) << char(219) << char(187) << char(219) << char(219) << char(186);
cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << " " << " " << char(219) << char(219);
cout << char(219) << char(219) << char(219) << char(187) << " " << " " << char(219) << char(219) << char(186) << " ";
cout << " " << " " << " " << " " << char(219) << char(219) << char(186) << " " << char(200) << char(219);
cout << char(219) << char(219) << char(201) << char(188) << " " << endl;

gotoxy(x, y+3);
cout << char(219) << char(219) << char(186) << " " << " " << char(219) << char(219) << char(187) << char(219) << char(219);
cout << char(186) << char(219) << char(219) << char(186) << char(200) << char(219) << char(219) << char(219) << char(219) << char(186);
cout << char(219) << char(219) << char(201) << char(205) << char(205) << char(188) << " " << " " << char(219) << char(219);
cout << char(201) << char(205) << char(205) << char(188) << " " << " " << char(219) << char(219) << char(186) << " ";
cout << " " << " " << " " << " " << char(219) << char(219) << char(186) << " " << char(219) << char(219);
cout << char(201) << char(219) << char(219) << char(187) << " " << endl;

gotoxy(x, y+4);
cout << char(200) << char(219) << char(219) << char(219) << char(219) << char(219) << char(201) << char(188) << char(219) << char(219);
cout << char(186) << char(219) << char(219) << char(186) << " " << char(200) << char(219) << char(219) << char(219) << char(186);
cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(219) << char(219);
cout << char(186) << " " << " " << " " << " " << " " << char(219) << char(219) << char(219) << char(219);
cout << char(219) << char(219) << char(219) << char(187) << char(219) << char(219) << char(186) << char(219) << char(219) << char(201);
cout << char(188) << char(200) << char(219) << char(219) << char(187) << endl;

gotoxy(x, y+5);
cout << " " << char(200) << char(205) << char(205) << char(205) << char(205) << char(188) << " " << char(200) << char(205);
cout << char(188) << char(200) << char(205) << char(188) << " " << " " << char(200) << char(205) << char(205) << char(188);
cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << char(200) << char(205);
cout << char(188) << " " << " " << " " << " " << " " << char(200) << char(205) << char(205) << char(205);
cout << char(205) << char(205) << char(205) << char(188) << char(200) << char(205) << char(188) << char(200) << char(205) << char(188);
cout << " " << " " << char(200) << char(205) << char(188) << endl;

}

void logoChico(int x, int y){
gotoxy(x, y);
cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << " " << " " << " ";
cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187);
gotoxy(x,y+1);
cout << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) <<" ";
cout << char(219) << char(219) << char(201) << char(205) << char(205) << char(205) << char(205) << char(188);
gotoxy(x,y+2);
cout << char(219) << char(219) << char(186) << " " << " " << char(200) << char(205) << char(188) << " ";
cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(187);
gotoxy(x,y+3);
cout << char(219) << char(219) << char(186) << " " << " " << char(219)<< char(219) << char(187) << " ";
cout << char(219) << char(219) << char(201) << char(205) << char(205) << char(188);
gotoxy(x,y+4);
cout << char(200) << char(219) << char(219) << char(219) << char(219) << char(219) << char(201);
cout << char(188) << " " << char(219) << char(219) << char(186);
gotoxy(x,y+5);
cout << " " << char(200) << char(205) << char(205) << char(205);
cout << char(205) << char(188) << " " << " "<<  char(200) << char(205) << char(188);
}

void mostrarButacas(){
int Butacas[15][20];
///pintar butacas

int posGot=0;
int posGot2=0;
SetConsoleTextAttribute(hConsole, 7);
for(int x=1;x<=20;x++){
    gotoxy(15+posGot,8);
    cout << "C" << x;
    posGot=posGot+4;
}

for(int x=1;x<=15;x++){
    gotoxy(13,10+posGot2);
    cout << "F" << x;
    posGot2=posGot2+2;
}

posGot=0;
posGot2=0;

for(int x=0;x<15;x++){
    for(int y=0;y<20;y++){
        if(Butacas[x][y]==0){
            SetConsoleTextAttribute(hConsole, 2);
        }
        else if(Butacas[x][y]==1){
            SetConsoleTextAttribute(hConsole, 4);
        }
        else{
            SetConsoleTextAttribute(hConsole, 6);
        }
        gotoxy(15+posGot,10+posGot2);
        cout << char(204) << char(220) << char(185);
        posGot=posGot+4;
    }
    posGot=0;
    posGot2=posGot2+2;
}
}

#endif // VISUALES_H_INCLUDED
