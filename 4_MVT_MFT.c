//MVT
#include<stdio.h>
int main()
{
 int i,m,n,tot,s[20];
 printf("Enter total memory size:");
 scanf("%d",&tot);
 printf("Enter no. of pages:");
 scanf("%d",&n);
 printf("Enter memory for OS:");
 scanf("%d",&m);
 for(i=0;i<n;i++)
 {
 printf("Enter size of page%d:",i+1);
 scanf("%d",&s[i]);
 }
 tot=tot-m;
 for(i=0;i<n;i++)
 {
 if(tot>=s[i])
 {
 printf("Allocate page %d\n",i+1);
 tot=tot-s[i];
 }
 else
 printf("process p%d is blocked\n",i+1);
 }
printf("External Fragmentation is=%d",tot);
}
/*Output:
Enter total memory size:80
Enter no. of pages:2
Enter memory for OS:23
Enter size of page1:52
Enter size of page2:57
Allocate page 1
process p2 is blocked
External Fragmentation is=5
*/
//MFT
#include<stdio.h>
int main()
{
int m,p,s,p1;
int m1[4],i,f,f1=0,f2=0,fra1,fra2,s1,pos;
printf("Enter the memory size:"); scanf("%d",&m);
printf("Enter the no of partitions:"); scanf("%d",&p);
s=m/p;
printf("Each partn size is:%d",s); printf("\nEnter the no of processes:"); scanf("%d",&p1);
pos=m;
for(i=0;i<p1;i++)
{
if(pos<s)
{
printf("\nThere is no further memory for process%d",i+1); m1[i]=0;
break;
}
else
{
printf("\nEnter the memory req for process%d:",i+1); scanf("%d",&m1[i]);
if(m1[i]<=s)
{
printf("\nProcess is allocated in partition%d",i+1); fra1=s-m1[i];
printf("\nInternal fragmentation for process is:%d",fra1); f1=f1+fra1;
pos=pos-s;
}
else
{
printf("\nProcess not allocated in partition%d",i+1); s1=m1[i];
while(s1>s)
{
s1=s1-s;pos=pos-s;
}
pos=pos-s;fra2=s-s1;f2=f2+fra2;
printf("\nExternal Fragmentation for this process is:%d",fra2);
}
}
}
printf("\nProcess\tallocatedmemory");
for(i=0;i<p1;i++)
printf("\n%5d\t%5d",i+1,m1[i]);
f=f1+f2;
printf("\nThe tot no of fragmentation is:%d",f);
return 0;
}
/*Output:
Enter the memory size:80
Enter the no of partitions:4
Each partn size is:20
Enter the no of processes:2
Enter the memory req for process1:18
Process is allocated in partition1
Internal fragmentation for process is:2
Enter the memory req for process2:18
Process is allocated in partition2
Internal fragmentation for process is:2
Process	 allocatedmemory
    1	   18
    2	   18

The tot no of fragmentation is:4
*/
