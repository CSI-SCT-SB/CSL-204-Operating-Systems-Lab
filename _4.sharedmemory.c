#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
struct shared{
    int a_b;
    int c_d;
};
const key_t key = 1;
pid_t pid;
void* shared_mem;                                                                        
int main()
{
    	int a,b,c,d;
    	printf("Enter the values of a: ");
    	scanf("%d",&a);
    	printf("Enter the values of b: ");
    	scanf("%d",&b);
    	printf("Enter the values of c: ");
    	scanf("%d",&c);
    	printf("Enter the values of d: ");
    	scanf("%d",&d);
    	int shmid = shmget(key,sizeof(struct shared), 0666|IPC_CREAT);
    	if(shmid == -1) {
        	printf("\nUnable to create shared memory");
        	exit(0);
    	}
    	pid = fork();
    	if(pid == 0){  
        	shared_mem = shmat(shmid,(void*) 0,0);
        	struct shared* shared_data = (struct shared*) shared_mem;
        	shared_data->a_b = a * b;
        	exit(EXIT_SUCCESS);
    	}
   	else{ 
    		wait(NULL);
    		shared_mem = shmat(shmid,(void*) 0,0);
    		if(shared_mem == (void*) -1) exit (EXIT_FAILURE);
    		struct shared* shared_data = (struct shared*) shared_mem;
    		shared_data->c_d = c*d;
    		int result = (shared_data->a_b)+(shared_data->c_d);
    		printf("Result is %d\n", result);
    		if(shmdt(shared_mem) == -1) exit (EXIT_FAILURE);
    		if(shmctl(shmid,IPC_RMID,0) == -1) exit(EXIT_FAILURE);
    		return EXIT_SUCCESS;
    	}
}
