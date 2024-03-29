#include <stdio.h>
#include <stdlib.h>

#define VAL 100

int Max(int a[],int b)
{
	int max=-0xefff;
	int thismax=0;
	for(int i=0;i<b;i++)
	{
		thismax+=a[i];
		if(thismax>max)
			max=thismax;
		if(thismax<0)
			thismax=0;
	}
	return max;
}

int v[VAL][VAL];
int col[VAL][VAL+1];
int temp[VAL];

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;i++)
		{
			col[i][0]=0;
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&v[i][j-1]);

				col[i][j]=col[i][j-1]+v[i][j-1];
			}
		}

		int maxValue=0;
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++)
			{
				for(int k=0;k<n;k++)
					temp[k]=col[k][j+1]-col[k][i];

				int p=Max(temp,n);
				if(p>maxValue)
					maxValue=p;
			}
		printf("%d",maxValue);
	}
}
