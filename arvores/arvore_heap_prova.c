#include <stdio.h>
#include <stdlib.h>

typedef struct MAXheap_tree{
    int *harr;
    int tamanho_maximo;
    int tamanho_heap;
}MAXheap_tree;

MAXheap_tree *inicializacao(int tamanho_maximo){

    /*Nessa função, nó vamos incializar, para isso, criamos um malloc da struct MAXheap_tree, depois criamos 
    um lugar int para guardarmos o harr, definimos o tamanho maximo da heap, e incializamos o tamanho da heap
    como 0*/
    MAXheap_tree* h = (MAXheap_tree*)malloc(sizeof(MAXheap_tree));
    h -> harr = (int*)malloc(tamanho_maximo * sizeof(int));
    h -> tamanho_maximo = tamanho_maximo;
    h -> tamanho_heap = 0;
    return h;

}

int parent(int i){
    return (i - 1)/2;
}

int filho_esquerda(int i){
    return (2 * i) + 1;
}

int filho_direita (int i){
    return (2 * i) + 2;
}

void  troca (int *x, int *y){

    int temp = *x;
    *x = *y;
    *y = temp;
    
}

void inserir_MAXheap(MAXheap_tree *h, int valor){

    /*Nessa funcao, vamos começar a inserir valores no nosso espaço de memoria, aqui, primeiro verificamos 
    se a heap já atingiu seu tamanho máximo, se ainda nao, a funcao continua, depois nós criamos mais um espaço
    na heap, definimos o i como o ultimo indice a ser adicionado e por ultimo, adicionamos o valor a ultima casinha
    do vetor (arvore), depois ve se o pai de quem foi adicionado é menor, se for, faz a troca */

    if (h -> tamanho_heap == h -> tamanho_maximo){
        printf("Nao pode inserir mais nada");
        return;
    }

    h -> tamanho_heap++;
    int i = h -> tamanho_heap - 1;
    h -> harr[i] = valor;

    while ( i != 0 && h -> harr[parent(i)] < h -> harr[i] ){
        troca(&h -> harr[i], &h -> harr[parent(i)]);
        i = parent(i); // sobe enquanto necessário
    }
}

int extracao_MAXheap (MAXheap_tree *h){

    /**/

    if (h -> tamanho_heap <= 0){
        return -1;
    }
    if (h->tamanho_heap == 1) {
        h->tamanho_heap--;
        return h->harr[0];
    }

    int raizquevaiserremovida = h -> harr[0];
    h -> harr[0] = h -> harr[h -> tamanho_heap - 1];
    h -> tamanho_heap--;

    int i = 0;
    while(filho_esquerda(i) < h -> tamanho_heap){
        
    int maior = filho_esquerda(i);
    
    if (filho_direita(i) < h -> tamanho_heap && h -> harr[filho_direita(i)] > h -> harr[filho_esquerda(i)]){
        maior = filho_direita(i);
    }

    if ( h -> harr[i] < h -> harr[maior]){
        troca(&h -> harr[i], &h -> harr[maior]);
        i = maior;
    }else{
        break;
    }
}
    return raizquevaiserremovida;

}

int main() {
    printf("--- Teste do Max Heap ---\n");

    // Cria uma heap com capacidade para 11 elementos
    MAXheap_tree* h = inicializacao(11);

    // Inserindo valores fora de ordem
   
    inserir_MAXheap(h, 3);
    inserir_MAXheap(h, 2);
    inserir_MAXheap(h, 15);
    inserir_MAXheap(h, 5);
    inserir_MAXheap(h, 4);
    inserir_MAXheap(h, 45);

    printf("\nRemovendo...\n");

    printf("Valores removidos: ");
    // Removemos todos até esvaziar
    while (h->tamanho_heap > 0) {
        printf("%d ", extracao_MAXheap(h));
    }
    printf("\n");

    // Limpa memória
    free(h->harr);
    free(h);
    
    return 0;
}