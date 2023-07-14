#include <bits/stdc++.h>

#define __DEBUG__ puts("__DEBUG__");

using namespace std;

template <typename T> inline void output(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top -- ] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
int n;
string k;
vector<int> fact[N], zro;
int ary[N];
bool st[N];

void print(vector<int> a) {
	puts("__DEBUG__");
	for (int i = a.size() - 1; i >= 0; i --) {
		cout << a[i];
	}
	cout << '\n';
	puts("__DEBUG__");
}
 
bool cmp(vector<int> &A, vector<int> &B) {
	if (A.size() != B.size()) return A.size() > B.size();
	for (int i = A.size() - 1; i >= 0; i --)
		if (A[i] != B[i]) return A[i] > B[i];
	return true;
}

vector<int> add(vector<int> &A, vector<int> &B) {
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size() or i < B.size(); i ++) {
		if (i < A.size()) t += A[i];
		if (i < B.size()) t += B[i];
		C.push_back(t % 10);
		t = t / 10;
	}
	if (t) C.push_back(1);
	return C;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
	vector<int> C;
	for (int i = 0, t = 0; i < A.size(); ++ i) {
		t = A[i] - t;
		if (i < B.size()) t -= B[i];
		C.push_back((t + 10) % 10);
		if (t < 0) t = 1;
		else t = 0;
	}
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}

vector<int> mul(const vector<int> &A, int b) {
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size() or t; ++ i) {
		if (i < A.size()) t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}

void InitFact(int n) {
	fact[0].push_back(1);
	for (int i = 1; i <= n; ++ i) 
		fact[i] = mul(fact[i - 1], i);
	return;
}

int find(int idx) {
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		if (!st[i]) cnt ++;
		if (cnt == idx) return i;
	}
}

int main() {
	zro.push_back(1);
	scanf("%d%d", &n, &k);
	
    vector<int> K;
    for (int i = k.size() - 1; i >= 0; i --)
        K.push_back(k[i] - '0');
    
	InitFact(n);
	for (int i = n; i >= 1; -- i) {
		int cnt = 0;
		while (cmp(K, fact[i - 1])) {
			auto tmp = sub(K, fact[i - 1]);
			if (!cmp(tmp, zro)) break;
			K = tmp, cnt ++;
		}
		int val = find(cnt + 1);
		ary[i] = val, st[val] = true;
	}
	
	for (int i = n; i >= 1; i --) output(ary[i], ' ');
	puts("");
}

