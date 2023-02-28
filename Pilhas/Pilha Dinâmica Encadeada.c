#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20
// PILHA DINAMICA
struct Carro{
  int ano;  
  double motor;
  char modelo[TAM];
};
typedef struct Elemento{
  struct Carro dado;
  struct Elemento *proximo;
}Elemento;
typedef struct Elemento* Pilha;
// CRIA PILHA
Pilha* cria_pilha(){
  Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
  if(pi != NULL){
    pi = NULL;
  }
  return pi;
}
// LIBERA PILHA
void libera_pilha(Pilha* pi){
  if(pi != NULL){
    Elemento* no;
    while((*pi) != NULL){
      no = *pi;
      *pi = (*pi)->proximo;
      free(no);
    }
    free(pi);
  }
}
// LIBERA PILHA
int tamanho_pilha(Pilha* pi){
  int cont = 0;
  Elemento* no = *pi;
  while(no != NULL){
    cont++;
    no = no->proximo;
  }
  return cont;
}
// PILHA VAZIA
int pilha_vazia(Pilha* pi){
  if(pi == NULL || *pi == NULL){
    printf("Pilha vazia!\n");
    return 1;
  }else{
    return 0;
  }
}
// PUSH
int push(Pilha* pi, struct Carro c){
  Elemento *no; 
  no = (Elemento*) malloc(sizeof(Elemento));
  if(no == NULL){
    printf("Nao foi possivel!\n");
    return -1;
  }else{
    no->dado = c;
    no->proximo = (*pi);
    *pi = no;
    return 0;
  }
}
// POP
void pop(Pilha* pi){
  Elemento *no = *pi;
  *pi = no->proximo;
  free(no);
}
// TOP
int top(Pilha* pi, struct Carro *c){
  *c = (*pi)->dado;
  return 0;

}
// IMPRIME PILHA
void imprime_pilha(Pilha* pi){
  Elemento *no = *pi;
  while(no != NULL){
    printf("Ano: %d\n",no->dado.ano);
    printf("Motor: %lf\n",no->dado.motor);  
    printf("Modelo: %s\n\n",no->dado.modelo);  
    no = no->proximo; 
  }
}
// IMPRIME MENU
void imprime_menu(int *opcao){
  printf("\n======= MENU =======\n");
  printf("(1) Push\n");
  printf("(2) Pop\n");
  printf("(3) Top\n");
  printf("(4) Stack\n");
  printf("(5) Lenght\n");
  printf("(6) Out\n");
  printf("(7) Clear\n");
  printf("Informe a opcao desejada: ");
  scanf("%d",&(*opcao));
}
// MAIN
int main(){
  int x;
  Pilha *pi = cria_pilha();
  struct Carro c;
  int opcao, escolha;
  while(opcao != 6){
    imprime_menu(&opcao);
    switch (opcao){
      case 1:
        printf("\n== PUSH ==\n");
        int x = push(pi, c);
      break;
      case 2:
        printf("\n== POP ==\n");
        if(pilha_vazia(pi)){
        }else{
          pop(pi);
        }
      break;
      case 3:
        printf("\n== TOP ==\n");
        if(pilha_vazia(pi)){
        }else{
          int x = top(pi, &c);
        }
      break;
      case 4:
        printf("\n== STACK ==\n");
        if(pilha_vazia(pi)){
        }else{
          imprime_pilha(pi);
        }
      break;
      case 5:
        printf("\n== LENGHT ==\n");
        if(pilha_vazia(pi)){
        }else{
          printf("%d\n",tamanho_pilha(pi));
        }
      break;
      case 6:
        system("clear");
        printf("\n== FIM DO PROGRAMA ==\n");
      break;
      case 7:
        system("clear");
      break;
      default:
        printf("\nOpcao invalida!\n");
      break;
    }
  }
  return 0;
}