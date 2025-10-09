#include<stdio.h>
#include<time.h>

int buscaBinaria(int array[], int tamanho, int elemento){
    int esquerda = 0;
    int direita = tamanho - 1;

    while(esquerda <= direita){
        int meio = esquerda + (direita - esquerda) / 2;
        if(array[meio] == elemento){
            return meio;
        }
        if(array[meio] < elemento){
            esquerda = meio + 1;
        }else{
            direita = meio - 1;
        }
    }
    return -1;
}

void main(){
    int array[50];
    int tamanho = 50;
    int i;
    int elemento;
    int indice;

    srand(time(NULL));
    for(i = 0; i < tamanho; i++){
        array[i] = (i + 1) * 3; //rand() % 100;
        printf("%d\t%d\n", i, array[i]);
    }
    printf("Digite o elemento que deseja buscar: ");
    scanf("%d", &elemento);
    indice = buscaBinaria(array, tamanho, elemento);
    if(indice == -1){
        printf("Elemento nao encontrado!");
    }else{
        printf("Elemento na posicao %d", indice);
    }
}
