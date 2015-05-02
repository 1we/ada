/* Warshall's algorithm 3b*/
#include<stdio.h>
#include<conio.h>
void warshall(int cost[10][10], int n){
	int i, j, k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				cost[i][j]=cost[i][j]||cost[i][k]&&cost[k][j];
	}

void main(){
	int n, cost[10][10], i, j;
	clrscr();
	printf("Enter the no of vertices of graph\n");
	scanf("%d",&n);
	printf("Enter the adjancy matrix\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);
	}
	warshall(cost,n);
	printf("The path matrix is \n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d\t",cost[i][j]);
			}
		printf("\n");
	}
	getch();
}
