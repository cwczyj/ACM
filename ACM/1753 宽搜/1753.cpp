#include <stdio.h>
#include <queue>
#include <string>

using namespace std;

#define MAX 0xffff

bool state[MAX];

int add[16]={0xc800,0xe400,0x7200,0x3100,
			 0x8c80,0x4e40,0x2720,0x1310,
			 0x08c8,0x04e4,0x0272,0x0131,
	         0x008c,0x004e,0x0027,0x0013};

int GetAns(int n)
{
	memset(state,false,sizeof(state));

	state[n]=true;

	queue<int> q;
	queue<int> num;
	
	q.push(n);
	num.push(0);

	while(!q.empty())
	{
		int tmp=q.front();
		int tmp_num=num.front();
		q.pop();
		num.pop();

		if(tmp==0x0000||tmp==0xffff)
			return tmp_num;

		for(int i=0;i<16;i++)
		{
			if((tmp^add[i])==0x0000||(tmp^add[i])==0xffff)
				return 1+tmp_num;

			if(!state[tmp^add[i]])
			{
				num.push(tmp_num+1);
				q.push(tmp^add[i]);
				state[tmp^add[i]]=true;
			}
		}
	}

	return -1;
}

int main(int argc, char *argv[])
{
	char input[17];
	
	
		int i=0;
		for(int j=0;j<20;j++)
		{
			char t=getchar();
			if(t!='\n')
				input[i++]=t;
			else
				continue;
		}
		input[i]='\0';

		int n=0;
		int tmp=1;
		for(i-=1;i>=0;i--)
		{
			if(input[i]=='b')
				n+=tmp;

			tmp=tmp*2;
		}

		int ans=GetAns(n);
		if(ans!=-1)
			printf("%d\n",ans);
		else
			printf("Impossible\n");
	

	return 0;
}
