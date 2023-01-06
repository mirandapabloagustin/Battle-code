#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#include "TDAlistaSimple.h"
#include "TDAarboles.h"
#include "botonesAnimaciones.h"
#include "gotoxy.h"
#include "usuario.h"
#include "menus.h"
#include "estructuras.h"


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
#define PALABRACLAVE "mermelada"

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
#define V 118
#define UNO 49
#define DOS 50
#define TRES 51


#define ESBIRRO 1
#define BOOS 2




//    FUNCIONES MENUS




void frontMenuCombate()
{
    system("cls");
    dibujarCuadro(0,0,118,25,CYAN); // cuadrado principal
    dibujarCuadro(0,0,118,39,CYAN);//cuadrado panel
    dibujarCuadro(4,4,29,22,CYAN); // cuadrado Exterior
    cuadradoAscii(2,2,117,24,219);//cuadrado batalla
    cuadradoAscii(2,26,117,39,219);


    cuadradoConMarco(3,3,26,22,MARRON); // cuadrado personaje
    cuadradoConMarco(92,3,115,22,MARRON); //cuadrado enemigo
    cuadradoConMarco(45,10,74,16,MARRON); //cuadrado accion enemigo

    pintarEnemigo(99,10);
    pintarPersonajeParado(9,10);

    cuadradoConMarco(42,27,77,36,MARRON); //cuadrado muestra controles
    muestraControles(44,30);
    gotoxy(44,29);
    printf("%sAtaca%s     %sCurar%s     %sEspera%s",APERTURA,CERRADO,APERTURA,CERRADO,APERTURA,CERRADO);

    cuadradoConMarco(3,27,35,37,MARRON); //cuadrado muestra info enemigo

    cuadradoConMarco(84,27,115,31,MARRON); //cuadrado estad. info enemigo
    cuadradoConMarco(84,31,115,37,MARRON); //cuadrado estad. info enemigo

}

void menuCombate(stPj * personaje,nodoEnemigo * enemigo)
{
    frontMenuCombate();
    gotoxy(86,28);
    printf("ENEMIGO:");
    nombresEnemigos(enemigo->atributos.tipo);
    gotoxy(90,32);
    printf("ATRIBUTOS:");
    gotoxy(86,33);
    printf("Vida : %d",enemigo->atributos.vida);
    gotoxy(86,34);
    printf("Danio : %d",enemigo->atributos.danio);
    gotoxy(86,35);
    printf("Defensa : %d",enemigo->atributos.defensa);
}

char menuInicioSesionSecundario(char tecla)
{
    frontMenuInicioSesion();
    int posicion = 1;
    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();

            if(tecla == DERECHA)
            {
                cuadradoAscii(28,31,34,33,32);
                selector(61,31);
                posicion  = 2;
            }
            if(tecla == IZQUIERDA)
            {
                cuadradoAscii(60,31,66,33,32);
                selector(28,31);
                posicion = 1;
            }
            if(tecla == ENTER && posicion == 1)
            {
                aniBotonIngresar(35,30);
                tecla = menuIngresar(0);
            }
            if(tecla == ENTER && posicion == 2)
            {
                aniBotonRegistrarse(68,30);
                tecla = menuRegitro(0);
            }
        }
    }
    return tecla;
}

char inicioMenuSecundario(char tecla)
{
    frontInicioMenu();
    while(tecla != SALIR)
    {

        if(kbhit())
        {
            tecla = getch();

            if(tecla == ENTER)
            {
                aniBotonAceptar(45,33);
                tecla = menuInicioSesion(0);
            }
            if(tecla == C)
            {
                aniBotonCreditos(2,33);
                frontCreditos();
                Sleep(10000);
                tecla = inicioMenuSecundario(0);
            }
            if(tecla == A)
            {
                aniBotonAdmin(103,34);
                tecla = menuAdministrador(0);
            }
        }
    }
    return tecla;
}

void frontMenuInicioSesion()
{
    system("cls");

    gotoxy(28,16);
    printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
    gotoxy(28,17);
    printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);
    gotoxy(87,16);
    printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
    gotoxy(87,17);
    printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);

    dibujarCuadro(0,0,119,39,CYAN);

    nombreJuego(33,10);
    botonIngresar(35,30);
    botonRegistrarse(68,30);
    botonSalir(2,1);
    gotoxy(30,24);
    printf("printf(%cSi tienes una Cuenta Ingresar sino Registrate...%c);",34,34);
    selector(28,31);
}

char menuInicioSesion(char tecla)
{
    frontMenuInicioSesion();
    int posicion = 1;
    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();

            if(tecla == DERECHA)
            {
                cuadradoAscii(28,31,34,33,32);
                selector(61,31);
                posicion  = 2;
            }
            if(tecla == IZQUIERDA)
            {
                cuadradoAscii(60,31,66,33,32);
                selector(28,31);
                posicion = 1;
            }
            if(tecla == ENTER && posicion == 1)
            {
                aniBotonIngresar(35,30);
                tecla = menuIngresar(0);
            }
            if(tecla == ENTER && posicion == 2)
            {
                aniBotonRegistrarse(68,30);
                tecla = menuRegitro(0);
            }
            if(tecla == SALIR)
            {
                aniBotonSalir(2,1);
                tecla = inicioMenuSecundario(0);
            }
        }
    }
    return tecla;
}

void frontInicioMenu()
{
    system("cls");
    gotoxy(4,10);
    printf("printf(%cHello World!%c);",34,34);
    gotoxy(50,5);
    printf("printf(%cGoodbye World!%c);",34,34);
    gotoxy(70,8);
    printf("desapilar(&Wold);");
    gotoxy(4,30);
    printf("Sleep(forever);",34,34);
    gotoxy(20,3);
    printf("while(jugadorVivo != dead);");
    gotoxy(10,25);
    printf("free(nodoJugador);");
    gotoxy(90,25);
    printf("if(siApruebo)");
    gotoxy(90,26);
    printf("     bailar;");
    gotoxy(90,27);
    printf("else");
    gotoxy(90,28);
    printf("     llorar;");

    gotoxy(28,16);
    printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
    gotoxy(28,17);
    printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);

    gotoxy(87,16);
    printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
    gotoxy(87,17);
    printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);

    dibujarCuadro(0,0,119,39,CYAN);
    nombreJuego(33,10);
    botonAdmin(103,34);
    botonAceptar(45,33);
    botonSalir(2,1);
    botonCreditos(2,33);
}

char inicioMenu(char tecla)
{
    frontInicioMenu();
    while(tecla != SALIR)
    {

        if(kbhit())
        {
            tecla = getch();

            if(tecla == ENTER)
            {
                aniBotonAceptar(45,33);
                tecla = menuInicioSesion(0);
            }
            if(tecla == C)
            {
                aniBotonCreditos(2,33);
                frontCreditos();
                Sleep(10000);
                tecla = inicioMenuSecundario(0);
            }
            if(tecla == A)
            {
                aniBotonAdmin(103,34);
                tecla = menuAdministrador(0);

            }
            if(tecla == SALIR)
            {
                aniBotonSalir(2,1);
                system("cls");
            }
        }
    }
    return tecla;
}

void frontMenuIngreso()
{
    gotoxy(28,16);
    printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
    gotoxy(28,17);
    printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);
    gotoxy(87,16);
    printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
    gotoxy(87,17);
    printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);

    dibujarCuadro(0,0,119,39,CYAN);
    botonEnter(80,25);
    nombreJuego(33,10);
    botonSalir(2,1);
    botonEmail(27,25);
    botonContrasenia(27,30);

    gotoxy(35,23);
    printf("printf(%cPrecione ESPACIO para Iniciar Sesion...%c);",34,34);

    botonCargaDatos(44,25);
    botonCargaDatos(44,30);
}

