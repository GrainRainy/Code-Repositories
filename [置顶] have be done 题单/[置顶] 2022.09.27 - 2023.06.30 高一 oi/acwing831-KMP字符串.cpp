#include <iostream>

using namespace std;

const int N = 1e5, M = 1e6;
// N 为模板串长度，M 为模式串长度 
char p[N + 10], s[M + 10];
// p 为子串，s 为主串 
int ne[N + 10];
// 子串 p 的 next 数组 
int n, m;
// 子串长度 n 和主串长度 m  

int main()
{
	cin >> n >> p + 1 >> m >> s + 1;
	// 将子串和主串从 1 开始读入 
	
	for (int i = 2, j = 0; i <= n; i ++)
	{
		while (j && p[i] != p[j + 1]) j = ne[j];
		if (p[i] == p[j + 1]) j ++;
		ne[i] = j;
	}
	// 求子串的 next 数组 
	
	for (int i = 1, j = 0; i <= m; i ++)
	{
		while (j && s[i] != p[j + 1]) j = ne[j];
		if (s[i] == p[j + 1]) j ++;
		if (j == n)
		{
			printf("%d ", i - n);
			// 匹配成功，按题意执行操作 
			
			j = ne[j];
			// 继续进行的匹配操作 
		}
	}
	// 进行 KMP 匹配的过程 
	return 0;
}
