#include<stdlib.h>
#include<stdio.h>
#include<locale.h>

struct pilha{
	int topo;
	int capa;
	float *delemento;
	
}typedef duracell;

void criarpilha(duracell *p,int c){
	p -> topo=-1;
	p -> capa=c;
	p -> delemento = (float*) malloc (c* sizeof(float)); 
}

int estavazia(duracell *p){
	if (p-> topo == -1){
		return 1;
	}
	else{
		return 0;
	}
}

int estacheia (duracell *p){
	if (p-> topo == p-> capa-1){
		return 1;
	}
	else{
		return 0;
	}
}

void empilhar(duracell *p, float v){
	p-> topo++;
	p-> delemento[p->topo]=v;
}

float desempilhar(duracell *p){
	float aux=p-> delemento[p->topo];
	p-> topo--;
	return(aux);
}

float retornatopo(duracell *p){
	return(p-> delemento[p->topo]);
}

main ()
{
	setlocale (LC_ALL, "Portuguese");
	
	duracell meupilha;
	int capacidade,op;
	float valor;
	
	printf("Capacidade da pilha: ");
	scanf("%d",&capacidade);
	
	criarpilha(&meupilha,capacidade);
	
	while(1){
		printf("\n1-Adiciona.\n2-Tira.\n3-Mostra Topo.\n4-Sair.\n");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				if(estacheia(&meupilha)==1){
					printf("\n\nA Pilha Cheia (OVERFLOW)!");
				}
				else{
					printf("\n\nValor?");
					scanf("%f",&valor);
					empilhar(&meupilha,valor);
				}
				break;
			case 2:
				if(estavazia(&meupilha)==1){
					printf("\n\nA Pilha Vazia (UNDERFLOW)!");
				}
				else{
					valor=desempilhar(&meupilha);
					printf("\n\nO valor retirado é: %f",valor);
				}
				break;
			case 3:
				if(estavazia(&meupilha)==1){
					printf("\n\nPilha Vazia!");
				}
				else{
					printf("\n\nO topo é: %f",retornatopo(&meupilha));
				}
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\n\nNúmero inválido, repita o processo.");
		}
	}
}

