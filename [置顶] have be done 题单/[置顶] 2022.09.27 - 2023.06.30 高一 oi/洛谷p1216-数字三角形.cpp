#include <iostream>

using namespace std;

const int N = 1000;
int nums[N + 10][N + 10];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j <= i; j ++)
			cin >> nums[i][j];
			
	for (int i = n - 2; i >= 0; i --)
		for (int j = 0; j <= i; j ++)
			nums[i][j] += max(nums[i + 1][j], nums[i + 1][j + 1]);
		
	cout << nums[0][0] << endl;
	return 0;
}
