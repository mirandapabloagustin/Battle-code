#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>


#include "usuario.h"
#include "botonesAnimaciones.h"
#include "gotoxy.h"
#include "TDAarboles.h"
#include "TDAlistaSimple.h"

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
#define N 110

#define ESBIRRO 1
#define BOOS 2






//GENERA AUTOMATICAMENTE EL ARCHIVO DE PERSONAJES UNICOS POR USUARIO
void nombreArchivoPersonajes(stUsuario * usuario)
{
    char tipoArchivo [30]= "_personajes.bin";
    char temporal [80];
    strcpy(temporal,usuario->nickUsuario);
    strcat(temporal,tipoArchivo);
    strcpy(usuario->nombreArchivoPersonajes,temporal);
}


//EDITA EN EL REGISTRO LOS DATOS INGRESADOS POR EL USUARIO
void editarIngreso(stUsuario * usuario)
{
    int posicion = 1;
    imprimirSelector(posicion);
    char tecla;
    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();
            if(tecla == ARRIBA && posicion > 1 )
            {
                posicion--;
            }

            if(tecla == ABAJO && posicion < 4 )
            {
                posicion++;
            }
            if(tecla == ESPACIO && posicion == 1)
            {
                limpiarArregloChar(usuario->nombreApellido);
                dibujarLinea(48,11,77,32);
                cargarDato(usuario->nombreApellido,48,11);
                aniBotonNombreApellidoUsuarioApretado(27,10);
                tecla = SALIR;
            }
            if(tecla == ESPACIO && posicion == 2)
            {
                limpiarArregloChar(usuario->nickUsuario);
                dibujarLinea(48,16,77,32);
                cargarDato(usuario->nickUsuario,48,16);
                aniBotonNombreUsuario(27,15);
                limpiarArregloChar(usuario->nombreArchivoPersonajes);
                nombreArchivoPersonajes(usuario);
                tecla = SALIR;
            }
            if(tecla == ESPACIO && posicion == 3)
            {
                limpiarArregloChar(usuario->email);
                dibujarLinea(48,21,77,32);
                cargarDato(usuario->email,48,21);
                aniBotonEmail(27,20);
                tecla = SALIR;
            }
            if(tecla == ESPACIO && posicion == 4)
            {
                limpiarArregloChar(usuario->contrasenia);
                dibujarLinea(48,26,77,32);
                cargarDatoPass(usuario->contrasenia,48,26);
                aniBotonPass(27,25);
                tecla = SALIR;
            }
            imprimirSelector(posicion);
        }
    }
}


//AGREGA AL USUARIO A UN ARCHIVO DE USUARIO
void agregarAlArchivoUsuarios(stUsuario usuario, char nombreArchivo[])
{
    char direccionCarpeta [30]= "ArchivosAdmins\\";
    char temporal [100];
    strcpy(temporal,direccionCarpeta);
    strcat(temporal,nombreArchivo);

    FILE * archivo = fopen(temporal,"a+b");

    if(archivo)
    {
        fwrite(&usuario,sizeof(usuario),1,archivo);

     fclose(archivo);
    }
}

int verificarUsuario(char string1[],char string2[])
{
    stUsuario usuario;
    int flag = 0;
    FILE * archivo = fopen("ArchivosAdmins\\lista_usuarios.bin","r+b");
    if(archivo)
    {
        while(fread(&usuario,sizeof(usuario),1,archivo) > 0)
        {
            if( strcmpi(usuario.email,string1) == 0)
            {
                if( strcmpi(usuario.contrasenia,string2) == 0)
                {
                    if(usuario.habilitado == true)
                    {
                        flag = 1;
                    }
                }
            }
        }
        fclose(archivo);
    }
    return flag;
}

stUsuario buscaUsuario (char string[])
{
    stUsuario usuario;
    int flag = 0;
    FILE * archivo = fopen("ArchivosAdmins\\lista_usuarios.bin","r+b");
    if(archivo)
    {
        while(fread(&usuario,sizeof(usuario),1,archivo) > 0)
        {
            if( strcmpi(usuario.email,string) == 0)
            {
                    return usuario;
            }
        }
        fclose(archivo);
    }
}

