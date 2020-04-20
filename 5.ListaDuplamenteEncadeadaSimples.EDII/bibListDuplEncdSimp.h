#include <stdlib.h>
#include <iostream>

struct Lista{
	struct Lista* anterior; //ponteiro de ligacao noh anterior
	int info;
	struct Lista* proximo; //ponteiro de ligacao noh posterior
};
typedef struct Lista minhaLista;

minhaLista* inicializar(minhaLista* listaPTR, int valor);
minhaLista* insereInicio(minhaLista* listaPTR, int valor);
minhaLista* insereFim(minhaLista* listaPTR, int valor);
minhaLista* removeInicio(minhaLista* listaPTR);
minhaLista* removeFim(minhaLista* listaPTR);
minhaLista* removeKey(minhaLista* listaPTR, int valor);
void size(minhaLista* listaPTR);
void mostraListaInicioFim(minhaLista* listaPTR);
void mostraListaFimInicio(minhaLista* listaPTR);
void mostraInicio(minhaLista* listaPTR);
void mostraFim(minhaLista* listaPTR);
void apagaLista(minhaLista* listaPTR);

