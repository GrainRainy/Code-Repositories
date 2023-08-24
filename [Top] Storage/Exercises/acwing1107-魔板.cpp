#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

const int N = 10;
char now[N];
string st = "12348765", ed;
string ans;
queue<string> q;
map<string, int> dist;
map<string, pair<char, string> > path;

string change(string t, int op) {
    string k;
    if (op == 0) k = {t[4], t[5], t[6], t[7], t[0], t[1], t[2], t[3]};
    if (op == 1) k = {t[3], t[0], t[1], t[2], t[7], t[4], t[5], t[6]};
    if (op == 2) k = {t[0], t[5], t[1], t[3], t[4], t[6], t[2], t[7]};
    return k;
}

//string change(string a, int op)
//{
//	string tmpn;
//	if (op == 0) tmpn = a[4] + a[5] + a[6] + a[7] + a[0] + a[1] + a[2] + a[3];
//	if (op == 1) tmpn = a[3] + a[0] + a[1] + a[2] + a[7] + a[4] + a[5] + a[6];
//	if (op == 2) tmpn = a[0] + a[5] + a[1] + a[3] + a[4] + a[6] + a[2] + a[7];
//	return tmpn;
//}

int bfs()
{
	dist[st] = 0;
	q.push(st);
	
	while (q.size())
	{
		auto t = q.front(); q.pop();
		if (t == ed) return dist[t];
		
		for (int i = 0; i < 3; i ++)
		{
			auto tmpx = change(t, i);
			if (!dist.count(tmpx))
			{
				dist[tmpx] = dist[t] + 1;
				path[tmpx].first = 'A' + i;
				path[tmpx].second = t;
				q.push(tmpx);
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 8; i ++)
		cin >> now[i];
	// input
	reverse(now + 4, now + 8);
	
	for (int i = 0; i < 8; i ++)
		ed.push_back(now[i]);
	
//	string ed = now; // target state
	
	cout << bfs() << endl;
	
	while (ed != st)
	{
		ans += path[ed].first;
		ed = path[ed].second;
	}
	
	reverse(ans.begin(), ans.end());
	cout << ans << endl;	
	return 0;
}
