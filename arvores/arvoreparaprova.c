#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore{
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
        return raiz;
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

noArvore *remove_raiz(noArvore *r){
    //r: É a raiz atual (quem vai morrer).
    //p: Vai servir como o "pai" do nó que vamos mover (importante para não perder referências).
    //q: É o candidato a nova raiz.

    noArvore *p = r;
    // Se r -> left for diferente de NULL, q = r -> left, se nao, q recebe r
    noArvore *q = r->left != NULL ? r->left : r; 

    //A nova raiz (q) passa a ser simplesmente o filho da direita. Se a direita for nula, a árvore fica vazia. Simples assim.
    if (q == r){
        q = r -> right;
    }else{
        /*Estamos descendo tudo para a direita a partir do filho esquerdo da raiz.
        p vai guardando quem é o pai do q.
        q avança para a direita.
        Quando o loop para, q é o nó mais à direita (o maior valor da esquerda). Ele é o "escolhido" para virar a nova raiz.*/
        while(q -> right != NULL){
            p = q; 
            q = q->right;
        }
        if (p != r) //O escolhido não é filho direto da raiz(q)
        {
            p->right = q->left; //O p que era quem guardava a raiz q, adota o filho esquerdo de q
            q->left = r->left;  //O Q que agora ta la em cima, vai adotar para a sua esquerda, quem já era a esquerda de r
        }
        q->right = r->right; //Agora que o q subiu para o trono, ele precisa assumir a subárvore da direita inteira que pertencia à raiz antiga (r).
    }
    return q;
}

noArvore *remove_no(noArvore *raiz, int valor)
/*Encontra o nó (n).

Encontra o pai dele.

Chama a função difícil (remove_raiz) passando o n. Ela se vira para rearranjar os filhos do n e retorna o substituto.

Se tinha pai, o pai aponta para o substituto.

Se não tinha pai, o substituto vira a nova raiz global.*/
{
    noArvore *n = search(raiz, valor);
    if (n)
    {
        noArvore *pai = search_Father(raiz, n);

        //nessa daqui, verifica se o n tem pai, se ele tiver, ele vira a raiz da subarvore, é removido e o pai vai apontar para q
        if (pai)
        {
            if (pai->right == n)
                pai->right = remove_raiz(n);
            else
                pai->left = remove_raiz(n);
        }
        else
        {
            raiz = remove_raiz(n);
        }
    }
    return raiz;
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