int verificarEmail(char email[])
{
    stUsuario usuario;
    int flag = 0;
    FILE * archivo = fopen("ArchivosAdmins\\lista_usuarios.bin","r+b");
    if(archivo)
    {
        while(fread(&usuario,sizeof(usuario),1,archivo) > 0)
        {
            if( strcmpi(usuario.email,email) == 0)
            {
                flag = 1;
            }
        }
        fclose(archivo);
    }
    return flag;
}

int verificarNickUsuario(char nick[])
{
    stUsuario usuario;
    int flag = 0;
    FILE * archivo = fopen("ArchivosAdmins\\lista_usuarios.bin","r+b");
    if(archivo)
    {
        while(fread(&usuario,sizeof(usuario),1,archivo) > 0)
        {
            if( strcmpi(usuario.nickUsuario,nick) == 0)
            {
                flag = 1;
            }
        }
        fclose(archivo);
    }
    return flag;
}

int asignarIdUsuario()
{
    stUsuario usuario;
    int contador = 0;
    FILE * archivo = fopen("ArchivosAdmins\\lista_usuarios.bin","r+b");
    if(archivo)
    {
        while(fread(&usuario,sizeof(usuario),1,archivo) > 0)
        {
            contador ++;
        }
        fclose(archivo);
    }
    return contador;
}

nodoUsuario * inicListaUsuarios()
{
    return NULL;
}

nodoUsuario * crearUsuario(stUsuario usuario)
{
    nodoUsuario * nodoAuxiliar = (nodoUsuario*)malloc(sizeof(nodoUsuario));

    nodoAuxiliar->usuario = usuario;
    nodoAuxiliar->listaPersonajes = inicNodoSimple();
    nodoAuxiliar->siguienteUsuario = NULL;

    return nodoAuxiliar;
}

nodoUsuario * agregaraAlPrincipioUsuario(nodoUsuario * listaUsuarios,nodoUsuario * nuevoUsuario)
{
    if(listaUsuarios == NULL)
    {
        listaUsuarios = nuevoUsuario;
    }
    else
    {
        nuevoUsuario->siguienteUsuario = listaUsuarios;
        listaUsuarios = nuevoUsuario;
    }
    return listaUsuarios;
}

nodoUsuario * agregarEnOrden(nodoUsuario * listaUsuarios,nodoUsuario * nuevoUsuario)
{
    if(listaUsuarios == NULL)
    {
        listaUsuarios = nuevoUsuario;
    }
    else
    {
        if(nuevoUsuario->usuario.id < listaUsuarios->usuario.id)
        {
            listaUsuarios = agregaraAlPrincipioUsuario(listaUsuarios,nuevoUsuario);
        }
        else
        {
            nodoUsuario * anterior;
            nodoUsuario * iterador = listaUsuarios;

            while(iterador != NULL && nuevoUsuario->usuario.id > iterador->usuario.id)
            {
                anterior = iterador;
                iterador = iterador->siguienteUsuario;
            }
            anterior->siguienteUsuario = nuevoUsuario;
            nuevoUsuario->siguienteUsuario = iterador;
        }
    }
    return listaUsuarios;
}

nodoUsuario * deListaArchivo(nodoUsuario * listaUsuarios)
{
    stUsuario usuario;
    FILE * archivo =  fopen("ArchivosAdmins\\lista_usuarios.bin","r+b");

    if(archivo)
    {
        while(fread(&usuario,sizeof(usuario),1,archivo) > 0 )
        {
            nodoUsuario * nodoNuevo = crearUsuario(usuario);

            listaUsuarios = agregarEnOrden(listaUsuarios,nodoNuevo);
        }
        fclose(archivo);
    }
    return listaUsuarios;
}

