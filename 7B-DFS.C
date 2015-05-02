#include<stdio.h>
#include<conio.h>
int a[10][10],visited[10],n;

void dfs(int u)
{
	int v;
	visited[u]=1;
	for(v=1;v<n;v++)
	if(a[u][v]==1&& visited[v]==0)
	dfs(v);
	}
	
	void main()
	{
		int n,i,j,source;
		clrscr();
		printf("Enter the no of vertices of the ud graph priffred\n");
		scanf("%d",&n);
		printf("Enter the adjacencymatrix of Directed Graph\n");
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	for(i=1;i<n;i++)
	visited[i]=0;
	for(i=1;i<n;i++)
	{
		dfs(i);
		for(j=1;j<n;j++)
		{
			if(visited[j]!=1)
			{
				printf("%d is not reachable from %d\n",j,i);
				printf("so graph is not connected");
				getch();
				exit(0);
			}
		}
	for(j=1;j<n;j++)
	visited[j]=0;
}
printf("graph is connected\n");
getch();
}
