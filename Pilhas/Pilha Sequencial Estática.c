#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3
// PILHA
typedef struct Pilha{
  int elementos[TAM];
  int quantidade, topo;
}Pilha;
Pilha pi;
// INSERE PILHA
void insere_pilha(){
  int numero;
  printf("\n===== INSERIR =====\n");
  printf("Informe um numero: ");
  scanf("%d",&numero);
  pi.elementos[pi.quantidade] = numero;
  pi.topo++;
  pi.quantidade++;
}
// REMOVE PILHA
void remove_pilha(){
  pi.topo--;
  pi.quantidade--;
}
// BUSCA PILHA
void busca_pilha(){
  printf("Topo contém: %d\n",pi.elementos[pi.topo]);
}
// IMPRIME PILHA
void imprime_pilha(){
  for(int j = pi.topo; j >=0 ; j--){
    printf("%3d\n",pi.elementos[j]); 
  } 
}
// PILHA CHEIA
int pilha_cheia(Pilha *pi){
  if(pi == NULL){
    return -1;
  }else{
   return (pi->quantidade == TAM);
  }
}
// PILHA VAZIA
int pilha_vazia(Pilha *pi){
  if(pi == NULL){
    return -1;
  }else{
    return (pi->quantidade == 0);
  }
}
// IMPRIME MENU
void ImprimeMenu(int *opcao){
  printf("\n======= MENU =======\n");
  printf("(1) Push\n");
  printf("(2) Pop\n");
  printf("(3) Top\n");
  printf("(4) See\n");
  printf("(5) Out\n");
  printf("(6) Clear\n");
  printf("Informe a opcao desejada: ");
  scanf("%d",&(*opcao));
}
// FUNCOES MENU
void FuncoesMenu(int opcao){
  int escolha;
  switch (opcao){
    case 1:
      if(pilha_cheia(&pi)){
        printf("Pilha cheia!\n");
      }else{
        insere_pilha();        
      }
    break;
    case 2:
      if(pilha_vazia(&pi)){
        printf("Pilha vazia!\n");  
      }else{
        remove_pilha();
      }
    break;
    case 3:
      if(pilha_vazia(&pi)){
        printf("Pilha vazia!\n");  
      }else{
        busca_pilha();
      }
    break;
    case 4:
      if(pilha_vazia(&pi)){
        printf("Pilha vazia!\n");  
      }else{
        imprime_pilha();
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
  pi.topo = -1;
  pi.quantidade = 0;
  while(opcao != 5){
    ImprimeMenu(&opcao);
    FuncoesMenu(opcao);
  }
  return 0;
}