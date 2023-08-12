#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    srand(time(0));
    for(int K=1;K<=10;K++) {
		string s,sout;
		s = "trip"+to_string(K)+".in";
		sout = "trip"+to_string(K)+".out";
		cerr<<s<<'\n';
		// freopen(s,"w",stdout);
		freopen(s.c_str(),"w",stdout);
        if(K<=2) n=10;
        else if(K<=4) n=100;
        else n=1000;
        cout<<n<<'\n';
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i==j) cout<<100<<' ';
                else {
                    if(K==5||K==6) {
                        if(i==j-1) cout<<rand()%101+1<<' ';
                        else cout<<0<<' ';
                    }
                    else {
                        if(abs(i-j) <= max(10,n/5)) cout<<rand()%101+1<<' ';
                        else cout<<0<<' ';
                    }
                }
            }
            cout<<'\n';
        }
        freopen(s.c_str(),"r",stdin);
		freopen(sout.c_str(),"w",stdout);
		system("./trip");
    }
}