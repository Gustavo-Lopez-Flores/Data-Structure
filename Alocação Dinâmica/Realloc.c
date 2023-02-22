#include <stdio.h>
#include <stdlib.h>
// MAIN
int main(){
  int i, *p;
  // Realoca (Altera) o tamanho da memória
  p = (int*) malloc(200);
  // Equivale a: p = (int*) realloc(NULL, 50*sizeof(int));

  // Aumentando de 200 bytes (50 inteiros) para 400 bytes (100 inteiros)
  p = (int*) realloc(p,400);
  
  // Verificar se houve erro
  if(p == NULL){
    printf("Memoria insuficiente!\n");
    exit(1);
  }

  /* 
    Precavendo erros, se p1 der erro para não perder p:
    p1 = (int*) realloc(p,15*sizeof(int)); 
    if(p1 != NULL){
      p = p1;
    }
  */
  
  // Usa-se (p) como vetor:
  for(i=0;i<5;i++){
    scanf("%d",&p[i]);
  }
  for(i=0;i<5;i++){
    printf("%d",p[i]);
  }
  
  // Liberar a memoria manualmente:
  free(p);
  // Equivale a: p = (int*) realloc(p,0);
  return 0;
}