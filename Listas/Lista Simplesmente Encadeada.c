#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define TAM 15
// LISTA DINAMICA
struct Carro{
  int ano;
  float motor;
  char modelo[TAM];
};
typedef struct Elemento{
  struct Carro dados;
  struct Elemento *proximo;
}Elemento;
typedef struct Elemento *Lista;
// CRIA LISTA
Lista* cria_lista(){
  Lista* li = (Lista*) malloc(sizeof(Lista));
  if(li == NULL){
    printf("Nao foi possivel criar a lista\n");
  }else{
    *li = NULL;
  }
  return li;
}
// LIBERA LISTA
void libera_lista(Lista *li){
  if(li != NULL){
    Elemento* no;
    while((*li)!=NULL){
      no = *li;
      *li = (*li)->proximo;
      free(no);
    }
    free(li);
  }
}
// TAMANHO LISTA
int tamanho_lista(Lista* li){
  if(li == NULL){
    return 0;
  }else{
    int cont = 0;
    Elemento* no = *li;
    while(no != NULL){
      cont++;
      no = no->proximo;
    }
    return cont;
  }
}
// LISTA VAZIA
int lista_vazia(Lista* li){
  if(li == NULL){
    return 1;
  }
  if(*li == NULL){
    return 1;
  }
  return 0;
}
// IMPRESSAO LISTA
void imprime_lista(Lista *li){
  if(li != NULL){
    int cont = 1;
    Elemento* no = *li;
    system("clear");
    while(no != NULL){
      printf("--- Carro %d ---\n",cont);
      printf("Ano: %d\n",no->dados.ano);
      printf("Motor: %.1f\n",no->dados.motor);
      printf("Modelo: %s\n\n",no->dados.modelo);
      no = no->proximo;
      cont++;
    }
    printf("\n");
  }else{
    printf("...nao ha carros\n");
  }
}
// INSERCAO INICIO
void insere_inicio(Lista* li, struct Carro c){
  if(li == NULL){ // cabeca de lista
    return;
  }else{
    Elemento* no;
    no = (Elemento*) malloc(sizeof(Elemento));
    no->dados = c;
    no->proximo = *li;
    *li = no;
  }
}
// INSERCAO FIM
void insere_fim(Lista* li, struct Carro c){
  int posicao_atual = 1, tamanho = tamanho_lista(li);
  if(tamanho == 0){
    insere_inicio(li, c);
  }
  Elemento *no_novo, *no_percorre;
  no_percorre = (*li);
  no_novo = (Elemento*) malloc(sizeof(Elemento));
  no_novo->dados = c;
  no_novo->proximo = NULL;
  while(posicao_atual < tamanho){
    no_percorre = no_percorre->proximo;
    posicao_atual++;
  }
  no_novo->proximo = no_percorre->proximo;
  no_percorre->proximo = no_novo;
}
// INSERCAO MEIO
void insere_meio(Lista* li, struct Carro c, int posicao){
  if (li == NULL) {
    puts("Lista nao foi criada!");
    return;
  }
  
  int posicao_atual = 0;
  Elemento *no_percorre, *no_novo;
  no_percorre = *li;

  no_novo = (Elemento*) malloc (sizeof(Elemento));
  no_novo->dados = c;

  while (posicao_atual < posicao) {
      no_percorre = no_percorre->proximo;
      posicao_atual++;
  }
  no_novo->proximo = no_percorre->proximo;
  no_percorre->proximo = no_novo;
}
// REMOVE INICIO
void remove_inicio(Lista* li){
  if(lista_vazia(li)){
    return;
  }else{
    Elemento* no = *li;
    *li = (*li)->proximo;
    free(no);
    printf("...carro removido\n");
  }
}
// REMOVE MEIO
void remove_meio(Lista* li, int posicao){
  if(lista_vazia(li)){
    return;
  }else{
    int posicao_atual = 1;  
    Elemento *ant, *no = *li;
    while(posicao_atual < posicao){
      ant = no;
      no = no->proximo;
      posicao_atual++;
    }
    ant->proximo = no->proximo;
    free(no);
    printf("...carro removido\n");
  }
}
// REMOVE FIM
void remove_fim(Lista* li){
  if(lista_vazia(li)){
    return;
  }else{
    int posicao_atual = 1, tamanho = tamanho_lista(li);
    if(tamanho == 1){
      remove_inicio(li);
      return;
    }else{
      Elemento *no = *li;
      while(posicao_atual < (tamanho-1)){
        no = no->proximo;
        posicao_atual++;
      }
      free(no->proximo);
      no->proximo = NULL;
      printf("...carro removido\n");
    }
  }
}
// BUSCA POSICAO
void busca_posicao(Lista* li, int posicao){
  if(li == NULL || posicao <= 0){
    return;
  }
  Elemento *no = *li;
  int cont = 1, i = 1;
  while(no != NULL && i < posicao){
    no = no->proximo;
    i++;
  }
  if(no == NULL){
    printf("...elemento nao existe\n");
    return;
  }else{
    printf("\n--- Carro %d ---\n", cont);
    printf("Ano: %d\n",no->dados.ano);
    printf("Motor: %.1f\n",no->dados.motor);
    printf("Modelo: %s\n",no->dados.modelo);
    return;
  }
}
// BUSCA ELEMENTO
void busca_elemento(Lista* li, int dado){
  if(li == NULL){
    return;
  }
  int cont = 1;
  Elemento *no = *li;
  while(no != NULL && cont < tamanho_lista(li)){
    if(no->dados.ano == dado){
      printf("\n--- Carro %d ---\n", cont);
      printf("Ano: %d\n",no->dados.ano);
      printf("Motor: %.1f\n",no->dados.motor);
      printf("Modelo: %s\n",no->dados.modelo);
    }
    no = no->proximo;
    cont++;
  }
  if(no == NULL){
    printf("...elemento nao existe\n");
    return;
  }
}
// IMPRIME MENU
void imprime_menu(int *opcao){
  printf("\n======= MENU =======\n");
  printf("(1) Inserir\n");
  printf("(2) Excluir\n");
  printf("(3) Buscar\n");
  printf("(4) Imprimir\n");
  printf("(5) Tamanho\n");
  printf("(6) Sair\n");
  printf("(7) Limpa tela\n");
  printf("Informe a opcao desejada: ");
  scanf("%d",&(*opcao));
}
// OPCOES BASE
void opcoes_base(int *escolha){
  printf("(1) Inicio\n");
  printf("(2) Meio\n");
  printf("(3) Fim\n");
  printf("Informe a opcao desejada: ");
  scanf("%d",&(*escolha));
} 
// OPCOES BUSCA
void opcoes_busca(int *escolha){
  printf("(1) Elemento\n");
  printf("(2) Posicao\n");
  printf("Informe a opcao desejada: ");
  scanf("%d",&(*escolha));
}
// CARRO
struct Carro leitura(struct Carro c){
  printf("\n=== DADOS DO CARRO ===\n");
  printf("Ano: ");
  scanf("%d",&c.ano);
  printf("Motor: ");
  scanf("%f",&c.motor);
  printf("Modelo: ");
  scanf("%s",c.modelo);
  return c;
}
// MAIN
int main () {
  int opcao, escolha, posicao, elemento;
  Lista* li = cria_lista();
  struct Carro c;
  while(opcao != 6){
    imprime_menu(&opcao);
    switch(opcao){
      case 1: 
        system("clear");
        printf("\n===== INSERIR =====\n");
        opcoes_base(&escolha);
        switch(escolha){
          case 1: 
            c = leitura(c);
            insere_inicio(li, c);
          break;
          case 2:
            printf("Informe a posicao desejada (1 - %d): ",tamanho_lista(li)+1);
            scanf("%d",&posicao);
            posicao--;
            if(posicao < 0 || posicao > tamanho_lista(li)){
              printf("Posicao invalida!\n");
            }else{
              c = leitura(c);
              insere_meio(li, c, posicao);
            }
          break;
          case 3:
            c = leitura(c);
            insere_fim(li, c);
          break;
          default:
            printf("Opcao invalida!\n");  
          break;
        }
      break;
      case 2: 
        if(lista_vazia(li)){
          printf("\nLista vazia!\n");
        }else{
          system("clear");
          printf("\n===== REMOVER =====\n");
          opcoes_base(&escolha);
          switch(escolha){
            case 1: 
              remove_inicio(li);
            break;
            case 2:
            printf("Informe a posicao desejada (1 - %d): ",tamanho_lista(li));
              scanf("%d",&posicao);
              posicao--;
              if(posicao < 0 || posicao > tamanho_lista(li)){
                printf("Posicao invalida!\n");
              }else{
                remove_meio(li, posicao);
              }
            break;
            case 3:
              remove_fim(li);
            break;
            default:
              printf("Opcao invalida!\n");  
            break;
          }
        }
      break;
      case 3:
        if(lista_vazia(li)){
          printf("\nLista vazia!\n");
        }else{
          system("clear");
          printf("\n===== BUSCAR =====\n");
          opcoes_busca(&escolha);
          switch(escolha){
          case 1: 
            printf("Informe o ano: ");
            scanf("%d",&elemento);
            busca_elemento(li, elemento);
          break;
          case 2:
            printf("Informe a posicao desejada (1 - %d): ",tamanho_lista(li));
            scanf("%d",&posicao);
            posicao--;
            if(posicao < 0 || posicao > tamanho_lista(li)){
              printf("Posicao invalida!\n");
            }else{
              busca_posicao(li, posicao);
            }
          break;
          default:
            printf("Opcao invalida!\n");  
          break;
        }
        }
      break;
      case 4:
        if(lista_vazia(li)){
          printf("\nLista vazia!\n");
        }else{
          imprime_lista(li);          
        }
      break;
      case 5:
        system("clear");
        printf("\n==== TAMANHO ====\n");
        printf("Lista possui %d elemento(s)\n",tamanho_lista(li));
      break;
      case 6:
        system("clear");
        printf("==== FIM DO PROGRAMA ====\n");
      break;
    }
  }
  return(0);
}