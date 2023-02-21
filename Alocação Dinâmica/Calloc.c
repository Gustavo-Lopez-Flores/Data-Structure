#include <stdio.h>
#include <stdlib.h>
// MAIN
int main(){
  int i, *p;

  // Inicializa os BYTES do espaco alocado com 0's 
  // int *p = (50,4)

  p = (int*) calloc(50, sizeof(int));

  // Verificando se há memória suficiente
  if(p == NULL){
    printf("Memoria insuficiente!\n");
    exit(1);
  }

  // Usa-se (p) como vetor:
  for(i=0;i<5;i++){
    scanf("%d",&p[i]);
  }

  for(i=0;i<5;i++){
    printf("\n%d",p[i]);
  }

  // Liberando a memoria manualmente:
  free(p);
  return 0;
}