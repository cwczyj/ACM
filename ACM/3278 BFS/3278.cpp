#include <stdio.h>
#include <queue>
#include <string>

using namespace std;

#define INT __int64

typedef struct{
	int num;
	int step;
	int preOper;//-1,0,1
}Node;

queue<Node> q;
bool v[200000];

INT bfs(int start,int end)
{
	memset(v,false,sizeof(v));

	Node n;
	n.num=start;
	n.step=0;
	n.preOper=0;

	v[n.num]=true;
	q.push(n);

	while(!q.empty())
	{
		int num=q.front().num;
		int step=q.front().step;
		int preOper=q.front().preOper;

		q.pop();

		if(num==end)
			return step;

		if(preOper!=-1&&num<end&&!v[num+1])
		{
			n.num=num+1;
			n.step=step+1;
			n.preOper=1;
			v[n.num]=true;
			q.push(n);
		}
		if(preOper!=1&&!v[num-1])
		{
			n.num=num-1;
			n.step=step+1;
			n.preOper=-1;
			v[n.num]=true;
			q.push(n);
		}
		if(num<end&&!v[num*2])
		{
			n.num=num*2;
			n.step=step+1;
			n.preOper=0;
			v[n.num]=true;
			q.push(n);
		}
	}

	return -1;
}

int main(int argc, char *argv[])
{
	int a,b;
	while(scanf("%d %d",&a,&b)==2)
	{
		int ans=bfs(a,b);
		printf("%d\n",ans);
	}
	
	return 0;
}
