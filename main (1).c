/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int a[70];
    int at[70];
    int i, x;
    
    for(i=0; i<70;i++){
        a[i]=at[i]=0;
    }
    
    a[8] = 1;
    
    a[20] = 1;
    
    a[40] = 1;
    
    a[60] = 1;
    
    for(i=0;i<70;i++){
        printf("%d", a[i]);
    }
    printf("\n");
    
   // Gerar o at pelo a
   // at[n] = formula usando o a como base (a[i-1] + a[i+1]) % 2
   for(x=1; x<=100;x++){
       for(i=0;i<70;i++){
           if(i==0){
                at[i] = (a[69]+a[i+1])%2;  
           } else if(i == 69){
               at[i] = (a[i-1]+a[0])%2;
           }else{
             at[i] = (a[i-1]+a[i+1])%2;    
           }
           if(at[i] == 0)
                printf(" ");
            else
                printf("X");
           
        }
        printf("\n");
        for(i=0;i<70;i++)
            a[i]=at[i];
   }
    

    return 0;
}