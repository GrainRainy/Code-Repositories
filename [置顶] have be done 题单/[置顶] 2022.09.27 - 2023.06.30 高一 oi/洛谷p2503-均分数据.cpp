#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>

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

template <typename T> inline void output(T x, char ed = '\n'){
    if (x < 0) putchar('-'), x = -x;
    static short st[64], top;
    do st[++ top] = x % 10, x /= 10; while (x);
    while (top) putchar(st[top --] | '0');
    putchar(ed);
}

const int N = 25;
const int M = 10;

int n, m;
int nums[N];
// basic things
int grp[M];
double ans = 1e8 + 10;
// greed
int times = 100;
double reduce = 0.99;
// simulate anneal

inline double calc(){
    memset(grp, 0, sizeof grp);

    for (int i = 0; i < n; i ++){
        int minx = 0;
        for (int j = 0; j < m; j ++)
            if (grp[minx] > grp[j]) minx = j;
        // find the minimal group
        grp[minx] += nums[i];
    }
    double avr = 0;
    for (int i = 0; i < m; i ++)
        avr += ((double)grp[i] / m);
    double res = 0;
    for (int i = 0; i < m; i ++)
        res += (grp[i] - avr) * (grp[i] - avr);
    res = sqrt(res / m);
    ans = min(ans, res);
    return res;
}

void simulateAnneal(){
    random_shuffle(nums, nums + n);
    for (double t = 1e6; t > 1e-6; t *= reduce){
        int x = rand() % n, y = rand() % n;
        double ori = calc();
        swap(nums[x], nums[y]);
        double nw = calc();
        double delta = nw - ori;
        if (exp(-delta / t) < (double)rand() / RAND_MAX)
            swap(nums[x], nums[y]);
    }
}

int main(){
    input(n), input(m);
    for (int i = 0; i < n; i ++) input(nums[i]);
    while (times --){
        simulateAnneal();
    }
    printf("%.2lf\n", ans);
    return 0;
}