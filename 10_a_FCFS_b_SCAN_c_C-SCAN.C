//10_Simulate disk scheduling algorithms a. FCFS b. SCAN c.C-SCAN
//a_FCFS
#include<stdio.h>
#include<stdlib.h>
int main()
{
int p[20],head,n,i,seek=0,diff=0;
printf("Enter queue size:");
scanf("%d",&n);
printf("Enter the processes in queue:\n");
for(i=1;i<=n;i++)
scanf("%d",&p[i]);
printf("Enter current read/write head:");
scanf("%d",&head);
p[0]=head;
for(i=0;i<=n-1;i++)
{
diff=abs(p[i+1]-p[i]);
seek+=diff;
}
printf("Total seek time: %d\n",seek);
}
/*
o/p:
Enter queue size:7
Enter the processes in queue:
82 170 43 140 24 16 190
Enter current read/write head:50
Total seek time: 642
*/
//b_SCAN
#include<stdio.h>
#include<stdlib.h>
int main()
{
 int 
queue[20],n,head,i,j,k,seek=0,max,diff,temp,queue1[20],queue2[20],temp
1=0,temp2=0;
 float avg;
 printf("Enter max range of disk:");
 scanf("%d",&max);
 printf("Enter initial head position:");
 scanf("%d",&head);
 printf("Enter size of queue request:");
 scanf("%d",&n);
 printf("Enter queue of disk positions to read:\n");
 for(i=1;i<=n;i++)
 {
 scanf("%d",&temp);
 if(temp>=head)
 {
 queue1[temp1]=temp;
 temp1++;
 }
 else
 {
 queue2[temp2]=temp;
 temp2++;
 }
 }
 for(i=0;i<temp1-1;i++)
 {
 for(j=i+1;j<temp1;j++)
 {
 if(queue1[i]>queue1[j])
 {
 temp=queue1[i];
 queue1[i]=queue1[j];
 queue1[j]=temp;
 }
 }
 }
 for(i=0;i<temp2-1;i++)
 {
 for(j=i+1;j<temp2;j++)
 {
 if(queue2[i]<queue2[j])
 {
 temp=queue2[i];
 queue2[i]=queue2[j];
 queue2[j]=temp;
 }
 }
 }
 for(i=1,j=0;j<temp1;i++,j++)
 queue[i]=queue1[j];
 queue[i]=max;
 for(i=temp1+2,j=0;j<temp2;i++,j++)
 queue[i]=queue2[j];
 queue[i]=0;
 queue[0]=head;
 for(j=0;j<=n;j++)
 {
 diff=abs(queue[j+1]-queue[j]);
 seek+=diff;
 printf("Disk head moves from %d to %d with seek %d\
n",queue[j],queue[j+1],diff);
 }
 printf("TOtal seek time is:%d\n",seek);
 avg=seek/(float)n;
 printf("Average seek time is %f\n",avg);
 return 0;
}
/*
o/p: 
Enter max range of disk:199
Enter initial head position:50
Enter size of queue request:7
Enter queue of disk positions to read:
82 170 43 140 24 16 190
Disk head moves from 50 to 82 with seek 32
Disk head moves from 82 to 140 with seek 58
Disk head moves from 140 to 170 with seek 30
Disk head moves from 170 to 190 with seek 20
Disk head moves from 190 to 199 with seek 9
Disk head moves from 199 to 43 with seek 156
Disk head moves from 43 to 24 with seek 19
Disk head moves from 24 to 16 with seek 8
TOtal seek time is:332
Average seek time is 47.428570
*/
//c_C-SCAN
#include<stdio.h>
#include<stdlib.h>
int main()
{
 int 
queue[20],n,head,i,j,k,seek=0,max,diff,temp,queue1[20],queue2[20],temp
1=0,temp2=0;
 float avg;
 printf("Enter max range of disk:");
 scanf("%d",&max);
 printf("Enter initial head position:");
 scanf("%d",&head);
 printf("Enter size of queue request:");
 scanf("%d",&n);
 printf("Enter queue of disk positions to read:\n");
 for(i=1;i<=n;i++)
 {
 scanf("%d",&temp);
 if(temp>=head)
 {
 queue1[temp1]=temp;
 temp1++;
 }
 else
 {
 queue2[temp2]=temp;
 temp2++;
 }
 }
 for(i=0;i<temp1-1;i++)
 {
 for(j=i+1;j<temp1;j++)
 {
 if(queue1[i]>queue1[j])
 {
 temp=queue1[i];
 queue1[i]=queue1[j];
 queue1[j]=temp;
 }
 }
 }
 for(i=0;i<temp2-1;i++)
 {
 for(j=i+1;j<temp2;j++)
 {
 if(queue2[i]>queue2[j])
 {
 temp=queue2[i];
 queue2[i]=queue2[j];
 queue2[j]=temp;
 }
 }
 }
 for(i=1,j=0;j<temp1;i++,j++)
 queue[i]=queue1[j];
 queue[i]=max;
 queue[i+1]=0;
 for(i=temp1+3,j=0;j<temp2;i++,j++)
 queue[i]=queue2[j];
 queue[0]=head;
 for(j=0;j<=n+1;j++)
 {
 diff=abs(queue[j+1]-queue[j]);
 seek+=diff;
 printf("Disk head moves from %d to %d with seek %d\
n",queue[j],queue[j+1],diff);
 }
 printf("TOtal seek time is:%d\n",seek);
 avg=seek/(float)n;
 printf("Average seek time is %f\n",avg);
 return 0;
}
/*
o/p: 
Enter max range of disk:199
Enter initial head position:50
Enter size of queue request:7
Enter queue of disk positions to read:
82 170 43 140 24 16 190
Disk head moves from 50 to 82 with seek 32
Disk head moves from 82 to 140 with seek 58
Disk head moves from 140 to 170 with seek 30
Disk head moves from 170 to 190 with seek 20
Disk head moves from 190 to 199 with seek 9
Disk head moves from 199 to 0 with seek 199
Disk head moves from 0 to 16 with seek 16
*/
