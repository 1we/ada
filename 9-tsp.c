/*TSP*/
#include<stdio.h>
#include<stdlib.h>
int cost[20][20];
int tsp(int path[20],int start,int n)
{
int i,j,k,temp[20],mintour[20],mincost,ccost;
if(start==n-1)
return cost[path[n-1]][path[n]]+cost[path[n]][1];
mincost=999;
for(i=start+1;i<=n;i++)
{
for(j=1;j<=n;j++)
temp[j]=path[j];
temp[start+1]=path[i];
temp[i]=path[start+1];
if(cost[path[start]][path[i]]+(ccost=tsp(temp,start+1,n))<mincost)
{
mincost=cost[path[start]][path[i]]+ccost;
for(k=1;k<=n;k++)
mintour[k]=temp[k];
}
}
for(i=1;i<=n;i++)
path[i]=mintour[i];
return mincost;
}

int atsp(int path[10],int start,int n)
{
int i,j,min,s,count=1,next,mincost=0,visit[10];
for(i=1;i<=n;i++ )
visit[i]=0;
visit[start]=1;
path[count++]=start;
s=start;
for(i=1;i<=n;i++)
{
min=999;
for(j=1;j<=n;j++)
{
if(visit[j]==0&&min>cost[start][j])
{
min=cost[start][j];
next=j;
}
}
visit[next]=1;
if(cost[start][next]!=999)
mincost=mincost+cost[start][next];
path[count++]=next;
start=next;
}
count--;
mincost=mincost+cost[path[count-1]][s];
return mincost;
}
int main()
{
int n,i,j,path[20],mincost,amincost;
float ratio;
clrscr();
system("clear");
printf("enter no of cities");
scanf("%d",&n);
printf("enter rhe cost matrix and enter 99 for no correction:\n" );
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&cost[i][j]);
for(i=1;i<=n;i++)
path[i]=i;
printf("tsp using dynamic programing\m");
mincost=tsp(path,1,n);
printf("tsp  tour is:");
for(i=1;i<=n;i++)
printf("%d----->",path[i]);
printf("1\n");
printf("tsp tour cost=%d\n",mincost);
for(i=1;i<=n;i++)
path[i]=i;
printf("tsp using approximation algorithem\n");
amincost=atsp(path,1,n);
printf("tsp tour is:");
for(i=1;i<=n;i++)
printf("%d----.",path[i]);
printf("1\n");
printf("tsp your cost=%d\n",amincost);
ratio=(float)amincost/mincost;
printf("accuracy ratio=%f",ratio);
getch();
return;
}