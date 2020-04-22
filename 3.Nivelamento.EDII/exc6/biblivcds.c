#include "biblivcds.h"

void menu(struct livro *cadastroPTR, int *contPTR, FILE *pont_arq){
	
	int opcao;
  	
  	//Inicio do menu de chamada
  	do{
		do{
			printf("\nDigite:\n[1] - Adicionar cadastro\n[2] - Mostrar os livros cadastrados\n[3] - Sair\nSua opcao: ");
			scanf("%d", &opcao);
		}while(opcao < 1 || opcao > 3);
		switch(opcao){
			case 1:
				addCadastroLivro(cadastroPTR, contPTR, pont_arq);
				break;
			case 2:
				printCadastroLivro(cadastroPTR, contPTR);
				break;
			case 3:
				printf("\n\nObrigado por utilizar o software FEMASS!\nBOM DIA!");
				break;
		}
		
	}while(opcao != 3);
}

void addCadastroLivro(struct livro *cadastroPTR, int *contPTR, FILE *pont_arq){
	fflush(stdin);
	printf("\nInforme o codigo ISBN: ");
	scanf(" %[^\n]", (cadastroPTR + *contPTR)->cod);
	fflush(stdin);
	printf("Informe o nome: ");
	scanf(" %[^\n]", (cadastroPTR + *contPTR)->nome);
	fflush(stdin);
	printf("Informe autor: ");
	scanf(" %[^\n]", (cadastroPTR + *contPTR)->autor);
	fflush(stdin);
	printf("Informe o ano de publicacao: ");
	scanf(" %[^\n]", (cadastroPTR + *contPTR)->ano);
	fflush(stdin);
	fprintf(pont_arq, "\nCodigo ISBN: %s	|	Nome: %s	|	Autor: %s	|	Ano de publicacao: %s", (cadastroPTR + *contPTR)->cod, (cadastroPTR + *contPTR)->nome, (cadastroPTR + *contPTR)->autor, (cadastroPTR + *contPTR)->ano);
	*contPTR = *contPTR + 1;
	cadastroPTR = (struct livro *) realloc(cadastroPTR, *contPTR);
	printf("\n\nCadastrado efetuado!\n");
}

void printCadastroLivro(struct livro *cadastroPTR, int *contPTR){
	for(int i = 0; i < *contPTR; i++){
		printf("\nCodigo ISBN: %s	|	Nome: %s	|	Autor: %s	|	Ano de publicacao: %s\n", (cadastroPTR + i)->cod, (cadastroPTR + i)->nome, (cadastroPTR + i)->autor, (cadastroPTR + i)->ano);		
	}
	getch();
}

