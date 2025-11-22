#include <stdio.h>
#include <stdlib.h>

typedef struct ArvoreBin{
    int valor;
    struct ArvoreBin *esquerda;
    struct ArvoreBin *direita;
}ArvoreBin;

ArvoreBin *criacao_NO(int valor){

    ArvoreBin* novo_NO = (ArvoreBin*)malloc(sizeof(ArvoreBin));
    novo_NO -> valor = valor;
    novo_NO -> esquerda = NULL;
    novo_NO -> direita = NULL;

    return novo_NO;

}

void pre_Ordem(ArvoreBin *raiz){
    if (raiz == NULL){
        return;
    }
    printf("%d", raiz -> valor);
    pre_Ordem(raiz -> esquerda);
    pre_Ordem(raiz -> direita);
}

void pos_Ordem(ArvoreBin *raiz){

    if (raiz == NULL){
        return;
    }
    pre_Ordem(raiz -> esquerda);
    pre_Ordem(raiz -> direita);
    printf("%d", raiz -> valor);

}

void em_Ordem(ArvoreBin *raiz){

    if (raiz == NULL){
        return;
    }
    em_Ordem(raiz -> esquerda);
    printf("%d", raiz -> valor);
    em_Ordem(raiz -> direita);
    
}


ArvoreBin *insercao(ArvoreBin *raiz, ArvoreBin *novo_valor){
    if (raiz == NULL){
        return novo_valor;
    }

    if (raiz -> valor > novo_valor -> valor){
        raiz -> esquerda = insercao(raiz -> esquerda, novo_valor);
    }else{
        raiz -> direita = insercao(raiz -> direita, novo_valor);
    }


}
