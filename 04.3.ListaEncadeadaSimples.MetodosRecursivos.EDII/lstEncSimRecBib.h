#include <stdlib.h>
#include <iostream>

struct Lista{
	int info;
	struct Lista* prox; //ponnteiro de ligacao
};

typedef struct Lista minhaLista;
minhaLista* inicializa();
minhaLista* insereInicio(minhaLista* listaPTR, int i);
void imprime_recursiva(minhaLista* listaPTR);
bool vazia(minhaLista* listaPTR);
minhaLista* buscaInfo(minhaLista* listaPTR, int valor);
void libera_recursiva(minhaLista* listaPTR);
minhaLista* retira_recursiva(minhaLista* listaPTR, int valor);


