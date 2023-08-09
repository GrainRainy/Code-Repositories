#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int r()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int a,b,c;
bool vis[25][25][25],tr[25];
void dfs(int x,int y,int z)
{
	if(x==0) tr[z]=1;
	if(vis[x][y][z]) return;
	vis[x][y][z]=1;
	dfs(x-min(x,b-y),y+min(x,b-y),z);
	dfs(x+min(y,a-x),y-min(y,a-x),z);
	dfs(x-min(x,c-z),y,z+min(x,c-z));
	dfs(x+min(z,a-x),y,z-min(z,a-x));
	dfs(x,y-min(y,c-z),z+min(y,c-z));
	dfs(x,y+min(z,b-y),z-min(z,b-y));
}
 
int main()
{
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	a=r(); 
	b=r(); 
	c=r();
	dfs(0,0,c);
	for(int i=0;i<=c;++i) if(tr[i]) printf("%d ",i);
	return 0;	
}