char menuIngresarSecundario(char tecla)
{

    system("cls");
    frontMenuIngreso();

    char email[30];
    char contrasenia [30];
    stUsuario usuario;

    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();

            if(tecla == ESPACIO)
            {
                limpiarArregloChar(email);
                cuadradoAscii(47,26,78,27,32);
                gotoxy(48,26);
                cargarDato(email,48,26);
                aniBotonEmail(27,25);

                limpiarArregloChar(contrasenia);
                cuadradoAscii(47,31,78,32,32);
                gotoxy(48,31);
                cargarDatoPass(contrasenia,48,31);
                aniBotonPass(27,30);
            }
            if(tecla == ENTER)
            {
                aniBotonEnter(80,25);
                int flag = verificarUsuario(email,contrasenia);
                if(flag)
                {
                    usuario = buscaUsuario(email);
                    gotoxy(25,37);
                    printf("%sprintf(%cBienvenido %s ...%c);%s",VERDE,34,usuario.nickUsuario,34,NORMAL);
                    Sleep(2000);
                    tecla = menuUsuario(usuario,0);
                }
                else
                {
                    gotoxy(20,37);
                    printf("%sprintf(%cTe atrapamos tramposillo, apriete ESPACIO para volver a Intentar...%c);%s",ROJO,34,34,NORMAL);
                    Sleep(3000);
                    cuadradoAscii(20,36,100,38,32);
                }
            }
        }
    }
    return tecla;
}

char menuIngresar(char tecla)
{

    system("cls");
    frontMenuIngreso();

    char email[30];
    char contrasenia [30];
    stUsuario usuario;

    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();

            if(tecla == ESPACIO)
            {
                limpiarArregloChar(email);
                cuadradoAscii(47,26,78,27,32);
                gotoxy(48,26);
                cargarDato(email,48,26);
                aniBotonEmail(27,25);

                limpiarArregloChar(contrasenia);
                cuadradoAscii(47,31,78,32,32);
                gotoxy(48,31);
                cargarDatoPass(contrasenia,48,31);
                aniBotonPass(27,30);
            }
            if(tecla == ENTER)
            {
                aniBotonEnter(80,25);
                int flag = verificarUsuario(email,contrasenia);
                if(flag)
                {
                    usuario = buscaUsuario(email);
                    gotoxy(25,37);
                    printf("%sprintf(%cBienvenido %s ...%c);%s",VERDE,34,usuario.nickUsuario,34,NORMAL);
                    Sleep(2000);
                    tecla = menuUsuario(usuario,0);
                }
                else
                {
                    gotoxy(20,37);
                    printf("%sprintf(%cTe atrapamos tramposillo, apriete ESPACIO para volver a Intentar...%c);%s",ROJO,34,34,NORMAL);
                    Sleep(3000);
                    cuadradoAscii(20,36,100,38,32);
                }
            }
            if(tecla == SALIR)
            {
                aniBotonSalir(2,1);
                tecla = menuInicioSesionSecundario(0);
            }
        }
    }
    return tecla;
}

void frontMenuAdministrador()
{
    system("cls");
    gotoxy(28,12);
    printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
    gotoxy(28,13);
    printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);
    gotoxy(87,12);
    printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
    gotoxy(87,13);
    printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);

    dibujarCuadro(0,0,119,39,CYAN);
    botonEnter(80,25);
    tituloAdmins(33,8);
    botonSalir(2,1);

    botonEmail(27,20);
    botonContrasenia(27,25);
    botonCodigo(27,30);

    gotoxy(36,19);
    printf("printf(%cBienvenido Se%cor de las Tinieblas...%c);",34,164,34);

    botonCargaDatos(44,20);
    botonCargaDatos(44,25);
    botonCargaDatos(44,30);
}

char menuAdministradorSecundario(char tecla)
{
    frontMenuAdministrador();

    char email[30];
    char contrasenia [30];
    char palabraSecreta[30];
    stUsuario usuario;

    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();

            if(tecla == ESPACIO)
            {
                limpiarArregloChar(email);
                cuadradoAscii(48,21,78,22,32);
                cargarDato(email,48,21);
                aniBotonEmail(27,20);

                limpiarArregloChar(contrasenia);
                cuadradoAscii(48,26,78,27,32);
                cargarDatoPass(contrasenia,48,26);
                aniBotonPass(27,25);

                limpiarArregloChar(palabraSecreta);
                cuadradoAscii(48,31,78,32,32);
                cargarDatoPass(palabraSecreta,48,31);
                aniBotonCodigo(27,30);


            }
            if(tecla == ENTER)
            {
                aniBotonEnter(80,25);
                int flag = verificarUsuario(email,contrasenia);
                if(flag)
                {
                    usuario = buscaUsuario(email);

                    if(strcmpi(palabraSecreta,PALABRACLAVE) == 0)
                    {
                        gotoxy(40,37);
                        printf("%sprintf(%cBienvenido %s ...%c);%s",VERDE,34,usuario.nickUsuario,34,NORMAL);
                        Sleep(2000);
                        tecla = menuComandoAdmin(0,usuario);
                    }
                    else
                    {
                        gotoxy(20,37);
                        printf("%sprintf(%cLa policia esta llendo a tu casa IMPOSTOR!!!...  o vuelva intentar...%c);%s",ROJO,34,34,NORMAL);
                        Sleep(4000);
                        cuadradoAscii(15,36,100,38,32);
                    }
                }
                else
                {
                    gotoxy(20,37);
                    printf("%sprintf(%cTe atrapamos tramposillo, apriete ESPACIO para volver a Intentar...%c);%s",ROJO,34,34,NORMAL);
                    Sleep(3000);
                    cuadradoAscii(20,36,100,38,32);
                }
            }
            if(tecla == SALIR)
            {
                system("cls");
            }
        }
    }
    return tecla;
}

char menuAdministrador(char tecla)
{
    frontMenuAdministrador();

    char email[30];
    char contrasenia [30];
    char palabraSecreta[30];
    stUsuario usuario;

    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();

            if(tecla == ESPACIO)
            {
                limpiarArregloChar(email);
                cuadradoAscii(48,21,78,22,32);
                cargarDato(email,48,21);
                aniBotonEmail(27,20);

                limpiarArregloChar(contrasenia);
                cuadradoAscii(48,26,78,27,32);
                cargarDatoPass(contrasenia,48,26);
                aniBotonPass(27,25);

                limpiarArregloChar(palabraSecreta);
                cuadradoAscii(48,31,78,32,32);
                cargarDatoPass(palabraSecreta,48,31);
                aniBotonCodigo(27,30);


            }
            if(tecla == ENTER)
            {
                aniBotonEnter(80,25);
                int flag = verificarUsuario(email,contrasenia);
                if(flag)
                {
                    usuario = buscaUsuario(email);

                    if(strcmpi(palabraSecreta,PALABRACLAVE) == 0)
                    {
                        gotoxy(40,37);
                        printf("%sprintf(%cBienvenido %s ...%c);%s",VERDE,34,usuario.nickUsuario,34,NORMAL);
                        Sleep(2000);
                        tecla = menuComandoAdmin(0,usuario);
                    }
                    else
                    {
                        gotoxy(20,37);
                        printf("%sprintf(%cLa policia esta llendo a tu casa IMPOSTOR!!!...  o vuelva intentar...%c);%s",ROJO,34,34,NORMAL);
                        Sleep(4000);
                        cuadradoAscii(15,36,100,38,32);
                    }
                }
                else
                {
                    gotoxy(20,37);
                    printf("%sprintf(%cTe atrapamos tramposillo, apriete ESPACIO para volver a Intentar...%c);%s",ROJO,34,34,NORMAL);
                    Sleep(3000);
                    cuadradoAscii(20,36,100,38,32);
                }
            }
            if(tecla == SALIR)
            {
                aniBotonSalir(2,1);
                tecla = inicioMenuSecundario(0);
            }
        }
    }
    return tecla;
}

