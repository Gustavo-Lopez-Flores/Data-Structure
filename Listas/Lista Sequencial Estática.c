#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 64
// LISTA
typedef struct Lista{
  int elementos[TAM];
  int quantidadeElementos;
}Lista;
Lista li;
//INSERINDO NO FINAL
void insere_lista_final(){
  int numero;
  printf("Informe um numero: ");
  scanf("%d",&numero);
  li.elementos[li.quantidadeElementos] = numero;
  li.quantidadeElementos++;
}
// INSERINDO NO INICIO
void insere_lista_inicio(){
  int numero;
  printf("Informe um numero: ");
  scanf("%d",&numero);
  if(lista_vazia(li)){
    li.elementos[li.quantidadeElementos] = numero;
    li.quantidadeElementos++;
  }else{
    for(int i=(li.quantidadeElementos - 1); i >= 0; i--){
      li.elementos[i+1] = li.elementos[i];
    }
    li.elementos[0] = numero;
    li.quantidadeElementos++;
  }
}
// INSERINDO NO MEIO
void insere_lista_meio(){
  int numero, p;
  printf("Informe o numero: ");
  scanf("%d",&numero);
  printf("Informe a posicao(1..N): ");
  scanf("%d",&p);
  if(p <= 0 || p > li.quantidadeElementos){
    printf("Posicao invalida!\n");
  }else{
    if(lista_vazia(li)){
      li.elementos[li.quantidadeElementos] = numero;
      li.quantidadeElementos++;
    }else{
      for(int k=(li.quantidadeElementos - 1);k>=p-1;k--){
        li.elementos[k+1] = li.elementos[k];    
      }
      li.elementos[p-1] = numero;
      li.quantidadeElementos++;
    }
  }

}
// INSERE LISTA
void insere_lista(){
  int escolha;
  printf("\n===== INSERIR =====\n");
  printf("(1) Inserir no inicio\n");
  printf("(2) Inserir no meio\n");
  printf("(3) Inserir no fim\n");
  printf("Informe a opcao desejada: ");
  scanf("%d",&escolha);
  switch (escolha){
    case 1:
      insere_lista_inicio();
    break;
    case 2:
      insere_lista_meio();
    break;
    case 3:
      insere_lista_final();
    break;
    default:
      printf("\nOpcao invalida!\n");
    break;
  }
}
// REMOVENDO NO FINAL
void remove_lista_final(){
  li.quantidadeElementos--;
}
// REMOVENDO NO INICIO
void remove_lista_inicio(){
  for(int k=0; k<(li.quantidadeElementos - 1); k++){
    li.elementos[k] = li.elementos[k+1];
  }
  li.quantidadeElementos--;
}
// REMOVENDO NO MEIO
void remove_lista_meio(){
  int k, p, i=0;
  printf("Informe a posicao(1..N): ");
  scanf("%d",&p);
  if(p<=0 || p > li.quantidadeElementos){
    printf("Posicao invalida!\n");
  }else{
    while(i<li.quantidadeElementos && li.elementos[i] != p)
      i++;
    if(i==li.quantidadeElementos)
      return 0;
    for(k=i;k<(li.quantidadeElementos - 1);k++){
      li.elementos[k] = li.elementos[k+1];
    }
    li.quantidadeElementos--;    
  }
}
// REMOVE LISTA
void remove_lista(){
  int escolha;
  printf("\n===== REMOVER =====\n");
  printf("(1) Remover no inicio\n");
  printf("(2) Remover no meio\n");
  printf("(3) Remover no fim\n");
  printf("Informe a opcao desejada: ");
  scanf("%d",&escolha);
  switch (escolha){
    case 1:
      remove_lista_inicio();
    break;
    case 2:
      remove_lista_meio();
    break;
    case 3:
      remove_lista_final();
    break;
    default:
      printf("\nOpcao invalida!\n");
    break;
  }
}
// BUSCA POSICAO
void busca_posicao(){
  int p;
  printf("Informe a posicao: ");
  scanf("%d",&p);
  if(p<=0 || p>li.quantidadeElementos){
    printf("Nao esta na lista!\n");
  }else{
    printf("Elemento %d contém %d\n",p,li.elementos[p-1]); 
  }
}
// BUSCA ELEMENTO
void busca_elemento(){
  int k, p, i=0;
  printf("Informe o conteudo: ");
  scanf("%d",&p);
  while(i<li.quantidadeElementos && li.elementos[i] != p){
    i++;
  }
  if(i == li.quantidadeElementos)
    printf("Elemento não encontrado\n");
  else
    printf("Elemento %d contém %d\n",i+1,li.elementos[i]);
}
// BUSCA LISTA
void busca_lista(){
  int escolha;
  printf("\n===== INSERIR =====\n");
  printf("(1) Buscar por posicao\n");
  printf("(2) Buscar por elemento\n");
  printf("Informe a opcao desejada: ");
  scanf("%d",&escolha);
  switch (escolha){
    case 1:
      busca_posicao();
    break;
    case 2:
      busca_elemento();
    break;
    default:
      printf("\nOpcao invalida!\n");
    break;
  }
}
// LISTA CHEIA
int lista_cheia(Lista *li){
  if(li == NULL){
    return -1;
  }else{
   return (li->quantidadeElementos == TAM);
  }
}
// LISTA VAZIA
int lista_vazia(Lista *li){
  if(li == NULL){
    return -1;
  }else{
    return (li->quantidadeElementos == 0);
  }
}
// LISTAR ELEMENTOS
void listar_elementos(){
  for(int i=0; i<(li.quantidadeElementos); i++){
    printf("%d ",li.elementos[i]);
  }
  printf("\n");
}
// IMPRIME MENU
void ImprimeMenu(int *opcao){
  printf("\n======= MENU =======\n");
  printf("(1) Inserir\n");
  printf("(2) Excluir\n");
  printf("(3) Buscar\n");
  printf("(4) Listagem\n");
  printf("(5) Sair\n");
  printf("(6) Limpa tela\n");
  printf("Informe a opcao desejada: ");
  scanf("%d",&(*opcao));
}
// FUNCOES MENU
void FuncoesMenu(int opcao){
  int escolha;
  switch (opcao){
    case 1:
      if(lista_cheia(&li)){
        printf("Lista cheia!\n");
      }else{
        insere_lista();        
      }
    break;
    case 2:
      if(lista_vazia(&li)){
        printf("Lista vazia!\n");  
      }else{
        remove_lista();
      }
    break;
    case 3:
      if(lista_vazia(&li)){
        printf("Lista vazia!\n");  
      }else{
        busca_lista();
      }
    break;
    case 4:
      if(lista_vazia(&li)){
        printf("Lista vazia!\n");  
      }else{
        listar_elementos();
      }
    break;
    case 5:
      printf("\n== FIM DO PROGRAMA ==\n");
    break;
    case 6:
      system("clear");
    break;
    default:
      printf("\nOpcao invalida!\n");
    break;
  }
}
// MAIN
int main(){
  int opcao;
  li.quantidadeElementos = 0;
  while(opcao != 5){
    ImprimeMenu(&opcao);
    FuncoesMenu(opcao);
  }
  return 0;
}