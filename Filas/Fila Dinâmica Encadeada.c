#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20
// FILA DINAMICA
typedef struct Carro{
  int ano;  
  double motor;
  char modelo[TAM];
}Carro;
typedef struct Elemento{
  struct Carro dado;
  struct Elemento *proximo;
}Elemento;
typedef struct{
  Elemento *inicio;
  Elemento *fim;
  int quantidade;
}Fila;
// CRIA FILA
Fila* cria_fila(){
  Fila* fi = (Fila*) malloc(sizeof(Fila));
  if(fi != NULL){
    fi->inicio = NULL;
    fi->fim = NULL;
    fi->quantidade = 0; 
  } 
  return fi;
}
// LIBERA FILA
void libera_fila(Fila *fi){
  if(fi != NULL){
    Elemento* no;
    while(fi->inicio != NULL){
      no = fi->inicio;
      fi->inicio = fi->inicio->proximo;
      free(no);
    }
    free(fi);
  }
}
// LIBERA FILA
int tamanho_fila(Fila *fi){
  if(fi != NULL){
    return 0;
  }else{
    return fi->quantidade;
  }    
}
// IMPRIME FILA
void imprime_fila(Fila* fi){
    Elemento* no = fi->inicio;
    while(no != NULL){  
      printf("%d\n",no->dado.ano);
      printf("%.1f\n",no->dado.motor);
      printf("%s\n\n",no->dado.modelo);
      no =no->proximo;
    }
    printf("\n");
}
// LISTA VAZIA
int fila_vazia(Fila* fi){
  if(fi->inicio == NULL && fi->fim == NULL){
    printf("Fila vazia!\n");
    return 1;
  }else{
    return 0;
  }
}
// INSERE INICIO
int insere_fila(Fila* fi, struct Carro c){
  Elemento* no = (Elemento*) malloc(sizeof(Elemento));
  if(no == NULL){
    return 0;
  }
  no->dado = c;
  printf("Ano: ");
  scanf("%d",&c.ano);
  printf("Motor: ");
  scanf("%lf",&c.motor);
  printf("Modelo: ");
  scanf("%s",c.modelo);
  no->proximo = NULL;
  if(fi->fim == NULL){
    fi->inicio = no;
  }else{
    fi->fim->proximo = no;
  }
  fi->fim = no;
  fi->quantidade++;
  return 1;
  }
// REMOVE FILA
void remove_fila(Fila* fi){
  Elemento *no = fi->inicio; 
  fi->inicio = fi->inicio->proximo;
  if(fi->inicio == NULL){
    fi->fim = NULL;
  }
  fi->quantidade--;
  free(no);
}
// IMPRIME MENU
void imprime_menu(int *opcao){
  printf("\n======= MENU =======\n");
  printf("(1) Inserir\n");
  printf("(2) Excluir\n");
  printf("(3) Mostra\n");
  printf("(4) Sair\n");
  printf("(5) Limpa tela\n");
  printf("Informe a opcao desejada: ");
  scanf("%d",&(*opcao));
}
// MAIN
int main(){
  Fila *fi;
  struct Carro c;
  fi = cria_fila();
  int opcao, escolha, num, dado;
  while(opcao != 4){
    imprime_menu(&opcao);
    switch (opcao){
      case 1:
        printf("\n== CADASTRA CARRO ==\n");
          insere_fila(fi, c);
      break;
      case 2:
        if(fila_vazia(fi)){
        
        }else{
          remove_fila(fi);
        }
      break;
      case 3:
        printf("\n== MOSTRAR CARRO ==\n");
          imprime_fila(fi);
      break;
      case 4:
        system("clear");
        printf("\n== FIM DO PROGRAMA ==\n");
      break;
      case 5:
        system("clear");
      break;
      default:
        printf("\nOpcao invalida!\n");
      break;
    }
  }
  libera_fila(fi);
  return 0;
}