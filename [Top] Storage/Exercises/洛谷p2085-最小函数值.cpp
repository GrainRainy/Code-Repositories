#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

int n, m;

struct fnc
{
	int x;
	int a, b, c;
	int fx;
	
	bool operator < (const fnc &t) const
	{
		return fx > t.fx;
	}
	
}nums[N];

priority_queue<fnc> heap;

void init()
{
	for (int i = 0; i < n; i ++)
	{
		nums[i].x = 1;
		nums[i].fx = nums[i].a * nums[i].x * nums[i].x + nums[i].b * nums[i].x + nums[i].c;
		heap.push(nums[i]);
	}
}

void update(fnc t)
{
	t.x ++;
	t.fx = t.a * t.x * t.x + t.b * t.x + t.c;
	heap.pop();
	heap.push(t);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		cin >> nums[i].a >> nums[i].b >> nums[i].c;
	// input
	
	init();
	
	for (int i = 0; i < m; i ++)
	{
		cout << heap.top().fx << " ";
		update(heap.top());
	}
	
	return 0;
}
