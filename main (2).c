#include <stdio.h>

int main()
{
    char nome[50];
    int i, x;
    
    printf("Digite o seu nome: ");
    scanf("%s", nome);
    printf("\nSeu nome eh : %s", nome);
    
    
    printf("\nA quarta letra eh: %c", nome[3]);
    printf("\n\n\n");
    
    for(i=0;i<50;i++){
        if(nome[i] == '\0') break;
        x = nome[i];
        printf("%c\n", x+1);
    }
}