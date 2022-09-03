#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fenv.h>

void guionfuera(afuera,dentro,k,i);
void guiondentro(dentro,i);

int main(int argc, char *argv[]){
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
    guionfuera(k,0,k,1);
    printf("\n");
    return 0;
}


void guiondentro(int afuera,int dentro,int k, int i){
    
    if(i<k && i!=1){
        for(int i=2;i<dentro;i++){
            printf(" ");   
        }
        printf("*");
        printf("\n");
    }else{
        printf("\n");
    }
        dentro+=1;
        i+=1;
        afuera-=1;
        guionfuera(afuera,dentro,k,i);
    return ;
}

void guionfuera(int afuera,int dentro,int k, int i){

    if(i<k){
        for(int i=1;i<afuera;i++){
            printf(" ");
        }
        printf("*");
        dentro+=1;
        guiondentro(afuera,dentro,k,i);
    }else{
        for(int i=0;i<(k+k-1);i++){
            printf("*");
        }
    }
        
    return ;
}