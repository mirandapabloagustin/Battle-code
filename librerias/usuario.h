#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <stdbool.h>
#include "estructuras.h"
#include "usuario.h"



void nombreArchivoPersonajes(stUsuario * usuario);
void editarIngreso(stUsuario * usuario);
void agregarAlArchivoUsuarios(stUsuario usuario, char nombreArchivo[]);
stUsuario buscaUsuario (char string[]);

int verificarUsuario(char string1[],char string2[]);
int verificarEmail(char email[]);
int verificarNickUsuario(char nick[]);
int asignarIdUsuario();

nodoUsuario * inicListaUsuarios();
nodoUsuario * crearUsuario(stUsuario usuario);
nodoUsuario * agregarEnOrden(nodoUsuario * listaUsuarios,nodoUsuario * nuevoUsuario);
nodoUsuario * agregaraAlPrincipioUsuario(nodoUsuario * listaUsuarios,nodoUsuario * nuevoUsuario);
nodoUsuario * deListaArchivo(nodoUsuario * listaUsuarios);
nodoUsuario * buscarNodo(stUsuario buscado, nodoUsuario * lista);
nodoUsuario * borrarNodoBuscado(stUsuario dato, nodoUsuario * lista);

int pasarListaArreglo(nodoUsuario * lista, stUsuario arreglo[],int cantElementos,int posicion);
void muestraArregloUsuarios(stUsuario arreglo[],int dim,int x,int y,int posInicial,int posFinal);
void mostrarUsuario(stUsuario usuario,int x,int y);
int contarElementos(nodoUsuario * lista);
void muestraUsuarioArregloSelector(int posSelector,stUsuario arreglo[]);
stUsuario editarUsuarioAdministrador(stUsuario usuario);
nodoUsuario * cambioEstado(nodoUsuario * lista,stUsuario buscado);
void cartelNoJugadores(int x,int y);
void pasarListaArchivo(nodoUsuario * lista);
void ocultarPass(char arreglo[],int x, int y);
int accionOcultarPas (int * valor,char arreglo[]);
stUsuario editarUsuarioMenuUsuario(stUsuario usuario);
void muestraUsuarioMenu(stUsuario usuario);
stUsuario modificarUsuarioArchivo(int id);
void copiaDatosArchivoPersonajesNuevo(char archivoNuevo[],char antiguioArchivo[]);
void cambiarEstadoUsuarioArchivo(int id);
void frontConfirmarAccion(int x,int y);
int confirmarAccion(int x,int y);

#endif // USUARIO_H_INCLUDED




