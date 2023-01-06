#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include "botonesAnimaciones.h"
#include "gotoxy.h"

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

#define ESBIRRO 1
#define BOOS 2


//     FUNCIONES BOTONES

void muestraControles(int x,int y )
{
    gotoxy(x,y); printf(" ______      ______      ______");
    gotoxy(x,y+1); printf("| | J  |    | | K  |    | | L  |");
    gotoxy(x,y+2); printf("| |    |    | |    |    | |    |");
    gotoxy(x,y+3); printf("| |____|    | |____|    | |____|");
    gotoxy(x,y+4); printf("|/_____/    |/_____/    |/_____/");
}


void botonIngresar(int x, int y)
{
    gotoxy(x,y);
    printf(" ______________");
    gotoxy(x,y+1);
    printf("| |  Ingresar  |");
    gotoxy(x,y+2);
    printf("| |____________|");
    gotoxy(x,y+3);
    printf("|/____________/");
}

void botonIngresarApretado(int x, int y)
{
    gotoxy(x,y);
    printf(" ______________");
    gotoxy(x,y+1);
    printf("||  Ingresar  |");
    gotoxy(x,y+2);
    printf("||____________|");
    gotoxy(x,y+3);
    printf("|/____________/");
}

void botonRegistrarse(int x, int y)
{
    gotoxy(x,y);
    printf(" _______________");
    gotoxy(x,y+1);
    printf("| | Registrarse |");
    gotoxy(x,y+2);
    printf("| |_____________|");
    gotoxy(x,y+3);
    printf("|/_____________/");
}

void botonRegistrarseApretado(int x, int y)
{
    gotoxy(x,y);
    printf(" _______________");
    gotoxy(x,y+1);
    printf("|| Registrarse |");
    gotoxy(x,y+2);
    printf("||_____________|");
    gotoxy(x,y+3);
    printf("|/_____________/");
}

void botonEmail(int x, int y)
{
        gotoxy(x,y);
    printf(" ______________");
    gotoxy(x,y+1);
    printf("| |   Email:   |");
    gotoxy(x,y+2);
    printf("| |____________|");
    gotoxy(x,y+3);
    printf("|/____________/");
}

void botonEmailApretado(int x, int y)
{
        gotoxy(x,y);
    printf(" ______________");
    gotoxy(x,y+1);
    printf("||   Email:   |");
    gotoxy(x,y+2);
    printf("||____________|");
    gotoxy(x,y+3);
    printf("|/____________/");
}

void botonContrasenia(int x, int y)
{
    gotoxy(x,y); printf(" ______________");
    gotoxy(x,y+1); printf("| |   Pass:    |");
    gotoxy(x,y+2); printf("| |____________|");
    gotoxy(x,y+3); printf("|/____________/");
}

void botonContraseniaApretado(int x, int y)
{
    gotoxy(x,y); printf(" ______________");
    gotoxy(x,y+1); printf("||   Pass:    |");
    gotoxy(x,y+2); printf("||____________|");
    gotoxy(x,y+3); printf("|/____________/");
}

void botonCargaDatos(int x, int y)
{
    gotoxy(x,y); printf(" __________________________________");
    gotoxy(x,y+1); printf("| |                                |");
    gotoxy(x,y+2); printf("| |________________________________|");
    gotoxy(x,y+3); printf("|/________________________________/");
}

void botonEnter(int x,int y)
{
    gotoxy(x,y); printf(" ___________");
    gotoxy(x,y+1); printf("| |         |",179);
    gotoxy(x,y+2); printf("| |       %c |",179);
    gotoxy(x,y+3); printf("| |__   <%c%c |",196,217);
    gotoxy(x,y+4); printf("|/__/|      |");
    gotoxy(x,y+5); printf("   | |      |");
    gotoxy(x,y+6); printf("   | |      |");
    gotoxy(x,y+7); printf("   | |______|");
    gotoxy(x,y+8); printf("   |/______/");
}

void botonEnterApretado(int x,int y)
{
    gotoxy(x,y); printf(" ___________");
    gotoxy(x,y+1); printf("||         |",179);
    gotoxy(x,y+2); printf("||       %c |",179);
    gotoxy(x,y+3); printf("||__   <%c%c |",196,217);
    gotoxy(x,y+4); printf("|/_/|      |");
    gotoxy(x,y+5); printf("   ||      |");
    gotoxy(x,y+6); printf("   ||      |");
    gotoxy(x,y+7); printf("   ||______|");
    gotoxy(x,y+8); printf("   |/______/");
}

