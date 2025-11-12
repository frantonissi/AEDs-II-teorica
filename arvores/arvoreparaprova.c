#include <stdio.h>
#include <stdlib.h>



typedef struct{

    int valor;
    struct noArvore *esquerda;
    struct noArvore *direita

}noArvore;

noArvore *criar_No(int valor){
    noArvore *novo_No = (noArvore*) malloc(sizeof(noArvore));
    novo_No -> direita = NULL;
    novo_No -> esquerda = NULL;
    novo_No -> valor = valor;
    return novo_No;
}