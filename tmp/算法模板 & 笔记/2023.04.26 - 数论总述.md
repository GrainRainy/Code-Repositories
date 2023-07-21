---
title: 数论总述 | 一文从入门到毕业
date: 2023-4-27 23:47:52
categories: 数学
tags: 数学
author: GrainRain
cover: https://pic.imgdb.cn/item/64b0162b1ddac507cc913e29.jpg
single_column: true
---

# 质数

## 千奇百怪的质数定理

- $1\sim n$ 中共有 $\frac{n}{\ln n}$ 个质数

## 判质数

### 1. 试除法 $O(\sqrt n)$

```cpp
bool isPrime(int u){
    if (u < 2) return false;
    for (int i = 2; i <= n / i; i ++){
        if (n % i == 0) return true;
    }
    return false;
}
```

### 2. 埃氏筛 $O(n \cdot \log_2 \log_2 n)$

只筛质数即可

```cpp
vector<int> prime; // Stacks for storing prime numbers
void Eratosthenes(int n){
    notPrime[0] = notPrime[1] = true;
    for (int i = 2; i <= n; ++i){ 
        if (!notPrime[i]){
            prime.push_back(i);
            for (int j = i + i; j <= n; j += i)
                notPrime[j] = true;
        }
    }
    return;
}
```

### 3. 线性筛 / 欧拉筛 $O(n)$

核心思想：一个合数 $n$ 只会被最小质因子筛出

对于线性筛的个人理解：

标记非素数的过程相当于对于每一个素数之上建立一个剩余系，随着 $i$ 的推进，逐步扩大剩余系规模，通过 $*i$ 实现。当 `i % primes[j] == 0` 则表示当前系统中已有 `primes[j] * i` 及其以后的数(他们已经被其他剩余系筛过了)，直接跳出即可

对于上述情况的处理也成为实现 $O(n)$ 预处理质数的关键

例如：如果 $i$ 是 $10$，第一个质数是 $2$，那么 $10$ % $2$ == $0$。所有 $10$ 的倍数都是第一个质数 $2$ 的倍数，避免重复标记，因此 `break` 掉。

```cpp
void Euler(int n){
	notPrime[0] = notPrime[1] = true;
	for (int i = 2; i <= n; i ++){
		if (!notPrime[i]) primes[++ top] = i;
		for (int j = 1; primes[j] <= n / i; j ++){
			notPrime[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		}
	}
}
```

进行以上算法之后，我们即得到了一张质数表 `notPrime`

然而，线性筛中使用了大量~~模法~~模运算，常数比埃氏筛略大。在小数据范围时，埃氏筛的 log 会很小，因此数据范围不大时埃氏筛可能不失为一种更好的选择

## 分解质因数

### 试除法 $O(\sqrt n)$

```cpp
void decompose(int u) {
	for (int i = 2; ; ++ i) {
        while (u % i == 0) cnt[i] ++, u /= i;
        if (u == 1) return;
    }
}
```

# 约数

## 求所有约数

### 试除法 $O(\sqrt n)$

```cpp
vector<int> getDivisors(int n){
    vector<int> ans;
    for (int i = 1; i <= n / i; i ++){
        if (n % i == 0){
            ans.push_back(i);
            if (i != n / i) ans.push_back(n / i);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
```

值得注意的是，$n$ 的约数个数约为 $\ln n$ ，因此排序不是时间复杂度瓶颈

## 约数个数

依据算术基本定理计算约数个数：

对于一个数 $n$，若对其分解质因数可表示为：

$$n = p_1^{c_1} \times p_2^{c_2} \times ... \times pk^{c_k}$$

则约数个数为：

$$ (c_1 + 1) \times (c_2 + 1) \times ... \times (c_k + 1)$$

形式化地，相当于在若干个约数中选取若干个约数相乘，组成一个新的约数，计入答案，因此使用乘法原理即可

## 约数之和

同样，对于一个数 $n$，若：

$$n = p_1^{c_1} \times p_2^{c_2} \times ... \times p_k^{c_k}$$

约数之和： 

$$(p_1^0 + p_1^1 + ... + p_1^{c_1}) * ... * (p_k^0 + p_k^1 + ... + p_k^{c_k})$$

