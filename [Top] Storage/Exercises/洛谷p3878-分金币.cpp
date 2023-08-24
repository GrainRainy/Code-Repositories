#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x){
    x = 0; char c = getchar();
    bool f = false;
    for (; !isdigit(c); c = getchar())
        f |= (c == '-');
    for (; isdigit(c); c = getchar())
        x = x * 10 + (c ^ '0');
    if (f) x = -x;
}

const int N = 50;
int n;
int nums[N];
// basic things
int times = 10;
double rdc = 0.96;
LL ans = 1e18 + 10;
// simulate anneal

inline LL calc(){
    LL res1 = 0, res2 = 0;
    int mid = (n + 1) / 2;
    for (int i = 0; i < mid; i ++)
        res1 += nums[i];
    for (int i = mid; i < n; i ++)
        res2 += nums[i];
    LL res = abs(res1 - res2);
    ans = min(res, ans);
    return res;
}

void simulateAnneal(){
    random_shuffle(nums, nums + n);
    for (double t = 1e5; t > 1e-10; t *= rdc){
        int x = rand() % n, y = rand() % n;
        LL ori = calc();
        swap(nums[x], nums[y]);
        LL nw = calc();
        LL delta = nw - ori;
        if (exp((double)-delta / t) < (double)rand() / RAND_MAX)
            swap(nums[x], nums[y]);
    }
}

inline void solve(){
    ans = 1e18 + 10;
    times = 10;
    // recover
    input(n);
    for (int i = 0; i < n; i ++) input(nums[i]);
    // input
    while (times --) simulateAnneal();
    printf("%lld\n", ans);
    return;
}

int main(){
    srand(time(0));
    int t; input(t);
    while (t --) solve();
    return 0;
}