---
title: $ST$ 表 | 学习笔记
date: 2023-1-28 23:01:57
categories: 数据结构
tags: 数据结构
author: GrainRain
cover: https://pic.imgdb.cn/item/64b011d01ddac507cc7cd4bb.jpg
single_column: true
---


# $ST$ 表 $Sparse\ Table$

> $RMQ$ ($Range\ Minimum\ /\ Maximum\ Query$) 问题：
> $O(1)$ 查询区间最大 / 最小值

## 基本思想

基于倍增的基本思想， 定义 $f_{i, j}$ 表示从 $i$ 开始，长度为 $2^j$ 的区间中最大 / 小值

考虑状态转移，将一个区间分为两部分，维护两部分的 $max$ 或 $min$ 即可。则有：

$$ f_{i, j} = max(f_{i, j - 1},\ f_{i + 2^{j - 1}, j - 1}) $$

![](https://pic.imgdb.cn/item/63d4c5c6face21e9efa1b86b.jpg)

在具体使用时，询问 $[l, r]$ 区间，`len = r - l + 1`，只需找到最大的 $k$ 使得 $2^k \geqslant len$。

$$ \Kappa = \lfloor \frac {log(len)} {log(2)} \rfloor $$

(c++ 标准库中 $log$ 函数默认以 $e$ 为底)

## 时间复杂度分析

$f_{i, j}$ 第一维 $n$ 个，第二维 $log_2n$ 个。

因此 $ST$ 表可以做到先以 $O(n \cdot log_2n)$ 的时间复杂度预处理，之后对于每次查询时间复杂度为 $O(1)$

## 例题

### [离线查询区间最大值 - 天才的记忆](https://www.acwing.com/problem/content/1275/) 

```cpp
int f[N][J]; // 下标从 i 开始，长度为 2^j 的区间最大值

void init() { // 初始化 st 
	for (int j = 0; j < J; j ++)
		for (int i = 1; i + (1 << j) - 1 <= n; i ++) {
			if (!j) f[i][j] = w[i];
			else f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
		}
}

int query(int l, int r) {
	int len = r - l + 1;
	int k = log2(len); // or log(len) / log(2);
	return max(f[l][k], f[r - (1 << k) + 1][k]);
}
```

### [进阶应用 - 超级钢琴](https://www.luogu.com.cn/problem/P2048)

注意 $ST$ 中存储值最大的下标。

```cpp
int n, k, l, r;
LL st[N][LOGN], sum[N], ans;

void init() {
	int tmpx, tmpy;
	for (int i = 0; i < LOGN; ++ i)
		for (int j = 1; j + (1 << i) - 1 <= n; ++ j) {
			if (!i) st[j][i] = j;
			else {
				tmpx = st[j][i - 1], tmpy = st[j + (1 << i - 1)][i - 1];
				st[j][i] = sum[tmpx] > sum[tmpy] ? tmpx : tmpy;
			}
		}
}

int query(int l, int r) {
	int k = log2(r - l + 1);
	int tmpx = st[l][k], tmpy = st[r - (1 << k) + 1][k];
	return sum[tmpx] > sum[tmpy] ? tmpx : tmpy;
}

struct Element {
	int st, l, r, pos;
	Element();
	Element(int a, int b, int c) : st(a), l(b), r(c), pos(query(l, r)) {}
	bool operator < (const Element &t) const {
		return sum[pos] - sum[st - 1] < sum[t.pos] - sum[t.st - 1];
	}
};
priority_queue<Element> q;

int main() {
	input(n), input(k), input(l), input(r);
	for (int i = 1; i <= n; ++ i) 
		input(sum[i]), sum[i] += sum[i - 1];
	init();
	for (int i = 1; i + l - 1 <= n; ++ i) 
		q.push(Element(i, i + l - 1, min(i + r - 1, n)));	
	while (k --) {
		int st = q.top().st, l = q.top().l, r = q.top().r, pos = q.top().pos;
		q.pop();
		ans += sum[pos] - sum[st - 1];
		if (l != pos) q.push(Element(st, l, pos - 1));
		if (r != pos) q.push(Element(st, pos + 1, r));
	}
	printf("%lld\n", ans);
	return 0;
}
```