nodoUsuario * buscarNodo(stUsuario buscado, nodoUsuario * lista)
{
    while ((lista != NULL) && (lista->usuario.id != buscado.id))
    {
        lista = lista->siguienteUsuario;
    }

    return lista;
}

nodoUsuario * borrarNodoBuscado(stUsuario usuarioBuscado, nodoUsuario * lista)
{
    nodoUsuario * iterator;
    nodoUsuario * anterior;

    if((lista != NULL) && (lista->usuario.id == usuarioBuscado.id ) )
    {
        nodoUsuario * nodoAuxiliar = lista;
        lista = lista->siguienteUsuario;
        free(nodoAuxiliar);
    }
    else
    {
        iterator = lista;
        while((iterator != NULL) && (iterator->usuario.id != usuarioBuscado.id))
        {
            anterior = iterator;
            iterator = iterator->siguienteUsuario;
        }

        if(iterator != NULL)
        {
            anterior->siguienteUsuario = iterator->siguienteUsuario;

            free(iterator);
        }
    }
    return lista;
}

int pasarListaArreglo(nodoUsuario * lista, stUsuario arreglo[],int cantElementos,int posicion)
{
    int j = 0;
    while(j < posicion)
    {
        lista = lista->siguienteUsuario;
        j++;
    }
    int i = 0;

    while(lista != NULL && i < 9 && posicion < cantElementos)
    {
        if(posicion < cantElementos+1)
        {
            arreglo[i] = lista->usuario;
            i++;
        }
        lista = lista->siguienteUsuario;
    }
    posicion+=i;
    return posicion;
}

void muestraArregloUsuarios(stUsuario arreglo[],int dim,int x,int y,int posInicial,int posFinal)
{
    int i;
    int j = 0;
    for( i = posInicial; i < posFinal && i< dim ; i++)
    {
        mostrarUsuario(arreglo[j],x,y);
        y += 3;
        j++;
    }
}

void mostrarUsuario(stUsuario usuario,int x,int y)
{
    gotoxy(x,y);printf("ID: %s%d%s",APERTURA,usuario.id,CERRADO);
    gotoxy(x,y+1);printf("NICK: %s%s%s",APERTURA,usuario.nickUsuario,CERRADO);
}

void muestraUsuarioArregloSelector(int posSelector,stUsuario arreglo[])
{
    gotoxy(51,6); printf("                              ");
    gotoxy(51,6); printf("%s",arreglo[posSelector].nombreApellido);
    gotoxy(51,10); printf("                             ");    gotoxy(51,10); printf("%s",arreglo[posSelector].nickUsuario);
    gotoxy(51,14); printf("                             ");
    gotoxy(51,14); printf("%s",arreglo[posSelector].email);
    gotoxy(51,18); printf("                             ");
    gotoxy(51,18); printf("%s",arreglo[posSelector].contrasenia);
    if(arreglo[posSelector].habilitado == true)
    {
        gotoxy(52,24); printf("%s%c%c%c%s",VERDE,219,219,219,NORMAL);
    }
    else
    {
        gotoxy(52,24); printf("%s%c%c%c%s",ROJO,219,219,219,NORMAL);
    }
}

int contarElementos(nodoUsuario * lista)
{
    int contador = 0;
    while(lista != NULL)
    {
        contador++;
        lista = lista->siguienteUsuario;
    }
    return contador;
}

stUsuario editarUsuarioAdministrador(stUsuario usuario)
{
    //cambia nombre apellido
    limpiarArregloChar(usuario.nombreApellido);
    gotoxy(51,6); printf("                              ");
    cargarDato(usuario.nombreApellido,51,6);

    // cambia nick

    limpiarArregloChar(usuario.nickUsuario);
    gotoxy(51,10); printf("                              ");
    cargarDato(usuario.nickUsuario,51,10);

    //como se cambia el nombre del archivo se cambia el nombre del archivo de guardado de personajes
    nombreArchivoPersonajes(&usuario);

    // cambia email
    limpiarArregloChar(usuario.email);
    gotoxy(51,14); printf("                              ");
    cargarDato(usuario.email,51,14);

    // cambia contraseña
    limpiarArregloChar(usuario.contrasenia);
    gotoxy(51,18); printf("                              ");
    cargarDato(usuario.contrasenia,51,18);

    return usuario;
}

