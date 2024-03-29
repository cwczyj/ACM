#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

#define MAX 200

int b[MAX][MAX];
bool visit[MAX];
int pre[MAX];
int n,m;

bool bfs(int s,int t)//通过广度优先搜索，找到一条到达t的通路
{
	memset(pre,-1,sizeof(pre));
	memset(visit,false,sizeof(visit));
	queue<int> q;
	q.push(s);
	pre[s]=s;
	visit[s]=true;

	while(q.size())
	{
		int tmp=q.front();
		q.pop();

		for(int i=0;i<m;i++)
		{
			if(!visit[i]&&b[tmp][i]>0)
			{
				pre[i]=tmp;
				q.push(i);
				visit[i]=true;
				if(i==t) return true;
			}
		}
	}
	return false;
}

int EK(int s,int t)
{
	int flow=0,d,i;
	while(bfs(s,t))
	{
		d=0x7fffffff;
		for(int i=t;i!=s;i=pre[i])
			d=(d<b[pre[i]][i])?d:b[pre[i]][i];
		for(int i=t;i!=s;i=pre[i])
		{
			b[pre[i]][i]-=d;
			b[i][pre[i]]+=d;
		}
		flow+=d;
	}
	return flow;
}

int main(int argc, char *argv[])
{
	while(scanf("%d %d",&n,&m)==2)
	{
		for(int i=0;i<m;i++)
			for(int j=0;j<m;j++)
				b[i][j]=0;

		int a,b1,c;
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&a,&b1,&c);
			b[a-1][b1-1]+=c;
		}

		int Maxflow=EK(0,m-1);
		printf("%d\n",Maxflow);
	}
	return 0;
}
