//a_Sequential
#include<stdio.h>
int main()
{
int f[50],i,st,j,len,c,k;
for(i=0;i<50;i++)
f[i]=0;
printf("\n Enter the starting block & length of file");
scanf("%d%d",&st,&len);
for(j=st;j<(st+len);j++)
if(f[j]==0)
{
f[j]=1;
printf("\n%d->%d",j,f[j]);
}
else
{
printf("Block already allocated");
break;
}
if(j==(st+len))
printf("\n the file is allocated to disk");
else
return 0;
}
/*Output:
Enter the starting block & length of file2 5
2->1
3->1
4->1
5->1
6->1
 the file is allocated to disk
*/
//b_Indexed
#include<stdio.h>
int f[50],i,k,j,inde[50],n,c,count=0,p;
int main()
{
for(i=0;i<50;i++)
f[i]=0;
printf("enter index block\t");
scanf("%d",&p);
if(f[p]==0)
{
f[p]=1;
printf("enter no of files on index\t");
scanf("%d",&n);
}
else
{
printf("Block already allocated\n");
}
for(i=0;i<n;i++)
scanf("%d",&inde[i]);
for(i=0;i<n;i++)
if(f[inde[i]]==1)
{
printf("Block already allocated");
}
for(j=0;j<n;j++)
f[inde[j]]=1;
printf("\n allocated");
printf("\n file indexed");
for(k=0;k<n;k++){
    printf("\n %d->%d:%d",p,inde[k],f[inde[k]]);
}
}
/*Output:
enter index block	9
enter no of files on index	3
1 2 3
allocated
 file indexed
 9->1:1
 9->2:1
 9->3:1
*/
//c_Linked
#include<stdio.h>
int main()
{
int f[50],p,i,j,k,a,st,len,n,c;
for(i=0;i<50;i++)
f[i]=0;
printf("Enter how many blocks that are already allocated");
scanf("%d",&p);
printf("\nEnter the blocks no.s that are already allocated");
for(i=0;i<p;i++)
{
scanf("%d",&a);
f[a]=1;
}
printf("Enter the starting index block & length");
scanf("%d%d",&st,&len);
k=len;
for(j=st;j<(k+st);j++)
{
if(f[j]==0)
{
f[j]=1;
printf("\n%d->%d",j,f[j]);
}
else
{
printf("\n %d->file is already allocated",j);
k++;
}
}
}
/*Output:
Enter how many blocks that are already allocated3
Enter the blocks no.s that are already allocated4 7 9 
Enter the starting index block & length3
7
3->1
 4->file is already allocated
5->1
6->1
 7->file is already allocated
8->1
 9->file is already allocated
10->1
11->1
12->1
*/
