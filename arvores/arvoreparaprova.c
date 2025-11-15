#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int valor;
    struct noArvore *right;
    struct noArvore *left;
} noArvore;


noArvore *create_Node(int valor){

    noArvore *novo_No = (noArvore*) malloc(sizeof(noArvore));
    novo_No -> valor = valor;
    novo_No -> right = NULL;
    novo_No -> left = NULL;
    return novo_No;
}


void pre_Order(noArvore *raiz){
    if (raiz == NULL){
        return;
    }
        printf("%d", raiz -> valor);
        pre_Order(raiz -> left);
        pre_Order(raiz -> right);
    
    
}

void in_Order(noArvore *raiz){

    if (raiz == NULL){
        return;
    }
        in_Order(raiz -> left);
        printf("%d", raiz -> valor);
        in_Order(raiz -> right);
}

void pos_Order(noArvore *raiz){

    if (raiz == NULL){
        return;
    }

        pos_Order(raiz -> left);
        pos_Order(raiz -> right);
        printf("%d", raiz -> valor);

}

noArvore *insert_Node(noArvore *raiz, noArvore *n){

    if (raiz == NULL){
        return n;
    }else if (raiz -> valor > n -> valor){
        raiz -> left = insert_Node(raiz -> left, n);
    }else{
        raiz -> right = insert_Node(raiz -> right, n);
            return raiz;
    }
}

noArvore *search(noArvore *raiz, int k){

    if (raiz == NULL){
        return NULL;
    }
    if (raiz -> valor == k){
        return raiz;
    }
    if (raiz -> valor > k){
        return search(raiz -> left, k);
    }else{
        return search(raiz -> right, k);
    }

}

noArvore *search_Father(noArvore *raiz, noArvore *n){

    if(raiz == n){
        return NULL;
    }
    if ((raiz->left != NULL && raiz->left == n) ||
        (raiz->right != NULL && raiz->right == n))
        return raiz;
    if (raiz -> valor > n -> valor){
        return search_Father(raiz -> left, n);
    }else {
        return search_Father(raiz -> right, n);
    }

}

int main(){

    noArvore *raiz = NULL;
    noArvore *no_inserir = create_Node(10);
    raiz = insert_Node(raiz, no_inserir);

    no_inserir = create_Node(5);
    raiz = insert_Node(raiz, no_inserir);

    no_inserir = create_Node(15);
    raiz = insert_Node(raiz, no_inserir);

    no_inserir = create_Node(7);
    raiz = insert_Node(raiz, no_inserir);
    return 0;
}