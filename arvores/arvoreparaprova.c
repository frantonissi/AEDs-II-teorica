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

noArvore *insere(noArvore *raiz, noArvore *n){

    if (raiz == NULL){
        return n;
    }
    
    if(raiz -> valor > n -> valor){
        raiz -> esquerda = insere(raiz -> esquerda, n);
    }else{
        raiz -> direita = insere(raiz -> direita, n);
            return raiz;
    }
}

noArvore *busca(noArvore *raiz, int k){

    if (raiz || raiz -> valor == k){
        return raiz;
    }

    if (raiz -> valor > k){
        return busca(raiz -> esquerda, k);
    }else{
        return busca(raiz -> direita, k);
    }
    

}


int main(){

    noArvore *raiz = NULL;
    noArvore *no_inserir = criar_No(10);
    raiz = insere(raiz, no_inserir);

    printf("%d\n", raiz -> valor);


    return 0;
}