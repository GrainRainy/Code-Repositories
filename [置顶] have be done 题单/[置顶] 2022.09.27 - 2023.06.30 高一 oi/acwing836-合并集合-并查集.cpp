#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int p[N];
// father 数组，用于指向每个节点的父节点

int find(int x)
// 返回 x 的根节点，同时处理路径压缩 
{
	if (p[x] != x)
	// 如果 x 不为根节点 
		p[x] = find(p[x]);
		// 向上查找同时将 x 的父节点指向根节点 
	
	return p[x];
	// 返回 p[x] 此时的父节点 ( 即为根节点 ) 
}

int main()
{
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++) p[i] = i;
	// 并查集的初始化，将每个节点的父节点指向自己
	
	while (m --)
	{
		char op[2];
		int a, b;
		cin >> op >> a >> b;
		if (op[0] == 'M') 
			p[find(a)] = find(b);
			// 返回 a 与 b 的根节点
			//同时将 a 所在集合的根节点指向 b 所在集合的根节点 
		else
		{
			if (find(a) == find(b)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	
	return 0;
}
