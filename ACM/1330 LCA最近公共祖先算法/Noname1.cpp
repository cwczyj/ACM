#include<stdio.h>  
#include<algorithm>  
#include<vector>  
#include<string.h>  
#define inf 99999999  
  
using namespace std;  
  
vector<int>tree[10005];  
int num,n;  
bool used[10005];  
int eular[20010];  
int deep[20010];  
int first[10005];  
  
void dfs(int root,int dep)  
{  
    int i;  
    eular[num]=root;  
    deep[num]=dep;  
    num++;  
    for(i=0;i<tree[root].size();i++)  
    {  
        dfs(tree[root][i],dep+1);  
        eular[num]=root;  
        deep[num]=dep;  
        num++;  
    }  
}  
  
int find(int a,int b)  
{  
    int i,min,ans;  
    min=inf;  
    for(i=first[a];i<first[b];i++)  
    {  
        if(deep[i]<min)  
        {  
            min=deep[i];  
            ans=i;  
        }  
    }  
    return ans;  
}  
  
void init()  
{  
    int i;  
    memset(used,0,sizeof(used));  
    num=0;  
    for(i=0;i<=n;i++)  
        tree[i].clear();  
}  
  
int main()  
{  
    int t,a,b,root,i;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d",&n);  
        init();  
        for(i=0;i<n-1;i++)  
        {  
            scanf("%d%d",&a,&b);  
            tree[a].push_back(b);  
            used[b]=true;  
        }  
        for(i=1;i<=n;i++)  
        {  
            if(used[i]==false)  
            {  
                root=i;  
                break;  
            }  
        }  
        dfs(root,1);  
        memset(used,0,sizeof(used));  
        for(i=0;i<num;i++)  
        {  
            if(!used[eular[i]])  
            {  
                used[eular[i]]=true;  
                first[eular[i]]=i;  
            }  
        }  
        scanf("%d%d",&a,&b);  
        if(first[a]>first[b])  
            swap(a,b);  
        int ans=find(a,b);  
        printf("%d\n",eular[ans]);  
    }  
    return 0;  
}  