void frontMenuRegistro()
{
    system("cls");
    dibujarCuadro(0,0,119,39,CYAN);

    gotoxy(35,3);
    printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
    gotoxy(35,4);
    printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);
    gotoxy(80,3);
    printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
    gotoxy(80,4);
    printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);

    tituloMenu(40,1);
    gotoxy(30,7);
    printf("printf(%cPrecione ESPACIO para llenar los Campos...%c);",34,34);
    gotoxy(90,9);
    printf("printf(%cREGISTRAR...%c);",34,34);

    botonEnter(95,10);
    botonSalir(2,1);

    botonNombreApellidoUsuario(27,10);
    botonNombreUsuario(27,15);
    botonEmail(27,20);
    botonContrasenia(27,25);
    botonConfirmarContrasenia(27,30);
    botonEditar(95,30);


    botonCargaDatos(44,10);
    botonCargaDatos(44,15);
    botonCargaDatos(44,20);
    botonCargaDatos(44,25);
    botonCargaDatos(44,30);



}

char menuRegitro(char tecla)
{
    frontMenuRegistro();
    int flag;
    stUsuario usuario;
    char passTemporal[30];

    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();

            if(tecla == ESPACIO)
            {

                cuadradoAscii(85,11,89,33,32);
                selector(85,11);
                cargarDato(usuario.nombreApellido,48,11);
                aniBotonNombreApellidoUsuarioApretado(27,10);
                do
                {
                    limpiarArregloChar(usuario.nickUsuario);
                    cuadradoAscii(85,11,89,33,32); // BORRA EL SELECTOR
                    cuadradoAscii(48,16,89,17,32); // BORRA EL ANTERIOR TEXTO INGRESADO
                    selector(85,16);
                    cargarDato(usuario.nickUsuario,48,16);
                    aniBotonNombreUsuario(27,15);
                    flag = verificarNickUsuario(usuario.nickUsuario);
                    if(flag == 1)
                    {
                        gotoxy(45,19);
                        printf("%sprintf(%cTe copiaste de otro...%c);%s",ROJO,34,34,NORMAL);
                        Sleep(3000);
                        cuadradoAscii(45,19,78,20,32); // BORRA EL ANTERIOR TEXTO INGRESADO
                    }
                }
                while(flag != 0);

                do
                {
                    limpiarArregloChar(usuario.email);
                    cuadradoAscii(85,11,89,33,32); // BORRA EL SELECTOR
                    cuadradoAscii(48,21,78,22,32); // BORRA EL ANTERIOR TEXTO INGRESADO
                    selector(85,21);
                    cargarDato(usuario.email,48,21);
                    aniBotonEmail(27,20);
                    flag = verificarEmail(usuario.email);
                    if(flag == 1)
                    {
                        gotoxy(45,24);
                        printf("%sprintf(%cTe copiaste de otro...%c);%s",ROJO,34,34,NORMAL);
                        Sleep(3000);
                        cuadradoAscii(45,24,78,25,32); // BORRA EL ANTERIOR TEXTO INGRESADO
                    }
                }
                while(flag != 0);

                cuadradoAscii(85,11,89,33,32);
                selector(85,26);
                cargarDatoPass(usuario.contrasenia,48,26);
                aniBotonPass(27,25);


                cuadradoAscii(85,11,89,33,32);
                selector(85,31);
                cargarDatoPass(passTemporal,48,31);
                aniBotonConfirmaContrasenia(27,30);

                usuario.habilitado = true;
                nombreArchivoPersonajes(&usuario);

                while(strcmpi(passTemporal,usuario.contrasenia) != 0)
                {
                    limpiarArregloChar(passTemporal);
                    gotoxy(15,37);
                    printf("%sprintf(%cAcabas de escribir la Contrasenia, se ve que te la olvidaste, Vuelve a Intentar...%c);%s",ROJO,34,34,NORMAL);
                    Sleep(2000);
                    selector(85,31);
                    dibujarLinea(2,37,115,32);
                    cuadradoAscii(85,11,89,33,32);
                    cargarDatoPass(passTemporal,48,31);
                    aniBotonConfirmaContrasenia(27,30);
                }
            }
            if(tecla == E)
            {
                aniBotonEditar(95,30);
                editarIngreso(&usuario);
                while(strcmpi(passTemporal,usuario.contrasenia) != 0)
                {
                    limpiarArregloChar(passTemporal);
                    gotoxy(15,37);
                    printf("%sprintf(%cAcabas de escribir la Contrasenia, se ve que te la olvidaste, Vuelve a Intentar...%c);%s",ROJO,34,34,NORMAL);
                    Sleep(2000);
                    selector(85,31);
                    dibujarLinea(2,37,115,32);
                    cuadradoAscii(85,11,89,33,32);
                    cargarDatoPass(passTemporal,48,31);
                    aniBotonConfirmaContrasenia(27,30);
                }
            }
            if(tecla == ENTER)
            {
                aniBotonEnter(95,10);
                usuario.id = asignarIdUsuario();
                agregarAlArchivoUsuarios(usuario,"lista_usuarios.bin");
                tecla = menuUsuario(usuario,0);
            }

            if(tecla == SALIR)
            {
                aniBotonSalir(2,1);
                tecla = menuInicioSesionSecundario(0);
            }
        }
    }
    return tecla;
}

void frontMenuComandoAdmin()
{
    system("cls");
    dibujarCuadro(0,0,119,39,CYAN); // principal
    dibujarCuadro(2,7,40,36,NORMAL); // seleccion
    dibujarCuadro(42,2,117,37,NORMAL); // todos datos usuario
    dibujarCuadro(44,4,85,35,MARRON); // solo datos usuario
    dibujarCuadro(87,4,115,35,MARRON); // datos personaje
    botonDatosUsuario(54,1);
    botonPersonajesAdmin(87,1);
    marcosUsuarios();

    botonCargaDatos(47,5);
    gotoxy(48,5);printf("%sNombre Apellido:%s",NORMALSUB,NORMAL);
    botonCargaDatos(47,9);
    gotoxy(48,9);printf("%sNick:%s",NORMALSUB,NORMAL);
    botonCargaDatos(47,13);
    gotoxy(48,13);printf("%sEmail:%s",NORMALSUB,NORMAL);
    botonCargaDatos(47,17);
    gotoxy(48,17);printf("%sContrase%ca:%s",NORMALSUB,164,NORMAL);
    gotoxy(48,22);printf("%sHabilitado:%s",NORMALSUB,NORMAL);
    gotoxy(70,22);printf("%sPersonajes:%s",NORMALSUB,NORMAL);
    botonVacio(48,23);
    botonVacio(70,23);

    botonVacio(91,7);
    gotoxy(92,7);printf("%sVida:%s",NORMALSUB,NORMAL);

    botonVacio(103,7);
    gotoxy(104,7);printf("%sDa%co:%s",NORMALSUB,164,NORMAL);

    botonVacio(91,12);
    gotoxy(92,12);printf("%sArmadur%sa:",NORMALSUB,NORMAL);

    botonVacio(103,12);
    gotoxy(104,12);printf("%sLlaves:%s",NORMALSUB,NORMAL);

    botonVacio(98,17);
    gotoxy(99,17);printf("%sFAV:%s",NORMALSUB,NORMAL);

    botonEditarPjUsuario(94,26);
    botonBorrarPersonaje(94,30);
    flechaRight(104,21);
    flechaLeft(89,21);

    botonEditarUsuario(49,30);
    botonCambioEstado(71,30);
    botonSalir(2,1);
    flechaUp(18,1);
    flechaDown(30,1);

}

