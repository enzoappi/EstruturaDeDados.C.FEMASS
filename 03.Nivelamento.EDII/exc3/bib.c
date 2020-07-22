#include "bib.h"

void menu(int *v){
	
	int opcao(0), cont(0), *contPTR;
  	contPTR = &cont;
  	
  	//Inicio do menu de chamada
	do{
		do{
			printf("\nDigite:\n[1] - Adicionar um numero\n[2] - Mostrar vetor criado\n[3] - Quantidade de numeros no vetor\n[4] - Remover o ultimo numero\n[5] - Sair\nSua opcao: ");
			scanf("%d", &opcao);
		}while(opcao < 1 || opcao > 5);
		switch(opcao){
				
			case 1:
				addNum(contPTR, v);
				break;
			case 2:
        		mostraVetorCriado(contPTR, v);
				break;
			case 3:
        		printf("\nA quantidade de numeros inseridos no vetor eh: %d\n\n", *contPTR);
				break;
			case 4:
        		rmvNum(contPTR, v);
				break;
			case 5:
				printf("\n\nObrigado por utilizar o software FEMASS!\nBOM DIA!");
				break;	
		}
	}while(opcao != 5);	
}

//Funcoes de criacao da pilha
void addNum(int *contPTR, int *v){
  	int valor(0);
	*contPTR = *contPTR + 1;
  	v = (int *) realloc(v, *contPTR);
	printf("\ndigite um numero inteiro e aleatorio: ");
	scanf("%d", &valor);
	v[*contPTR - 1] = valor;
	printf("\n\n");	
}

void mostraVetorCriado(int *contPTR, int *v){
	printf("\n\nVetor criado: [");
	for(int i = 0; i < *contPTR; i++){
		printf(" %d ", v[i]);
	};
	printf("]\n\n");
}

void rmvNum(int *contPTR, int *v){
  	int valor(0);
	if(*contPTR > 0){
		*contPTR = *contPTR - 1;
		if(*contPTR != 0){
			v = (int *) realloc(v, *contPTR);
		}
		printf("\nUltimo valor, removido com sucesso!\n\n");
	}
	else{
		printf("\nImpossivel remover outro numero, pois o vetor ja esta vazio!\n\n");
	}
	
}
