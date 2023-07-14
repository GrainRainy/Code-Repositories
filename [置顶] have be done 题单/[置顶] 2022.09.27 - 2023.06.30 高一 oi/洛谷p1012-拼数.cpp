#include <iostream>
#include <algorithm> 

using namespace std;

string nums[25];

bool cmp(string &a, string &b)
{
	return (a + b > b + a);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> nums[i];
	
	sort(nums, nums + n, cmp);
	
	string ans;
	for (int i = 0; i < n; i ++)
		ans += nums[i];
	
	cout << ans << endl;
	return 0;

}
