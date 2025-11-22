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
    /*Nessa funcao, vamos buscar o pai do v, se esse pai existir, é porque a raiz nao aponta para NULL 
    e tambem porque a raiz tem que ser igual a v  */
    if (raiz == NULL){
        return NULL;
    }
    if ((raiz -> right != NULL && raiz -> right == v) || (raiz -> left != NULL && raiz -> left == v)){
        return raiz;
    }

    if (raiz -> valor > v -> valor){
        return busca_Pai(raiz -> left, v);
    }else{
        return busca_Pai(raiz -> right, v);
    }
    
}

noArvore *remocao(noArvore *remover){
    /*Nessa funcao, nosso objetivo é remover a raiz, principal ou de sub-arvores, primeiramente, a gente tem que ver
    se a estrutura remover tem filhos a esquerda, se nao tiver, basicamente quem vai assumir o lugar dela é 
    o filho a direita (q  = r -> right), se tiver filho a esquerda, nós temos que começar a ir para a direita
    ate achar o mais a direita, depois nós colocamos o mais a direita no lugar do remover, e reatualizamos todos
    os ponteiros*/

    noArvore *paidosfilhosdoQ = remover;
     noArvore *q = remover->left != NULL ? remover->left : remover; 


    if (q == remover){
        q = remover -> right;
        return q;
    }

    while(q -> right != NULL){
        paidosfilhosdoQ = q;
        q = q -> right;

    }
    //se o paidosfilhosdoQ nao for diferente de remover, é porque nao desceu;

    if (paidosfilhosdoQ != remover){
        /*Aqui só vai funcionar se o  paidosfilhosdoQ for diferente do r, porque se ele for igual, quer dizer que o q é o a esquerda do remover
        sendo assim, nao precisa ligar o pai do q ao seu filho da esquerda, e tambem, se pegar o paidosfilhosdoQ -> right = q -> left; da erro
        pq vc vai fazer o paidosfilhosdoQ que é igual a remover receber o que o q apontava, o que da erro, e o q -> right = remover -> right; da
        erro pq vc vai fazer o q -> right apontar para ele mesmo (já que o q é o remover -> right)
*/
        paidosfilhosdoQ -> right = q -> left;
        q -> left = remover -> left;

    }

    //logo, só temos que consertar a parte direita da arvore:
    q -> right = remover -> right;
    return q;
}

    noArvore *remove_No (noArvore *raiz, int valor){
        noArvore *valoraser_Buscado = busca(raiz, valor);

        if (valoraser_Buscado){
            noArvore *pai = busca_Pai(raiz, valoraser_Buscado);
                if (pai){
                    if (pai -> right == valoraser_Buscado){
                        pai -> right = remocao(valoraser_Buscado);
                    }else{
                        pai -> left = remocao(valoraser_Buscado);
                    }
                }else{
                raiz = remocao(valoraser_Buscado);
                } 
        }
        return raiz;
    }

    int main(){

        noArvore *raiz = NULL;
        noArvore *insercao_No = criacao(10);
        raiz = insercao(raiz, insercao_No);

        insercao_No = criacao(20);
        raiz = insercao(raiz, insercao_No);

    }