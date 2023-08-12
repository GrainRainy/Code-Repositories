#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
    int n,m,k;
    srand(time(0));
    for(int K=1;K<=20;K++) {
        string s,t;
        s = "array" + to_string(K) + ".in";
        t = "array" + to_string(K) + ".out";
        freopen(s.c_str(),"w",stdout);
        n=300000;
        m=300000;
        k=n-rand()%100;
        if(K<=4) n = 100 , m = 100, k=n-rand()%10;
        else if(K<=8) {
            n = 1000;
            m = 1000;
            k = n - rand()%20;
        }
        for(int i=1;i<=n;i++) a[i]=rand()%m+1;
        if(8<K && K<=12) {
            n = 300000-rand()%100;
            for(int i=1;i<=n;i++) a[i]=m;
            k=n;
        }
        cout<<n<<' '<<m<<' '<<k<<'\n';
        for(int i=1;i<=n;i++) cout<<a[i]<<' ';
        cout<<'\n';
        fclose(stdout);
        freopen(s.c_str(),"r",stdin);
        freopen(t.c_str(),"w",stdout);
        system("./array");
    }
}