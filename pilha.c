#include<stdio.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct{
    Node* top;
}Stack;

Stack* criaPilha(){
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if(stack == NULL){
        printf("Sem memoria");
        exit(1);
    }
    stack ->top=NULL;
    return stack;
}
void push(Stack* stack, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Nao tem memoria para o no");
        exit(1);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}
int pop(Stack* stack){
    if(stack->top == NULL){
        printf("Erro. Acho que esta vazio");
        exit(1);
    }
    int popValue = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return popValue;
}
int isEmpty(Stack* stack){
    return (stack->top == NULL);
}

void main(){
    Stack* stack = criaPilha();

    push(stack, 10);
    push(stack, 20);
    push(stack, 50);
    push(stack, 90);

    printf("Desempilhando %d\n", pop(stack));

    while(!isEmpty(stack)){
        printf("\nDesempilhando %d", pop(stack));

    }
    free(stack);
}


