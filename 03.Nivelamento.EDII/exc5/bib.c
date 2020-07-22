#include "bib.h"

void menu(struct cadastro *cadastroPTR, int *contPTR){
	
	int opcao;
  	
  	//Inicio do menu de chamada
  	do{
		do{
			printf("\nDigite:\n[1] - Adicionar cadastro\n[2] - Mostrar os cadastros criados\n[3] - Quantidade de cadastros\n[4] - Remover o ultimo cadastro\n[5] - Sair\nSua opcao: ");
			scanf("%d", &opcao);
		}while(opcao < 1 || opcao > 5);
		switch(opcao){
			case 1:
				addCadastro(cadastroPTR, contPTR);
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

void addCadastro(struct cadastro *cadastroPTR, int *contPTR){
	fflush(stdin);
	printf("\nNome: ");
	gets((cadastroPTR + *contPTR)->nome);
	fflush(stdin);
	printf("RG: ");
	gets( (cadastroPTR + *contPTR)->rg);
	fflush(stdin);
	printf("CPF: ");
	gets((cadastroPTR + *contPTR)->cpf);
	fflush(stdin);
	printf("Endereco: ");
	gets((cadastroPTR + *contPTR)->endereco);
	fflush(stdin);
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

