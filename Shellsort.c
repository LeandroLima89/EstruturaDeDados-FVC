#include<stdio.h>

void shellSort (int *vet, int size);

void main(){
    int a[] = {7, 12, 1, -2, 0, 15, 4, 11, 9};
    int i;

    printf("Array original\n");

    for(i = 0; i < 9; i++){
        printf(" %d ", a[i]);
    }

    shellSort(a, 9);

    printf("\nArray ordenado\n");

    for(i = 0; i < 9; i++){
        printf(" %d ", a[i]);
    }
}

void shellSort (int *vet, int size){
    int i, j, value;
    int gap = 1;

    do{
        gap = 3 * gap + 1;
    }while(gap < size);

    do{
        gap /= 3;

        for(i = gap; i < size; i++){
            value = vet[i];
            j = i - gap;
            while(j >= 0 && value < vet[j]){
                vet[j + gap] = vet[j];
                j -= gap;
            }
            vet[j + gap] = value;
        }
    }while(gap > 1);
}
