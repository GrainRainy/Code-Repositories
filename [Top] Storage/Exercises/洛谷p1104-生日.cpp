#include <iostream>
#include <algorithm>

using namespace std;
int n;

struct stus
{
	string a;
	int year, month, day;
	
	
	bool operator < (const stus &t) const
	{
		if (year != t.year) return year < t.year;
		else if (month != t.month) return month < t.month;
		else if (day != t.day) return day < t.day;
		else return 1;
	}
};

int main()
{
	cin >> n;
	stus cjf[100];
			
	for (int i = 0; i < n; i ++)
		cin >> cjf[i].a >> cjf[i].year >> cjf[i].month >> cjf[i].day;
	
	stable_sort(cjf, cjf + n);
	
	for (int i = 0; i < n; i ++)
		cout << cjf[i].a << endl;
	return 0;
}