char menuComandoAdmin(char tecla, stUsuario admin)
{
    int posFinal = 0;
    int posInicial = 0;

    int flagMov = 0;
    int flagEdit = 0;
    int flagSave = 0;
    int preguntar = 0;

    //INICIO LISTA DE USUARIOS
    nodoUsuario * listaUsuarios;
    listaUsuarios = inicListaUsuarios();

    //MUESTRA FRONT
    system("cls");
    frontMenuComandoAdmin();

    //PASA DESDE EL ARCHIVO A LA LISTA
    listaUsuarios = deListaArchivo(listaUsuarios);
    //CUENTA LA CANTIDAD DE USUARIOS
    int cantidadElementos = contarElementos(listaUsuarios);
    //CREA UN ARREGLO DINAMICO PARA PODER SERVIR DE SELECTOR
    stUsuario * arreglo = malloc(sizeof(stUsuario)*cantidadElementos);
    //PASAMOS LA ULTIMA POSICION QUE TIENE SE COMIO DE LA LISTA AL ARREGO
    posFinal = pasarListaArreglo(listaUsuarios,arreglo,cantidadElementos,posInicial);
    //INICIAMOS EL SELECTOR QUE NOS VA A SERVIR PARA VISUALIZAR EL USUARIO DONDE ESTAMOS POSICIONADOS
    int selectorUsuario = 1;
    //MUESTRA EL MARCO DEL SELECTOR EN LA PANTALLA DONDE ESTAMOS
    movimientoSelectorUsuario(selectorUsuario);
    // MUESTRAS EL USUARIO DONDE ESTAMOS POSICIONADOS
    muestraUsuarioArregloSelector(selectorUsuario-1,arreglo);
    // MUESTRA EL CONTENIDO DEL ARREGLO
    muestraArregloUsuarios(arreglo,cantidadElementos,5,9,posInicial,posFinal);
    //VALOR QUE NOS SIRVE COMO BANDERA LIMITE DEL SELECTOR
    int valor = 2;

    //INICIO LISTA DE PERSONAJES x USUARIO
    nodoDoblePj * listaPj;
    listaPj = inicNodoDoblePj();

    //CREAMOS UN SELECTOR PARA SABER DONDE ESTAMOS PARADOS
    stPj selectorPj;

    //PASO TODOS LOS DATOS A LA LISTA SI ESTA TIENE ALGO CARGADO
    listaPj = pasarListaPersonajesArchivo(arreglo[selectorUsuario-1].nombreArchivoPersonajes,listaPj);

    //VARIABLE PARA CONTRA CANT PJS
    int cantidadPersonajes;

    //CUENTO LA CANTIDAD DE PERSONAjES EN LA LISTA
    cantidadPersonajes = verificarCantPersonajes(listaPj);

    //SI ES 0 IMPRIME UN CARTEL SINO MUESTRA LOS DATOS
    if(cantidadPersonajes == 0)
    {
        //SI EL USUARIO NO TIENE PERSONAJES IMPRIME ESTE CARTEL
        cartelNoJugadores(95,3);
    }
    else
    {
        //ITERADOR ENTRE LOS ELEMENTOS DE LA LISTA
        selectorPj = listaPj->personaje;
        //MUESTRAPERSONAJE
        muestraPersonajesMenuAdmin(selectorPj);
        flagMov = 1;
        flagEdit = 1;
    }

    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();

            if(tecla == ABAJO)
            {
                if(valor < cantidadElementos)
                {
                    //SE VUELBE A DECLARAR 0 PARA QUE LA LISTA NUEVA QUE SE VA A CARGAR SI ESTA VACIA NO SE MUEVA
                    flagMov = 0;
                    //BORRO LOS DATOS ANTERIORES MOSTRADOS
                    borrarDatosPersonajesMenuAdmin();

                    if(selectorUsuario < 10 && valor < cantidadElementos)
                    {
                        aniBotonDown(30,1);
                        selectorUsuario++;
                        valor++;
                    }

                    if(selectorUsuario == 10)
                    {
                        borrarMuestraUsuarios();
                        marcosUsuarios();
                        selectorUsuario = 1;
                        posInicial = posFinal;
                        posFinal = pasarListaArreglo(listaUsuarios,arreglo,cantidadElementos,posInicial);
                        valor--;
                    }

                    //BORRO TODOS LOS ELEMENTOS QUE TIENE LA LISTA PARA MOSTRAR LOS NUEVOS
                    borrarTodaLaLista(&listaPj);

                    //VOLVEMOS A CARGAR LA LISTA CON ELEMENTOS
                    listaPj = pasarListaPersonajesArchivo(arreglo[selectorUsuario-1].nombreArchivoPersonajes,listaPj);

                    //VOLVEMOS A CONTAR NUEVAMENTE LA CANTIDAD DE ELEMENTOS DE LA LISTA
                    cantidadPersonajes = verificarCantPersonajes(listaPj);

                    //SI ES 0 IMPRIME UN CARTEL SINO MUESTRA LOS DATOS
                    if(cantidadPersonajes > 0)
                    {
                        botonPersonajesAdmin(87,1);
                        //ITERADOR ENTRE LOS ELEMENTOS DE LA LISTA
                        selectorPj = listaPj->personaje;
                        //MUESTRAPERSONAJE
                        muestraPersonajesMenuAdmin(selectorPj);
                        flagMov = 1;
                        flagEdit = 1;
                    }
                    else
                    {
                        cartelNoJugadores(95,3);
                        flagMov = 0;
                        flagEdit = 0;
                    }


                    //MUESTRA USUARIO
                    movimientoSelectorUsuario(selectorUsuario);
                    muestraUsuarioArregloSelector(selectorUsuario-1,arreglo);
                    muestraArregloUsuarios(arreglo,cantidadElementos,5,9,posInicial,posFinal);

                }
            }

            if(tecla == ARRIBA)
            {
                if(valor > 1)
                {
                    //SE VUELBE A DECLARAR 0 PARA QUE LA LISTA NUEVA QUE SE VA A CARGAR SI ESTA VACIA NO SE MUEVA
                    flagMov = 0;
                    //BORRO LOS DATOS ANTERIORES MOSTRADOS
                    borrarDatosPersonajesMenuAdmin();
                    if(selectorUsuario > 0 && valor > 1)
                    {
                        aniBotonUp(18,1);
                        selectorUsuario--;
                        valor--;
                    }
                    if(selectorUsuario == 0)
                    {
                        borrarMuestraUsuarios();
                        marcosUsuarios();
                        selectorUsuario = 1;
                        posInicial -= 9;
                        if(posInicial <0)
                        {
                            posInicial = 0;
                        }
                        valor = (posInicial + 2);
                        posFinal = pasarListaArreglo(listaUsuarios,arreglo,cantidadElementos,posInicial);
                    }

                    //BORRO TODOS LOS ELEMENTOS QUE TIENE LA LISTA PARA MOSTRAR LOS NUEVOS
                    borrarTodaLaLista(&listaPj);

                    //VOLVEMOS A CARGAR LA LISTA CON ELEMENTOS
                    listaPj = pasarListaPersonajesArchivo(arreglo[selectorUsuario-1].nombreArchivoPersonajes,listaPj);

                    //VOLVEMOS A CONTAR NUEVAMENTE LA CANTIDAD DE ELEMENTOS DE LA LISTA
                    cantidadPersonajes = verificarCantPersonajes(listaPj);

                    //SI ES 0 IMPRIME UN CARTEL SINO MUESTRA LOS DATOS
                    if(cantidadPersonajes != 0)
                    {
                        botonPersonajesAdmin(87,1);
                        //ITERADOR ENTRE LOS ELEMENTOS DE LA LISTA
                        selectorPj = listaPj->personaje;
                        //MUESTRAPERSONAJE
                        muestraPersonajesMenuAdmin(selectorPj);
                        flagMov = 1;
                        flagEdit = 1;
                    }
                    else
                    {
                        cartelNoJugadores(95,3);
                        flagMov = 0;
                        flagEdit = 0;
                    }

                    movimientoSelectorUsuario(selectorUsuario);
                    muestraUsuarioArregloSelector(selectorUsuario-1,arreglo);
                    muestraArregloUsuarios(arreglo,cantidadElementos,5,9,posInicial,posFinal);
                }

            }

            if(tecla == ENTER)
            {
                aniBotonEditarUsuario(49,30);

                //BOORA EL USUARIO DE LA LISTA DONDE ESTA POSICIONADO EL SELECTOR
                listaUsuarios = borrarNodoBuscado(arreglo[selectorUsuario-1],listaUsuarios);


                //EDITA LA COPIA EN EL ARREGLO Y LO GUARDA EN UN USUARIO TEMPORAL
                stUsuario temporal = editarUsuarioAdministrador(arreglo[selectorUsuario-1]);

                //AGREGA EL USUARIO TEMPORAL MODIFICADO A LA LISTA
                listaUsuarios = agregarEnOrden(listaUsuarios,crearUsuario(temporal));

                if(cantidadPersonajes != 0)
                {
                    copiaDatosArchivoPersonajesNuevo(temporal.nombreArchivoPersonajes,arreglo[selectorUsuario-1].nombreArchivoPersonajes);
                }

                borrarTodaLaLista(&listaPj);

                selectorUsuario = 1;
                valor = 1;
                posInicial = 0;
                posFinal = 0;
                posFinal = pasarListaArreglo(listaUsuarios,arreglo,cantidadElementos,posInicial);

                listaPj = pasarListaPersonajesArchivo(arreglo[selectorUsuario-1].nombreArchivoPersonajes,listaPj);

                system("cls");
                frontMenuComandoAdmin();
                selectorPj = listaPj->personaje;
                muestraPersonajesMenuAdmin(selectorPj);
                movimientoSelectorUsuario(selectorUsuario);
                muestraUsuarioArregloSelector(selectorUsuario-1,arreglo);
                muestraArregloUsuarios(arreglo,cantidadElementos,5,9,posInicial,posFinal);

                //CUENTO LA CANTIDAD DE PERSONAjES EN LA LISTA
                cantidadPersonajes = verificarCantPersonajes(listaPj);

                //SI ES 0 IMPRIME UN CARTEL SINO MUESTRA LOS DATOS
                if(cantidadPersonajes == 0)
                {
                    //SI EL USUARIO NO TIENE PERSONAJES IMPRIME ESTE CARTEL
                    cartelNoJugadores(95,3);
                }
                else
                {
                    //ITERADOR ENTRE LOS ELEMENTOS DE LA LISTA
                    selectorPj = listaPj->personaje;
                    //MUESTRAPERSONAJE
                    muestraPersonajesMenuAdmin(selectorPj);
                    flagMov = 1;
                    flagEdit = 1;
                }
            }

            if(tecla == C)
            {
                aniBotonCambioEstado(71,30);

                listaUsuarios = cambioEstado(listaUsuarios,arreglo[selectorUsuario-1]);

                selectorUsuario = 1;
                valor = 1;

                posInicial = 0;
                posFinal = 0;

                posFinal = pasarListaArreglo(listaUsuarios,arreglo,cantidadElementos,posInicial);

                system("cls");
                frontMenuComandoAdmin();
                movimientoSelectorUsuario(selectorUsuario);
                muestraUsuarioArregloSelector(selectorUsuario-1,arreglo);
                muestraArregloUsuarios(arreglo,cantidadElementos,5,9,posInicial,posFinal);

            }

            if(tecla == DERECHA)
            {
                aniBotonRight(104,21);
                if(flagMov == 1 )
                {
                    if(listaPj->siguientePj == NULL)
                    {
                        listaPj = listaPj;
                    }
                    else
                    {
                        listaPj = listaPj->siguientePj;
                        selectorPj = listaPj->personaje;
                        muestraPersonajesMenuAdmin(selectorPj);
                    }
                }

            }

            if(tecla == IZQUIERDA)
            {
                aniBotonLeft(89,21);

                if(flagMov == 1 )
                {
                    if(listaPj->anteriorPj == NULL)
                    {
                        listaPj = listaPj;
                    }
                    else
                    {
                        listaPj = listaPj->anteriorPj;
                        selectorPj = listaPj->personaje;
                        muestraPersonajesMenuAdmin(selectorPj);
                    }
                }
            }

            if(tecla == UNO)
            {
                aniBotonEditarPjUsuario(94,26);
                //VERIFICAMOS ACCION
                if(flagEdit == 1)
                {
                    preguntar = confirmarAccion(33,15);
                    muestraPersonajesMenuAdmin(selectorPj);
                    frontMenuComandoAdmin();
                    movimientoSelectorUsuario(selectorUsuario);
                    muestraUsuarioArregloSelector(selectorUsuario-1,arreglo);
                    muestraArregloUsuarios(arreglo,cantidadElementos,5,9,posInicial,posFinal);

                    //VERIFICO SI ESTA HABILITADO PARA EDITAR
                    if(preguntar == 1)
                    {
                        //HABILITAMOS PARA GUARDAR
                        flagSave = 1;

                        //REMPLAZAMOS LOS DATOS DE LA POSICION EN LA LISTA
                        editarPersonajeMenuAdministrador(&listaPj->personaje);

                        if(flagSave == 1)
                        {
                            colocarAlPrincipioLista(&listaPj);
                            guardadoPersonajes(arreglo[selectorUsuario-1].nombreArchivoPersonajes,listaPj);
                        }

                        muestraPersonajesMenuAdmin(listaPj->personaje);
                    }
                }


            }

            if(tecla == DOS)
            {
                aniBotonBorrar(94,30);
                if(flagEdit == 1)
                {
                    //VERIFICAMOS ACCION
                    preguntar = confirmarAccion(33,15);
                    muestraPersonajesMenuAdmin(selectorPj);
                    frontMenuComandoAdmin();
                    movimientoSelectorUsuario(selectorUsuario);
                    muestraUsuarioArregloSelector(selectorUsuario-1,arreglo);
                    muestraArregloUsuarios(arreglo,cantidadElementos,5,9,posInicial,posFinal);

                    if(preguntar == 1)
                    {
                        //SI TENEMOS UNO
                        if(cantidadPersonajes == 1)
                        {
                            //BORRAMOS ARCHIVO
                            char ruta [80] = "listaPersonajesUsuarios\\";
                            borrarArchivoFisico(arreglo[selectorUsuario-1].nombreArchivoPersonajes);
                            borrarDatosPersonajesMenuAdmin();
                            cartelNoJugadores(95,3);
                            cantidadPersonajes = verificarCantPersonajes(listaPj);
                            gotoxy(74,24);printf("   ");
                            gotoxy(74,24);printf("%s%d%s",APERTURA,cantidadPersonajes,CERRADO);

                        }
                        else
                        {
                            //SINO BORRAMOS EL NODO
                            colocarAlPrincipioLista(&listaPj);
                            listaPj = borrarNodo(listaPj,selectorPj.id);
                            //SOBREESCRIBIMOS EL ARCHIVO CON LOS NUEVOS DATOS
                            guardadoPersonajes(arreglo[selectorUsuario-1].nombreArchivoPersonajes,listaPj);
                            //MOSTRAMOS
                            selectorPj = listaPj->personaje;
                            muestraPersonajesMenuAdmin(selectorPj);
                            cantidadPersonajes = verificarCantPersonajes(listaPj);
                            gotoxy(74,24);printf("   ");
                            gotoxy(74,24);printf("%s%d%s",APERTURA,cantidadPersonajes,CERRADO);
                        }
                    }
                }

            }

            if(tecla == SALIR)
            {
                pasarListaArchivo(listaUsuarios);
                aniBotonSalir(2,1);
                tecla = menuAdministradorSecundario(0);
            }

        gotoxy(74,24);printf("   ");
        gotoxy(74,24);printf("%s%d%s",APERTURA,cantidadPersonajes,CERRADO);
        }
    }
    return tecla;
}

