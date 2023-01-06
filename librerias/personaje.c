#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#include "gotoxy.h"
#include "usuario.h"
#include "menus.h"
#include "estructuras.h"
#include "sala.h"
#include "enemigo.h"
#include "objeto.h"
#include "puertas.h"


#define PURCLARO "\033[1;35m"
#define ROJO "\033[0;31m"
#define CYAN "\033[0;36m"
#define VERDE "\033[0;32m"
#define VERDESUB "\033[4;32m"
#define AZUL "\033[0;34m"
#define MARRON "\033[0;33m"
#define NORMAL "\033[0m"
#define NORMALSUB "\033[4;1;37m"
#define APERTURA "\033[0;36m[\033[0m"
#define CERRADO "\033[0;36m]\033[0m"

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77

#define ESPACIO 32
#define CANCELAR 8
#define ENTER 13
#define SALIR 27
#define C 99
#define A 97
#define E 101
#define G 103

#define ESBIRRO 1
#define BOOS 2



void interfaz(stPj * personaje)
{
    dibujarCuadroAscii(1,1,117,24,219);
    dibujarCuadro(0,0,118,25,CYAN); // cuadrado principal
    dibujarCuadro(0,0,118,39,CYAN);//cuadrado panel

    cuadradoAscii(1,26,118,39,219);//cuadrado estado nombre personaje


    cuadradoConMarco(40,27,68,37,CYAN); // DATOS PERSONAJE

    cuadradoConMarco(70,27,105,37,CYAN); // BOTONES OPCIONES

    cuadradoAscii(2,27,38,38,32); //CONTROLES

    gotoxy(4,27);
    printf("             ______ ");
    gotoxy(4,28);
    printf("            | | W  |");
    gotoxy(4,29);
    printf("            | | ^  |");
    gotoxy(4,30);
    printf("            | |_|__|");
    gotoxy(4,31);
    printf("            |/_____/");
    gotoxy(4,32);
    printf(" ______      ______      ______");
    gotoxy(4,33);
    printf("| | A  |    | | S  |    | | D  |");
    gotoxy(4,34);
    printf("| | <- |    | | |  |    | | -> |");
    gotoxy(4,35);
    printf("| |____|    | |_v__|    | |____|");
    gotoxy(4,36);
    printf("|/_____/    |/_____/    |/_____/");

    dibujarCuadro(2,27,37,37,CYAN); //CONTROLES


    gotoxy(42,28);
    printf("%sPersonaje:%s",VERDESUB,NORMAL);
    gotoxy(42,29);
    printf("%s>%s%s",VERDE,NORMAL,personaje->nick); //nombre personaje
    gotoxy(42,30);
    printf("%sVida:%s",VERDESUB,NORMAL);
    mostrarVida(42,31,personaje->atributos.vida,254); //vida personaje
    gotoxy(42,33);
    printf("%sDanio%s",VERDESUB,NORMAL);
    gotoxy(42,34);
    printf("%s%.2d%s",APERTURA,personaje->atributos.danio,CERRADO);
    gotoxy(42,35);
    printf("%sLlaves:%s",VERDESUB,NORMAL);
    gotoxy(42,36);
    printf("%s%.2d%s",APERTURA,personaje->llaves,CERRADO);
    gotoxy(personaje->posicion.x,personaje->posicion.y);
    printf("%s%c%s",CYAN,219,NORMAL);
    gotoxy(personaje->posicion.x,personaje->posicion.y);


    botonSalir(72,28);
    botonGuardar(87,28);

    gotoxy(73,35); printf("%sSALIR%s",APERTURA,CERRADO);
    gotoxy(86,35); printf("%sGUARDAR PARTIDA%s",APERTURA,CERRADO);


}

void crearPj(stPj * personaje, int xSpawn,int ySpawn, char nick[],int id)
{
    strcpy(personaje->nick,nick);
    personaje->id = id;
    personaje->favorito = false;
    personaje->atributos.vida = 20;
    personaje->atributos.danio = 5;
    personaje->atributos.defensa = 4;
    personaje->llaves = 0;

    personaje->posicion.x = xSpawn;
    personaje->posicion.y = ySpawn;

    gotoxy(xSpawn,ySpawn);
    printf("%s%c%s",CYAN,219,NORMAL);
    gotoxy(xSpawn,ySpawn);

    return personaje;
}

