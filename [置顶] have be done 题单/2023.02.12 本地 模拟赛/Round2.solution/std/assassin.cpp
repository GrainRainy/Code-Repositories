#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,T;
struct node{
	int nxt,to;
}e[2*N];
int hd[N],cnt;
void add(int x,int y){
	e[++cnt].nxt=hd[x];
	e[cnt].to=y;
	hd[x]=cnt;
}
int fa[N][20],dep[N];
void dfs(int x,int d){
	dep[x]=d;
	for(int i=hd[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa[x][0]) continue;
		fa[y][0]=x;
		dfs(y,d+1);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int j=19;j>=0;--j){
		if(dep[fa[x][j]]>=dep[y]) x=fa[x][j];
	}
	if(x==y) return x;
	for(int j=19;j>=0;--j){
		if(fa[x][j]!=fa[y][j]) x=fa[x][j],y=fa[y][j];
	}
	return fa[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)]; 
}
bool judge(int x,int a,int b){
	return dis(a,b)==(dis(x,a)+dis(x,b));
}
int main(){
	freopen("assassin.in","r",stdin);
	freopen("assassin.out","w",stdout);
	cin>>n>>T;
	int x,y;
	for(int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x); 
	}	
	dfs(1,1);
	for(int j=1;j<=19;++j){
		for(int i=1;i<=n;++i){
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	int a,b,c,d;
	while(T--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(judge(lca(a,b),c,d)||judge(lca(c,d),a,b)) puts("YES");
		else puts("NO");
	}
	return 0;
}
