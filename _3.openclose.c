#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

struct dirent *dptr;

int main(int argc, char *argv[]) {
    int f=open("filename.c", O_RDWR);
    if(f==-1){
        printf("Error in opening the file\n");
    }
    else{
        printf("\nFile has been opened\n");
    }
    close(f);
    printf("File has been closed");
}