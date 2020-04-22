#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct cadastro {
		char nome[30];
  		char rg[11];
  		char cpf[13];
  		char endereco[150];
	};
void menu(struct cadastro *cadastroPTR, int *contPTR, FILE *pont_arq);
void addCadastro(struct cadastro *cadastroPTR, int *contPTR, FILE *pont_arq);
void printCadastro(struct cadastro *cadastroPTR, int *contPTR);
void tamCadastro(int *contPTR);
void rmvCadastro(struct cadastro *cadastroPTR, int *contPTR);