nodoUsuario * cambioEstado(nodoUsuario * lista, stUsuario buscado)
{
    nodoUsuario * aux = lista;
    while(aux != NULL)
    {
        if(aux->usuario.id == buscado.id)
        {
            if(aux->usuario.habilitado == true)
            {
                aux->usuario.habilitado = false;
            }
            else
            {
                aux->usuario.habilitado = true;
            }
        }

        aux = aux->siguienteUsuario;
    }
    return lista;
}

void cartelNoJugadores(int x,int y)
{
    printf("%s",ROJO);    cuadradoAscii(x-8,y,x+22,y+2,219);
    printf("%s",NORMAL);
    gotoxy(x,y); printf(" NO  CONTIENE ");
    gotoxy(x,y+1);printf("  PERSONAJES  ");
}

void pasarListaArchivo(nodoUsuario * lista)
{
    stUsuario usuario;

    FILE * archivo = fopen("ArchivosAdmins\\lista_usuarios.bin","w+b");

    if(archivo)
    {
        while(lista != NULL)
        {
            usuario = lista->usuario;
            fwrite(&usuario,sizeof(usuario),1,archivo);
            lista = lista->siguienteUsuario;
        }
        fclose(archivo);
    }
}

void ocultarPass(char arreglo[],int x, int y)
{
    int i = 0;

    while(arreglo[i] != NULL)
    {
        gotoxy(x,y); printf("*");
        i++;
        x++;
    }
}

int accionOcultarPas (int * valor,char arreglo[])
{
    if(valor == 0)
    {
        aniBotonVerPass(20,30);
        gotoxy(11,25);printf("                           ");
        gotoxy(11,25);printf("%s",arreglo);
        botonOcutaPass(20,30);
        valor = 1;
    }
    else
    {
        aniBotonOcultarPass(20,30);
        gotoxy(11,25);printf("                           ");
        ocultarPass(arreglo,11,25);
        botonVerPass(20,30);
        valor = 0;
    }
    return valor;
}

stUsuario editarUsuarioMenuUsuario(stUsuario usuario)
{
    int flag;

    //cambia nombre apellido
    limpiarArregloChar(usuario.nombreApellido);
    gotoxy(11,13); printf("                              ");
    cargarDato(usuario.nombreApellido,11,13);

    do
    {
        // cambia nick
        limpiarArregloChar(usuario.nickUsuario);
        gotoxy(11,17); printf("                              ");
        cargarDato(usuario.nickUsuario,11,17);
        flag = verificarNickUsuario(usuario.nickUsuario);
        if(flag == 1)
        {
            gotoxy(8,29);
            printf("%sprintf(%cTe copiaste de otro...%c);%s",ROJO,34,34,NORMAL);
            Sleep(3000);
            gotoxy(8,29);
            printf("                                    ");
        }
    }while(flag != 0);

    //como se cambia el nombre del archivo se cambia el nombre del archivo de guardado de personajes
    nombreArchivoPersonajes(&usuario);

    // cambia email
    do
    {
        limpiarArregloChar(usuario.email);
        gotoxy(11,21); printf("                              ");
        cargarDato(usuario.email,11,21);
        flag = verificarEmail(usuario.email);
        if(flag == 1)
        {
            gotoxy(8,29);
            printf("%sprintf(%cTe copiaste de otro...%c);%s",ROJO,34,34,NORMAL);
            Sleep(3000);
            gotoxy(8,29);
            printf("                                    ");
        }
    }while(flag != 0);


    // cambia contraseña
    limpiarArregloChar(usuario.contrasenia);
    gotoxy(11,25); printf("                              ");
    cargarDato(usuario.contrasenia,11,25);

    return usuario;
}

