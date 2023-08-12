#include<bits/stdc++.h>
using namespace std;
int a[1000010];
void build(int K)
{
    int n,m,k;
    int T = 200 - rand()%50;
    if(K<=4) T = 10;
    cout<<T<<'\n';
    for(int j=1;j<=T;j++) {
        n=rand()%1000000+1,m=rand()%n+1,k=rand()%n+1;
        if(K<=4) n=rand()%15+1,m=rand()%n+1,k=rand()%n+1;
        else if(K<=10) n=rand()%1000+1,m=rand()%n+1,k=rand()%n+1;
        else if(K<=14) k=n;
        cout<<n<<' '<<m<<' '<<k<<'\n';
    }
}
int main()
{
    srand(time(0));
    for(int K=1;K<=20;K++) {
        string s,t,name;
        name = "ring";
        s = name + to_string(K) + ".in";
        t = name + to_string(K) + ".out";
        freopen(s.c_str(),"w",stdout);
        build(K);
        freopen(s.c_str(),"r",stdin);
        freopen(t.c_str(),"w",stdout);
        string cmd = "./" + name;
        system(cmd.c_str());
    }
}