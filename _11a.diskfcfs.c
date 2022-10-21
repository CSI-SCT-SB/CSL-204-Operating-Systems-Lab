#include<stdio.h>
#include<stdlib.h>
void main()
{
     int n,i,h,q[20],count=0;
     printf("Enter the length of queue:");
     scanf("%d",&n);
     printf("Enter the header:");
     scanf("%d",&h);
     printf("Enter the queue: ");
     for(i=1;i<(n+1);i++)
     {
       scanf("%d",&q[i]);
     }  
     q[0]=h;
     for(i=0;i<n;i++)
     {  
         count+=abs(q[i]-q[i+1]);
     }
     printf("The order of movement:\n");
     for(i=0;i<n+1;i++)
     {
         if(i==n)
		printf("%d",q[i]);
         else
		printf("%d->",q[i]);
     }
   
     printf("\nThe total disk movement is:%d\n",count);
     
}       
