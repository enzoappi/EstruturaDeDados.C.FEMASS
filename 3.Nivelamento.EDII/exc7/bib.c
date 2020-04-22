#include "bib.h"

void menu(struct cadastro *cadastroPTR, int *contPTR, FILE *pont_arq){
	
	int opcao;
  	
  	//Inicio do menu de chamada
  	do{
		do{
			printf("\nDigite:\n[1] - Adicionar cadastro\n[2] - Mostrar os cadastros criados\n[3] - Quantidade de cadastros\n[4] - Remover o ultimo cadastro\n[5] - Sair\nSua opcao: ");
			scanf("%d", &opcao);
		}while(opcao < 1 || opcao > 5);
		switch(opcao){
			case 1:
				addCadastro(cadastroPTR, contPTR, pont_arq);
				break;
			case 2:
				printCadastro(cadastroPTR, contPTR);
				break;
			case 3:
				tamCadastro(contPTR);
				break;
			case 4:
				rmvCadastro(cadastroPTR, contPTR);
				break;
			case 5:
				printf("\n\nObrigado por utilizar o software FEMASS!\nBOM DIA!");
				break;
		}
		
	}while(opcao != 5);
}

void addCadastro(struct cadastro *cadastroPTR, int *contPTR, FILE *pont_arq){
	fflush(stdin);
	printf("\nNome: ");
	scanf(" %[^\n]", (cadastroPTR + *contPTR)->nome);
	printf("LIDO: %s\n", (cadastroPTR + *contPTR)->nome);
	fflush(stdin);
	printf("RG: ");
	scanf(" %[^\n]", (cadastroPTR + *contPTR)->rg);
	printf("LIDO: %s\n",  (cadastroPTR + *contPTR)->rg);
	fflush(stdin);
	printf("CPF: ");
	scanf(" %[^\n]", (cadastroPTR + *contPTR)->cpf);
	printf("LIDO: %s\n", (cadastroPTR + *contPTR)->cpf);
	fflush(stdin);
	printf("Endereco: ");
	scanf(" %[^\n]", (cadastroPTR + *contPTR)->endereco);
	printf("LIDO: %s\n", (cadastroPTR + *contPTR)->endereco);
	fflush(stdin);
	fprintf(pont_arq, "\nNome: %s	|	rg: %s	|	cpf: %s	|	endereco: %s", (cadastroPTR + *contPTR)->nome, (cadastroPTR + *contPTR)->rg, (cadastroPTR + *contPTR)->cpf,  (cadastroPTR + *contPTR)->endereco);
	*contPTR = *contPTR + 1;
	cadastroPTR = (struct cadastro *) realloc(cadastroPTR, *contPTR);
}

void printCadastro(struct cadastro *cadastroPTR, int *contPTR){
	for(int i = 0; i < *contPTR; ++i){
		printf("\nNome: %s | RG: %s | CPF: %s | Endereco: %s", (cadastroPTR + i)->nome, (cadastroPTR + i)->rg, (cadastroPTR + i)->cpf, (cadastroPTR + i)->endereco);
			
	}
}

void tamCadastro(int *contPTR){
	printf("\nQuantidade de cadastros realizados: %d", *contPTR);
}

void rmvCadastro(struct cadastro *cadastroPTR, int *contPTR){
	if(*contPTR > 0){
		*contPTR = *contPTR - 1;
		if(*contPTR != 0){
			cadastroPTR = (struct cadastro *) realloc(cadastroPTR, *contPTR);
		}
		printf("\nUltimo cadastro, removido com sucesso!");
	}
	else{
		printf("\nNao existe mais nenhum cadastro a ser removido!");
	}

}
