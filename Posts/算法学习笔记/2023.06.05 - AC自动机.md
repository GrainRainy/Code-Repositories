---
title: $AC$ 自动机 | 学习笔记
date: 2023-06-07 23:39:16
categories: 字符串
tags: 学习笔记
author: GrainRain
cover: https://pic.imgdb.cn/item/6482fc961ddac507cce180d6.jpg
single_column: true
---

# $AC$自动机

~~有没有被头图吓一跳~~

不先弄懂 [KMP](https://grainrain.site/2022/10/14/KMP/) 和 [Trie 树](https://grainrain.site/2022/11/11/Trie/) 就别想搞懂 $AC$ 自动机啦 $\sim$

一切源于一个问题：

> 给定 $n$ 个模式串和 $1$ 个文本串, 求在文本串中出现的模式串个数

我们发现, $KMP$ 和以上问题本质上并没有区别, 都是在处理字符串匹配问题. 只不过 $KMP$ 处理单个字符串间的匹配, $AC$ 自动机处理多个字符串匹配问题. 最基础的想法是：$border$ 不能再只连向自身的公共前后缀, 也要连到别的串上去, 使得在一条路径（文本串）上进行查询时, 能查询到所有串的信息. 

发现 $Tire$ 树具有天然支持公共前缀查询字符串的特点, 于是在 $Trie$ 树上插入失配指针（类似于 $KMP$ 的 $nxt$, 这里命名为 $\text{fail}$）即可完成构建. 

你要问我怎么写？你先别急, 接着往下看. 

## 模板 $1$：[统计出现的字符串个数](https://www.luogu.com.cn/problem/P3808)

### 前置数组

```cpp
int tr[N * L][26], cnt[N * L], fail[N * L], tTol;
// 节点数 = 字符串个数 * 字符串长度 
char s[M];
```

### 建立 $Trie$

```cpp
void insert(char s[]) {
    int p = 0;
    for (int i = 0, c; s[i]; ++ i) {
        c = s[i] - 'a';
        if (!tr[p][c]) tr[p][c] = ++ tTol;
        p = tr[p][c];
    }
    cnt[p] ++;
    return;
}
```

### 初始化 $Fail$ 指针（建 $AC$ 自动机）

回忆 $KMP$ 获取当前位置 $nxt$ 的过程：

```cpp
for (int i = 2; i <= n; i ++) {
	while (pos && p[i] != p[pos + 1]) pos = nxt[pos];
	if (p[i] == p[pos + 1]) pos ++;
	nxt[i] = pos;
}
```

不难发现, $nxt_i$ 尝试使用 $nxt_{i - 1}$ 在后面加入一位进行更新. 如果无法插入, 则继续跳 $border$. 迁移至 $Trie$ 树上, 更新当前节点的 $\text{fail}$ 时, 尝试使用父节点信息更新, 如果父节点没有当前字母的子节点, 则继续跳向父节点的 $\text{fail}$. 

然而如果在每一个点都一直跳 $\text{fail}$, 最坏情况下时间复杂度仍是 $O(n^2)$. 为了优化, 我们更倾向于扫一遍出结果, 于是由上至下预处理每一节点的每一位字母的 $\text{fail}$（即使它在 $Trie$ 树中并不存在）, 再从子节点向上找 $\text{fail}$, 就仅需找 $1$ 次了. 

![](https://oi-wiki.org/string/images/ac-automaton1.gif)

~~借用一下 OI-Wiki 的图, 鸽鸽们不会生气的吧 $\sout{\sim}$~~

```cpp
void build() {
    queue<int> q;
    for (int i = 0; i < 26; ++ i) 
        if (tr[0][i]) q.push(tr[0][i]);
    while (q.size()) {
        int t = q.front(); q.pop();
        for (int i = 0, p = 0; i < 26; ++ i) {
            p = tr[t][i];
            if (!p) tr[t][i] = tr[fail[t]][i];
            else fail[p] = tr[fail[t]][i], q.push(p);
        }
    }
}
```

### 匹配

```cpp
int match(char s[]) {
    int res = 0;
    for (int i = 0, p = 0; s[i]; ++ i) {
        p = tr[p][s[i] - 'a']; // move 
		for (int nxt = p; nxt and ~cnt[nxt]; nxt = fail[nxt])
            /* Do Something */
			res += cnt[nxt], cnt[nxt] = -1;
        // 本题对是否出现该串计数, 仅需加 1 次 
    }
    return res;
}
```

注意：特判每一位置只加一次保证了时间复杂度为 $O(lem_s + \sum len_p)$.

## 模板 $2$：[统计字符串出现次数](https://www.luogu.com.cn/problem/P3796)

而如果统计所有字符串出现次数, 插入字符串时在末尾节点上打入字符串下标标记, 讯问中每次跳到当前点, 便对应位置的字符串数量 $+1$.

```cpp
void query(string a) {
	for (int i = 0, p = 0; i < a.size(); ++ i) {
		p = tr[p][a[i] - 'a'];
		for (int nxt = p; nxt; nxt = fail[nxt]) 
			q[id[nxt]].cnt ++;
	}
}
```

对于以上算法我们发现, $Trie$ 树节点标记不能访问一次就删掉. 但如果不删掉, 时间复杂度会退化到 $O(len_s \times len_p)$, 因为对于每一次跳 $\text{fail}$ 我们都只使深度减 $1$, 因此最多跳深度（模式串长度）次, 再乘上文本串长度, 就几乎是 $O(len_s \times len_p)$.

你仍能通过修改以上代码苟过去 [加强版](https://www.luogu.com.cn/problem/P3796), 但二次加强版就被卡掉了.

## 模板 $3$：[统计字符串出现次数（二次加强版）](https://www.luogu.com.cn/problem/P5357)

于是考虑优化：

首先我们发现, 对答案进行修改的方式都是不断跳 $\text{fail}$ 指针得到的, 形式化地来讲, 每次作出的修改是一条指向根节点的 $\text{fail}$ 链 (当前位置匹配成功则当前位置到根的 $\text{fail}$ 链必然也能匹配成功), 因此我们尝试对每一节点的 $\text{fail}$ 与自身连边, 转化为树上链加. 于是树上差分维护即可. 修改时间复杂度 $O(1)$, 子树求和时间复杂度 $O(n)$

```cpp
void query(string a) {
	for (int i = 0, p = 0; i < a.size(); ++ i) {
		p = tr[p][a[i] - 'a'];
		sum[p] ++;
	}
}

void dfs(int u) {
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		dfs(j);
		sum[u] += sum[j];
	}
}
```

```cpp
for (int i = 1; i <= tTol; ++ i) add(fail[i], i);
dfs(0); // fail 树根节点为 0, dfs 需要从 0 开始跑
```
