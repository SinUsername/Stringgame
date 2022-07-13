/*

Este es un codigo simple para ver para
que sirve estas cabeceras de C y como se usan 
para hacerse una idea.

*/
#include "stringgame.h"

/*
Definimos unas macros para utilizarlas
como teclas de movimientos el las cabeceras
o en el stringdefinitions.h se hallan son
solo el 'abc' basico con los numeros nada nuevo
*/
#define A 'a'
#define D 'd'
#define S 's'
#define W 'w'
/*Funcion principal*/
function main (){
    
    /*Se declaro una variable tipo char
    la cual sera utilizada para mover o
    la que vas ha mover*/
    char CharMove[] = "@";
    
    /*Se declara una structura la cual es nesesaria
    para mover el caracter*/
    struct Object Char;
    
    Char.ID = 1;/*inicializamos el ID que simplemente es para llevar un control y no marque error*/
    Char.positionX = 30;/*inicializamos la posicion en X en la posicion deseada*/
    Char.positionY = 10;/*inicializamos la posicion en Y en la posicion deseada*/
    strcpy(Char.Name,"Char_Move");/*le damos un nombre , al igual que el ID es para llevar un control*/
    
    /*creamos un bucle infinito*/
    while(True){
        
        string_clrscr();/*funcion para limbiar la pantalla*/
        StrShowObjectCoordinates(&CharMove);/*funcion para mostrar las coordenadas o posicion actual del caracter*/
        StrMoveObject(&Char,CharMove,A,D,S,W);/*funcion clave para mover el caracter sus parametros son sencillos
        el primero es la struct que hemos creador con antoriormente el segundo es un string es cual es el caracter
        que se desea mover y los ultimos 4 son la teclas que se utilizara para moverlo(Solo letras , números y simbolos)*/
        StrlimitObject(80,-1,23,-1);/*funcion para poner limites: 4 parametros primero: limite de la derecha segundo: limite
        de la izquierda , tercero: limite de abajo y cuarto limite de arriba*/
        
    }
    
    return 0;
}
