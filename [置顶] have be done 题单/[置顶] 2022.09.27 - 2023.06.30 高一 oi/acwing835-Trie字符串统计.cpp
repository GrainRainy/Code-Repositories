#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int son[N][26];
// 每个节点连到的子节点
int cnt[N];
// 以当前点结尾的字符串有多少个
int idx;
// 当前用到了哪些下标，根节点 root 和空节点都指向 idx = 0
char str[N];


void insert(char str[])
// 插入函数 
{
	int p = 0;
	// 从根节点 0 开始遍历 
	for (int i = 0; str[i]; i ++)
	{
		int u = str[i] - 'a';
		// 映射字母以查找或添加子节点
		if (!son[p][u]) son[p][u] = ++ idx;
		// 如果没有此字母的子节点，那么创建一个
		p = son[p][u];
		// 向下走一个点 
	}
	// 此时将待插入的字符串全部遍历完毕 
	cnt[p] ++;
	// 以此节点结束的字符串多了一个 
}

int query(char str[])
// 查询函数，返回字符串出现多少次
{
	int p = 0;
	for (int i = 0; str[i]; i ++)
	{
		int u = str[i] - 'a';
		if (!son[p][u]) return 0;
		// 如果不存在此字母的子节点，那么直接退出 
		p = son[p][u];
		// 如果存在当前子节点，走向那个 
	}
	// 此时将带查找的字符串遍历完毕 
	return cnt[p];
}

int main()
{
	int n;
	cin >> n;
	while (n --)
	{
		char op[2];
		scanf("%s%s", op, str);
		if (op[0] == 'I') insert(str);
		else printf("%d\n", query(str)); 
	}
	
	return 0;
}
