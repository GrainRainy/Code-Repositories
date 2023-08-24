#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
using namespace std;
int n;
int main() {
    scanf("%d", &n);
    if (lowbit(n) == n) return puts("No") & 0;
    puts("Yes");
    for (int i = 2; i < n; i += 2) {
        printf("1 %d\n", i);
        printf("1 %d\n", i + n + 1);
        printf("%d %d\n", i, i + 1);
        printf("%d %d\n", i + n, i + n + 1);
    }
    printf("%d 3\n", n + 1);
    if (!(n & 1)) {
        printf("%d %d\n", n + lowbit(n) + 1, n);
        printf("%d %d\n", n + n, n - lowbit(n));
    }
    return 0;
}
