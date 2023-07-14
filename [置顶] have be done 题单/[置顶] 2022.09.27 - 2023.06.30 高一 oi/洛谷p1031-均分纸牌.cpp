#include <iostream>

using namespace std;

int nums[110], cnt, sum;

int main()
{
	int n, aver;
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> nums[i];
		sum += nums[i];
	}
	aver = sum / n;
	for (int i = 1; i <= n; i ++)
	{
		if (nums[i] == aver) continue;
		nums[i + 1] += nums[i] - aver;
		cnt ++;
	}
	cout << cnt << endl;
	return 0;
}
