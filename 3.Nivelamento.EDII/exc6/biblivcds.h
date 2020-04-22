#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct livro {
	char cod[18];
  	char nome[50];
  	char autor[30];
  	char ano[6];
};
void menu(struct livro *cadastroPTR, int *contPTR, FILE *pont_arq);
void addCadastroLivro(struct livro *cadastroPTR, int *contPTR, FILE *pont_arq);
void printCadastroLivro(struct livro *cadastroPTR, int *contPTR);