void nombreJuego(int x,int y)
{
    gotoxy(x,y);
    printf(" ______   ______   ______   ______   ______   ______ ");
    gotoxy(x,y+1);
    printf("| | B  | | | A  | | | T  | | | T  | | | L  | | | E  |");
    gotoxy(x,y+2);
    printf("| |    | | |    | | |    | | |    | | |    | | |    |");
    gotoxy(x,y+3);
    printf("| |____| | |____| | |____| | |____| | |____| | |____|");
    gotoxy(x,y+4);
    printf("|/_____/ |/_____/ |/_____/ |/_____/ |/_____/ |/_____/");
    gotoxy(x+9,y+6);
    printf(" ______   ______   ______   ______ ");
    gotoxy(x+9,y+7);
    printf("| | C  | | | O  | | | D  | | | E  |");
    gotoxy(x+9,y+8);
    printf("| |    | | |    | | |    | | |    |");
    gotoxy(x+9,y+9);
    printf("| |____| | |____| | |____| | |____|");
    gotoxy(x+9,y+10);
    printf("|/_____/ |/_____/ |/_____/ |/_____/");
}

void botonAceptar(int x, int y)
{
    gotoxy(x,y);
    printf(" __________________________");
    gotoxy(x,y+1);
    printf("| |          ENTER         |");
    gotoxy(x,y+2);
    printf("| |                        |");
    gotoxy(x,y+3);
    printf("| |________________________|");
    gotoxy(x,y+4);
    printf("|/________________________/");
}

void botonSalir(int x, int y)
{
    gotoxy(x,y);
    printf(" ________");
    gotoxy(x,y+1);
    printf("| |  ESC |");
    gotoxy(x,y+2);
    printf("| |      |");
    gotoxy(x,y+3);
    printf("| |______|");
    gotoxy(x,y+4);
    printf("|/______/");
}

void botonCreditos(int x, int y)
{
    gotoxy(x,y);
    printf(" ________");
    gotoxy(x,y+1);
    printf("| |  C   |");
    gotoxy(x,y+2);
    printf("| |      |");
    gotoxy(x,y+3);
    printf("| |______|");
    gotoxy(x,y+4);
    printf("|/______/");
}

void botonAceptarApretado(int x, int y)
{
    gotoxy(x,y);
    printf(" __________________________");
    gotoxy(x,y+1);
    printf("||          ENTER         |");
    gotoxy(x,y+2);
    printf("||                        |");
    gotoxy(x,y+3);
    printf("||________________________|");
    gotoxy(x,y+4);
    printf("|/________________________/");
}

void botonSalirApretado(int x, int y)
{
    gotoxy(x,y);printf(" ________");
    gotoxy(x,y+1);printf("||  ESC |");
    gotoxy(x,y+2);printf("||      |");
    gotoxy(x,y+3);printf("||______|");
    gotoxy(x,y+4);printf("|/______/");
}

void botonCreditosApretado(int x, int y)
{
    gotoxy(x,y);
    printf(" ________");
    gotoxy(x,y+1);
    printf("||  C   |");
    gotoxy(x,y+2);
    printf("||      |");
    gotoxy(x,y+3);
    printf("||______|");
    gotoxy(x,y+4);
    printf("|/______/");
}

void botonAdmin(int x, int y)
{
    gotoxy(x,y);
    printf(" ______________");
    gotoxy(x,y+1);
    printf("| | A : Admin |");
    gotoxy(x,y+2);
    printf("| |___________|");
    gotoxy(x,y+3);
    printf("|/___________/");
}

void botonAdminApretado(int x, int y)
{
    gotoxy(x,y);
    printf(" ______________");
    gotoxy(x,y+1);
    printf("|| A : Admin |");
    gotoxy(x,y+2);
    printf("||___________|");
    gotoxy(x,y+3);
    printf("|/___________/");
}

void flechaUp(int x, int y)
{
    gotoxy(x,y);printf(" _______");
    gotoxy(x,y+1);printf("| |  ^  |");
    gotoxy(x,y+2);printf("| |  |  |");
    gotoxy(x,y+3);printf("| |_____|");
    gotoxy(x,y+4);printf("|/_____/");

}

