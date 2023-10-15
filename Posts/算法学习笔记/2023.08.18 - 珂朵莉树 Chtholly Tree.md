---
title: 珂朵莉树 | 学习笔记
date: 2023-08-18 23:26:15
categories: 数据结构
tags: 学习笔记
author: GrainRain
cover: https://pic.imgdb.cn/item/65183cc4c458853aef6d628d.jpg
single_column: true
---


# 珂朵莉树 $Chtholly\ Tree$

珂朵莉树是由 [$\color{ff8c00}{\mathbf{ODT}}$](https://codeforces.com/profile/ODT) 在 [Codeforces Round #449](https://codeforces.com/contest/896) 的题解中发明的一种数据结构, 或者说是做法, 因为它事实上是一系列基于 $\rm set$ 实现维护区间信息的操作. 仅适用于随机数据, 并且随机数据下实际运行效率不错. 

### 珂朵莉树能解决的问题

事实上, 珂朵莉树维护的是若干值相同的区间连续段, 对于具有区间推平类似的操作 (如区间赋值), 同时夹杂其他操作如区间加, 求区间第 $k$ 小 (可重), 询问区间每个数字的 $x$ 次方的和等, 并且数据随机的情况, 都能很好地应用珂朵莉树. 

### 算法思想

既然有对一段区间赋值的操作, 那么考虑维护若干值相同的连续区间: 

```cpp
struct Range {
	int l, r; // 段首段尾 
	mutable LL val; // 段值 
	Range(int l, int r = 0, LL val = 0) : l(l), r(r), val(val) {}
	bool operator < (const Range &t) const { return l < t.l; }
};
```

初始时将序列的每个元素视为一个区间插入 $\rm set$. 

注意这里定义 $val$ 变量为 $\rm mutable$ 类型.  $\rm mutable$ 关键字表示可修改的常量, 由于 $\rm set$ 迭代器是常量迭代器, 无法对它指向的值进行修改, 因此需要添加 $\rm mutable$ 关键字修饰. 

重载完运算符后, 我们将所有区间信息插入 $\rm set$, 即将每个区间按左端点排序, 得到了所维护的整个序列. 

#### 核心操作: 分裂区间

当区间赋值的操作覆盖到了某个区间段的一部分, 就需要将原区间分裂, 函数内传入 $pos$ 参数, 表示将该区间拆分成 $[l, pos - 1]$ 与 $[pos, r]$ 两部分. 

先将 $it$ 迭代器指向包含 $pos$ 的区间, 修改该区间的 $l, r$ 即可. 

```cpp
set<Range>::iterator split(int pos) {
	it = lower_bound(st.begin(), st.end(), Range(pos));
	// 找到左端点大于等于 pos 的第一个区间 
	if (it != st.end() and it->l == pos) return it;
	// pos 为该区间的左端点, 直接返回该区间即可 
	-- it;
	// 将 it 移动到包含 pos 的区间 
	if (it->r < pos) return st.end(); // 没有区间包含 pos 
	int l = it->l, r = it->r; LL val = it->val;
	st.erase(it);
	st.insert((Range){l, pos - 1, val});
	// 修改区间值, 重新插入 set
	return st.insert((Range){pos, r, val}).first;
}
```

注意这里的一个压行 $\rm Trick$: $\rm set$ 的 $\rm insert$ 函数返回一个二元组 $\rm pair$. 第一个关键字为插入位置的迭代器, 第二个关键字为是否插入成功的 $\rm bool$ 值. 

### 合并区间

当进行区间赋值等 "推平" 操作, 需要将多个区间信息合并为一个, 将包含 $l$ 和 $r$ 的区间断开, 移除 $l$ 到 $r$ 的所有区间即可. 

注意这里实现不好极容易 $\rm RE$, 必须要先 $\text{split}(r + 1)$ 再 $\text{split}(l)$. 如果先 $\text{split}(l)$ 则在 $\text{split}(r + 1)$ 时有可能移除 $itl$ 迭代器指向的区间 (当 $l$ 与 $r$ 同属于同一个区间时), 导致 $\rm RE$.

```cpp
void merge(int l, int r, int val) {
	itr = split(r + 1), itl = split(l);
	st.erase(itl, itr);
	st.insert((Range){l, r, val});
}
```

### 修改区间值

直接暴力修改即可. 

```cpp
void modify(int l, int r, int val) {
	itr = split(r + 1), itl = split(l);
	for (auto i = itl; i != itr; ++ i) i->val += val;
}
```

### 寻找区间第 $k$ 小

仍然是怎么暴力怎么来, 将 $l, r$ 区间内的所有区间全部取出顺次遍历, 每次减去该区间元素个数, 当 $k$ 第一次 $\leq cnt(l, r)$ 时意味着区间第 $k$ 小与该区间值相同. 

```cpp
LL rk(int l, int r, int k) {
	vector<Save> a;
	itr = split(r + 1), itl = split(l);
	for (auto i = itl; i != itr; ++ i)
		a.push_back((Save){i->r - i->l + 1, i->val});
	sort(a.begin(), a.end());
	for (auto t : a) {
		if (k <= t.len) return t.val;
		else k -= t.len;
	}
}
```

### 复杂度分析

时间复杂度均摊 $O(n \cdot \log \log n)$, 对数据的随机性要求较强, 这也导致它的应用面偏窄, 只能跑过数据随机的情况. 

具体的时间复杂度证明可以看 https://www.luogu.com.cn/blog/blaze/solution-cf896c