void frontMenuUsuario()
{
    system("cls");
               ///DATOS USUARIO ///
            dibujarCuadro(0,0,119,39,CYAN); /// ------> Borde Cyan?
            dibujarCuadro(2,7,48,37,NORMAL);
            dibujarCuadro(51,2,117,36,NORMAL);
            tituloMenuUsuario(14,1);
            botonSalir(2,1);
            botonComenzarJuego(82,34);

            dibujarCuadro(4,10,46,35,MARRON);
            botonDatosUsuario(14,8);
            botonCargaDatos(7,12);
            botonCargaDatos(7,16);
            botonCargaDatos(7,20);
            botonCargaDatos(7,24);
            botonEditar (6,30);
            botonVerPass(20,30);
            gotoxy(33,34);
            printf("%sDAR DE BAJA%s",ROJO,NORMAL);
            botonCambioEstado(33,30);

        ///DATOS PERSONAJE////
        flechaLeft(56,8);
        flechaRight(103,8);

        dibujarCuadro(53,4,115,19,MARRON);
        botonPersonajesUsuario(69,1);
        pintarPersonajeParado(79,7);


//      //BOTONES DE STATS //
        botonVida(54,20);
        botonDanio(69,20);
        botonDefensa(85,20);
        botonLlaves(102,20);
            //hp//
        botonVacio(54,24);
        //danio
        botonVacio(69,24);
       //defensa
        botonVacio(85,24);
        //llaves
        botonVacio(102,24);
        // id
        botonVacio(57,3);

        botonEditarPjUsuario(54,29);
        botonBorrarPersonaje(76,29);
        botonFavoritoPj(99,29);
        botonCrearPersonaje(59,34);
        cuadradoFav(56,15);
}

