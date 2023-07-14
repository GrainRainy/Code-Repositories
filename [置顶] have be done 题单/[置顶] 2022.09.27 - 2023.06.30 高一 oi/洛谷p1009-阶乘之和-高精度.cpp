#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> jiecheng[55];
vector<int> ans;

vector<int> mul(const vector<int> &A, int n)
{
	vector<int> C;
	int t = 0;
	
	for(int i = 0; i < A.size() || t; i ++)
	{
		if (i < A.size()) t += A[i] * n;
		C.push_back(t % 10);
		t = t / 10;
	}
	while (C.size() > 1 && C.back() == 0)
		C.pop_back();
	return C;
}

vector<int> add(const vector<int> &A, const vector<int> &B)
{
	int t = 0;
	vector<int> ans;
	for (int i = 0; i < A.size() || i < B.size(); i ++)
	{
		if (i < A.size()) t += A[i];
		if (i < B.size()) t += B[i];
		ans.push_back(t % 10);
		t /= 10;
	}
	if (t) ans.push_back(1);
	return ans;
}

int main()
{

	cin >> n;
	jiecheng[1].push_back(1);
	for (int i = 2; i <= n; i ++)
		jiecheng[i] = mul(jiecheng[i - 1], i);
		
	for (int i = 1; i <= n; i ++)
		ans = add(ans, jiecheng[i]);
	
	for (int i = ans.size() - 1; i >= 0; i --)
		cout << ans[i];
	cout << endl;
	
	return 0; 
}
