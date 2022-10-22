#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int pid, status;
    pid=fork();
    if(pid!=0){
        printf("Parent process ID is %d\n", getpid());
    }
    else{
        printf("Process ID is %d\n", getpid());
        execlp("/bin/ls/", "/Desktop", NULL);
        exit(0);
    }
    return 0;
}