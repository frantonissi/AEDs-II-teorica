#include <stdio.h>
#include <stdlib.h>

typedef struct MAXheap_tree{
    int *harr;
    int tamanho_maximo;
    int tamanho_heap;
}MAXheap_tree;

MAXheap_tree *inicializacao(int tamanho_maximo){

    MAXheap_tree* h = (MAXheap_tree*)malloc(sizeof(MAXheap_tree));
    h -> harr = (int*)malloc(sizeof(int));
    h -> tamanho_maximo = tamanho_maximo;
    h -> tamanho_heap = 0;
    return h;

}

int parent(int i){
    return (i - 1)/2;
}

int filho_esquerda(int i){
    return (2 * 1) + 1;
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

    if (h -> tamanho_heap == h -> tamanho_maximo){
        printf("Nao pode inserir mais nada");
        return;
    }

    h -> tamanho_heap++;
    int i = h -> tamanho_heap - 1;
    h -> harr[i] = valor;

    if ( i != 0 && h -> harr[parent(i)] < h -> harr[i] ){
        troca(&h -> harr[i], &h -> harr[parent(i)]);
        i = parent(i);
    }


}

int extracao_MAXheap (MAXheap_tree *h){

    

}