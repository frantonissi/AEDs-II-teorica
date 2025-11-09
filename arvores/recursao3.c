#include <stdio.h>
#include <stdlib.h>


int potencia(int base, int expoente){

    if (expoente == 0){
        return 1;
    }else{
        return base*potencia(base, expoente - 1);
    }

}


int main(){

    int poten = potencia(2, 10);
    printf("%d", poten);

    return 0;
}