void muestraUsuarioMenu(stUsuario usuario)
{
    gotoxy(20,3); printf("                              ");
    gotoxy(20,3);printf("%s%s%s",APERTURA,usuario.nickUsuario,CERRADO);
    gotoxy(11,13); printf("                              ");
    gotoxy(11,13);printf("%s",usuario.nombreApellido);
    gotoxy(11,17); printf("                              ");
    gotoxy(11,17);printf("%s",usuario.nickUsuario);
    gotoxy(11,21); printf("                              ");
    gotoxy(11,21);printf("%s",usuario.email);
    ocultarPass(usuario.contrasenia,11,25);
}

stUsuario modificarUsuarioArchivo(int id)
{
    stUsuario iterator;
    FILE*archivo = fopen("ArchivosAdmins\\lista_usuarios.bin","r+b");
    if(archivo)
    {
        while(fread(&iterator,sizeof(iterator),1,archivo)>0)
        {
            if(iterator.id == id)
            {
                fseek(archivo,sizeof(stUsuario)*-1,SEEK_CUR);

                iterator = editarUsuarioMenuUsuario(iterator);

                fwrite(&iterator,sizeof(iterator),1,archivo);

                fclose(archivo);
            }
        }
    }
    return iterator;
}

void copiaDatosArchivoPersonajesNuevo(char archivoNuevo[],char antiguioArchivo[])
{
    char ruta [30]= "listaPersonajesUsuarios\\";
    char rutaAcceso[80];
    strcpy(rutaAcceso,ruta);
    strcat(rutaAcceso,antiguioArchivo);

    //LEE LE ANTIGUO ARCHIVO
    FILE*archivo = fopen(rutaAcceso,"r+b");

    //LEE EL NEUVO ARCHIVO
    limpiarArregloChar(rutaAcceso);
    strcpy(rutaAcceso,ruta);
    strcat(rutaAcceso,archivoNuevo);
    FILE*arcNuevo = fopen(rutaAcceso,"a+b");

    stPj personaje;

    if(archivo && arcNuevo)
    {
        while(fread(&personaje,sizeof(personaje),1,archivo)>0)
        {
            fwrite(&personaje,sizeof(personaje),1,arcNuevo);
        }
        fclose(archivo);
        fclose(arcNuevo);
    }

}

void cambiarEstadoUsuarioArchivo(int id)
{
    stUsuario iterator;
    FILE*archivo = fopen("ArchivosAdmins\\lista_usuarios.bin","r+b");
    if(archivo)
    {
        while(fread(&iterator,sizeof(iterator),1,archivo)>0)
        {
            if(iterator.id == id)
            {
                fseek(archivo,sizeof(stUsuario)*-1,SEEK_CUR);

                iterator.habilitado = false;

                fwrite(&iterator,sizeof(iterator),1,archivo);

                fclose(archivo);
            }
        }
    }
}

void frontConfirmarAccion(int x,int y)
{
    cuadradoAscii(x-1,y-1,x+50,y+8,32);
    dibujarCuadro(x-1,y-1,x+50,y+8,CYAN);
    dibujarCuadro(x+1,y+1,x+48,y+6,ROJO);
    botonAdvertencia(x+15, y-2);
    gotoxy(x+4,y+3);printf(" printf(%cEstas seguro que queres hacer eso",34);
    gotoxy(x+4,y+4);printf("      amigo?... Yo que vos me fijo.%c);",34);
    botonConfirmar(x+4,y+5);
    botonEraChiste(x+30,y+5);
}

int confirmarAccion(int x,int y)
{
    frontConfirmarAccion(x,y);
    char tecla;
    int valor = 0;
    while(tecla != C &&   tecla != N)
    {
            tecla = getch();
            if(tecla == N)
            {
                aniBotonEraChiste(x+30,y+5);
                valor = 0;
            }
            if(tecla == C)
            {
                aniBotonConfirmar(x+4,y+5);
                valor = 1;
            }
    }

    return valor;
}








































