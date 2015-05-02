#include<stdio.h>
#include<conio.h>

int i,j,n,f=0,r=0,a[10][10],visited[10],q[10];

void bfs(int u)
{
	int v;
	visited[u]=1;
	q[r]=u;
	while(f<=r)
	{
		u=q[f++];
		for(v=1;v<n;v++)
		{
			if(a[u][v]==1 && visited[v]== 0)
			{
				visited[v]=1;
				q[++r]=1;
			}
		}
	}
}
void main()
{
	int source;
	clrscr();
	printf(" Enter the no of vertices\n");
	scanf("%d",&n);
	printf("Enter the adjacencymatrix of Directed Graph\n");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	printf("enter the source vertex\n");
	scanf("%d",&source);
	for(i=1;i<n;i++)
	visited[i]=0;
	bfs(source);
	printf("From soure vertex %d the vertes \n",source);
	for(i=1;i<n;i++)
	{
		if(visited[i]=1)
		printf("%d is reachable \n",i);
	}
getch();
}
	
	