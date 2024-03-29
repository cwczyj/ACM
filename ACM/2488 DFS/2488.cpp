#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 27

bool vis[MAX][MAX];
int row[MAX];
int col[MAX];

int dir[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};

bool dfs(int x,int y,int p,int q,int step)
{
	if(step==p*q)
		return true;

	bool flag=false;
	for(auto & i:dir)
	{
		int nextx,nexty;
		nextx=x+(*i)[0];
		nexty=y+(*(i+1))[1];

		if(nextx>=0&&nextx<p&&nexty>=0&&nexty<q&&!vis[nextx][nexty])
		{
			vis[nextx][nexty]=true;
			row[step]=nextx;
			col[step]=nexty;

			flag=dfs(nextx,nexty,p,q,step+1);
			vis[nextx][nexty]=false;
			if(flag)
				return true;
		}
	}


	return flag;
}

int main(int argc, char *argv[])
{
	int t;
	scanf("%d",&t);
	for(int j=1;j<=t;j++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		row[0]=0;
		col[0]=0;
		

		memset(vis,false,sizeof(vis));
		vis[0][0]=true;
		printf("Scenario #%d:\n",j);
		if(dfs(0,0,x,y,1))
			for(int i=0;i<x*y;i++)
				printf("%c%d",col[i]+'A',row[i]+1);
		else
		{	printf("impossible");}

		printf("\n\n");
	}
}
