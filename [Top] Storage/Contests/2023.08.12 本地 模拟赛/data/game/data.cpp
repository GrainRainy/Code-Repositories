#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int T=100000,p=rand()%999+1;
    freopen("game.in","w",stdout);
    cout<<T<<' '<<p<<'\n';
    for(int i=1;i<=T;i++) 
        cout<<rand()%100000+1<<' '<<rand()%100000+1<<'\n';
}