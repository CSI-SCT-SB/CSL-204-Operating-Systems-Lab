#include <stdio.h>
void main()
{
	int i,j,n,m,fnd,pg[100],fr[100],k=0,cnt=0;
	printf("ENTER THE NUMBER OF PAGES : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("ENTER THE PAGE NUMBER %d: ",i+1);
		scanf("%d",&pg[i]);
	}
	printf("ENTER THE NUMBER OF FRAMES : ");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		fr[i]=-1;
	}
	printf("\n\tREFERENCE STRING\t PAGE NUMBER\t\t  STATUS\n");
	for(i=0;i<n;i++)
	{
		fnd=0;
		printf("\t\t%d\t\t",pg[i]);
		for(j=0;j<m;j++)
		{
			if(fr[j]==pg[i])
			{
				fnd = 1;
			}
		}
		if(fnd == 0)
		{
			fr[k] = pg[i];
			k = (k+1)%m;
			cnt++;
		}
		for(j=0;j<m;j++)
		{
			if(fr[j] != -1)
			{
				printf("%d   ",fr[j]);
			}
		}
		if(fnd==1)
		{
			printf("\t\tHIT\n");
		}
		else
		{
			printf("\t\tMISS\n");
		}
	}
	printf("\nPAGE FAULT : %d\n",cnt);
}
