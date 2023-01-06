#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED
#include "estructuras.h"
#include "gotoxy.h"



void comprueboPosicion(stSala * room,stPj * personaje,int x,int y);
void mostrarVida(int x, int y,int fin, int ascii);
void crearPj(stPj * personaje, int xSpawn,int ySpawn, char nick[],int id);

int movimientoPersonaje(bool estado,stSala * sala1, stPj * heroe,char archivo[]);

void pintarPersonajeParado(int x,int y);
void pintarPersonajeAtaca(int x,int y);
void pintarPersonajeDefensa(int x,int y);
void accionPersonaje(nodoEnemigo * enemigo,stPj * personaje);
void interfaz(stPj * personaje);
stPj * agarraObjeto(stPj * personaje,stSala * room);
void cartelTurnoPj();
int contarListaPersonaje(nodoDoblePj * lista);

nodoDoblePj * inicNodoDoblePj();
nodoDoblePj * crearPersonajeNodo2(stPj personaje);
nodoDoblePj * agregarAlPrincipioDoble(nodoDoblePj * lista, nodoDoblePj * nuevoNodo);
nodoDoblePj * agregarNodoDobleOrden(nodoDoblePj * lista, nodoDoblePj * nuevoNodo);
nodoDoblePj * borrarNodo(nodoDoblePj * lista, int dato);


void pasarPersonajeListaArchivo(char nombreArchivo[],nodoDoblePj * nuevo);
int verificarCantPersonajes(nodoDoblePj * lista);
void mostrarFavoritoPj(nodoDoblePj * lista,int x,int y);
void cuadradoFav(int x,int y);
nodoDoblePj * pasarListaPersonajesArchivo(char nombreArchivo[],nodoDoblePj * lista);
nodoDoblePj * editarPersonaje(nodoDoblePj * lista,int id,char nombreNuevo[]);
void borrarTodaLaLista(nodoDoblePj ** lista);
void guardadoPersonajes(char nombreArchivo[],nodoDoblePj * lista);
void colocarAlPrincipioLista(nodoDoblePj ** lista);

void guardarDatosPersonaje(stPj *personaje,char nombreArchivo[]);

void muestraUnPersonaje(stPj personaje);
void muestraPrueba(nodoDoblePj * lista);

void muestraPersonajesMenuAdmin(stPj personaje);
void borrarDatosPersonajesMenuAdmin();
void editarPersonajeMenuAdministrador(stPj * personaje);
void borrarArchivoFisico (char rutaArchivo[]);












#endif // PERSONAJE_H_INCLUDED
