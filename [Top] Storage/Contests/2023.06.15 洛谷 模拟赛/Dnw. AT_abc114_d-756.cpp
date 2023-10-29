#include <iostream>
using namespace std;
int n, cnt[110];

void decompose(int u) {
	for (int i = 2; ; ++ i) {
        while (u % i == 0) cnt[i] ++, u /= i;
        if (u == 1) return;
    }
}

int work(int u) {
	int res = 0;
	for (int i = 1; i <= n; ++ i)
		if (cnt[i] >= u) res ++;
	return res;
}

int main() {
	cin >> n;
	for (int i = 2; i <= n; ++ i) decompose(i);
	cout << work(74) + work(14) * (work(4) - 1) + work(24) * (work(2) - 1) + work(4) * (work(4) - 1) * (work(2) - 2) / 2;
}