void flechaDown(int x, int y)
{
    gotoxy(x,y);printf(" _______");
    gotoxy(x,y+1);printf("| |  |  |");
    gotoxy(x,y+2);printf("| |  V  |");
    gotoxy(x,y+3);printf("| |_____|");
    gotoxy(x,y+4);printf("|/_____/");

}


void flechaUpApretado(int x, int y)
{
    gotoxy(x,y);printf(" _______");
    gotoxy(x,y+1);printf("||  ^  |");
    gotoxy(x,y+2);printf("||  |  |");
    gotoxy(x,y+3);printf("||_____|");
    gotoxy(x,y+4);printf("|/_____/");

}


void flechaDownApretado(int x, int y)
{
    gotoxy(x,y);printf(" _______");
    gotoxy(x,y+1);printf("||  |  |");
    gotoxy(x,y+2);printf("||  V  |");
    gotoxy(x,y+3);printf("||_____|");
    gotoxy(x,y+4);printf("|/_____/");

}

void flechaRight(int x,int y)
{
    gotoxy(x,y);printf(" ________");
    gotoxy(x,y+1);printf("| |      |");
    gotoxy(x,y+2);printf("| |  ->  |");
    gotoxy(x,y+3);printf("| |______|");
    gotoxy(x,y+4);printf("|/______/");
}

void flechaRightApretado(int x,int y)
{
    gotoxy(x,y);printf(" ________");
    gotoxy(x,y+1);printf("||      |");
    gotoxy(x,y+2);printf("||  ->  |");
    gotoxy(x,y+3);printf("||______|");
    gotoxy(x,y+4);printf("|/______/");
}


void flechaLeft(int x,int y)
{
    gotoxy(x,y);printf(" ________");
    gotoxy(x,y+1);printf("| |      |");
    gotoxy(x,y+2);printf("| |  <-  |");
    gotoxy(x,y+3);printf("| |______|");
    gotoxy(x,y+4);printf("|/______/");
}


void flechaLeftApretado(int x,int y)
{
    gotoxy(x,y);printf(" ________");
    gotoxy(x,y+1);printf("||      |");
    gotoxy(x,y+2);printf("||  <-  |");
    gotoxy(x,y+3);printf("||______|");
    gotoxy(x,y+4);printf("|/______/");
}

void botonEditarPersonaje(int x,int y)
{
    gotoxy(x,y);printf(" ________________________");
    gotoxy(x,y+1);printf("| |  Editar Personaje:   |");
    gotoxy(x,y+2);printf("| |______________________|");
    gotoxy(x,y+3);printf("|/______________________/");
}

void botonEditarUsuario(int x,int y)
{
    gotoxy(x,y);printf(" ___________________");
    gotoxy(x,y+1);printf("| | Editar Usuario: |");
    gotoxy(x,y+2);printf("| |_________________|");
    gotoxy(x,y+3);printf("|/_________________/");
}


void botonEditarUsuarioApretado(int x,int y)
{
    gotoxy(x,y);printf(" ___________________");
    gotoxy(x,y+1);printf("|| Editar Usuario: |");
    gotoxy(x,y+2);printf("||_________________|");
    gotoxy(x,y+3);printf("|/_________________/");
}

void botonCambioEstado(int x,int y)
{
    gotoxy(x,y);printf(" __________");
    gotoxy(x,y+1);printf("| | Cambio |");
    gotoxy(x,y+2);printf("| |_%sEstado%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/_________/");
}

void botonCambioEstadoApretado(int x,int y)
{
    gotoxy(x,y);printf(" __________");
    gotoxy(x,y+1);printf("|| Cambio |");
    gotoxy(x,y+2);printf("||_%sEstado%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/_________/");
}

void tituloAdmins(int x,int y)
{
    gotoxy(x+9,y);   printf(" ______   ______   ______   ______ ");
    gotoxy(x+9,y+1); printf("| | S  | | | O  | | | L  | | | O  |");
    gotoxy(x+9,y+2); printf("| |    | | |    | | |    | | |    |");
    gotoxy(x+9,y+3); printf("| |____| | |____| | |____| | |____|");
    gotoxy(x+9,y+4);printf("|/____/  |/____/  |/____/  |/____/");
    gotoxy(x,y+5);    printf(" ______   ______   ______   ______   ______   ______ ");
    gotoxy(x,y+6);  printf("| | A  | | | D  | | | M  | | | I  | | | N  | | | S  |");
    gotoxy(x,y+7);  printf("| |    | | |    | | |    | | |    | | |    | | |    |");
    gotoxy(x,y+8);  printf("| |____| | |____| | |____| | |____| | |____| | |____|");
    gotoxy(x,y+9);  printf("|/____/  |/____/  |/____/  |/____/  |/____/  |/____/");
}

