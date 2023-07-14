#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2000000;
int nums[N + 10];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i ++)
		scanf("%d", &nums[i]);
		
	sort(nums, nums + m);
	
	for (int i = 0; i < m; i ++)
		printf("%d ", nums[i]);
	
	return 0;
}
