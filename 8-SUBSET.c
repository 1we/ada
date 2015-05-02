/* Subset given of  +ve integers whose sum is equal a given +ve int's d */
#include<stdio.h>
#include<conio.h>
int flag=0,count;
int x[10],w[10],d,n,i,j;
void sum(int s,int k,int r)
{
x[k]=1;
if(s+w[k]==d)
{
printf("\nSubset %d:",++count);
flag=1;
for(i=0;i<=k;i++)
if(x[i])
printf("\n%3d",w[i]);
}
else if(s+w[k]+w[k+1]<=d)
{
sum(s+w[k],k+1,r-w[k]);
}
if((s+r-w[k]>=d)&&(s+w[k+1]<=d))
{
x[k]=0;
sum(s,k+1,r-w[k]);
}
}
void main()
{
int r=0,s,pos,temp;
clrscr();
printf("\nEnter the no. of elements\n");
scanf("\n%d",&n);
printf("\nEnter the elements\n");
for(i=0;i<n;i++)
scanf("\n%d",&w[i]);
for(i=0;i<n;i++)
{
pos=i;
for(j=i+1;j<n;j++)
{
if(w[j]<w[pos])
pos=j;
}
temp=w[i];
w[i]=w[pos];
w[pos]=temp;
}
printf("\nAfter sorting the elements are:\n");
for(i=0;i<n;i++)
printf("%d\t",w[i]);
printf("\nEnter the sum\n");
scanf("%d",&d);
for(i=0;i<n;i++)
x[i]=0;
for(i=0;i<n;i++)
r+=w[i];
if(r<d)
{
printf("\nNO subset possible\n");
flag=1;
}
else
sum(0,0,r);
if(flag==0)
printf("\nNo subset possible\n");
getch();
}
