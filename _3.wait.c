#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    int pid, status, exitch;
    if((pid=fork()) == -1){
        perror("Error\n");
        exit(0);
    }
    if(pid==0) {
        sleep(1);
        printf("Child process\n");
        exit(0);
    }
    else{
        printf ("Parent process\n");
        if((exitch=wait(&status)) == -1){
            perror("During wait()\n");
            exit(0);
        }
        printf("Parent existing\n");
        exit(0);
    }
}