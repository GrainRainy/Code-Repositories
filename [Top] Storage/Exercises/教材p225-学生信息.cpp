#include <bits/stdc++.h>
using namespace std;

struct stu
{
	string name;
	char sex;
	int age;
	double weight;
};

int main()
{
	stu a;
	cin >> a.name >> a.sex >> a.age >> a.weight;
	cout << a.name << " " << a.sex << " " << a.age << " ";
	printf("%.1lf\n", a.weight);
	return 0;
}
