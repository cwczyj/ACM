#include <stdio.h>
#include <stdlib.h>

int cal_inversion(char a[],int l)
{
	int sum=0;
	int T=0,C=0,G=0;
	for(int i=0;i<l;i++)
	{
		switch(a[i])
		{
			case 'A':
			{
				sum+=T;
				sum+=C;
				sum+=G;
				break;
			}
			case 'C':
			{
				sum+=G;
				sum+=T;
				C++;
				break;
			}
			case 'G':
			{
				sum+=T;
				G++;
				break;
			}
			case 'T':
			{
				T++;
				break;
			}
		}
	}
	return sum;
}

struct D
{
	char a[110];
	int inversion;
};

void quick_sort(int s[], D d[],int l,int r)
{
	int a=l,b=r,x=s[l];
	if(a<b)
	{
		while(a<b)
		{
			bool f1=true;
			while(a<b&&d[s[b]].inversion>=d[x].inversion)
			{
				if(a<b&&d[s[b]].inversion==d[x].inversion&&s[b]<x)
				{
						//int tmp=s[b];
						//s[b]=s[a];
						//s[a]=tmp;
						//f1=false;
						break;
				}
				else
					b--;
			}
			if(a<b&&f1)
				s[a++]=s[b];

			bool f2=true;
			while(a<b&&d[s[a]].inversion<=d[x].inversion)
			{
				if(a<b&&d[s[a]].inversion==d[x].inversion&&s[a]>x)
				{
					//int tmp=s[a];
					//s[a]=s[b];
					//s[b]=tmp;
					//f2=false;
					break;
				}
				else 
					a++;
			}
			if(a<b&&f2)
				s[b--]=s[a];
		}
		s[a]=x;
		quick_sort(s,d,l,a-1);
		quick_sort(s,d,a+1,r);
	}
}

int main(int argc, char *argv[])
{
	int a,b;

	scanf("%d %d",&a,&b);

	D *DNA=new D[b];
	int *s=new int[b];

	for(int i=0;i<b;i++)
	{
		scanf("%s",&DNA[i].a);
		DNA[i].inversion=cal_inversion(DNA[i].a,a);
		s[i]=i;
	}
	
	quick_sort(s,DNA,0,b-1);

	for(int i=0;i<b;i++)
		printf("%s %d\n",DNA[s[i]].a,s[i]);

	return 0;
}
