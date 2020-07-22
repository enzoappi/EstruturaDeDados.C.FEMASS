#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stack> 
#include <vector>

using namespace std;

struct noArv {
	int info;
	struct noArv* esq;
	struct noArv* dir;
};
typedef struct noArv NoArv;
NoArv* abb_criavazia();
NoArv* abb_cria (int c, NoArv* e, NoArv* d);
NoArv* abb_insere(NoArv* a, int v);
void abb_displayTree(NoArv* a);
void abb_imprime(NoArv* a);
int abb_busca(NoArv* a, int num);
void abb_imprimeTravessiaPreOrdem(NoArv* a);
void abb_imprimeTravessiaInOrdem(NoArv* a);
void abb_imprimeTravessiaPosOrdem(NoArv* a);
int exibir_altura(NoArv* a);
int qtde_nodos(NoArv* a);
NoArv* abb_retira(NoArv* a, int v);
void armazenaNohsArvoreEmVetor(NoArv* a, vector<NoArv* > &nohs);
NoArv* balanceador(vector<NoArv* > &nohs, int inicio, int fim);
NoArv* abb_balancear(NoArv* a);


