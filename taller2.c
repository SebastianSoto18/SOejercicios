#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>


void error(char *msg){
    perror(msg);
    exit(-1);
}


int leerNumeros(char *filename, int **vec)
{
    int c, numero, totalNumeros;
    FILE *infile;
    infile = fopen(filename, "r");

    if (!infile){
        error("Error fopen\n");
    }
    fscanf(infile, "%d", &totalNumeros);

    *vec = (int *)calloc(totalNumeros, sizeof(int));

    if (!*vec){
        error("error calloc");
    }

    for (c = 0; c < totalNumeros; c++){
        fscanf(infile, "%d", &numero);
        (*vec)[c] = numero;
    }

    fclose(infile);
    return c;
}


void sumar(int *vec, int ini,int final,FILE *outfile, FILE *time){
    
    int i = 0;
    long long int suma=0;
    double trans_time=0.0;

    clock_t sumaINI = clock();
    for (i = ini; i < final; i++){
        suma += vec[i];
    }
    clock_t sumaEND = clock();

    fprintf(time,"%f",trans_time += (double)(sumaEND- sumaINI) / CLOCKS_PER_SEC);
    fprintf(time, "%s", "\n");
    fprintf(outfile, "%lli", suma);
    fprintf(outfile, "%s", "\n");
}

long long int leerTotal(){
    FILE *infile;
    long long int sumap1=0,sumap2=0,total=0;
    

    infile = fopen("out.txt","r");

    if(!infile) error("Error padre archivo resultados");

    fscanf(infile,"%lli", &sumap1);
    fscanf(infile,"%lli", &sumap2);

    total = sumap1 + sumap2;

    return total;
 }

 float leerTiempo(){
    FILE *infile;
    float tiempo1=0,tiempo2=0,total=0;
    

    infile = fopen("time.txt","r");

    if(!infile) error("Error padre archivo resultados");

    fscanf(infile,"%f", &tiempo1);
    fscanf(infile,"%f", &tiempo2);

    total = tiempo1 + tiempo2;

    return total;
 }

int main(int argc, char *argv[]){

    int *array = NULL;
    FILE *outfile;
    FILE *timefile;
    timefile= fopen("time.txt","w");
    outfile = fopen("out.txt", "w");
    double trans_time=0.0;

    clock_t lecturaINI = clock();
    int totalNumeros = leerNumeros(argv[1], &array);
    clock_t lecturaEND = clock();

    trans_time += (double)(lecturaEND- lecturaINI) / CLOCKS_PER_SEC;

    printf("la lectura tomo un tiempo de: %f \n",trans_time);

    int delta = totalNumeros / 2;
   
    int pid = fork();
    
    if(pid!=0){
        int pid2 = fork();
        if(pid2==0){
                sumar(array, 0, delta, outfile, timefile);
                exit(1);
        }
    }

    if(pid==0){
        sumar(array, delta, totalNumeros, outfile, timefile);
    }
    

    if(pid!=0){
        for (int i = 0; i < 2; i++){
            wait(NULL);
        }

        
        printf("La suma tomo un tiempo de: %f \n",leerTiempo());
        fclose(outfile);
        fclose(timefile);
        printf("la suma total de los elementos es: %lli \n", leerTotal());
    }
    
    return 0;
}
