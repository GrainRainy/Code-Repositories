#include <set>
#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	
	set<int> s;
	for (int i = 0; i < n; i ++)
	{
		int t;
		cin >> t;
		s.insert(t);
	}
	
	if (s.size() < k)
	{
		cout << "NO RESULT" << endl;
		return 0;
	}
	
	set<int> :: iterator it = s.begin();
	while (-- k) it ++;
	cout << *it << endl;
	
	return 0;
}
