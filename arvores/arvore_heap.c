#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 7

typedef struct MinHeap {
    int* harr;       // O array que armazena os elementos
    int capacity;    // O tamanho máximo (MAX_SIZE)
    int heap_size;   // O número atual de elementos
} MinHeap;


MinHeap *inicialização(int capacity){

    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h -> harr = (int*)malloc(sizeof(int));
    h -> capacity = capacity;
    h -> heap_size = 0;

}

int parent(int i){

    return (i - 1)/2;

}

int left_Chield(int i){

    return 2 * i + 1;

}

int right_Chield(int i){

    return 2 * i + 2;

}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

    

int main(){

    inicialização(MAX_SIZE);

    return 0;
}