//COMPRUEBA LA COLICION DEL PERSONAJE EN LA MATRIZ
void comprueboPosicion(stSala * room,stPj * personaje,int x,int y)
{
    bool flag;

    if(room->matriz[x][y] != 219)
    {
        if(room->matriz[x][y] == 35)
        {
            nodoPuerta * puerta = buscarPuerta(room->listaPuertas,x,y);
            if(puerta->habilitado  == true && personaje->llaves >= puerta->cantLlaves)
            {
                personaje->posicion.x = x;
                personaje->posicion.y = y;
                room->matriz[puerta->posPuerta.x][puerta->posPuerta.y] = 250;
                puerta->habilitado = false;
                personaje->llaves -= puerta->cantLlaves;
                gotoxy(42,36);
                printf("%s%.2d%s",APERTURA,personaje->llaves,CERRADO);
            }
            else if(puerta->habilitado  == true && personaje->llaves != puerta->cantLlaves)
            {
                personaje->posicion.x = personaje->posicion.x;
                personaje->posicion.y = personaje->posicion.y;
            }
            else
            {
                personaje->posicion.x = x;
                personaje->posicion.y = y;
            }
        }
        else
        {

            personaje->posicion.x = x;
            personaje->posicion.y = y;
        }
    }
}

void mostrarVida(int x, int y,int fin, int ascii)
{
    int contador =0;
    int valor = x + fin;
    for(int i = x ; i <= valor; i++ )
    {
        if(contador <= 20)
        {
            gotoxy (i,y);
            printf("%s%c%s",ROJO,ascii,NORMAL);
            gotoxy (x,y+1);
            printf("|0");
            gotoxy (valor-1,y+1);
            printf(">|%d",fin);
        }
        contador++;
    }
}

int movimientoPersonaje(bool estado,stSala * room, stPj * personaje,char archivo[])
{
    muestraMatriz(room->matriz,room->filas,room->columnas,0,0);
    mostrarLista(room->listaEnemigos);
    muestraListaObjetos(room->listaDeObjetos);
    interfaz(personaje);

    char tecla;

    while(!estado && tecla != SALIR)
    {
        if(kbhit())
        {
            int nuevaX;
            int nuevaY;

            tecla = getch();

            gotoxy(personaje->posicion.x,personaje->posicion.y);
            printf("%s%c%s",VERDE,250,NORMAL);
            if(tecla == 'w')
            {
                nuevaX = personaje->posicion.x;
                nuevaY = personaje->posicion.y-1;
                comprueboPosicion(room,personaje,nuevaX,nuevaY);
            }
            if(tecla == 's')
            {
                nuevaX = personaje->posicion.x;
                nuevaY = personaje->posicion.y+1;
                comprueboPosicion(room,personaje,nuevaX,nuevaY);
            }
            if(tecla == 'a')
            {
                nuevaX = personaje->posicion.x-1;
                nuevaY = personaje->posicion.y;
                comprueboPosicion(room,personaje,nuevaX,nuevaY);
            }
            if(tecla == 'd')
            {
                nuevaX = personaje->posicion.x+1;
                nuevaY = personaje->posicion.y;
                comprueboPosicion(room,personaje,nuevaX,nuevaY);
            }
            //METODO RECORRER LA LISTA DE ENEMIGOS (QUE RICIBE POR PARAMETRO LA POSICION X Y DEL PJ y LISTA ENEMIGOS)
            personaje = colicionEnemigo(personaje,room,&estado);
            personaje = agarraObjeto(personaje,room);

            gotoxy(personaje->posicion.x,personaje->posicion.y);
            printf("%s%c%s",CYAN,219,NORMAL);
            gotoxy(personaje->posicion.x,personaje->posicion.y);

            if(personaje->atributos.vida < 1)
            {
                frontGameOver();
                tecla = SALIR;
            }

            if(estado == true)
            {
                system("cls");
                PantallaVictoria();
            }

            if(tecla == SALIR)
            {
                aniBotonSalir(72,28);
            }
            if(tecla == G)
            {
                aniBotonGuardar(87,28);
                guardarDatosPersonaje(&(*personaje),archivo);
            }
        }
    }
    return estado;
}

