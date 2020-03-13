/* Data de submissao: 13/03/2020
 * Nome: Marcos Gabriel Barboza Dure Diaz
 * RA: 221525
 */

#include <stdio.h>
#include <stdlib.h>
const int tam_buffer=100;

typedef struct{
	int top;
	char* v;
	int tamanho;
} pilha, *Pilha;

void iniciar_pilha(Pilha p, int tamanho){
	p->v= malloc(tamanho*sizeof(char));
	p->top=0;
	p->tamanho=tamanho;
}

void destruir_pilha(Pilha p){
	free(p->v);
}

void empilhar(Pilha p, char x){
	if ((p->top) < (p->tamanho))
		p->v[p->top++]=x;
	else
		printf("Pilha cheia\n");
}

char desempilhar(Pilha p){
	if ((p->top)>0)
		return p->v[--p->top];
	else
		printf("Pilha vazia\n");
}

int main(){
  char buffer[tam_buffer];
  fgets(buffer, tam_buffer, stdin);
  int i=0, j, k;
  int tamanho=0;
  while(buffer[i]!='\n'){
	  	if (buffer[i]==' ')
			i++;
		//contar letras
  		while((buffer[i]!=' ')&&(buffer[i]!='\n')){
			tamanho++;
			i++;
		}
		//criar pilha
		pilha a;
		Pilha pa = &a;
		iniciar_pilha(pa, tamanho);
		//empilhar
		for(k=0;k<tamanho;k++){
			empilhar(pa, buffer[i-tamanho+k]);
		}
		//desempilhar
		for(j=0;j<pa->tamanho;j++){
			buffer[i-tamanho+j]=desempilhar(pa);
		}
		//destruir a pilha
		destruir_pilha(pa);
		tamanho=0;
  }
  fputs(buffer, stdout);
  return 0;
}
