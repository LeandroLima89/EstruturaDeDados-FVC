#include <stdio.h>


void main(){
    struct TData{
    int dia;
    int mes;
    int ano;
}   hoje;

    printf("Informe a data de hoje: ");
    scanf("%d-%d-%d", &hoje.dia, &hoje.mes, &hoje.ano);
    printf("\n");
    printf("O dia informado eh %d\n", hoje.dia);
    printf("Olha so  %02d/%02d/%d", hoje.dia, hoje.mes, hoje.ano);

}
