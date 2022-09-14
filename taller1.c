#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(int argc, char *argv[]){

    FILE *file;
    long long int sum=0;
    int size;
    int *array = NULL;
    double trans_time=0.0;


    printf("archivo [%s] abiero \n",argv[1]);

    clock_t lecturaINI = clock();
    file = fopen(argv[1], "r");
    fscanf(file, "%d", &size);
    array = (int *)malloc(size*sizeof(int));

    for(int i=0; i<size; i++){
        fscanf(file, "%d", &array[i]);
    }
    clock_t lecturaEND = clock();

    trans_time += (double)(lecturaEND- lecturaINI) / CLOCKS_PER_SEC;

    printf("la lectura tomo un tiempo de: %f \n",trans_time);

    clock_t sumINI = clock();
    for(int i=0; i<size; i++){
        sum += array[i];
    }
    clock_t sumEND = clock();

    trans_time += (double)(sumEND - sumINI) / CLOCKS_PER_SEC;

    printf("la suma de los elementos tomo un tiempo de: %f \n",trans_time);
    printf("%s %lli %s","la suma de los elementos es: ",sum,"\n");

    int *array2 = NULL;
    int mayor=0;
    int mayorRepetido=0;
    int cantidadRepetido=0;

    for(int i=0; i<size; i++){
        mayor = (array[i] >= mayor ? array[i] : mayor);
    }

    array2 = (int *)malloc(mayor*sizeof(int));

    for(int i=0; i<mayor; i++){
        for (int j = 0; j < size; j++){
            if(array[j] == i){
                array2[i]+=1;
            }
        }
    }

    for (int i = 0; i < mayor; i++){
        if (array2[i]>=cantidadRepetido){
            mayorRepetido = i;
            cantidadRepetido = array2[i];
        }
    }
    
    printf("%s %s %d %s %d %s ", "el numero que mas se repitio fue el: ","(",mayorRepetido,",",cantidadRepetido,")");
    printf("\n");
    fclose(file);
    free(array);
    free(array2);
    return 0;
}