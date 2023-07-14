# $Contest\ Summary$

~~其实不是赛时的题也可以写的~~

## [2023.5.11 - CF359B](https://www.luogu.com.cn/problem/CF359B)

构造：构造一个长度为$2n$的排列 $a$，满足:

$$\sum_{i=1}^{n}\mid{a_{2i}-a_{2i-1}}\mid-\mid\sum_{i=1}^{n} a_{2i}-a_{2i-1} \mid=2*k$$

### $Solutions$

发现当 $k = 0$ 时直接输出 $1 \sim 2n$ 的排列就可以了，考虑利用这一性质。当 $a_{2i} < a_{2i + 1}$ 答案会增加 $2 \times (a_{2i} - a_{2i - 2})$，因此将第一个数变成 $k + 1$，剩下的直接输出排列即可

### [2023.6.3 - ABC304D](https://atcoder.jp/contests/abc304/tasks/abc304_d)

