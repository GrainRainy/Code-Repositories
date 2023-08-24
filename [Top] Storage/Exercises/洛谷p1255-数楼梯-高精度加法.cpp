#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> save[5050];


vector<int> add (const vector<int> &A, const vector<int> &B)
{
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size() || i < B.size(); i ++)
	{
		if (i < A.size()) t += A[i];
		if (i < B.size()) t += B[i];
		C.push_back(t % 10);
		t = t / 10;
	}
	if (t) C.push_back(1);
	return C;	
}

vector<int> ways(int n)
{
	if (!(save[n].empty())) return save[n];
	auto ans = add(ways(n - 1), ways(n - 2));
	save[n] = ans;
	return ans;
}
	
int main()
{
	int n;
	cin >> n;
	save[1].push_back(1);
	save[2].push_back(2);
	auto C = ways(n);
	for (int i = C.size() - 1; i >= 0; i --)
		cout << C[i];
	cout << endl;
	
	return 0;
}
