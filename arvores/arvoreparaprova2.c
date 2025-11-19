#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore {

    int valor;
    struct noArvore *right;
    struct noArvore *left;

}noArvore;

noArvore *criacao(int valor){

    noArvore *novo_No = (noArvore*) malloc(sizeof(noArvore));
    novo_No -> valor = valor;
    novo_No -> right = NULL;
    novo_No -> left = NULL;
    return novo_No;
}

void pre_Ordem(noArvore *raiz){

    if (raiz == NULL){
        return;
    }
    printf("%d", raiz -> valor);
    pre_Ordem(raiz -> left);
    pre_Ordem(raiz -> right);  

}

void pos_Ordem(noArvore *raiz){

    if (raiz == NULL)
    return;

    pos_Ordem(raiz -> left);
    pos_Ordem(raiz -> right);
    printf("%d", raiz -> valor);

}

void em_Ordem(noArvore *raiz){

    if (raiz == NULL)
    return;

    em_Ordem(raiz -> left);
    printf("%d", raiz -> valor);
    em_Ordem(raiz -> right);
    
}

noArvore *insercao (noArvore *raiz, noArvore *v){
    /*Nessa função, meu objetivo é inserir um no na arvore, para isso eu devo, ver se o "v" é maior do que
    a raiz, se for, ele deve ser adicionado a direita, se for menor, deve ser adicionado a esquerda
    para isso eu vou usar a recursividade!!! (O v vai ser criado na funcao de criacao)*/

    if (raiz == NULL){
        return v;
    }
    if (raiz -> valor > v -> valor){
        raiz -> left = insercao(raiz -> left, v);
        return raiz;
    } else{
        raiz -> right = insercao(raiz -> right, v);
        return raiz;
    }

}

noArvore *busca (noArvore *raiz, int v){
    /*Nessa funcao, eu vou buscar na minha arvore a partir do valor que o usuario pedir, entao por isso eu preciso do int v, entao
    basicamente eu preciso comparar, se for maior, eu faço a recursividade pela direita, se for menor, faço pela esquerda*/

    if (raiz == NULL){
        return NULL; //nao existe arvore;
    }
    if (raiz -> valor == v){
        return raiz;
    }
    if (raiz -> valor > v){
        return busca(raiz -> left, v);
    }else{
        return busca(raiz -> right, v);
    }
}

noArvore *busca_Pai (noArvore *raiz, noArvore *v){
    /*Nessa funcao, vamos buscar o pai do v, se esse pai existir, é porque a raiz nao aponta para NULL e tambem porque a raiz tem que ser igual a v  */
    if (raiz == NULL){
        return NULL;
    }
    if (raiz -> right != NULL && raiz -> right == v || raiz -> left != NULL && raiz -> left == v){
        return raiz;
    }

    if (raiz -> valor > v -> valor){
        return busca_Pai(raiz -> left, v);
    }else{
        return busca_Pai(raiz -> right, v);
    }
    
}