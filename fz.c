#include<stdio.h>
#include<omp.h>
#include<time.h>
int min(int a,int b)
{
	return(a<b)?a:b;
}
void floyds(int cost[10][10],int n)
{
        int i,j,k;
        #pragma omp parallel private(i,j,k)
        shared(cost)for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
}

void main()
{
        int n,cost[10][10],source,i,j;
        double start,end;
        printf("enter the no of vertices of th the graph");
        scanf("%d",&n);
        printf("enter the cost matrix of the graph\n");
        for(i=1;i<n;i++)
        for(j=1;j<n;j++)
        {
                scanf("%d",&cost[i][j]);
        }
        start=omp_get_wtime();
        floyds(cost,n);
        end=omp_get_wtime();
        for(i=1;i<n;i++)
        {
                for(j=1;j<n;j++)
                {
                        printf("%d\t",cost[i][j]);
                }
        }
        printf("Timre taken= %10.9f\n",(double)(end-start));
}

