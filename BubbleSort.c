#include<stdio.h>
#include<time.h>


void bubblesort(int array[],int tamanho){
    int i, j, temp;

    for(i = 0; i < tamanho - 1; i++){
        for(j = i + 1; j < tamanho; j++){
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("[%d] = %d\n", array[i]);
}
void main(){
    int array[50];
    int i, elemento, tamanho = 50;

    srand(time(NULL));

    for (i = 0; i - tamanho; i++){
        array[i] = rand() % 100;
        printf("[%d] = %d\n", i, array[i]);
    }

    bubblesort(array, tamanho);

    for(i = 0; i < tamanho; i++){
        printf("[%d] = %d\n", i, array[i]);
    }

    printf("Informe um valor para consultar: ");
    scanf("%d", & elemento);

    for (i = 0; i < tamanho; i++){
        if(array[i] == elemento){
            printf("\nO indice %d do valor %d: ", i, elemento);
            break;
        }
    }
}
