/*knapsack demo 4 */
#include<stdio.h>
#include<conio.h>
int max(int a,int b)
   {
   if(a>b)
   return a;
   else
   return b;
   }
void main()
{
int n,j,i,capacity;
int weight[20],value[20];
int v[50][50],w;
clrscr();
printf("\n\n\t\t enter the number of items");
scanf("%d",&n);
printf("\t\t---------\n");
printf("\n\t\t enter : WEIGHTS-VALUES\n");
printf("\t\t----------\n");
printf("\t\t\----------\n\t\t");
for(i=1;i<=n;i++)
{
scanf("%d",&weight[i]);
scanf("%d",&value[i]);
printf("\t\t");
}
printf("------------\n");
printf("\t\t enter the capacity of knapsack: ");
scanf("%d",&capacity);
printf("\t\t----\n\t\t");
for(i=0;i<=n;i++)
{
for(j=0;j<=capacity;j++)
{
if(i==0||j==0)
{
v[i][j]=0;
}
else if(j-weight[i]>=0)
{
v[i][j]=max(v[i-1][j],v[i-1][j-weight[i]]+value[i]);
}
else
{
v[i][j]=v[i-1][j];
}
printf("%4d",v[i][j]);}
printf("\n\t\t");
} w=capacity;printf("the items in the knapsack: \n");
for(i=n;i>0;i--)
{
printf("\t\t");
if(v[i][w]==v[i-1][w])
continue ;
else
{
w=w-weight[i];
printf("%3d",i);}
}
printf("\n\t\t total profit=%d",v[n][capacity]);
getch();
}