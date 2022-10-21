#include<stdio.h>
#include<stdlib.h>
void main()
{
     int n,i,ind,j,t,h,q[20],count=0,low=0,max=199;
     printf("Enter the length of queue:");
     scanf("%d",&n);
     printf("Enter the header:");
     scanf("%d",&h);
     n++;
     printf("Enter the queue: ");
     for(i=1;i<n;i++)
     {
       scanf("%d",&q[i]);
     }  
     q[0]=h;
     q[i++]=max;
     n++;
    
	for(i=0;i<n;i++)
	{	
		for(j=0;j<n-1-i;j++)
		{
			if(q[j]>=q[j+1])
			{
				t=q[j];
				q[j]=q[j+1];
				q[j+1]=t;
			}
		}
	}
	
	for (i = 0; i < n; i += 1)
	{
		if(q[i]==h)
			ind=i;
	}
	
     for(i=ind;i<n;i++)
	{
		printf("%d->",q[i]);
	}
     printf("%d->",low);
     for(i=0;i<ind-1;i++)
	{
		printf("%d->",q[i]);		
	}
     printf("%d",q[i]);

     count=((q[n-1]-q[ind])+(q[n-1]-low)+(q[ind-1]-low));
     printf("\nThe total disk movement is:%d\n",count);
     
}       
    
