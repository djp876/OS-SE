#include<stdio.h>
void sort_type(int n);
void sort_at(int n);
void wt_tat(int n);
void swap(int i,int j);
void sort_pid(int n);
struct data
{
	int p,a,b,c,w,t,type;
}s[10];
void main()
{
	int n,i,j;
	float avg_wt,avg_tat,sum_wt=0,sum_tat=0;
	printf("Enter how many number of processes : ");
	scanf("%d",&n);
	printf("Enter Process Id's : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i].p);
	}
	printf("Enter Arrival Times : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i].a);
	}
	printf("Enter Burst Times : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i].b);
	}
	printf("Enter type of process (0 for system and 1 for user process type) : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i].type);
	}
	sort_type(n);
	sort_at(n);
	s[0].c=s[0].b;
	for(i=1;i<n;i++)
	{
		s[i].c=s[i-1].c+s[i].b;
	}
	wt_tat(n);
	for(i=0;i<n;i++)
	{
		sum_wt=sum_wt+s[i].w;
		sum_tat=sum_tat+s[i].t;
	}
	avg_wt=sum_wt/n;
	avg_tat=sum_tat/n;
	sort_pid(n);
	printf("\nPID\tAT\tBT\tTYPE\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",s[i].p,s[i].a,s[i].b,s[i].type,s[i].c,s[i].t,s[i].w);
	}
	printf("\nAverage Waiting Time = %f\n",avg_wt);
	printf("Average Turn Around Time = %f\n\n",avg_tat);
}
void sort_type(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(s[i].type>s[j].type)
			{
				swap(i,j);
			}
		}
	}
}
void sort_at(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(s[i].a>s[j].a && s[i].type==s[j].type)
			{
				swap(i,j);
			}
		}
	}
}
void wt_tat(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		s[i].t=s[i].c-s[i].a;
		s[i].w=s[i].t-s[i].b;
	}
}
void swap(int i,int j)
{
	struct data temp;
	temp=s[i];
	s[i]=s[j];
	s[j]=temp;
}
void sort_pid(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(s[i].p>s[j].p)
			{
				swap(i,j);
			}
		}
	}
}
/*Output:
Enter how many number of processes : 3
Enter Process Id's : 1 2 3
Enter Arrival Times : 3  3 20
Enter Burst Times : 20 20 20
Enter type of process (0 for system and 1 for user process type) : 
1
1
1

PID	AT	BT	TYPE	CT	TAT	WT
1	3	20	1	20	17	-3
2	3	20	1	40	37	17
3	20	20	1	60	40	20

Average Waiting Time = 11.333333
Average Turn Around Time = 31.333334
*/
