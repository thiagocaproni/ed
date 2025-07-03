#include <stdio.h>
#include <stdlib.h>

 struct node {   
  int dado;   
  struct node *prox;
  struct node *ant;   
};

struct Lista{
  struct node *inicio;
	struct node *fim;
} Lista;

void somarAnteriorPosterior(struct Lista *lista, int valor);
void inicializar(struct Lista *lista);
int inserirInicio(struct Lista *lista, int dado);
int inserirFim(struct Lista *lista, int dado);
int mostrar(struct Lista lista);
int remover(struct Lista *lista, int dado);
int menu();

int main(){

  struct Lista lista;
  inicializar(&lista);	


  inserirFim(&lista, 0);
  inserirFim(&lista, 2);
  inserirFim(&lista, 4);
  inserirFim(&lista, 6);
  inserirFim(&lista, 8);

  mostrar(lista);  

  somarAnteriorPosterior(&lista, 4);
  somarAnteriorPosterior(&lista, 6);

  
  mostrar(lista);  




	
	return 0;
}

void somarAnteriorPosterior(struct Lista *lista, int valor) {
    struct node *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->dado == valor && atual->ant != NULL && atual->prox != NULL) {
            atual->dado = atual->ant->dado + atual->prox->dado;
        }
        atual = atual->prox;
    }
}


void inicializar (struct Lista *lista){   
  lista->inicio = NULL;   
  lista->fim = NULL;   
}   

int inserirInicio(struct Lista *lista, int dado){
	struct node  *novo = malloc(sizeof(struct node));
	
	if(novo == NULL)
		return 0;

	novo->dado = dado;	
	
	if(lista->inicio == NULL){
		lista->inicio = novo;
		lista->fim = novo;
		novo->prox = NULL;
    novo->ant  = NULL;
	}else{
		novo->prox = lista->inicio;
    lista->inicio->ant = novo;
    novo->ant = NULL;
		lista->inicio = novo;
	}

	return 1;
}

int inserirFim(struct Lista *lista, int dado){
	struct node  *novo = malloc(sizeof(struct node));
  if(novo == NULL)
		return 0;
	
  novo->dado = dado;	
	
	if(novo == NULL)
		return 0;

	if(lista->inicio == NULL){
		lista->inicio = novo;
		lista->fim = novo;
		novo->prox = NULL;
    novo->ant  = NULL;
	}else{
		lista->fim->prox = novo;
    novo->ant = lista->fim;
    novo->prox = NULL;
		lista->fim = novo;
	}

	return 1;
}

int remover(struct Lista *lista, int dado){
	struct node *aux;
	int qtdDel = 0;
	
	aux = lista->inicio;

	while(aux != NULL){
		if(aux->dado == dado){
			qtdDel++;
			if(aux == lista->inicio){
				lista->inicio = aux->prox;
        if(lista->inicio != NULL){
          lista->inicio->ant = NULL;
        }
				free(aux);
				aux = lista->inicio;
			}else if(aux == lista->fim){
				lista->fim = lista->fim->ant;
        lista->fim->prox = NULL;
				free(aux);
				aux = NULL;
			}else{
			  aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        struct node *aux2;
        aux2 = aux->prox;
				free(aux);
				aux = aux2;
			}
		}else{
			aux = aux->prox;
		}
	}
	
	return qtdDel;
}

int mostrar(struct Lista lista){
	struct node *aux;	
	
	if(lista.inicio == NULL){
		return 0;	
	}else{
		aux = lista.inicio;
		while(aux != NULL){
			printf("%d ", aux->dado);
			aux = aux->prox;
		}
	}
  printf("\n");
	return 1;
}