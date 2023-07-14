#include <iostream>
#include <cstring>
#include <bitset>
#include <queue>

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed); 
	}
}

using namespace IO;
using namespace std;
const int N = 5e2 + 10;
const int K = 10;
int n, k, c, ptc[N][K];

struct Node {
	bitset<N> S;
	vector<int> V;
	int pos, val;
	bool operator < (const Node &t) const {
		return val < t.val;
	}
}tmp;
priority_queue<Node> q;

void work(Node x) {
	static int tmp[K]; // save new plan 
	memset(tmp, 0, sizeof tmp);
	
	x.pos = x.V.size();
	for (int i = 1; i <= x.pos; ++ i)
		for (int j = 1; j <= k; ++ j)
			tmp[j] = max(tmp[j], ptc[x.V[i - 1]][j]);
	for (int i = x.pos + 1, id; i <= k; ++ i) {
		id = -1;
		for (int j = 1; j <= n; ++ j)
			if (x.S[j] and (!(~(id)) or ptc[j][i] >= ptc[id][i]))
				id = j;
		// choose a second best plan 
		if (!(~id)) return;
		for (int j = 1; j <= k; ++ j) tmp[j] = max(tmp[j], ptc[id][j]);
		x.V.push_back(id);
		x.S[id] = 0; // have been chosen 
	}
	x.val = 0;
	for (int i = 1; i <= k; ++ i) x.val += tmp[i];
	q.push(x);
}

int main() {
	input(n), input(k), input(c);
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= k; ++ j)
			input(ptc[i][j]);
	tmp.S.set();
	
	work(tmp);
	while (c --) {
		Node x = q.top(); q.pop();
		if (!c) return output(x.val) , 0;
		for (int i = x.pos; i < k; ++ i) {
			Node y = x;
			y.V.resize(i); // enlarge the vecotr 
			y.S[x.V[i]] = 0; // been chose 
			for (int j = i + 1; j < k; ++ j) y.S[x.V[j]] = 1;
			work(y);
		}
	}
	return 0;
}