void pintarPersonajeParado(int x,int y)
{
    gotoxy(x,y);
    printf("     %c%c",219,219);

    gotoxy(x,y+2);
    printf("   %c%c%c%c%c%c",220,223,219,219,223,220);
    gotoxy(x,y+3);
    printf("   %c %c%c %c",219,219,219,219);
    gotoxy(x,y+4);
    printf("   %c %c%c %c",220,219,219,220);
    gotoxy(x,y+5);
    printf("    %c  %c",219,219);
    gotoxy(x,y+6);
    printf("    %c  %c",219,219);
    gotoxy(x,y+7);
    printf("   %c%c  %c%c",220,219,219,220);
    gotoxy(x,y+8);
    printf("=============");
    gotoxy(x,y+9);
    printf("  =========");
    gotoxy(x,y+10);
    printf("   ======");
}

void pintarPersonajeDefensa(int x,int y)
{
    gotoxy(x,y-3);
    printf("  %s%c     %c%s",VERDE,38,38,NORMAL);
    gotoxy(x,y-2);
    printf("  %s%c%c    %c%c%s",VERDE,38,38,38,38,NORMAL);
    gotoxy(x,y-1);
    printf("  %s%c%s%c%s%c%s  %s%c%s%c%s%c%s",VERDE,38,NORMAL,223,VERDE,38,NORMAL,VERDE,38,NORMAL,223,VERDE,38,NORMAL);
    gotoxy(x,y);
    printf("   %c %c%c %c",219,219,219,219);
    gotoxy(x,y+1);
    printf("   %c    %c",219,219);
    gotoxy(x,y+2);
    printf("    %c%c%c%c",223,219,219,223);
    gotoxy(x,y+3);
    printf("     %c%c",219,219);
    gotoxy(x,y+4);
    printf("     %c%c",219,219);
    gotoxy(x,y+5);
    printf("    %c  %c",219,219);
    gotoxy(x,y+6);
    printf("    %c  %c",219,219);
    gotoxy(x,y+7);
    printf("   %c%c  %c%c",220,219,219,220);
    gotoxy(x,y+8);
    printf("=============");
    gotoxy(x,y+9);
    printf("  =========");
    gotoxy(x,y+10);
    printf("   ======");
}

void pintarPersonajeAtaca(int x,int y)
{
    gotoxy(x,y-3);
    printf("        %s%c%s",ROJO,38,NORMAL);
    gotoxy(x,y-2);
    printf("       %s%c%c%s",ROJO,38,38,NORMAL);
    gotoxy(x,y-1);
    printf("       %s%c%s%c%s%c%s",ROJO,38,NORMAL,223,ROJO,38,NORMAL);
    gotoxy(x,y);
    printf("     %c%c %c",219,219,219);
    gotoxy(x,y+1);
    printf("        %c",219);
    gotoxy(x,y+2);
    printf("   %c%c%c%c%c",220,223,219,219,223);
    gotoxy(x,y+3);
    printf("   %c %c%c",219,219,219);
    gotoxy(x,y+4);
    printf("   %c %c%c",220,219,219);
    gotoxy(x,y+5);
    printf("    %c  %c",219,219);
    gotoxy(x,y+6);
    printf("    %c  %c",219,219);
    gotoxy(x,y+7);
    printf("   %c%c  %c%c",220,219,219,220);
    gotoxy(x,y+8);
    printf("=============");
    gotoxy(x,y+9);
    printf("  =========");
    gotoxy(x,y+10);
    printf("   ======");
}

stPj * agarraObjeto(stPj * personaje,stSala * room)
{
    int flag = false;
    nodoObjeto * item = room->listaDeObjetos;
    while(item != NULL)
    {
        flag = tocarObjeto(item,personaje->posicion.x,personaje->posicion.y);

        if(flag && item->habilitado)
        {
            if(item->tipo == 1 && personaje->atributos.vida < 20)
            {
                personaje->atributos.vida += item->valor;
                while(personaje->atributos.vida > 20)
                {
                    personaje->atributos.vida--;
                }
            }
            if(item->tipo == 2)
            {
                personaje->atributos.danio += item->valor;
            }
            if(item->tipo == 3)
            {
                personaje->llaves += item->valor;
            }
            item->habilitado = false;

            muestraListaObjetos(room->listaDeObjetos);
            interfaz(personaje);

        }
        item = item->siguiente;
    }
    return personaje;
}

