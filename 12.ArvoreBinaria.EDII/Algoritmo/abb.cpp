#include "abb.h"

// função de inicialização: retorna uma árvore vazia 
NoArv* abb_criavazia()
{
	return NULL;
}

// função de criação: retorna uma árvore com o elemento criado 
NoArv* abb_cria (int c, NoArv* sae, NoArv* sad)
{
	NoArv* p=(NoArv*)malloc(sizeof(NoArv));
	if(p==NULL){
		cout << "FALHA DE ALOCAÇÃO EM MEMÓRIA!\n";
		exit(1);
	} 
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}

NoArv* abb_insere(NoArv* a, int v)
{
	if (a == NULL) //primeira inserção, insira nó root
		a = abb_cria (v, NULL, NULL);
	else if (v < a->info)
		a->esq = abb_insere(a->esq,v); //insere como filho à esquerda
	else /*senão, temos: v >= a->info */
		a->dir = abb_insere(a->dir,v); //insere como filho à direita
	return a;
}

void abb_displayTree(NoArv* a){ //baseado em displayTree, p.371 - Livro Robert Lafore, ED e Alg em Java - Ciência Moderna, 2004.
	stack<NoArv*> globalStack; //uso de bib stack.h da STD lib (contâiner C++ LIFO)
	globalStack.push(a);
	int nBlanks = 32;
	bool isRowEmpty = false;
	cout << "Visão encadeada de árvore: " << endl;
	
	while (isRowEmpty == false){
		stack<NoArv*> localStack; 
		isRowEmpty = true;
	
		for (int j=0; j<nBlanks; j++)
			cout << " ";
	
		while (globalStack.empty()== false){
			NoArv* temp = globalStack.top(); //pega topo da pilha global e...
			globalStack.pop(); //...e o remove em seguida
			
			if (temp != NULL){
				cout << temp->info;
				localStack.push(temp->esq);
				localStack.push(temp->dir);
				
				if ((temp->esq != NULL) || (temp->dir != NULL)){
					isRowEmpty = false;
				}	
			}else{
				cout << "-";	
				localStack.push(NULL);
				localStack.push(NULL);	
			}
			int fim = nBlanks*2 - 1;
			for (int j=0; j<fim; j++)
				cout << " ";
		} //fim-while do globalStack não vazio
		cout << endl;
		nBlanks = nBlanks / 2;
		while (localStack.empty() == false){
			globalStack.push(localStack.top()); //pega topo da pilha local e...
			localStack.pop(); //...e o remove em seguida
		}
	} //fim-while do isRowEmpty é falso
	cout << endl;
}

//EXERCICIO
void abb_imprime(NoArv* a) {	
	if (a != NULL) {
		cout << a->info << " "; /* mostra raiz */
		abb_imprime(a->esq); /* mostra sae */
		abb_imprime(a->dir); /* mostra sad */
	}
}

int abb_busca(NoArv* a, int num) {	
	if(a == NULL){
		return 0; /* árvore vazia: não encontrou */ 
	} 
	else{
		return a->info == num || abb_busca(a->esq, num) || abb_busca(a->dir, num); 
	}
}

void abb_imprimeTravessiaPreOrdem(NoArv* a) {	
	if (a != NULL) {
		cout << a->info << " "; /* mostra raiz */
		abb_imprimeTravessiaPreOrdem(a->esq); /* mostra sae */
		abb_imprimeTravessiaPreOrdem(a->dir); /* mostra sad */
	}
}

void abb_imprimeTravessiaInOrdem(NoArv* a) {	
	if (a != NULL) {
		abb_imprimeTravessiaInOrdem(a->esq);
		cout << a->info << " "; /* mostra raiz */
		abb_imprimeTravessiaInOrdem(a->dir);
	}
}

void abb_imprimeTravessiaPosOrdem(NoArv* a) {
	if (a != NULL){
		abb_imprimeTravessiaPosOrdem(a->esq); /* mostra sae */
		abb_imprimeTravessiaPosOrdem(a->dir); /* mostra sad */
		cout << a->info << " "; /* mostra raiz */
	}
}

int exibir_altura(NoArv* a){
    int sae, sad;
    if (a == NULL) {
    	return -1;
	}
    sae = exibir_altura(a->esq);
    sad = exibir_altura(a->dir);
    if (sae > sad) {
		return sae + 1;
	}
    else {
		return sad + 1;
	}
}

int qtde_nodos(NoArv* a) { 
    if (a == NULL) {
        return 0;
	}
    return (1 + qtde_nodos(a->esq) + qtde_nodos(a->dir)); 
} 

