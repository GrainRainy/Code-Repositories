#include <iostream>
#include <algorithm>

using namespace std;

struct students
{
	int num;
	int chi, mat, eng;
	int tot;
	
	
}stu[310];

bool cmp(students a, students b)
{
		if (a.tot != b.tot) return a.tot > b.tot;
		else if (a.chi != b.chi) return a.chi > b.chi;
		else return a.num < b.num;
} 

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		stu[i].num = i + 1;
		cin >> stu[i].chi >> stu[i].mat >> stu[i].eng;
		stu[i].tot = stu[i].chi + stu[i].mat + stu[i].eng;
	}
	
	sort(stu, stu + n, cmp);
	
	for (int i = 0; i < 5; i ++)
		cout << stu[i].num << " " << stu[i].tot << endl;
	
	return 0; 
}