void accionPersonaje(nodoEnemigo * enemigo,stPj * personaje)
{
    int vidaPj = personaje->atributos.vida;
    int tecla;
    bool turno = true;

    cuadradoConMarco(45,3,74,7,MARRON);
    gotoxy(47,4);
    printf("Vida Personaje:");
    mostrarVida(47,5,vidaPj,219);

    cuadradoConMarco(45,18,74,22,MARRON);
    gotoxy(47,19);
    printf("Vida Enemigo:");
    mostrarVida(47,20,enemigo->atributos.vida,219);

    while(turno == true)
    {
        if(kbhit())
        {
            tecla = getch();
            if(tecla == 'j')
            {
                cuadradoConMarco(3,3,26,22,MARRON); // cuadrado personaje
                pintarPersonajeAtaca(9,10);
                Sleep(500);

                enemigo->atributos.vida -= personaje->atributos.danio;

                 cuadradoConMarco(3,3,26,22,MARRON); // cuadrado personaje
                pintarPersonajeParado(9,10);
                Sleep(500);

                turno = false;
            }
            if(tecla == 'k')
            {
                cuadradoConMarco(3,3,26,22,MARRON); // cuadrado personaje
                pintarPersonajeDefensa(9,10);
                Sleep(500);

                if(vidaPj <20)
                {
                    vidaPj += personaje->atributos.defensa;
                }

                cuadradoConMarco(3,3,26,22,MARRON); // cuadrado personaje
                pintarPersonajeParado(9,10);
                Sleep(500);

                turno = false;
            }
            if(tecla == 'l')
            {
                cuadradoConMarco(3,3,26,22,MARRON); // cuadrado personaje
                pintarPersonajeParado(9,10);
                Sleep(500);
                turno = false;
            }

                cuadradoConMarco(45,3,74,7,MARRON);
                gotoxy(47,4);
                printf("Vida Personaje:");
                mostrarVida(47,5,vidaPj,219);

                cuadradoConMarco(45,18,74,22,MARRON);
                gotoxy(47,19);
                printf("Vida Enemigo:");
                mostrarVida(47,20,enemigo->atributos.vida,219);
        }
    }
    personaje->atributos.vida = vidaPj;
}

void cartelTurnoPj()
{
    cuadradoConMarco(28,3,35,9,MARRON);
    printf("%s",VERDE);
    gotoxy(32,5); printf("%c%c",220,219);
    gotoxy(31,6); printf("%c%c%c",219,219,219);
    gotoxy(32,7); printf("%c%c",223,219);
    printf("%s",NORMAL);
}

int verificarCantPersonajes(nodoDoblePj * lista)
{
    int contador = 0;
    while(lista != NULL)
    {
        contador++;
        lista = lista->siguientePj;
    }

   return contador;
}

void pasarPersonajeListaArchivo(char nombreArchivo[],nodoDoblePj * nuevo)
{
    stPj personaje;
    char ruta [30] = "listaPersonajesUsuarios\\";
    strcat(ruta,nombreArchivo);
    int contador = 0;
    FILE * archivo = fopen(ruta,"a+b");

    if(archivo)
    {
        while(fread(&personaje,sizeof(personaje),1,archivo)>0)
        {
            contador++;
        }
        if(contador < 5)
        {
            personaje = nuevo->personaje;
            fwrite(&personaje,sizeof(personaje),1,archivo);
        }
        fclose(archivo);
    }
}

nodoDoblePj * inicNodoDoblePj()
{
    return NULL;
}

nodoDoblePj * crearPersonajeNodo2(stPj personaje)
{
    nodoDoblePj * nodoAuxiliar = (nodoDoblePj*)malloc(sizeof(nodoDoblePj));
    nodoAuxiliar->personaje = personaje;
    nodoAuxiliar->siguientePj = NULL;
    nodoAuxiliar->anteriorPj = NULL;

    return nodoAuxiliar;
}

nodoDoblePj * agregarAlPrincipioDoble(nodoDoblePj * lista, nodoDoblePj * nuevoNodo)
{
    nuevoNodo->siguientePj = lista;

    if (lista != NULL)
    {
        lista->anteriorPj = nuevoNodo;
    }

    return nuevoNodo;
}

nodoDoblePj * agregarNodoDobleOrden(nodoDoblePj * lista, nodoDoblePj * nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else if (nuevoNodo->personaje.id < lista->personaje.id)
    {
        lista = agregarAlPrincipioDoble(lista, nuevoNodo);
    }
    else
    {
        nodoDoblePj * anterior = lista;
        nodoDoblePj * iterador = lista->siguientePj;

        while (iterador != NULL && iterador->personaje.id < nuevoNodo->personaje.id)
        {
            anterior = iterador;
            iterador = iterador->siguientePj;
        }
        anterior->siguientePj = nuevoNodo;
        nuevoNodo->anteriorPj = anterior;
        nuevoNodo->siguientePj = iterador;

        if (iterador != NULL)
        {
            iterador->anteriorPj = nuevoNodo;
        }
    }
    return lista;
}

