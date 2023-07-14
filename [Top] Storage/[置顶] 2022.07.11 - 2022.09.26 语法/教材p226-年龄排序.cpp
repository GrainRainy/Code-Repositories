#include <bits/stdc++.h>
using namespace std;

struct student
{
	string name, sex;
	int birth_y, birth_m;
};

const int N = 105;
student a[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 5; i ++)
		cin >> a[i].name >> a[i].sex >> a[i].birth_y >> a[i].birth_m;
	for (int i = 0; i < 5; i ++)
		for (int j = i + 1; j < 5; j ++)
			if (a[i].birth_y < a[j].birth_y || a[i].birth_y == a[j].birth_y && a[i].birth_m < a[j].birth_m)
				swap(a[i], a[j]);
	
	for (int i = 0; i < 5; i ++)
		cout << a[i].name << " " << a[i].sex << " " << a[i].birth_y << " " << a[i].birth_m << endl;
	return 0;
}
