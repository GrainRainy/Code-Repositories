#include <bits/stdc++.h>

using namespace std;

const int N = 210;

int cow[N];
// refers to the position of the cows
int gap[N], idx = 1;
// all of them begin with 1

int main()
{
	int m, s, c;
	// refers to the nums of woods
	// refers to the length of the (niupeng
	// refers to the nums of cows
	cin >> m >> s >> c;
	for (int i = 1; i <= c; i ++)
		cin >> cow[i];
	// input
	
	sort(cow + 1, cow + idx + 1);
	
	s = s - (cow[1] - 1) - (s - cow[c]);
	// delete the gap on the head and end
	for (int i = 1; i < c; i ++)
	{
		int x = cow[i], y = cow[i + 1];
		if (y - x != 1) gap[idx ++] = y - x - 1;
	}
	
	sort(gap + 1, gap + idx, greater<int>());
	
	int nl = s;
	// refer to the lenth that need to be covered
	m --;
	// refer to the nums of the gap
	int idxg = 1;
	while (m --)
		nl -= gap[idxg ++];
		
		
	cout << nl << endl;
	
	return 0;
}