nodoDoblePj * borrarNodo(nodoDoblePj * lista, int dato)
{
    nodoDoblePj * borrado = NULL;
    nodoDoblePj * iterador = NULL;

    if(lista!=NULL)
    {
        if(lista->personaje.id == dato)
        {
            borrado = lista;

            lista = lista->siguientePj;

            if(lista != NULL)
            {
                lista->anteriorPj = NULL;
            }

            free(borrado);
        }
        else
        {
            iterador = lista->siguientePj;

            while(iterador != NULL && iterador->personaje.id != dato)
            {
                iterador = iterador->siguientePj;
            }

            if( iterador!= NULL)
            {
                nodoDoblePj * anterior = iterador->anteriorPj; // bajo a una variable el anterior

                anterior->siguientePj = iterador->siguientePj; //salteo el nodo que quiero eliminar.

                if(iterador->siguientePj) // si existe el nodo siguiente
                {
                    nodoDoblePj * siguiente = iterador->siguientePj;
                    siguiente->anteriorPj = anterior;
                }
                free(iterador); //elimino el nodo.
            }
        }
    }
    return lista;

}

void contienePersonajes(int valor)
{
    if(valor == 0)
    {
        cartelNoJugadores(79,10);
    }
}

void mostrarFavoritoPj(nodoDoblePj * lista,int x,int y)
{
    while(lista != NULL)
    {
        if(lista->personaje.favorito == true)
        {
            gotoxy(x,y);printf("%c",4);
        }
        else
        {
            gotoxy(x,y);printf(" ");
        }
    }
}

void cuadradoFav(int x,int y)
{
    gotoxy(x,y);printf("%c%c%c%c%c",201,205,205,205,187);
    gotoxy(x,y+1);printf("%c   %c FAV",186,186);
    gotoxy(x,y+2);printf("%c%c%c%c%c",200,205,205,205,188);
}

void muestraUnPersonaje(stPj personaje)
{

    gotoxy(73,3);printf("                      ");
    gotoxy(73,3);printf("%s",personaje.nick);
    gotoxy(61,4);printf("   ");
    gotoxy(61,4);printf("%s%d%s",APERTURA,personaje.id,CERRADO);
    gotoxy(62,5);printf("%sID%s",NORMALSUB,NORMAL);
    gotoxy(58,25);printf("   ");
    gotoxy(58,25);printf("%s%.2d%s",APERTURA,personaje.atributos.vida,CERRADO);
    gotoxy(73,25);printf("   ");
    gotoxy(73,25);printf("%s%.2d%s",APERTURA,personaje.atributos.danio,CERRADO);
    gotoxy(89,25);printf("   ");
    gotoxy(89,25);printf("%s%.2d%s",APERTURA,personaje.atributos.defensa,CERRADO);
    gotoxy(106,25);printf("   ");
    gotoxy(106,25);printf("%s%d%s",APERTURA,personaje.llaves,CERRADO);
    if(personaje.favorito == true)
    {
        gotoxy(58,16);printf("%s%c%s",MARRON,4,NORMAL);
    }
    else
    {
        gotoxy(58,16);printf(" ");
    }
}

void guardadoPersonajes(char nombreArchivo[],nodoDoblePj * lista)
{
    stPj personaje;
    char ruta [30] = "listaPersonajesUsuarios\\";
    strcat(ruta,nombreArchivo);
    FILE * archivo = fopen(ruta,"w+b");
    if(archivo)
    {
        while(lista != NULL)
        {
            personaje = lista->personaje;
            fwrite(&personaje,sizeof(personaje),1,archivo);
            lista = lista->siguientePj;
        }

        fclose(archivo);
    }
}

void muestraPrueba(nodoDoblePj * lista)
{
    if(lista == NULL)
    {
        printf("LISTA VACIA");
    }
    while(lista != NULL)
    {
        printf("%s\n",lista->personaje.nick);
//        muestraUnPersonaje(lista->personaje);
        lista = lista->siguientePj;
    }

}