NoArv* abb_retira(NoArv* a, int v){
	//direcionamento para os casos de nao ter encontrado o no-dado com o valor-chave que deseja-se remover
	if(a == NULL){
		return NULL;
	}
	else if(a->info > v){
		a->esq = abb_retira(a->esq, v);
	}
	else if(a->info < v){
		a->dir = abb_retira(a->dir, v);
	}
	//Se nada, anteriormente, satisfez, quer dizer que achamos o no-dado com o valor-chave a ser removido.
	else{
		//Condicao 1: removendo um no folha
		if(a->esq == NULL && a->dir == NULL) {
			free(a);
			a = NULL;
		}
		//Condicao 2: Eh um noh-dado, com filho a esquerda, SOMENTE.
		else if(a->dir == NULL) {
			NoArv* noTmp = a;
			a = a->esq;
			free(noTmp);
		}
		//Condicao 3: Eh um noh-dado, com filho a direta, SOMENTE.
		else if(a->esq == NULL) {
			NoArv* noTmp = a;
			a = a->dir;
			free(noTmp);
		}
		//Condicao 4: Eh um noh-dado, com filho a esquerda e a direta.
		//Usaremos a remocao por copia.
		else {
			NoArv* noFolha = a->esq; //Meu no folha alvo esta na subarvore esquerda, por isso aponto para la, inicialmente.
			while(noFolha->dir != NULL) { //quero o no folha direito dessa subarvore
				noFolha = noFolha->dir; //Sei que meu alvo eh o maior numero dessa subarvore (logo, o elemento mais a direita dela)
			}
			a->info = noFolha->info; //Troco o valor da raiz, pelo maior valor da subarvore esquerda.
			noFolha->info = v; //fazemos com que o maior elemento da subarvore esquerda, tenha o valor-chave == ao valor a ser removido (v)
			a->esq = abb_retira(a->esq, v); //faco a remocao do maior valor da subarvore esquerda.
		}
	}
	return a;
}

/* funcao de criacao de um vetor ordenado a partir da leitura de uma arvore */
void armazenaNohsArvoreEmVetor(NoArv* a, vector<NoArv* > &nohs) { 
    // Caso base 
    if (a == NULL) {
    	return;
	}     

    // Armazena os nohs usando travessia In-order na arvore 
    armazenaNohsArvoreEmVetor(a->esq, nohs); 
    nohs.push_back(a); 
    armazenaNohsArvoreEmVetor(a->dir, nohs); 
} 
  
/* Funcao de balanceamento de uma arvore */
NoArv* balanceador(vector<NoArv* > &nohs, int inicio, int fim) { 
    // melhor caso 
    if (inicio > fim) {
    	return NULL;
	}  

    /* Transformar um noh do meio da arvore, em noh raiz */
    int meio = (inicio + fim)/2; 
    NoArv* a = nohs[meio]; 

    /* Usando o indice de Travessia In-Order para construir-se as subarvores esquerda e direita */
    a->esq  = balanceador(nohs, inicio, meio - 1); 
    a->dir = balanceador(nohs, meio + 1, fim); 

    return a; 
} 
  
//funcao de chamada para o balanceamento de uma arvore binaria
NoArv* abb_balancear(NoArv* a) {
 
    int sae = exibir_altura(a->esq); //calculo do tamanho da subarvore esquerda
    int sad = exibir_altura(a->dir); //calculo do tamanho da subarvore esquerda
    
    int difSaeSad = sae - sad; // calculo das diferencas de alturas, das subarvores
    //cout << "\n\ndifSaeSad = " << difSaeSad; //caso queira ver o valor, soh descomentar
    
    if(difSaeSad < -1 || difSaeSad > 1) {
		// Armazena os valores-chaves dos nohs lidos da arvore desbalanceada, em um vetor ordenado (a ordenacao e a da leitura da Travessia In-order)  
    	vector<NoArv* > nohs; 
    	armazenaNohsArvoreEmVetor(a, nohs); 
  
    	//Criando uma arvore balanceada a partir do vetor ordenado
    	int tamanhoAbb = nohs.size();
    	//ou
    	//int tamanhoAbb = exibir_altura(a);
    	return balanceador(nohs, 0, tamanhoAbb - 1);
    	cout << "\n\nArvore Balanceada com sucesso!\n\n\n";
	}
	else {
		cout << "\n\n\nA arvore atual ja esta balanceada!\n\n\n";
		return a;
	}
} 

