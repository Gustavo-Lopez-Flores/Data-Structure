#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3
// FILA
typedef struct Fila{
  int elementos[TAM];
  int inicio, fim;
  int quantidade;
}Fila;
Fila fi;
// INSERE FILA
void insere_fila(){
  int numero;
  printf("\n===== INSERIR =====\n");
  printf("Informe um numero: ");
  scanf("%d",&numero);
  fi.elementos[fi.fim] = numero;
  fi.fim=(fi.fim+1)%TAM;
  fi.quantidade++;
}
// REMOVE FILA
void remove_fila(){
  fi.inicio=(fi.inicio+1)%TAM;
  fi.quantidade--;
}
// BUSCA FILA
void busca_fila(){
  printf("Inicio contém: %d\n",fi.elementos[fi.inicio]);
}
// IMPRIME FILA
void imprime_fila(){
  int i = fi.inicio;
  for(int j = 0; j < fi.quantidade; j++){
    printf("%3d",fi.elementos[i]); 
    i = (i+1)%TAM;
  }
  printf("\n"); 
}
// FILA CHEIA
int fila_cheia(Fila *fi){
  if(fi == NULL){
    return -1;
  }else{
   return (fi->quantidade == TAM);
  }
}
// FILA VAZIA
int fila_vazia(Fila *fi){
  if(fi == NULL){
    return -1;
  }else{
    return (fi->quantidade == 0);
  }
}
// IMPRIME MENU
void ImprimeMenu(int *opcao){
  printf("\n======= MENU =======\n");
  printf("(1) Inserir\n");
  printf("(2) Excluir\n");
  printf("(3) Buscar\n");
  printf("(4) Imprime\n");
  printf("(5) Sair\n");
  printf("(6) Limpar tela\n");
  printf("Informe a opcao desejada: ");
  scanf("%d",&(*opcao));
}
// FUNCOES MENU
void FuncoesMenu(int opcao){
  int escolha;
  switch (opcao){
    case 1:
      if(fila_cheia(&fi)){
        printf("Fila cheia!\n");
      }else{
        insere_fila();        
      }
    break;
    case 2:
      if(fila_vazia(&fi)){
        printf("Fila vazia!\n");  
      }else{
        remove_fila();
      }
    break;
    case 3:
      if(fila_vazia(&fi)){
        printf("Fila vazia!\n");  
      }else{
        busca_fila();
      }
    break;
    case 4:
      if(fila_vazia(&fi)){
        printf("Fila vazia!\n");  
      }else{
        imprime_fila();
      }
    break;
    case 5:
      system("clear"); // LINUX - REPLIT
      printf("\n== FIM DO PROGRAMA ==\n");
    break;
    case 6:
      system("clear"); // LINUX - REPLIT1
    break;
    default:
      printf("\nOpcao invalida!\n");
    break;
  }
}
// MAIN
int main(){
  int opcao;
  fi.inicio = 0;
  fi.fim = 0;
  fi.quantidade = 0;
  while(opcao != 5){
    ImprimeMenu(&opcao);
    FuncoesMenu(opcao);
  }
  return 0;
}