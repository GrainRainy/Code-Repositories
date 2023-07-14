#include <bits/stdc++.h>
#define FI first
#define SE second
using namespace std;
using PII = pair<int,int>;
const int N=5e5+10;
int n,k,tmp,last,ans;
struct Node {
	int val,l,r;
}a[N];
bool st[N];
PII nd;
priority_queue<PII,vector<PII>,greater<PII>> heap;
int main() {
	scanf("%d%d%d",&n,&k,&last);
	for (int i=1;i<n;++i){
		scanf("%d",&tmp);
		a[i]={tmp-last,i-1,i+1};
		heap.push({a[i].val,i});
		last=tmp;
	}
	a[0].val=a[n].val=0x3f3f3f3f;
	for(int i=1;i<=k;++i){
		while(st[heap.top().SE])heap.pop();
		auto t=heap.top();heap.pop();
		ans+=t.FI;
		st[a[t.SE].l]=st[a[t.SE].r]=1;
		a[t.SE].val=a[a[t.SE].l].val+a[a[t.SE].r].val-a[t.SE].val;
		heap.push({a[t.SE].val, t.SE});
		a[t.SE].l=a[a[t.SE].l].l,a[t.SE].r=a[a[t.SE].r].r;
		a[a[t.SE].l].r=t.SE,a[a[t.SE].r].l=t.SE;
	}
	return printf("%d", ans), 0;
}
