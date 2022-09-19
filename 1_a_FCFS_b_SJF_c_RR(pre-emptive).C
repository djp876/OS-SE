//FCFS
#include<stdio.h>
void main()
{
 int i,n,sum,wt,tat,twt,ttat;
 int t[10];
 float awt,atat;
 printf("Enter number of processors:\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("\n Enter the Burst Time of the process %d",i+1);
 scanf("\n %d",&t[i]);
 }
 printf("\n\n FIRST COME FIRST SERVE SCHEDULING ALGORITHM \n");
 printf("\n Process ID \t Waiting Time \t Turn Around Time \n");
 printf("1 \t\t 0 \t\t %d \n",t[0]);
 sum=0;
 twt=0;
 ttat=t[0];
 for(i=1;i<n;i++)
 {
 sum+=t[i-1];
 wt=sum;
 tat=sum+t[i];
 twt=twt+wt;
 ttat=ttat+tat;
 printf("\n %d \t\t %d \t\t %d",i+1,wt,tat);
 printf("\n\n");
 }
 awt=(float)twt/n;
 atat=(float)ttat/n;
 printf("\n Average Waiting Time %4.2f",awt);
 printf("\n Average Turnaround Time %4.2f",atat);
}
/*
O/P:
Output:
Enter number of processors:
2
Enter the Burst Time of the process 120
Enter the Burst Time of the process 230
FIRST COME FIRST SERVE SCHEDULING ALGORITHM 

Process ID 	 Waiting Time 	 Turn Around Time 
1 		               0 		        20 

2 		              20 		        50

Average Waiting Time 10.00
Average Turnaround Time 35.00
*/
//SJF
#include<stdio.h>
#include<string.h> 
void main()
{
int et[20],at[10],n,i,j,temp,st[10],ft[10],wt[10],ta[10];
int totwt=0,totta=0;
float awt,ata;
char pn[10][10],t[10];
printf("Enter the number of process:"); scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter process name, arrival time & execution time:");
scanf("%s%d%d",pn[i],&at[i],&et[i]);
}
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
if(et[i]<et[j])
{
temp=at[i];
at[i]=at[j];
at[j]=temp;
temp=et[i];
et[i]=et[j];
et[j]=temp;
strcpy(t,pn[i]);
strcpy(pn[i],pn[j]);
strcpy(pn[j],t);
}
}
for(i=0;i<n;i++)
{
if(i==0)
st[i]=at[i]; else st[i]=ft[i-1];
wt[i]=st[i]-at[i];
ft[i]=st[i]+et[i];
ta[i]=ft[i]-at[i];
totwt+=wt[i];
totta+=ta[i];
}
awt=(float)totwt/n;
ata=(float)totta/n;
printf("\nPname\tarrivaltime\texecutiontime\twaitingtime\ttatime");
for(i=0;i<n;i++)
printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],et[i],wt[i],ta[i]); 
printf("\nAverage waiting time is:%f",awt);
printf("\nAverage turnaroundtime is:%f",ata);
}
/*Output:
Enter the number of process:3
Enter process name, arrival time & execution time:1 3 20
Enter process name, arrival time & execution time:2 3 20
Enter process name, arrival time & execution time:3 20 20
Pname	arrival time	execution time	waiting time	tatime
1	    3		   20		    0		   20
2	    3		   20		   20		   40
3	   20		   20		   23		   43
Average waiting time is:14.333333
Average turnaroundtime is:34.333332*/

//Round _Robin(pre-emptive)

#include<stdio.h>
void main()
{
int et[30],ts,n,i,x=0,tot=0; char pn[10][10];
printf("Enter the no of processes:"); 
scanf("%d",&n);
printf("Enter the time quantum:"); 
scanf("%d",&ts); for(i=0;i<n;i++)
{
printf("enter process name & estimated time:"); 
scanf("%s %d",pn[i],&et[i]);
}
printf("The processes are:"); 
for(i=0;i<n;i++)
printf("process %d: %s\n",i+1,pn[i]); 
for(i=0;i<n;i++)
tot=tot+et[i];
while(x!=tot)
{
for(i=0;i<n;i++)
{
if(et[i]>ts)
{
x=x+ts;
printf("\n %s -> %d",pn[i],ts);
et[i]=et[i]-ts;
}
else if((et[i]<=ts)&&et[i]!=0)
{
x=x+et[i];
printf("\n %s -> %d",pn[i],et[i]); et[i]=0;}
}
}
printf("\n Total Estimated Time:%d",x);
}
/*Output:
Enter the no of processes:2
Enter the time quantum:3
enter process name & estimated time:12 15
enter process name & estimated time:13 16
The processes are:process 1: 12
process 2: 13

 12 -> 3
 13 -> 3
 12 -> 3
 13 -> 3
 12 -> 3
 13 -> 3
 12 -> 3
 13 -> 3
 12 -> 3
 13 -> 3
 13 -> 1
 Total Estimated Time:31*/