void botonCodigo(int x, int y)
{
    gotoxy(x,y);printf(" ____________");
    gotoxy(x,y+1);printf("| | Codigo   |");
    gotoxy(x,y+2);printf("| |_%sSecreto:%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/___________/");
}


void botonCodigoApretado(int x, int y)
{
    gotoxy(x,y);printf(" ____________");
    gotoxy(x,y+1);printf("|| Codigo   |");
    gotoxy(x,y+2);printf("||_%sSecreto:%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/___________/");
}


void botonEditar(int x ,int y)
{
    gotoxy(x,y);printf(" ___________");
    gotoxy(x,y+1);printf("| | E       |");
    gotoxy(x,y+2);printf("| |_%sEditar:%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/_________/");
}

void botonEditarApretado(int x ,int y)
{
    gotoxy(x,y);printf(" ___________");
    gotoxy(x,y+1);printf("|| E       |");
    gotoxy(x,y+2);printf("||_%sEditar:%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/_________/");
}

void botonConfirmarContrasenia(int x ,int y)
{
    gotoxy(x,y);printf(" _____________");
    gotoxy(x,y+1);printf("| | Confirmar |");
    gotoxy(x,y+2);printf("| |_%sPass :%s____|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/___________/");
}

void botonConfirmarContraseniaApretado(int x ,int y)
{
    gotoxy(x,y);printf(" _____________");
    gotoxy(x,y+1);printf("|| Confirmar |");
    gotoxy(x,y+2);printf("||_%sPass :%s____|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/___________/");
}

void botonNombreApellidoUsuario(int x ,int y)
{
    gotoxy(x,y);printf(" ______________");
    gotoxy(x,y+1);printf("| |  Nombre    |");
    gotoxy(x,y+2);printf("| |__%sApellido:%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/____________/");
}

void botonNombreApellidoUsuarioApretado(int x ,int y)
{
    gotoxy(x,y);printf(" ______________");
    gotoxy(x,y+1);printf("||  Nombre    |");
    gotoxy(x,y+2);printf("||__%sApellido:%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/____________/");
}

void botonNombreUsuario(int x ,int y)
{
    gotoxy(x,y);printf(" ______________");
    gotoxy(x,y+1);printf("| |  Usuario:  |");
    gotoxy(x,y+2);printf("| |____________|");
    gotoxy(x,y+3);printf("|/____________/");
}

void botonNombreUsuarioApretado(int x ,int y)
{
    gotoxy(x,y);printf(" ______________");
    gotoxy(x,y+1);printf("||  Usuario:  |");
    gotoxy(x,y+2);printf("||____________|");
    gotoxy(x,y+3);printf("|/____________/");
}

void tituloMenu(int x,int y)
{
    gotoxy(x,y);printf(" _____________________________________");
    gotoxy(x,y+1);printf("| |        Registrar Usuario          |");
    gotoxy(x,y+2);printf("| |                                   |");
    gotoxy(x,y+3);printf("| |___________________________________|");
    gotoxy(x,y+4);printf("|/___________________________________/");
}

void botonVacio(int x ,int y)
{
    gotoxy(x,y);printf(" _______");
    gotoxy(x,y+1);printf("| |     |");
    gotoxy(x,y+2);printf("| |_____|");
    gotoxy(x,y+3);printf("|/_____/");
}


void tituloMenuUsuario(int x,int y)
{
    gotoxy(x,y);printf(" _______________________________");
    gotoxy(x,y+1);printf("| |      Bienvenido Usuario     |");
    gotoxy(x,y+2);printf("| |                             |");
    gotoxy(x,y+3);printf("| |_____________________________|");
    gotoxy(x,y+4);printf("|/_____________________________/");
}

void botonPersonajesUsuario(int x,int y)
{
    gotoxy(x,y);printf(" _____________________________");
    gotoxy(x,y+1);printf("| |      Tus Personajes       |");
    gotoxy(x,y+2);printf("| |                           |");
    gotoxy(x,y+3);printf("| |___________________________|");
    gotoxy(x,y+4);printf("|/___________________________/");
}

