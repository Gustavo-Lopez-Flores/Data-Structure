#include <stdio.h>
#include <stdlib.h>

int main(){
  int i, *p;
  
  // Passando tamanho em bytes
  // int *p = (200)

  p = (int*) malloc(5 * sizeof(int));
  
  // Verificando se há memória suficiente
  if(p == NULL){
    printf("Memoria insuficiente!\n");
    exit(1);
  }

  // Usa-se (p) como vetor:
  for(i=0; i<5; i++){
    scanf("%d",&p[i]);
  }

  for(i=0; i<5; i++){
    printf("\n%d",p[i]);
  }
  
  // Liberando a memória manualmente:
  free(p);
  return 0;
}