#include <stdio.h>
#include <stdlib.h>

typedef struct proc{
    int id;
    float burst;
    float arrtime;
    int prior;
} proc;

void fcfs(proc *, int);
void sjf(proc *, int);
void displayproc(proc *, int);

int main(){
    int n, inp = 1;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    proc *proclist = (proc *) malloc(sizeof(proc)*n);
    for (int i = 0; i < n; i++){
        printf("Enter id of process %d: ", i+1);
        scanf("%d",&proclist[i].id);
        printf("Enter arrival time of process %d: ", i+1);
        scanf("%f",&proclist[i].arrtime);
        printf("Enter burst time of process %d: ", i+1);
        scanf("%f",&proclist[i].burst);
        printf("Enter priority of process %d: ", i+1);
        scanf("%d",&proclist[i].prior);
        printf("--------------------------\n");
    }
    while (inp != 0){
        printf("1: SJF\t2: FCFS\t0: Exit\nInput: ");
        scanf("%d", &inp);
        switch(inp){
            case 1:
                sjf(proclist, n);
                break;
            case 2:
                fcfs(proclist, n);
                break;
            case 0:
                printf("Exiting....\n");
                break;
            default:
                printf("Invalid input\n");
        }
        printf("---------------------------------------------------------------------\n");
    }

}

void displayproc(proc *proclist, int n){
    float tat, wt, avwt = 0, avtat = 0, ct = proclist[0].arrtime;
    printf("No.\tProc id\tPrio.\tArr. t\tBurst t\tTurn. t\tWait t\n");
    for (int i = 0; i < n; i++){
        ct+=proclist[i].burst;
        tat = ct - proclist[i].arrtime;
        wt = tat - proclist[i].burst;
        avwt += wt;
        avtat += tat;
        printf("%d\tP%d\t%d\t%.2f\t%.2f\t%.2f\t%.2f\n", i+1, proclist[i].id, proclist[i].prior, proclist[i].arrtime, proclist[i].burst, tat, wt);
    }
    avwt/=n;
    avtat/=n;
    ct = proclist[0].arrtime;
    printf("Gantt chart:\n");
    for (int i = 0; i < n; i++){
        printf("\tP%d\t", proclist[i].id);
    }
    printf("\n%.2f\t\t", ct);
    for (int i = 0; i < n; i++){
        ct+=proclist[i].burst;
        printf("%.2f\t\t", ct);
    }
    printf("\nAverage turnaround time: %.2f\nAverage wait time: %.2f\n", avtat, avwt);
}

void fcfs(proc *proclist, int n){
    proc temp;

    for (int i = 0; i < n; i++){
        for (int j = i; j < n-1; j++){
            if (proclist[j].arrtime > proclist[j+1].arrtime){
                temp = proclist[j];
                proclist[j] = proclist[j+1];
                proclist[j+1] = temp;
            }
        }
    }
    displayproc(proclist, n);
}

void sjf(proc *proclist, int n){
    proc temp;
    int max = 0;
    int flg;
    float time = 0;
    for (int i = 0; i < n; i++){
        for (int j = i-1; j >= 0; j--){
            if (proclist[j].arrtime > proclist[j+1].arrtime){
                max = j+1;
            }
            else if (proclist[j].arrtime == proclist[j+1].arrtime && proclist[j].burst > proclist[j+1].burst){
                max = j+1;
            }
            else if (proclist[j].arrtime == proclist[j+1].arrtime && proclist[j].burst < proclist[j+1].burst){
                max = j;
            }
        }
    }
    time = proclist[max].arrtime;
    temp = proclist[max];
    proclist[max] = proclist[0];
    proclist[0] = temp;

    for (int i = 1; i < n; i++){
        flg = 0;
        max = i;
        for (int j = i; j < n; j++){
            if (proclist[j].arrtime >= time){
                if (proclist[j].burst < proclist[max].burst){
                    max = j;
                }
                else if (proclist[j].burst == proclist[max].burst && proclist[j].arrtime < proclist[max].arrtime){
                    max = j;
                }
                flg = 1;
            }
        }
        if (flg != 0){
            temp = proclist[max];
            proclist[max] = proclist[i];
            proclist[i] = temp;
        }
    }

    displayproc(proclist, n);
}