nodoDoblePj * pasarListaPersonajesArchivo(char nombreArchivo[],nodoDoblePj * lista)
{
    stPj personaje;
    char ruta [80] = "listaPersonajesUsuarios\\";
    strcat(ruta,nombreArchivo);
    FILE * archivo = fopen(ruta,"r+b");
    if(archivo)
    {
        while(fread(&personaje,sizeof(personaje),1,archivo)>0)
        {
            lista = agregarNodoDobleOrden(lista,crearPersonajeNodo2(personaje));
        }

        fclose(archivo);
    }
    return lista;
}

nodoDoblePj * editarPersonaje(nodoDoblePj * lista,int id,char nombreNuevo[])
{
    nodoDoblePj * iterator = lista;
    while(iterator != NULL)
    {
        if(iterator->personaje.id == id)
        {
            limpiarArregloChar(iterator->personaje.nick);
            strcpy(iterator->personaje.nick,nombreNuevo);
        }
    }
    return lista;
}

void colocarAlPrincipioLista(nodoDoblePj ** lista)
{
    while((*lista)->anteriorPj != NULL)
    {
        (*lista) = (*lista)->anteriorPj;
    }
}

void muestraPersonajesMenuAdmin(stPj personaje)
{

    gotoxy(91,3);printf("                      ");
    gotoxy(91,3);printf("%s%s%s",APERTURA,personaje.nick,CERRADO);

    gotoxy(95,8);printf("    ");
    gotoxy(95,8);printf("%s%d%s",APERTURA,personaje.atributos.vida,CERRADO);

    gotoxy(107,8);printf("    ");
    gotoxy(107,8);printf("%s%d%s",APERTURA,personaje.atributos.danio,CERRADO);

    gotoxy(95,13);printf("   ");
    gotoxy(95,13);printf("%s%d%s",APERTURA,personaje.atributos.defensa,CERRADO);

    gotoxy(107,13);printf("   ");
    gotoxy(107,13);printf("%s%d%s",APERTURA,personaje.llaves,CERRADO);

    if(personaje.favorito == true)
    {
        gotoxy(103,18);printf("%s%c%s",MARRON,4,NORMAL);
    }
    else
    {
        gotoxy(103,18);printf(" ");
    }
}

void borrarDatosPersonajesMenuAdmin()
{
    gotoxy(91,3);printf("                      ");
    gotoxy(95,8);printf("    ");
    gotoxy(107,8);printf("    ");
    gotoxy(95,13);printf("    ");
    gotoxy(107,13);printf("   ");
    gotoxy(102,18);printf(" ");
}

void borrarTodaLaLista(nodoDoblePj ** lista)
{
    nodoDoblePj * borrado;

    while((*lista) != NULL)
    {
        borrado = (*lista);
        (*lista) = (*lista)->siguientePj;
        free(borrado);
    }
}

void editarPersonajeMenuAdministrador(stPj * personaje)
{
    char nuevoNombre[30];
    gotoxy(91,3); printf("                      ");
    cargarDato(nuevoNombre,91,3);
    limpiarArregloChar(personaje->nick);
    strcpy(personaje->nick,nuevoNombre);

    gotoxy(95,8);printf("    ");
    fflush(stdin);
    gotoxy(96,8);scanf("%d",&personaje->atributos.vida);

    gotoxy(107,8);printf("   ");
    fflush(stdin);
    gotoxy(108,8);scanf("%d",&personaje->atributos.danio);

    gotoxy(95,13);printf("   ");
    fflush(stdin);
    gotoxy(96,13);scanf("%d",&personaje->atributos.defensa);

    gotoxy(107,13);printf("   ");
    fflush(stdin);
    gotoxy(108,13);scanf("%d",&personaje->llaves);
}

void borrarArchivoFisico (char rutaArchivo[])
{
    char ruta [80] = "listaPersonajesUsuarios\\";
    strcat(ruta,rutaArchivo);
    remove(ruta);
}

void guardarDatosPersonaje(stPj * personaje,char nombreArchivo[])
{
    stPj iterator;
    char ruta [30] = "listaPersonajesUsuarios\\";
    strcat(ruta,nombreArchivo);
    FILE * archivo = fopen(ruta,"r+b");
    if(archivo)
    {
        while(fread(&iterator,sizeof(iterator),1,archivo)>0)
        {
            if(iterator.id == personaje->id)
            {
                fseek(archivo,sizeof(stUsuario)*-1,SEEK_CUR);

                iterator = (*personaje);

                fwrite(&personaje,sizeof(iterator),1,archivo);

                fclose(archivo);
            }
        }
    }
}








