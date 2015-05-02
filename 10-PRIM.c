/* To Find min Spanning Tree of give Undirected Graph using Prim's Algo*/
#include<stdio.h>
#include<conio.h>
int i,j,k,a,b,v,u,n,ne=1;
int visited[9],min,mincost=0,cost[9][9];
void main()
{
clrscr();
printf("\n enter the number of vertices: ");
scanf("%d",&n);
printf("enter the cost matrix of the graph:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
if(cost[i][j]==0)
cost[i][j]=999;
}
printf("\n");
for(i=2;i<=n;i++)
visited[i]=0;
printf("the edges of spanning tree are:\n\n");
printf("----------------------------\n");
visited[1]=1;
while(ne<n)
{
for(i=1,min=999;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(cost[i][j]<min)
{
if(visited[i]==1)
{
min=cost[i][j];
a=u=i;
b=v=j;
}
}
}
}
if(visited[u]==0||visited[v]==0)
{
printf("%d edge(%d,%d)=%d\n",ne++,a,b,min);
mincost+=min;
visited[b]=1;
}
cost[a][b]=cost[b][a]=999;
}
printf("\n\nMINCOST=%d\n",mincost);
getch();
}