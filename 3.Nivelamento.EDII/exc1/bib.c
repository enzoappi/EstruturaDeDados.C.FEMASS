#include "bib.h"

void codCaractAscII(){
	char caract;
	
	printf("Digite um caracter: ");
	caract = getch();
	
	printf("\n\nO caracter digitado foi: %c.\nO codigo asc II (decimal) dele eh: %i", caract, (int) caract);

}

