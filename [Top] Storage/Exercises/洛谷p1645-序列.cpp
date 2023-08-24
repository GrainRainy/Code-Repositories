#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;

bool nums[N];

struct sequence
{
	int l, r;
	int n;
}sqs[N]; 

bool cmp(sequence &a, sequence &b)
{
	if (a.r != b.r) return a.r < b.r;
	else return a.l < b.l;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> sqs[i].l >> sqs[i].r >> sqs[i].n;
	// input
	sort(sqs, sqs + n, cmp);
	
	for (int i = 0; i < n; i ++)
		cerr << sqs[i].l << " " << sqs[i].r << endl;
		
	for (int i = 0; i < n; i ++)
	{
		int tmpn = 0;
		for (int j = sqs[i].l; j <= sqs[i].r; j ++)
			if (nums[j]) tmpn ++;
			
		int needn = sqs[i].n - tmpn;
		
		for (int j = sqs[i].r; needn > 0 && j >= sqs[i].l; j --)
			if (!nums[j]) nums[j] = 1, needn --;
	}

	int tmpans = 0;
	for (int i = 0; i < 1011; i ++)
		if (nums[i]) tmpans ++;
	
	cout << tmpans << endl;
	
	return 0;
		
}
