#include "bib.h"

int* aumVetLetraAscii(int *letraAsciiPTR, int cont){
	letraAsciiPTR = (int *) realloc(letraAsciiPTR, cont * sizeof(int));
	return letraAsciiPTR;
}

char* aumVetLetra(char *letraPTR, int cont){
	letraPTR = (char *) realloc(letraPTR, cont * sizeof(char));
	return letraPTR;
}