void botonDatosUsuario(int x,int y)
{
    gotoxy(x,y);printf(" ____________________");
    gotoxy(x,y+1);printf("| | Datos Personales |");
    gotoxy(x,y+2);printf("| |__________________|");
    gotoxy(x,y+3);printf("|/__________________/");
}


void botonComenzarJuego(int x,int y)
{
    gotoxy(x,y);printf(" __________________________");
    gotoxy(x,y+1);printf("| |     Comenzar Juego     |");
    gotoxy(x,y+2);printf("| |__________%sENTER%s_________|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/________________________/");
}

void botonComenzarJuegoApretado(int x,int y)
{
    gotoxy(x,y);printf(" __________________________");
    gotoxy(x,y+1);printf("||     Comenzar Juego     |");
    gotoxy(x,y+2);printf("||__________%sENTER%s_________|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/________________________/");
}

void botonVida(int x, int y)
{
    gotoxy(x,y); printf(" _________");
    gotoxy(x,y+1); printf("| | Vida: |");
    gotoxy(x,y+2); printf("| |_______|");
    gotoxy(x,y+3); printf("|/_______/");
}

void botonDanio(int x, int y)
{
    gotoxy(x,y); printf(" __________");
    gotoxy(x,y+1); printf("| | Ataque |");
    gotoxy(x,y+2); printf("| |________|");
    gotoxy(x,y+3); printf("|/________/");
}

void botonDefensa(int x, int y)
{
    gotoxy(x,y); printf(" ___________");
    gotoxy(x,y+1); printf("| | Defensa |");
    gotoxy(x,y+2); printf("| |_________|");
    gotoxy(x,y+3); printf("|/_________/");
}

void botonLlaves(int x, int y)
{
    gotoxy(x,y); printf(" ___________");
    gotoxy(x,y+1); printf("| | Llaves: |");
    gotoxy(x,y+2); printf("| |_________|");
    gotoxy(x,y+3); printf("|/_________/");
}


