/* Topological ordering of vertices in give directed graph (3a) */
#include<stdio.h>
#include<conio.h>
void main()
{
int i,w,j,n,cost[10][10],indeg[10],flag[10],count=0;
clrscr();
printf("\nEnter the no. of vertices\n");
printf("\n");
scanf("%d",&n);
printf("\nEnter the adjacency matrix\n");
printf("\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
}
}
for(i=1;i<=n;i++)
{
indeg[i]=0;
flag[i]=0;
}
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
indeg[i]=indeg[i]+cost[j][i];
}
count=0;
printf("\nThe topological order is\n");
while(count<n)
{
for(i=1;i<=n;i++)
{
if(indeg[i]==0 && !flag[i])
{
printf("\n%d\t",i);
flag[i]=1;
count++;
for(w=1;w<=n;w++)
if(cost[i][w]==1)
indeg[w]--;
}
}
getch();
}
}
}