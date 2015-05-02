/* Krushkal's algorthum for tree of given undirected graph to find min cost spanning tree */
#include<stdio.h>
#include<conio.h>
int parent[10];
void main()
{
int mincost=0,cost[10][10],n,i,j,ne,a,b,min,u,v;
clrscr();
printf("enter the no of vertices of the graph\n");
scanf("%d ",&n);
printf("enter the cost matrix\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
if(cost[i][j]==0)
cost[i][j]=999;
}
for(i=1;i<=n;i++)
parent[i]=0;
ne=1;
printf("the edge of minimum spanning tree are: \n");
while(ne<n)
{
for(min=999,i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(cost[i][j]<min)
{
min=cost[i][j];
a=u=i;
b=v=j;
}
while(parent[u])
u=parent[u];
while(parent[v])
v=parent[v];
if(v!=u)
{
printf("%d edge(%d%d)=%d\n",ne++,a,b,min);
mincost+=min;
parent[b]=a;
}
cost[a][b]=cost[b][a]=999;
}
printf("the minimum cost of spanning tree is %d\n",mincost);
getch();
}