## 最大公约数

### 辗转相除法 / 欧几里得算法

易证：

若 $d \mid a$ 且 $d \mid b$，则 $d \mid ax + by$

因此 $\gcd(a, b) = \gcd(b, a \bmod b)$

## 欧拉函数

$φ(n)$ 表示 $1$ ~ $n$ 中与 $n$ 互质的数的个数

# 同余

对于两个整数 $a$，$b$，若满足 $a \bmod m = b \bmod m$，则称 $a$ 与 $b$ 在 $mod m$ 的意义下**同余**，记作 $a \equiv b \pmod m$

## 乘法逆元

### 定义

对于两个互质的正整数 $a$，$b$，若满足 $ax \equiv 1 \pmod b$，则称 $x$ 为 $a$ 在 $mod\ b$ 意义下的**逆元**，记作 $a^{-1}$

> 另外，对于逆元还有另一种定义：
> 若 $x$ 满足 $m / a \equiv m * x \pmod b$，则称 $x$ 为 $a$ 在 $mod\ b$ 意义下的逆元
> (其中 $b$, $m$ 互质，$b\mid a$)
> 
> (摘自李煜东《算法竞赛进阶指南》)

形式化地，我们可以将逆元理解为 在模运算下的倒数，即：

$$a * a^{-1} \bmod b = 1$$

### 求一个数 $a$ 在 模 $b$ 意义下的逆元

#### 1. 扩展欧几里得算法

对于同余式 $ax \equiv 1 \pmod b$，设 $ax - 1$ 是 $b$ 的 $-y$ 倍，则有：

$$ax + by = 1$$

根据 $Bézout$ 定理（裴蜀定理），对于以上的一个线性同于方程有解，当且仅当 $\gcd(a, b) = 1$，即 $a$ 与 $b$ 互质。我们直接应用 $exgcd$ 求出一组可行解，再将解通过~~模法~~模运算偏移至 $[1, b - 1]$ 的区间即可

这是我们可爱的扩展欧几里得算法板子：

```cpp
LL exgcd(LL a, LL b, LL &x, LL &y){
	if (!b) { x = 1, y = 0; return a; }
	LL d = exgcd(b, a % b, x, y);
	LL tmp = x;
	x = y, y = tmp - (a / b) * y;
	return d;
}

x = (x % b + b) % b;
```

#### 2. 费马小定理

当模数 $b$ 为质数时（此时经常写作 $p$），我们可以根据费马定理，对以上同余式进行变形，得到：

$$b * b^{p - 2} \equiv 1 \pmod p$$

因此，我们使用快速幂在 $O(log_2 p)$ 的时间内求出 $b^{p - 2}$ 对 $p$ 取模的模数即可

```cpp
LL fPow(LL a, LL b, LL p) {
    LL res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
```

#### 3. 线性逆元

当解决形如：

> 给定一个正整数 $n$，求 $1$ ~ $n$ 之间所有数 $\bmod\ p$  意义下的逆元（保证 $p$ 为质数）

的问题时，可以考虑在线性时间内递推逆元。

设 $p = k * i + r$，$(1 < r < i < p )$

因此 $k * i + r \equiv 0 \pmod p$

两侧同时乘 $r^{-1}, i^{-1}$ 可得：

$$i^{-1} \equiv -k * r^{-1} \pmod p$$

即：

$$i^{-1} \equiv -\lfloor \frac{p}{i} \rfloor * (p \bmod i)^{-1} \pmod p$$

因此，我们获得了在线性时间内递推区间模 $p$ 的逆元的方法

```cpp
inv[0] = inv[1] = 1;
for(int i = 2; i < p; ++ i)
    inv[i] = (p - p / i) * inv[p % i] % p;
```

## 同余方程

依据未知数次数的不同我们将同余方程分为以下两种：

### 1. 线性同余方程

### 2. 高次同余方程



### 解同余方程组

#### $\scriptsize situation\ 1$ : 模数两两互质

中国剩余定理($crt$)

#### $\scriptsize situation\ 2$ : 模数不保证互质

扩展中国剩余定理 ($excrt$)

对于