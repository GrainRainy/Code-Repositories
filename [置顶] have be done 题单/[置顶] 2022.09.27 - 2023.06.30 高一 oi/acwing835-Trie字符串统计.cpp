#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int son[N][26];
// ÿ���ڵ��������ӽڵ�
int cnt[N];
// �Ե�ǰ���β���ַ����ж��ٸ�
int idx;
// ��ǰ�õ�����Щ�±꣬���ڵ� root �Ϳսڵ㶼ָ�� idx = 0
char str[N];


void insert(char str[])
// ���뺯�� 
{
	int p = 0;
	// �Ӹ��ڵ� 0 ��ʼ���� 
	for (int i = 0; str[i]; i ++)
	{
		int u = str[i] - 'a';
		// ӳ����ĸ�Բ��һ�����ӽڵ�
		if (!son[p][u]) son[p][u] = ++ idx;
		// ���û�д���ĸ���ӽڵ㣬��ô����һ��
		p = son[p][u];
		// ������һ���� 
	}
	// ��ʱ����������ַ���ȫ��������� 
	cnt[p] ++;
	// �Դ˽ڵ�������ַ�������һ�� 
}

int query(char str[])
// ��ѯ�����������ַ������ֶ��ٴ�
{
	int p = 0;
	for (int i = 0; str[i]; i ++)
	{
		int u = str[i] - 'a';
		if (!son[p][u]) return 0;
		// ��������ڴ���ĸ���ӽڵ㣬��ôֱ���˳� 
		p = son[p][u];
		// ������ڵ�ǰ�ӽڵ㣬�����Ǹ� 
	}
	// ��ʱ�������ҵ��ַ���������� 
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
