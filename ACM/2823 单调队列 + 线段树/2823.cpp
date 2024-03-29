#include <stdio.h>

#define MAX 1000000

int A[MAX];
int P[MAX];
int n,k;

void GetMin()
{
	int i;
	int head=1,tail=0;
	for(i=0;i<k-1;i++)
	{
		while(head<=tail&&A[P[tail]]>=A[i])
			--tail;
		P[++tail]=i;
	}

	for(i=k-1;i<n;i++)
	{
		while(head<=tail&&A[P[tail]]>=A[i])
			--tail;
		P[++tail]=i;

		while(P[head]<i-k+1&&head<=tail)
		{
			head++;
		}

		printf("%d ",A[P[head]]);
	}

	printf("\n");
}

void GetMax()
{
	int i;
	int head=1,tail=0;
	for(i=0;i<k-1;i++)
	{
		while(head<=tail&&A[P[tail]]<=A[i])
			--tail;
		P[++tail]=i;
	}

	for(i=k-1;i<n;i++)
	{
		while(head<=tail&&A[P[tail]]<=A[i])
			--tail;
		P[++tail]=i;

		while(P[head]<i-k+1&&head<=tail)
		{
			head++;
		}

		printf("%d ",A[P[head]]);
	}

	printf("\n");
}

int main(int argc, char *argv[])
{
	while(scanf("%d %d",&n,&k)==2)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);

		GetMin();
		GetMax();
	}
	
	return 0;
}
