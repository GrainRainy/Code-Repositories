#include <bits/stdc++.h>
#define FI first
#define SE second
using namespace std;
using PII = pair<int,int>;
const int N=5e5+10;
int n,k,tmp,ans,val[N],l[N],r[N];
bool st[N];
PII nd;
priority_queue<PII,vector<PII>,greater<PII>> heap;
int main(){
	scanf("%d%d",&k,&n);
	for (int i=1;i<=n;i++) scanf("%d",&val[i]);
	sort(val+1,val+n+1);
	for (int i=1;i<n;++i){
		val[i]=val[i+1]-val[i],l[i]=i-1,r[i]=i+1;
		heap.push({val[i],i});
	}
	cout << endl;
	val[0]=val[n]=0x3f3f3f3f;
	for(int i=1;i<=k;++i){
		while(st[heap.top().SE])heap.pop();
		auto t=heap.top();heap.pop();
		ans+=t.FI;
		st[l[t.SE]]=st[r[t.SE]]=1;
		val[t.SE]=val[l[t.SE]]+val[r[t.SE]]-val[t.SE];
		heap.push({val[t.SE], t.SE});
		l[t.SE]=l[l[t.SE]],r[t.SE]=r[r[t.SE]];
		r[l[t.SE]]=t.SE,l[r[t.SE]]=t.SE;
	}
	return printf("%d", ans), 0;
}