char menuUsuario(stUsuario usuario,char tecla)
{
    int flagVerPas = 0;
    int flagFav = 0;
    int flagSave = 0;
    int flagMov = 0;

    int preguntar;
    stUsuario temporal;
    stPj selector;

    frontMenuUsuario();
    //CREO LA LISTA
    nodoDoblePj * listaPersonajes;
    listaPersonajes = inicNodoDoblePj();

    //PASO TODOS LOS DATOS A LA LISTA SI ESTA TIENE ALGO CARGADO
    listaPersonajes = pasarListaPersonajesArchivo(usuario.nombreArchivoPersonajes,listaPersonajes);

    //IMPRIMO LOS DATOS DEL USUARIO
    muestraUsuarioMenu(usuario);

    //CUENTO LA CANTIDAD DE PERSONAjES EN LA LISTA
    int cantidadPersonajes;
    cantidadPersonajes = verificarCantPersonajes(listaPersonajes);

    nodoDoblePj * iterador = listaPersonajes;

    if(cantidadPersonajes == 0)
    {
        //SI EL USUARIO NO TIENE PERSONAJES IMPRIME ESTE CARTEL
        cartelNoJugadores(78,10);
    }
    else
    {
        //ITERADOR ENTRE LOS ELEMENTOS DE LA LISTA
        selector = listaPersonajes->personaje;
        //MUESTRAPERSONAJE
        muestraUnPersonaje(selector);
        flagSave = 1;
        flagMov = 1;
    }

    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();


            if(tecla == ESPACIO)
            {
                aniBotonCrearPersonaje(59,34);

                if(cantidadPersonajes < 5)
                {
                    char nombrePersonaje[30];
                    gotoxy(72,3);printf("                      ");
                    cargarDato(nombrePersonaje,73,3);
                    // CREA UN NUEVO PERSONAJE Y CARGA DATOS
                    cantidadPersonajes = verificarCantPersonajes(listaPersonajes);

                    stPj personajeNuevo;

                    crearPj(&personajeNuevo,4,21,nombrePersonaje,cantidadPersonajes);

                    //CREA UN NODO NUEVO DEL PERSONAJE CREARDO
                    nodoDoblePj * nuevo = crearPersonajeNodo2(personajeNuevo);

                    //GUARDA AL NUEVO PERSONAJE EN LA LISTA PARA QUE FIGURE
                    listaPersonajes = agregarNodoDobleOrden(listaPersonajes,nuevo);

//                  //GUARDA AL PERSONAJE NUEVO AL ARCHIVO
                    pasarPersonajeListaArchivo(usuario.nombreArchivoPersonajes,nuevo);

                    flagSave = 1;
                    flagMov = 1;
                }

            }
            if(tecla == ENTER)
            {
                aniBotonComenzarJuego(82,34);
                if(flagSave == 1)
                {
                    cargarJuego(&selector,usuario.nombreArchivoPersonajes);

                    frontMenuUsuario();

                    muestraUsuarioMenu(usuario);

                    borrarTodaLaLista(&listaPersonajes);

                    listaPersonajes = pasarListaPersonajesArchivo(usuario.nombreArchivoPersonajes,listaPersonajes);

                    selector = listaPersonajes->personaje;

                    muestraUnPersonaje(selector);

                }

            }
            if(tecla == UNO)
            {
                aniBotonEditarPjUsuario(54,29);
                if(flagSave == 1)
                {
                    char nuevoNombre[30];
                    gotoxy(72,3);printf("                      ");
                    cargarDato(nuevoNombre,74,3);

                    limpiarArregloChar(listaPersonajes->personaje.nick);
                    strcpy(listaPersonajes->personaje.nick,nuevoNombre);
                }

            }
            if(tecla == DOS)
            {
                aniBotonBorrar(76,29);

                //ERROR CUANDO BORRAS EL ULTIMO NODOOO!!!!! PROBLEMAS
                if(flagSave == 1)
                {
                    preguntar = confirmarAccion(33,15);
                    frontMenuUsuario();
                    muestraUsuarioMenu(usuario);
                    cantidadPersonajes = verificarCantPersonajes(listaPersonajes);

                    if(preguntar == 1)
                    {
                        if(cantidadPersonajes == 1)
                        {
                            flagSave = 0;
                            flagMov = 0;
                            flagFav = 0;

                            borrarTodaLaLista(&listaPersonajes);
                            //SI LA CANTIDAD DE PERSONAJES ES IGUAL A 1 BORRAR EL ARCHIVO
                            borrarArchivoFisico(usuario.nombreArchivoPersonajes);
                            cartelNoJugadores(78,10);
                        }
                        else
                        {
                            colocarAlPrincipioLista(&listaPersonajes);
                            listaPersonajes = borrarNodo(listaPersonajes,selector.id);
                            selector = listaPersonajes->personaje;
                            muestraUnPersonaje(selector);
                        }
                    }
                }


            }
            if(tecla == TRES)
            {
                aniBotonAgregarFav(99,29);
                if(flagSave == 1)
                {
                    if(listaPersonajes->personaje.favorito == true)
                    {
                        listaPersonajes->personaje.favorito = false;
                    }
                    else
                    {
                        listaPersonajes->personaje.favorito = true;
                    }
                }

            }
            if(tecla == C)
            {
                aniBotonCambioEstado(33,30);
                preguntar = confirmarAccion(33,15);
                if(preguntar == 1)
                {
                    temporal = usuario;
                    cambiarEstadoUsuarioArchivo(temporal.id);
                    tecla = SALIR;
                }
                else
                {
                    frontMenuUsuario();
                    muestraUsuarioMenu(usuario);
                }
            }
            if(tecla == E)
            {
                aniBotonEditar(6,30);
                preguntar = confirmarAccion(33,15);
                if(preguntar == 1)
                {
                    temporal = usuario;
                    usuario = modificarUsuarioArchivo(usuario.id);

                    copiaDatosArchivoPersonajesNuevo(usuario.nombreArchivoPersonajes,temporal.nombreArchivoPersonajes);
                    tecla =SALIR;
                }
                frontMenuUsuario();
                muestraUsuarioMenu(usuario);
                muestraUnPersonaje(selector);
            }
            if(tecla == V)
            {
                flagVerPas = accionOcultarPas(flagVerPas,usuario.contrasenia);
            }
            if(tecla == DERECHA)
            {
                aniBotonRight(103,8);
                if(flagMov == 1 )
                {
                    if(listaPersonajes->siguientePj == NULL)
                    {
                        listaPersonajes = listaPersonajes;
                    }
                    else
                    {
                        listaPersonajes = listaPersonajes->siguientePj;
                        selector = listaPersonajes->personaje;
                        muestraUnPersonaje(selector);
                    }
                }
            }
            if(tecla == IZQUIERDA)
            {
                aniBotonLeft(56,8);

                if(flagMov == 1 )
                {
                    if(listaPersonajes->anteriorPj == NULL)
                    {
                        listaPersonajes = listaPersonajes;
                    }
                    else
                    {
                        listaPersonajes = listaPersonajes->anteriorPj;
                        selector = listaPersonajes->personaje;
                        muestraUnPersonaje(selector);
                    }
                }
            }
            cantidadPersonajes = verificarCantPersonajes(listaPersonajes);

            if(flagSave == 1)
            {
                selector = listaPersonajes->personaje;
                muestraUnPersonaje(selector);
                cuadradoAscii(70,10,100,12,32);
                pintarPersonajeParado(79,7);
            }
            else
            {
                cartelNoJugadores(78,10);
            }

            if(tecla == SALIR)
            {
                aniBotonSalir(2,1);
                if(flagSave == 1)
                {
                    colocarAlPrincipioLista(&listaPersonajes);
                    guardadoPersonajes(usuario.nombreArchivoPersonajes,listaPersonajes);
                }
                tecla = menuIngresarSecundario(0);
            }
        }
    }
    return tecla;
}







