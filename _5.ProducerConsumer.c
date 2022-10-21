#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
int main()
{
 int n;
 int wait(int s)
 {
 return (--s);
 }
 int signal(int s)
 {
 return(++s);
}
void producer()
{
mutex=wait(mutex);
full=signal(full);
empty=wait(empty);
x++;
printf("Item %d produced\n",x);
mutex=signal(mutex);
}
void consumer()
{
mutex=wait(mutex);
full=wait(full);
empty=signal(empty);
printf("Item %d consumed\n",x);
x--;
mutex=signal(mutex);
}
printf("\n1.Producer 2.Consumer 3.Exit\n");
while(1)
{
printf("\nEnter your choice:");
scanf("%d",&n);
switch(n)
{
case 1: if((mutex==1)&&(empty!=0))
producer();
else
printf("\nBuffer is full!\n");
break;
case 2: if((mutex==1)&&(full!=0))
consumer();
else
printf("\nBuffer is empty!\n");
break;
default: exit(0);
break;
}
}
return 0;
}
