/* Dijkshtra's Algorithum (directed graph)5*/
#include<stdio.h>
#include<conio.h>
#define infinity 999
void dijkstra(int n,int v,int cost[10][10],int dist[])
{
int i,u,count,w,visited[10],min;
for(i=1;i<=n;i++)
{
visited[i]=0;
dist[i]=cost[v][i];
}
visited[v]=1;
dist[v]=0;
count=2;
while(count<n)
{
min=999;
for( i=1;i<=n;i++)
{
if(dist[i]<min && visited[i]==0)
{
min=dist[i];
u=i;
}
}
visited[u]=1;
count++;
for(w=1;w<=n;w++)
{
if (visited[w]==0)
{
if(dist[u]+cost[u][w]<dist[w])
dist[w]=dist[u]+cost[u][w];
}
}
}
}
void main()
{
int n,v,i,j,cost[10][10],dist[10];
clrscr();
printf("\n enter the number of vertices of the directed graph: \t");
scanf("%d",&n);
printf("\n enter the cost matrix : \n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
scanf("%d", &cost[i][j]);
if(cost[i][j]==0)
cost[i][j]=infinity;
}
printf("\n enter source vertex : \n");
scanf("%d",&v);
dijkstra(n,v,cost,dist);
printf("\n shortest path : \n");
for(i=1;i<=n;i++)
if(i!=v)
printf("%d->%dcost =%d\n",v,i,dist[i]);
getch();
}