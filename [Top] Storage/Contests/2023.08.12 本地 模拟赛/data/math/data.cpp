#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	int T=10,flg=0;
	for(int K=1;K<=10;K++) {
		if(K<=3) flg=1;
		else flg=0;
		string sout;
		s = "math"+to_string(K)+".in";
		sout = "math"+to_string(K)+".out";
		cerr<<s<<'\n';
		// freopen(s,"w",stdout);
		freopen(s.c_str(),"w",stdout);
		cout<<T<<'\n';
		for(int i=1;i<=T;i++) {
			int k = rand()%10+1;
			int n=rand()%(1000000000)+1;
			if(flg) n = rand()%(1000)+1;
			if(4<=K&&K<=6) k=1;
			cout<<n<<' '<<k<<'\n';
		}
		freopen(s.c_str(),"r",stdin);
		freopen(sout.c_str(),"w",stdout);
		system("./math");
	}
}