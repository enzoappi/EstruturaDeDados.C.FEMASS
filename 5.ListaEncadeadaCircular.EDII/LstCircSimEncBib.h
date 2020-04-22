#include <stdlib.h>
#include <iostream>

struct Lista{
	int info;
	struct Lista* proximo; //ponteiro de ligacao
};
typedef struct Lista minhaLista;

minhaLista* inicializar(minhaLista* listaPTR, int valor);
minhaLista* insereInicio(minhaLista* listaPTR, int valor);
minhaLista* insereFim(minhaLista* listaPTR, int valor);
minhaLista* removeInicio(minhaLista* listaPTR);
minhaLista* removeFim(minhaLista* listaPTR);
minhaLista* removeKey(minhaLista* listaPTR, int valor);
void size(minhaLista* listaPTR);
void mostraLista(minhaLista* listaPTR);
void mostraInicio(minhaLista* listaPTR);
void mostraFim(minhaLista* listaPTR);
void apagaLista(minhaLista* listaPTR);

