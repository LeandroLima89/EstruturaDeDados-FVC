#include <stdio.h>

//Método para ajustar o próprio heap
void heapify(int arr[], int n, int i){
    int largest = i; // Inicializar o maoi com a raiz
    int left = 2 * i + 1;  //Filho esquerdo
    int right = 2 * i + 2; //Filho direito

    //Se o filho esquerdo for maior que a raiz
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    //Se o filho direito for maior encontrado até agora
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    //Se o maior não for a raiz
    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int i, temp;

    for(i= n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }

    for(i=n-1; i> 0; i--){
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main(){
    int arr[] = {12, 1, 10, 13, 5, 6, 7, 2, 98, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Array original : ");
    for(i=0; i < n; i++){
        printf("%2d ", arr[i]);
    }

    heapSort(arr, n);

    printf("\nArray ordenado :");
    for(i=0; i<n; i++){
        printf("%2d ", arr[i]);
    }

    scanf("%d", &i);
    return 0;
