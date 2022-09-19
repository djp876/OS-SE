7_paging_technique_memory_management.
#include<stdio.h>
main()
{
int np,ps,i; int *sa;
printf("enter how many pages\n"); scanf("%d",&np);
printf("enter the page size \n"); scanf("%d",&ps); sa=(int*)malloc(2*np); for(i=0;i<np;i++)
{
sa[i]=(int)malloc(ps);
printf("page%d\t address %u\n",i+1,sa[i]);
}
}
/*
Output:
enter how many pages
5
enter the page size 
4
page1	 address 3546839776
page2	 address 3546839808
page3	 address 3546839840
page4	 address 3546839872
page5	 address 3546839904
*/
