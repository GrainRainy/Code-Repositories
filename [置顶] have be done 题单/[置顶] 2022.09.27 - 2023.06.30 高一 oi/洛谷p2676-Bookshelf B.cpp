#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20000;
int height_mur[N + 10];
int main()
{
	int n, height_shelf;
	cin >> n >> height_shelf; 
	
	for (int i = 0; i < n; i ++)
		scanf("%d", &height_mur[i]);
	
	sort(height_mur, height_mur + n, greater<int>());
	
	int sum_height = 0;
	int cnt = 0;
	while (sum_height < height_shelf)
	{
		sum_height += height_mur[cnt];
		cnt ++;
	}
	cout << cnt << endl;
	return 0;
}
