#include <stdio.h>
#include <stdlib.h>

void inverterString(char *inicio, char *fim){

    if (inicio >= fim) return;
     char temp = *inicio;
     *inicio = *fim;
    *fim = temp;

        inverterString(inicio + 1, fim - 1);

}


int main (){

char str[] = "computador";

    char *fim = str;
    while (*fim != '\0') fim++;   
    fim--;                        

    inverterString(str, fim);

    printf("%s\n", str);  
    return 0;
}