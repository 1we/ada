#include<stdio.h>
#include<omp.h>
#include<time.h>
void merge(int a[],int b[],int c[],int p,int q,int n)
{
	int i,j,k;
	i=j=k=0;
	while(i<p&&j<q)
	{
		if(b[i]<=c[j])
		{
			a[k]=b[i];
			i++;
		}
		else
		{
			a[k]=c[j];
			j++;
		}
		k++;
	}	
	if(i==p)
	{
			while(j<q)
			{
				a[k]=c[j];
				k++;
				j++;
			}
	}
	else
	{
		while(i<p && k<n)
			a[k++]=b[i++];
	}
}
void mergesort(int a[],int n)
{
	int b[5000],c[5000],i,j;
	if(n>1)
	{
	for(i=0;i<n/2;i++)
	b[i]=a[i];
	for(i=n/2,j=0;i<n;i++,j++)
	c[j]=a[i];
	#pragma omp parallel sections
	{
	#pragma omp section
	mergesort(b,n/2);
	#pragma omp section
	mergesort(c,n-n/2);
	}
	merge(b,c,a,n/2,n-n/2,n);
	}
}
int main()
	{
		int a[5000],j,i,n;
		double start,end;
		printf("enter the value of n\n");
		scanf("%d",&n);
		srand(1);
		for(i=0;i<n;i++)
			a[i]=rand();
		start=omp_get_wtime();
		mergesort(a,n);
		end=omp_get_wtime();
		printf("sorted array is \n");
		for(i=0;i<n;i++)
		printf("\n %d",a[i]);
		printf("\n time taken = %10.9f seconds \n",(double)(end-start));
		return 0;
	}
