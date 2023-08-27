#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i,j,n,f,min;
    int next=0,pf=0;
    int pg[30],fr[30],count[20],flag[20];

    printf("\n enter the no. of pages: ");
    scanf("%d",&n);

    printf("\n enter the sequence: ");
    for(i=0;i<n;i++)
    {
        flag[i]=0;
        scanf("%d",&pg[i]);
    }

    printf("\n enter the frame no.: ");
    scanf("%d",&f);

    printf("\n the lru page replacement process\n");
    for(i=0;i<f;i++)
    {
        count[i]=0;
        fr[i]=-1;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<f;j++)
        {
            if(fr[j]==pg[i])
            {
                flag[i]=1;
                count[j]=next;
                next++;
            }
        }
        if(flag[i]==0)
        {
            if(i<f)
            {
                fr[i]=pg[i];
                count[i]=next;
                next++;
            }
            else
            {
                min=0;
                for(j=0;j<f;j++)
                if(count[min]>count[j])
                min=j;
                fr[min]=pg[i];
                count[min]=next;
                next++;
            }
            pf++;
        }

        for(j=0;j<f;j++)
        printf("\t%d",fr[j]);

        if(flag[i]==0)
        printf("\t PF NO.%d",pf);

        printf("\n");

    }
    printf("\n total no. of page fault: %d",pf);
}