#include<stdio.h>
#include<unistd.h>>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
    char *path,pathl[10];
    struct stat *nfile;
    nfile = (struct stat *)malloc(sizeof(struct stat));
    printf("Enter file : ");
    scanf("%s", pathl);
    stat(pathl, nfile);
    printf("User id: %d\n", nfile->st_uid);
    printf("Blocksize: %ld\n", nfile->st_blksize);
    printf("Last access time : %ld\n", nfile->st_atime);
    printf("Production mode : %d\n", nfile->st_mode);
    printf("Size of file : %ld\n", nfile->st_size);
    printf("Number of links: %ld\n", nfile->st_nlink);
    return 0;
}
