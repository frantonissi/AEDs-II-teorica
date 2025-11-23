#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore_bin{
    int valor;
    struct Arvore_bin *direita;
    struct Arvore_bin *esquerda; 
}Arvore_bin;

Arvore_bin *criacao(int valor){
    Arvore_bin* novo_no = (Arvore_bin*)malloc(sizeof(Arvore_bin));
    novo_no -> valor = valor;
    novo_no -> direita = NULL;
    novo_no -> esquerda = NULL;
}

Arvore_bin *insercao(Arvore_bin *raiz, Arvore_bin *novo){

    Arvore_bin *aux = raiz;

    while(aux != NULL){

        if(raiz -> valor > novo -> valor){
            aux = raiz -> esquerda;
        }else{
           aux = raiz -> direita;
    }
}
    aux = novo;
    return novo;
}

Arvore_bin *insercao_r(Arvore_bin *raiz, Arvore_bin *novo){

    if (raiz == NULL){
        return novo;
    }

    if (raiz -> valor > novo -> valor){
        raiz -> esquerda = insercao_r(raiz -> esquerda, novo);
        return raiz;
    }else{
        raiz -> direita = insercao_r(raiz -> direita, novo);
    }

}


Arvore_bin *busca(Arvore_bin *raiz, int k){
    if (raiz == NULL) {
        return NULL;
    }

    Arvore_bin *aux = raiz;

    while(aux -> valor != k){
        if(raiz -> valor > k){
            aux = raiz -> esquerda;
        }else{
           aux = raiz -> direita;
    }
    }
    return raiz;
}

Arvore_bin *busca_r(Arvore_bin *raiz, int k){
    if (raiz == NULL){
        return NULL;
    }

    if (raiz -> valor == k){
        return raiz;
    }

    if (raiz -> valor > k){
        return busca_r(raiz -> esquerda, k);
    }else{
        return busca_r(raiz -> direita, k);
    }
}

Arvore_bin *busca_pai(Arvore_bin *raiz, Arvore_bin *no){
    if (raiz == NULL){
        return NULL;
    }
}

Arvore_bin *busca_pai_r(Arvore_bin *raiz, Arvore_bin *no){
    if (raiz == NULL){
        return NULL;
    }

    
}