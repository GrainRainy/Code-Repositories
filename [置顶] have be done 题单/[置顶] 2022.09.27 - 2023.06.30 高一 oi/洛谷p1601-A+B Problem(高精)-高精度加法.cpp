#include <iostream>
#include <vector>

using namespace std;

vector<int> add (const vector<int> &a, const vector<int> &b)
{
	vector<int> c;
	int t = 0;
	for (int i = 0; i < a.size() || i< b.size(); i ++)
	{	
		if (i < a.size()) t += a[i];
		if (i < b.size()) t += b[i];
		c.push_back(t % 10);
		t = t / 10;
	}
	if (t) c.push_back(1);
	return c;
		
}

int main()
{
	string a, b;
	cin >> a >> b;
	vector<int> A, B;
	for (int i = a.size() - 1; i >= 0; i --)
		A.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; i --)
		B.push_back(b[i] - '0');
	auto C = add(A, B);
	
	for (int i = C.size() - 1; i >= 0; i --)
		cout << C[i];
	cout << endl;
	return 0;
}