// FUNCIONES HERRAMIENTAS DE LOS MENUS

void cargarDato(char arreglo[],int x,int y)
{
    gotoxy(x,y);
    char tecla; // tecla apretada
    int i = 0; // iterador

    int posCursorX; // where devuelve la posicion de cursor en la consola en X
    int posCursorY = whereY(); // where devuelve la posicion de cursor en la consola en Y

    while((tecla = _getch()) != ENTER ) // Mientras la tecla obtenida sea diferente que enter segui.
    {

        posCursorX = whereX(); // donde esta ubicado el cuersor en X;

        if(tecla != CANCELAR && i < 30)
        {
            gotoxy(posCursorX,posCursorY); // el cursor se va posicionar en las posiciones anteriormente definidas
            arreglo[i] = tecla; // asigo la tecla obtenida al arreglo en la posicion del iterador
            printf("%c",tecla); // imprimo la tecla para verla
            i++; // iterador aumenta
        }
        else if(tecla == CANCELAR && i > 0) //si apreta la tecla la borrar texto
        {
            arreglo[i] = '\0';
            i--; // iterador se resta para que en el arreglo se pare en la posicon del borrado
            posCursorX--;
            gotoxy(posCursorX,posCursorY);
            printf(" "); //que se pare en la posicion -1 en x del cursor y imprime VACIO
            gotoxy(posCursorX,posCursorY); // que se posicione devuelta donde esta el borrado .
        }
    }
    arreglo[i] = '\0';
}

void cargarDatoPass(char arreglo[],int x,int y)
{
    gotoxy(x,y);
    char tecla; // tecla apretada
    int i = 0; // iterador

    int posCursorX; // where devuelve la posicion de cursor en la consola en X
    int posCursorY = whereY(); // where devuelve la posicion de cursor en la consola en Y

    while((tecla = _getch()) != ENTER ) // Mientras la tecla obtenida sea diferente que enter segui.
    {

        posCursorX = whereX(); // donde esta ubicado el cuersor en X;

        if(tecla != CANCELAR && posCursorX < 84 && i < 30)
        {
            gotoxy(posCursorX,posCursorY); // el cursor se va posicionar en las posiciones anteriormente definidas
            arreglo[i] = tecla; // asigo la tecla obtenida al arreglo en la posicion del iterador
            printf("%c",42); // imprimo la tecla para verla
            i++; // iterador aumenta
        }
        else if(tecla == CANCELAR && i > 0) //si apreta la tecla la borrar texto
        {
            arreglo[i] = '\0';
            i--; // iterador se resta para que en el arreglo se pare en la posicon del borrado
            posCursorX--;
            gotoxy(posCursorX,posCursorY);
            printf(" "); //que se pare en la posicion -1 en x del cursor y imprime VACIO
            gotoxy(posCursorX,posCursorY); // que se posicione devuelta donde esta el borrado .
        }
    }
    arreglo[i] = '\0';
}

void limpiarArregloChar(char arreglo[])
{
    for(int i = 0; i < 30; i++)
    {
        arreglo[i] = '\0';
    }
}

void imprimirSelector(int posicion)
{
    cuadradoAscii(85,11,89,33,32);
    if(posicion == 1)
    {
        selector(85,11);
    }
    if(posicion == 2)
    {
        selector(85,16);
    }
    if(posicion == 3)
    {
        selector(85,21);
    }
    if(posicion == 4)
    {
        selector(85,26);
    }

}

void selector(int x, int y)
{
    gotoxy(x,y);
    printf("%s%c%c%s%c%c%s ",ROJO,219,219,VERDE,219,219,NORMAL);
    gotoxy(x,y+1);
    printf("%s%c%c%s%c%c%s ",MARRON,219,219,AZUL,219,219,NORMAL);
}

void selectorUsuario(int x, int y,char color[])
{
    dibujarCuadro(x,y,x+36,y+3,color);
}

void movimientoSelectorUsuario(int posicion)
{
    switch(posicion)
    {
    case 1:
        marcosUsuarios();
        selectorUsuario(3,8,ROJO);
        break;
    case 2:
        marcosUsuarios();
        selectorUsuario(3,11,ROJO);
        break;
    case 3:
        marcosUsuarios();
        selectorUsuario(3,14,ROJO);
        break;
    case 4:
        marcosUsuarios();
        selectorUsuario(3,17,ROJO);
        break;
    case 5:
        marcosUsuarios();
        selectorUsuario(3,20,ROJO);
        break;
    case 6:
        marcosUsuarios();
        selectorUsuario(3,23,ROJO);
        break;
    case 7:
        marcosUsuarios();
        selectorUsuario(3,26,ROJO);
        break;
    case 8:
        marcosUsuarios();
        selectorUsuario(3,29,ROJO);
        break;
    case 9:
        marcosUsuarios();
        selectorUsuario(3,32,ROJO);
        break;

    }
}

void marcosUsuarios()
{
    selectorUsuario(3,8,MARRON);
    selectorUsuario(3,11,MARRON);
    selectorUsuario(3,14,MARRON);
    selectorUsuario(3,17,MARRON);
    selectorUsuario(3,20,MARRON);
    selectorUsuario(3,23,MARRON);
    selectorUsuario(3,26,MARRON);
    selectorUsuario(3,29,MARRON);
    selectorUsuario(3,32,MARRON);
}

void borrarMuestraUsuarios()
{
    cuadradoAscii(4,10,38,35,32);
}

void frontCreditos ()
{
    system("cls");
    dibujarCuadro(0,0,119,39,CYAN);
    dibujarCuadro(3,3,115,35,MARRON);
    BotonCreditos(50,1);
    gotoxy(44,8);printf(" printf(%cFue una Produccion de: %c);",34,34);
    nombreEquipo(34,10);
    dinamitaIZQ(24,8);
    dinamitaDER(74,8);
    //dibujarCuadro(10,25,109,33,NORMAL);
    gotoxy(13,25);printf(" printf(%cAgradecimiento especial a CODEBLOCKS por vivir rompiendose, ayudandonos a crear este ",34);
    gotoxy(13,26);printf("         juego inspirado en la vida de todos los estudiantes de programacion. %c);",34);
    gotoxy(13,28);printf(" printf(%cGracias al Cafe, las Monster, Y speed por ser nuestra agua bendita.%c);",34,34);
    gotoxy(13,30);printf(" printf(%cA Nico, German, Jorge,  Nazareno, Ian, y a aquellos que no recordamos porque ya nuestro",34);
    gotoxy(13,31);printf("          cerebro exploto tratando de terminar esto.%c);",34);

}

