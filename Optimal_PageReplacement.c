//OPTIMAL PAGE REPLACEMENT
#include<stdio.h>
#include<stdlib.h>

//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
//4 7 6 1 7 6 1 2 7 2
//7 0 1 2 0 3 0 4 2 3 0 3 2 3

int findOPTIMAL(int occur[],int fr[],int rs[],int f,int n,int r){
    int flag;
    for(int i=0;i<f;i++){
        flag=0;
        for(int j=r+1;j<n;j++){
            if(fr[i]==rs[j]){
                occur[i]=j;
                flag=1;
                break;
            }
        }
        if(flag!=1 && fr[i]!=-1){
            occur[i]=100;
        }
    }
    int max=occur[0],pos=0,pos1,pos2;
    for(int i=0;i<f;i++){
        if(occur[i]>max){
            max=occur[i];
            pos=i;
        }

       else if(occur[i]==max){
            pos1-1;pos2=-1;
            for(int j=0;j<n;j++){
                if(rs[j]==fr[i]){
                    pos1=j;
                }
                if(rs[j]==fr[pos]){
                    pos2=j;
                }
                if(pos1!=-1 && pos2!=-1){
                    break;
                }
            }
            
            if(pos1<pos2){
                pos=i;
            }
        }
    }
    return pos;

}

void main(){
    int n,f,pf=0,hits=0;
    printf("Enter the no: of pages in reference string : ");
    scanf("%d",&n);
    int rs[n];
    printf("\nEnter the reference string : ");
    for(int i=0;i<n;i++){
        scanf("%d",&rs[i]);
    }
    printf("\nEnter the no: of frames : ");
    scanf("%d",&f);
    int fr[f],occur[f];
    for(int i=0;i<f;i++){
        fr[i]=-1;
        occur[i]=1000;
    }
    printf("\nOPTIMAL PAGE REPLACEMENT....\n\n");
    int pos,flag;
    for(int i=0;i<n;i++){
        flag=0;
        for(int j=0;j<f;j++){
            if(rs[i]==fr[j]){
                flag=1;
                hits++;
                printf("\t\t--------------------------------------------------------------HIT\n\n");
                break;
            }
        }
        if(flag!=1){
            pos=findOPTIMAL(occur,fr,rs,f,n,i);
            fr[pos]=rs[i];
            pf++;
            for(int k=0;k<f;k++){
                if(fr[k]==-1){
                    printf("\t\t");
                }
                else{
                    printf("\t\t%d",fr[k]);
                }    
            }
            printf("\t\tPAGEFAULT\n\n");         
        }
    }
    printf("\nThe no: of page faults = %d.",pf);
    printf("\nThe no: of hits = %d.\n",hits);
}