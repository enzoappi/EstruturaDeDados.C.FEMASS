#include "bib.h"

int main(int argc, char** argv) {
	char *letraPTR = NULL;
	int *letraAsciiPTR = NULL, num = 0, cont = 0;

	letraPTR = (char *) malloc(1 * sizeof(char));
	letraAsciiPTR = (int *) malloc(1 * sizeof(int));
	
	printf("Digite qualquer tecla ou (ESC) para sair do programa: ");
	
	//Preenchendo as matrizes	
	while (num != 27){
		num = getch();
		if (num == 13){
			printf("\n");
		}
		letraPTR[cont] = num;
		letraAsciiPTR[cont] = num;
		printf("%c", letraPTR[cont]);
		cont++;
		letraAsciiPTR = aumVetLetraAscii(letraAsciiPTR, cont + 1);
		letraPTR = aumVetLetra(letraPTR, cont + 1);
	}
	
	//Exibindo as matrizes
	printf("\nVoce escreveu...\n");
	printf("\nLinha   Caractere\tCodigo ASCII:");	
	for(int i = 0; i < cont - 1; i++){
		printf("\n%d\t%c\t\t%d", i, letraPTR[i], letraAsciiPTR[i]);	
	}
	printf("\n\n	Obrigado por utilizar o software FEMASS!	\n\n");
	getch();
	return 0;
}

