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
        return raiz;
    }else{
        raiz -> direita = insercao(raiz -> direita, novo_valor);
        return raiz;
    }



}


ArvoreBin *busca(ArvoreBin *raiz, int k){

    if (raiz == NULL){
        return NULL;
    }

    if (raiz -> valor == k){
        return raiz;
    }
    if (raiz -> valor > k){
        return busca(raiz -> esquerda, k);
    }else{
        return busca(raiz -> direita, k);
    }

}

ArvoreBin *busca_Pai(ArvoreBin *raiz, ArvoreBin *n){
    if (raiz == NULL){
        return NULL;
    }

    if ((raiz -> esquerda != NULL && raiz -> esquerda == n) || (raiz -> direita != NULL && raiz -> direita == n)){
        return raiz;
    }

    if (raiz -> valor > n){
        return busca_Pai (raiz -> esquerda, n);
    }else{
         return busca_Pai (raiz -> direita, n);
    }
}

ArvoreBin *remocao_Raiz(ArvoreBin *raizaremover){
    if (raizaremover == NULL){
        return NULL;
    }

    ArvoreBin *pai_auxiliar = raizaremover;
    ArvoreBin *q; 

    if (raizaremover -> esquerda == NULL){
        q = raizaremover -> direita;
        return q;
    }else{
        q = raizaremover -> esquerda;
    }

    while (q -> direita != NULL){
        pai_auxiliar = q;
        q = q-> direita;
    }

    if (pai_auxiliar != raizaremover){

        pai_auxiliar -> direita = q -> esquerda;
        q -> esquerda = raizaremover -> esquerda;

    }
            q -> direita = raizaremover -> direita;
    return q;
}

ArvoreBin *remover_No(ArvoreBin *raiz, int valor){

    if (raiz == NULL){
        return -1;
    }

    ArvoreBin *valor_Buscado = busca(raiz, valor);
    if (valor_Buscado){
        ArvoreBin *n = busca_Pai(raiz, valor_Buscado);
            if (n){
                if (n -> direita == valor_Buscado){
                     n->direita = remocao_Raiz(valor_Buscado);
                }else{
                    n -> esquerda = remocao_Raiz(valor_Buscado);
                }
            }else{
                raiz = remocao_Raiz(valor_Buscado);
            }
    }
    return raiz;
    
}



