#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fenv.h>

int main(int argc, char *argv[])
{
    int k=0;
    int delta=0;
    
    if(argc!=2){
        printf("error en la cantidad de argumentos");
        exit(1);
    }

    if(!(atoi(argv[1])%2!=0)){
            printf("no se permiten valores pares");
            exit(1);
    }

    k=atoi(argv[1]);

    delta=lround(k/2)+1;
    
    for(int i=1;i<=k;i++){
        if(i!=delta){
            for(int i=1;i<delta;i++){
                printf(" ");
            }
            printf("*");
            printf("\n");
        }else{
            for(int i=1;i<=k;i++){
                printf("*");
            }
            printf("\n");
        }
        }
    

    return 0;
}