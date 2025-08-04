#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
}No;
        
typedef struct fila {
    struct No *inicio;
    struct No *fim;
    int tam;
}Fila;

void inicia (Fila * fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

int insere (Fila *fila, int valor ){
	No *novo = (No*) malloc(sizeof(No));

	if (novo == NULL)
		return 0;
	
    novo->dado = valor;
    novo->prox = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    }
    else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
    fila->tam++;
    return 1;					
}

int retira (Fila * fila) {
    No *aux = fila->inicio;
    int rem = aux->dado;
    fila->inicio = aux->prox;
    free(aux);
    fila->tam--;
    return rem; 
}

void apresentaFila(Fila *fila)
{
     No *aux;
     aux = fila->inicio;
     printf("============== FILA ==============\n");
     while(aux != NULL){
         printf ("Dado = %3d\n", (aux->dado));
       	aux = aux->prox;
	 }
     printf("=============== FIM ==============\n");
}

void soma(Fila *fila)
{
     No *aux;
     aux = fila->inicio;
     int s=0;
     printf("============== FILA ==============\n");
     while(aux != NULL){
         printf ("Dado = %3d\n", (aux->dado));
         s=s+aux->dado;
       	aux = aux->prox;
	 }
     printf("Soma = %d\n",s);
}

void duplicarPrimeiroElemento(Fila *f){
    No *novo = malloc(sizeof(No));
    novo->dado = f->inicio->dado;
    novo->prox = f->inicio->prox;
    f->inicio->prox = novo;
}

void duplicarPrimeiroElementoGuilherme(Fila *f){
    if(f == NULL)
        return;

    int tamanho = f->tam;
    int primeiro;

    for(int i = 0; i<tamanho; i++){
        int valor = retira(f);
        if(i == 0){
            primeiro = valor;
        
            insere(f, primeiro);
            insere(f, primeiro);
        }else{
            insere(f, valor);
        }
    }
}

void duplicarPrimeiroElementoMaria(Fila *f){
    No *novo = malloc(sizeof(No));
    novo->dado = f->inicio->dado;
    novo->prox = f->inicio->prox;
    f->inicio->prox = novo;
}


void duplicarPrimeiroElementoFelipe(Fila *f){

    if(f->tam == 0)
        return;
    
    
    No *aux = f->inicio;
    int temp = aux->dado;
    aux = aux->prox;
    while (aux != NULL)
    {
        int temp2 = aux->dado;
        aux->dado = temp;
        temp = temp2;
        aux = aux->prox;
    }
    insere(f, temp);
}

void retiran(Fila *fila,int q)
{
     int i;
	 if(q>fila->tam)
     	printf("\nPosição invalida");
    else
    	{
    		for(i=0;i<q;i++)
    			{
    				retira(fila);
				}
		}
}





int main(){
    struct fila f;
    inicia(&f);
    insere(&f,10);
    insere(&f,7);
    insere(&f,8);
    insere(&f,1);
    insere(&f,4);
    //soma(&f);
    
    //retiran(&f,3);
    apresentaFila(&f);
    
    duplicarPrimeiroElementoGuilherme(&f);

    apresentaFila(&f);
    
    /*apresentaFila(&f);
    getchar();
    
    printf("retira = %d\n",retira(&f));
    apresentaFila(&f);
    getchar();

    printf("retira = %d\n",retira(&f));
    apresentaFila(&f);
    getchar();

    printf("retira = %d\n",retira(&f));
    apresentaFila(&f);
    getchar();

    printf("retira = %d\n",retira(&f));
    apresentaFila(&f);
    getchar();
    */
}
