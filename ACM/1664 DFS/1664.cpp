#include <stdio.h>

int dfs(int n,int pre,int l)
{
	if(n==0)
		return 1;

	if(l==1&&n>pre)
		return 0;
	else if(l==1)
		return 1;



	int sum=0;
	int start=(pre<n)?pre:n;
	for(int i=start;i>=0;i--)
	{
		int  tmp = dfs(n-i,i,l-1);

		sum+=tmp;
	}

	//printf("%d %d\n",sum,l);

	return sum;
}

int main(int argc, char *argv[])
{
	int a,b,c;
	scanf("%d",&a);

	for(int i=0;i<a;i++)
	{
		scanf("%d %d",&b,&c);
		int ans=dfs(b,b,c);

		printf("%d",ans);
	}
	
	return 0;
}