void botonVerPass(int x, int y)
{
    gotoxy(x,y); printf(" __________");
    gotoxy(x,y+1); printf("| | Ver  V |");
    gotoxy(x,y+2); printf("| |_%sPass :%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3); printf("|/________/");
}


void botonVerPassaPretado(int x, int y)
{
    gotoxy(x,y); printf(" __________");
    gotoxy(x,y+1); printf("|| Ver  V |");
    gotoxy(x,y+2); printf("||_%sPass :%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3); printf("|/________/");
}


void botonOcutaPass(int x, int y)
{
    gotoxy(x,y); printf(" __________");
    gotoxy(x,y+1); printf("| | Oculta |");
    gotoxy(x,y+2); printf("| |_%sPass :%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3); printf("|/________/");
}

void botonOcutaPassApretado(int x, int y)
{
    gotoxy(x,y); printf(" __________");
    gotoxy(x,y+1); printf("|| Oculta |");
    gotoxy(x,y+2); printf("||_%sPass :%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3); printf("|/________/");
}


void botonEditarPjUsuario(int x,int y)
{
    gotoxy(x,y);printf(" ______________");
    gotoxy(x,y+1);printf("| | Editar   1 |");
    gotoxy(x,y+2);printf("| |_%sPersonaje:%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/____________/");
}

void botonEditarPjUsuarioApretado(int x,int y)
{
    gotoxy(x,y);printf(" ______________");
    gotoxy(x,y+1);printf("|| Editar   1 |");
    gotoxy(x,y+2);printf("||_%sPersonaje:%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/____________/");
}


void botonBorrarPersonaje(int x,int y)
{
    gotoxy(x,y);printf(" ______________");
    gotoxy(x,y+1);printf("| | Borrar   2 |");
    gotoxy(x,y+2);printf("| |_%sPersonaje:%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/____________/");
}


void botonBorrarPersonajeApretado(int x,int y)
{
    gotoxy(x,y);printf(" ______________");
    gotoxy(x,y+1);printf("|| Borrar   2 |");
    gotoxy(x,y+2);printf("||_%sPersonaje:%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/____________/");
}


void botonFavoritoPj(int x,int y)
{
    gotoxy(x,y);printf(" ______________");
    gotoxy(x,y+1);printf("| | Agregar  3 |");
    gotoxy(x,y+2);printf("| |_%sPersonaje:%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/____________/");
}


void botonFavoritoPjApretado(int x,int y)
{
    gotoxy(x,y);printf(" ______________");
    gotoxy(x,y+1);printf("|| Agregar  3 |");
    gotoxy(x,y+2);printf("||_%sPersonaje:%s_|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/____________/");
}

void botonCrearPersonaje(int x,int y)
{
    gotoxy(x,y);printf(" ___________________");
    gotoxy(x,y+1);printf("| | Crear Personaje |");
    gotoxy(x,y+2);printf("| |_____%sESPACIO%s_____|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/_________________/");
}

void botonCrearPersonajeApretado(int x,int y)
{
    gotoxy(x,y);printf(" ___________________");
    gotoxy(x,y+1);printf("|| Crear Personaje |");
    gotoxy(x,y+2);printf("||_____%sESPACIO%s_____|",NORMALSUB,NORMAL);
    gotoxy(x,y+3);printf("|/_________________/");
}


void botonAdvertencia(int x, int y)
{
    gotoxy(x,y); printf(" __________________");
    gotoxy(x,y+1); printf("| |  ADVERTENCIA:  |");
    gotoxy(x,y+2); printf("| |________________|");
    gotoxy(x,y+3); printf("|/________________/");
}

void botonConfirmar(int x, int y)
{
    gotoxy(x,y); printf(" ____________");
    gotoxy(x,y+1); printf("| |        C |");
    gotoxy(x,y+2); printf("| |_%sConfirmo%s_|",NORMALSUB, NORMAL);
    gotoxy(x,y+3); printf("|/__________/");
}

void botonConfirmarApretado(int x, int y)
{
    gotoxy(x,y); printf(" ____________");
    gotoxy(x,y+1); printf("||        C |");
    gotoxy(x,y+2); printf("||_%sConfirmo%s_|",NORMALSUB, NORMAL);
    gotoxy(x,y+3); printf("|/__________/");
}
void botonEraChiste (int x, int y)
{
    gotoxy(x,y); printf(" ______________");
    gotoxy(x,y+1); printf("| |          N |");
    gotoxy(x,y+2); printf("| |_%sEra Chiste%s_|",NORMALSUB, NORMAL);
    gotoxy(x,y+3); printf("|/____________/");
}

void botonEraChisteApretado (int x, int y)
{
    gotoxy(x,y); printf(" ______________");
    gotoxy(x,y+1); printf("||          N |");
    gotoxy(x,y+2); printf("||_%sEra Chiste%s_|",NORMALSUB, NORMAL);
    gotoxy(x,y+3); printf("|/____________/");
}



void BotonCreditos(int x, int y)
{
    gotoxy(x,y); printf(" __________________");
    gotoxy(x,y+1); printf("| |    CREDITOS    |");
    gotoxy(x,y+2); printf("| |________________|");
    gotoxy(x,y+3); printf("|/________________/");
}

void botonPersonajesAdmin(int x,int y)
{
    gotoxy(x,y);printf(" ____________________________");
    gotoxy(x,y+1);printf("| |       Personaje:         |");
    gotoxy(x,y+2);printf("| |                          |");
    gotoxy(x,y+3);printf("| |__________________________|");
    gotoxy(x,y+4);printf("|/__________________________/ ");
}


void botonGuardar(int x, int y)
{
    gotoxy(x,y);printf(" ____________");
    gotoxy(x,y+1);printf("| |  GUARDAR |");
    gotoxy(x,y+2);printf("| |          |");
    gotoxy(x,y+3);printf("| |__________|");
    gotoxy(x,y+4);printf("|/__________/");
}

void botonGuardarApretado(int x, int y)
{
    gotoxy(x,y);printf(" ____________");
    gotoxy(x,y+1);printf("||  GUARDAR |");
    gotoxy(x,y+2);printf("||          |");
    gotoxy(x,y+3);printf("||__________|");
    gotoxy(x,y+4);printf("|/__________/");
}

//{   FUNCIONES ANIMACIONES


void aniBotonEnter(int x,int y)
{
    botonEnterApretado(x,y);
    Sleep(200);
    botonEnter(x,y);
}

void aniBotonNombreUsuario(int x, int y)
{
    botonNombreUsuarioApretado(x,y);
    Sleep(200);
    botonNombreUsuario(x,y);
}

void aniBotonNombreApellidoUsuarioApretado(int x,int y)
{
    botonNombreApellidoUsuarioApretado(x,y);
    Sleep(200);
    botonNombreApellidoUsuario(x,y);
}

void aniBotonConfirmaContrasenia(int x, int y)
{
    botonConfirmarContraseniaApretado(x,y);
    Sleep(200);
    botonConfirmarContrasenia(x,y);
}

void aniBotonEditar(int x,int y)
{
    botonEditarApretado(x,y);
    Sleep(200);
    botonEditar(x,y);
}

void aniBotonSalir(int x,int y)
{
    botonSalirApretado(x,y);
    Sleep(100);
    botonSalir(x,y);
    Sleep(100);

}

void aniBotonPass(int x, int y)
{
    botonContraseniaApretado(x,y);
    Sleep(300);
    botonContrasenia(x,y);
    Sleep(300);
}

void aniBotonEmail(int x, int y)
{
    botonEmailApretado(x,y);
    Sleep(300);
    botonEmail(x,y);
    Sleep(300);
}

void aniBotonIngresar(int x, int y)
{
    botonIngresarApretado(x,y);
    Sleep(200);
    botonIngresar(x,y);
    Sleep(200);
}

void aniBotonRegistrarse(int x, int y)
{
    botonRegistrarseApretado(x,y);
    Sleep(200);
    botonRegistrarse(x,y);
    Sleep(200);
}

void aniBotonAceptar(int x, int y)
{
    botonAceptarApretado(x,y);
    Sleep(100);
    botonAceptar(x,y);
    Sleep(100);
}

void aniBotonCreditos(int x,int y)
{
    botonCreditosApretado(x,y);
    Sleep(100);
    botonCreditos(x,y);
    Sleep(100);
}

void aniBotonAdmin(int x,int y)
{
    botonAdminApretado(x,y);
    Sleep(100);
    botonAdmin(x,y);
    Sleep(100);
}


void aniBotonCodigo(int x,int y)
{
    botonCodigoApretado(x,y);
    Sleep(100);
    botonCodigo(x,y);
    Sleep(100);
}

void aniBotonUp(int x,int y)
{
    flechaUpApretado(x,y);
    Sleep(100);
    flechaUp(x,y);
}


void aniBotonDown(int x,int y)
{
    flechaDownApretado(x,y);
    Sleep(100);
    flechaDown(x,y);
}


void aniBotonLeft(int x, int y)
{
    flechaLeftApretado(x,y);
    Sleep(100);
    flechaLeft(x,y);
}


void aniBotonRight(int x , int y)
{
    flechaRightApretado(x,y);
    Sleep(100);
    flechaRight(x,y);
}

void aniBotonEditarUsuario(int x, int y)
{
    botonEditarUsuarioApretado(x,y);
    Sleep(100);
    botonEditarUsuario(x,y);
}


void aniBotonCambioEstado(int x, int y)
{
    botonCambioEstadoApretado(x,y);
    Sleep(100);
    botonCambioEstado(x,y);
}


void aniBotonVerPass(int x,int y)
{
    botonVerPassaPretado(x,y);
    Sleep(100);
    botonVerPass(x,y);
}

void aniBotonOcultarPass(int x, int y)
{
    botonOcutaPassApretado(x,y);
    Sleep(100);
    botonOcutaPass(x,y);
}


void aniBotonEditarPjUsuario(int x, int y)
{
    botonEditarPjUsuarioApretado(x,y);
    Sleep(100);
    botonEditarPjUsuario(x,y);
}


void aniBotonBorrar(int x,int y)
{
    botonBorrarPersonajeApretado(x,y);
    Sleep(100);
    botonBorrarPersonaje(x,y);
}


void aniBotonAgregarFav(int x,int y)
{
    botonFavoritoPjApretado(x,y);
    Sleep(100);
    botonFavoritoPj(x,y);
}

void aniBotonCrearPersonaje(int x, int y)
{
    botonCrearPersonajeApretado(x,y);
    Sleep(100);
    botonCrearPersonaje(x,y);
}


void aniBotonComenzarJuego(int x,int y)
{
    botonComenzarJuegoApretado(x,y);
    Sleep(100);
    botonComenzarJuego(x,y);
}

void aniBotonEraChiste(int x,int y)
{
    botonEraChisteApretado(x,y);
    Sleep(100);
    botonEraChiste(x,y);
}


void aniBotonConfirmar(int x, int y)
{
    botonConfirmarApretado(x,y);
    Sleep(100);
    botonConfirmar(x,y);
}

void aniBotonGuardar(int x, int y)
{
    botonGuardarApretado(x,y);
    Sleep(100);
    botonGuardar(x,y);
}


//}




























