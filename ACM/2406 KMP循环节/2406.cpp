#include <stdio.h>

#define MAX 1000010

char arr[MAX];
int next[MAX];

int GetNext(int n,char* a)
{
	int k=-1;
	int j=0;

	next[0]=-1;

	while(j<n)
	{
		if(k==-1||a[k]==a[j])
		{
			k++;
			j++;
			if(a[k]!=a[j]) next[j]=k;
			else next[j]=next[k];
		}
		else
			k=next[k];
	}

	int tmp=n-next[n];

	if(n%tmp==0)
		return n/tmp;
	else
		return 1;
}

int main(int argc, char *argv[])
{
	while(1)
	{
		int i=0;
		arr[i++]=getchar();
		if(arr[0]=='.')
			break;
		while(arr[i-1]!='\n')
			arr[i++]=getchar();

		arr[--i]='\0';
		//printf("string is %s and length is %d\n",arr,i);
		int ans=GetNext(i,arr);
		printf("%d\n",ans);
	}
	
	return 0;
}