void dinamitaDER(int x, int y)
{
///Cartucho Derecha ///
//LLAMITA//
printf("%s",ROJO);dibujarCuadroAscii(x+20,y,x+20,y,177); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+18,y+1,x+20,y+1,177); printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+20,y+1,x+21,y+1,177); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+18,y+2,x+18,y+2,177); printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+19,y+3,x+19,y+3,177); printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+20,y+2,x+20,y+2,177); printf("%s",NORMAL);

//Cartucho
printf("%s",ROJO);dibujarCuadroAscii(x+17,y+4,x+19,y+4,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+16,y+5,x+18,y+5,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+15,y+6,x+17,y+6,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+14,y+7,x+16,y+7,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+13,y+8,x+15,y+8,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+12,y+9,x+14,y+9,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+11,y+10,x+13,y+10,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+10,y+11,x+12,y+11,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+9,y+12,x+11,y+12,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+8,y+13,x+10,y+13,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+7,y+14,x+9,y+14,219); printf("%s",NORMAL);
}

void dinamitaIZQ(int x,int y)
{
//LLAMITAS//
printf("%s",ROJO);dibujarCuadroAscii(x,y,x,y,177); printf("%s",NORMAL);

printf("%s",ROJO);dibujarCuadroAscii(x,y+1,x+2,y+1,177); printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+2,y+1,x+2,y+1,177); printf("%s",NORMAL);



printf("%s",ROJO);dibujarCuadroAscii(x,y+2,x,y+2,177); printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+1,y+3,x+1,y+3,177); printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+2,y+2,x+2,y+2,177); printf("%s",NORMAL);

//CARTUCHO izquierda ///

printf("%s",ROJO);dibujarCuadroAscii(x+3,y+4,x+5,y+4,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+4,y+5,x+6,y+5,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+5,y+6,x+7,y+6,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+6,y+7,x+8,y+7,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+7,y+8,x+9,y+8,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+8,y+9,x+10,y+9,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+9,y+10,x+11,y+10,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+10,y+11,x+12,y+11,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+11,y+12,x+13,y+12,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+12,y+13,x+14,y+13,219); printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+13,y+14,x+15,y+14,219); printf("%s",NORMAL);

}

void nombreEquipo(int x,int y)
{
    gotoxy(x,y);
    printf(" ______   ______   ______   ______   ______   ______ ");
    gotoxy(x,y+1);
    printf("| | D  | | | I  | | | N  | | | A  | | | M  | | | I  |");
    gotoxy(x,y+2);
    printf("| |    | | |    | | |    | | |    | | |    | | |    |");
    gotoxy(x,y+3);
    printf("| |____| | |____| | |____| | |____| | |____| | |____|");
    gotoxy(x,y+4);
    printf("|/_____/ |/_____/ |/_____/ |/_____/ |/_____/ |/_____/");
    gotoxy(x+9,y+6);
    printf(" ______   ______   ______   ______ ");
    gotoxy(x+9,y+7);
    printf("| | T  | | | E  | | | A  | | | M  |");
    gotoxy(x+9,y+8);
    printf("| |    | | |    | | |    | | |    |");
    gotoxy(x+9,y+9);
    printf("| |____| | |____| | |____| | |____|");
    gotoxy(x+9,y+10);
    printf("|/_____/ |/_____/ |/_____/ |/_____/");
}

void programa()
{
    system("cls");
    system("mode con: cols=120 lines=40");
    inicioMenu(0);
}




///PANTALLA victoria///




void PantallaVictoria ()
{

dibujarCuadro(0,0,119,39,CYAN);
Cama(35,5);
Copa(10,5);

Copa(93,5);
victoria(21, 10);
gotoxy(28,30);printf(" printf(%c ALELUYA! Lograste resolver los problemas de tu codigo",34);
gotoxy(28,31);printf("                     Ya podes ir a dormir%c);",34);

getch();

}

void Cama(int x,int y )
{

printf("%s",MARRON); dibujarCuadroAscii(x,y,x+1,y+12,219); printf("%s",NORMAL);
printf("%s",MARRON); dibujarCuadroAscii(x,y+9,x+45,y+10,219); printf("%s",NORMAL);
printf("%s",MARRON); dibujarCuadroAscii(x+46,y+5,x+47,y+12,219); printf("%s",NORMAL);
printf("%s",ROJO); dibujarCuadroAscii(x+13,y+7,x+45,y+8,219); printf("%s",NORMAL);
printf("%s",ROJO); dibujarCuadroAscii(x+13,y+8,x+45,y+8,219); printf("%s",NORMAL);
printf("%s",ROJO); dibujarCuadroAscii(x+2,y+7,x+12,y+8,219); printf("%s",NORMAL);
printf("%s",NORMAL); dibujarCuadroAscii(x+2,y+5,x+12,y+6,219); printf("%s",NORMAL);

}

void  victoria (int x, int y )
{
    ///v///
printf("%s",ROJO);dibujarCuadroAscii(x+8,y+8,x+8,y+12,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+9,y+8,x+9,y+13,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+10,y+14,x+11,y+14,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+12,y+8,x+12,y+13,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+13,y+8,x+13,y+12,219);printf("%s",NORMAL);


///i//
printf("%s",ROJO);dibujarCuadroAscii(x+16,y+8,x+16,y+14,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+17,y+8,x+17,y+14,219);printf("%s",NORMAL);

///c//
printf("%s",ROJO);dibujarCuadroAscii(x+20,y+8,x+25,y+8,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+20,y+8,x+21,y+14,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+20,y+14,x+25,y+14,219);printf("%s",NORMAL);

///t//
printf("%s",ROJO);dibujarCuadroAscii(x+28,y+8,x+35,y+8,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+31,y+8,x+32,y+14,219);printf("%s",NORMAL);

///o//
printf("%s",ROJO);dibujarCuadroAscii(x+39,y+8,x+41,y+8,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+39,y+14,x+41,y+14,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+38,y+9,x+38,y+13,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+42,y+9,x+42,y+13,219);printf("%s",NORMAL);
///r//
printf("%s",ROJO);dibujarCuadroAscii(x+45,y+8,x+45,y+14,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+46,y+8,x+46,y+14,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+46,y+8,x+50,y+8,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+46,y+11,x+50,y+11,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+51,y+9,x+51,y+10,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+52,y+9,x+52,y+10,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+51,y+12,x+51,y+12,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+52,y+13,x+52,y+13,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+52,y+13,x+52,y+13,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+53,y+14,x+53,y+14,219);printf("%s",NORMAL);

///i///
printf("%s",ROJO);dibujarCuadroAscii(x+56,y+8,x+56,y+14,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+57,y+8,x+57,y+14,219);printf("%s",NORMAL);


///a///

printf("%s",ROJO);dibujarCuadroAscii(x+63,y+8,x+67,y+8,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+61,y+8,x+62,y+14,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+67,y+8,x+68,y+14,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+67,y+8,x+68,y+14,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+63,y+12,x+68,y+12,219);printf("%s",NORMAL);

}

void Copa (int x, int y )
{

printf("%s",MARRON);dibujarCuadroAscii(x,y,x+15,y,219);printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+1,y+1,x+14,y+1,219);printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+2,y+2,x+13,y+2,219);printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+3,y+3,x+12,y+3,219);printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+4,y+4,x+11,y+4,219);printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+6,y+5,x+9,y+5,219);printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+6,y+5,x+7,y+8,219);printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+7,y+5,x+7,y+8,219);printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+8,y+5,x+8,y+8,219);printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+9,y+5,x+9,y+8,219);printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+5,y+9,x+10,y+9,219);printf("%s",NORMAL);
printf("%s",MARRON);dibujarCuadroAscii(x+2,y+9,x+13,y+9,219);printf("%s",NORMAL);

}























