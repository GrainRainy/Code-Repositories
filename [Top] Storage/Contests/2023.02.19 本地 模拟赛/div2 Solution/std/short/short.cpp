#include<bits/stdc++.h>
using namespace std;

const int N=5000010;
const int M=10000010;
int ver[M<<1],suiv[M<<1],head[N];
long long edge[M<<1],d[N];
bool v[N];
int n,m,st,tot;
priority_queue<pair<long long,int> >q;

inline int R()
{
	int res=0;
	int fix=1;
	char ch;
	while(!isdigit(ch=getchar()))
		fix=(ch=='-')?-1:fix;
	do res=res*10+ch-'0';
	while(isdigit(ch=getchar()));
	return fix*res;
}

inline long long Rl()
{
	long long res=0;
	long long fix=1;
	char ch;
	while(!isdigit(ch=getchar()))
		fix=(ch=='-')?-1:fix;
	do res=res*10+ch-'0';
	while(isdigit(ch=getchar()));
	return fix*res;
}

inline void add(int x,int y,long long z)
{
	ver[++tot]=y;
	edge[tot]=z;
	suiv[tot]=head[x];
	head[x]=tot;
}

inline void dijkstra()
{
	for(int i=0;i<n;i++)
		d[i]=9223372036854775807;
	d[1]=0;
	q.push(make_pair(0,1));
	while(q.size())
	{
		int x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=suiv[i])
		{
			int y=ver[i];
			long long z=edge[i];
			if(d[y]>d[x]+z)
			{
				d[y]=d[x]+z;
				q.push(make_pair(-d[y],y));
			}
		}
	}
}


int main()
{
	//÷ÿ±ﬂ£ø 
	freopen("short.in","r",stdin);
	freopen("short.out","w",stdout);
	n=R(),m=R(),st=R();
	for(int i=1,a,b;i<=m;i++)
	{
		long long c;
		a=R(),b=R(),c=Rl();
		add(a,b,c),add(b,a,c);
	}
	dijkstra();
	printf("%lld\n",d[st]);
	fclose(stdout);
	return 0;
}
