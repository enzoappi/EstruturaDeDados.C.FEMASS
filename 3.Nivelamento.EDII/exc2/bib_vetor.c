#include "bib_vetor.h"

void printVetor(int n, int *vPtr){
	
	int opcao = 0;
	
	while(opcao < 1 || opcao > 4){
		printf("\n\nDigite\n[1] - Mostrar o vetor CRIADO\n[2] - Mostrar os elementos IMPARES\n[3] - Mostrar os elementos PARES\n[4] - ENCERRAR\n\nSua opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("\nVetor criado: ");
				for(int i = 0; i < n; i++){
					if(i == 0){
						printf("[ %i ", vPtr[i]);
					}
					else{
						printf("%d ", vPtr[i]);	
					}
				}
				printf("]");
				break;
			case 2:
				printf("\nElementos IMPARES: [");
				for(int i = 0; i < n; i++){
					if(vPtr[i] % 2 != 0){
						printf(" %d ", vPtr[i]);
					}
				};
				printf("]");
				break;
			case 3:
				printf("\nElementos PARES:[");
				for(int i = 0; i < n; i++){
					if(vPtr[i] % 2 == 0){
						printf(" %d ", vPtr[i]);
					}
				};
				printf("]");
				break;
			case 4:
				printf("\n\nObrigado por utilizar o software FEMASS!\nBom dia/Boa tarde/Boa noite!");
				break;
		}
	}
}
