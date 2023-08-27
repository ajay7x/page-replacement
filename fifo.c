#include<stdio.h>
#include<stdlib.h>
struct fifo
{
    int pg,fr;
}
p[20];
int main()
{
    int i,j,k,n,f;
    int pf=0,count=0;
printf("\n enter the no. of pages:");
scanf("%d",&n);
 printf("\n enter the pages: ");
for(i=0;i<n;i++)
{
 scanf("%d",&p[i].pg);

} 
printf("\n enter the frame no.: ");
scanf("%d",&f);

printf("\n the page replacement process-----\n");

for(i=0;i<f;i++)
{
    p[i].fr=-1;   
}

for(i=0;i<n;i++)
{
    for(k=0;k<f;k++)
    {
        if(p[k].fr==p[i].pg)
        break;
    }
    if(k==f)
    {
        p[count++].fr=p[i].pg;
        pf++;   
    }
    
    for(j=0;j<f;j++)
    printf("\t%d",p[j].fr);

    if(k==f)
    printf("\t PF NO. %d",pf);

    printf("\n");

    if(count==f)
        count=0;
}
 printf("\n no. of page fault occured: %d",pf);

 return 0;
}