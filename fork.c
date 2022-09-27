#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(){
    int i , n;
    scanf("%d", &n);

    for (i = 0; i< n; i++){
        if(fork () == 0)
        break;
    }
    if(i==n){
        printf("padre: %d\n", getpid());
        //for(int j = 0; j< n; j++) wait(NULL);
    }
    else{
        printf("hijo [%d] pid: %d padre: %d\n", i, getpid(), getppid());
    }
    return 0;
}
