#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 3;
int save[N], a[N], x[N];
int ans = 0;

int init(int a, int b, int c)
{
	int cnt = 0;
	int ld = b - a, rd = c - b;
	if (ld > rd)
	{
		cnt = ld / rd;
		int ed = ld % rd;
		if (!ed)
		{
			ed += rd;
			cnt --;
		}
		cnt += init(a, a + ed, a + ed + rd);
	}
	else if (ld < rd)
	{
		cnt = rd / ld;
		int ed = rd % ld;
		if (!ed)
		{
			ed += ld;
			cnt --;
		}
		cnt += init(c - ed - ld, c - ed, c);
	}
	else save[0] = a, save[1] = b, save[2] = c;
	return cnt;
}

void jump(int a, int b, int c, int step)
{
	int cnt = 0;
	int ld = b - a, rd = c - b;
	if (!step or ld == rd)
	{
		save[0] = a, save[1] = b, save[2] = c;
		return;
	}
	if (ld > rd)
	{
		int cnt = ld / rd;
		int ed = ld % rd;
		if (!ed)
		{
			ed += rd;
			cnt --;
		}
		if (step >= cnt)
			jump(a, a + ed, a + ed + rd, step - cnt);
        else
        {
            int k = cnt - step;
            jump(a, a + ed + k * rd, a + ed + (k + 1) * rd, 0);
        }
	}
	else if (ld < rd)
	{
		int cnt = rd / ld;
		int ed = rd % ld;
		if (!ed)
		{
			ed += ld;
			cnt --;
		}
		if (step >= cnt)
			jump(c - ed - ld, c - ed, c, step - cnt);
        else
        {
            int k = cnt - step;
            jump(c - ed - (k + 1) * ld, c - ed - k * ld, c, 0);
        }
	}
}

bool judge(int step)
{
	int tmp[3];
	jump(a[0], a[1], a[2], step);
	tmp[0] = save[0], tmp[1] = save[1], tmp[2] = save[2];
	jump(x[0], x[1], x[2], step);
	if (tmp[0] != save[0] or tmp[1] != save[1] or tmp[2] != save[2])
		return false;
	return true;
}

int main()
{
	cin >> a[0] >> a[1] >> a[2] >> x[0] >> x[1] >> x[2];
	sort(a, a + 3); sort(x, x + 3);
	// init
	int tmp[3];
	int stepa = init(a[0], a[1], a[2]);
	tmp[0] = save[0], tmp[1] = save[1], tmp[2] = save[2];
	int stepx = init(x[0], x[1], x[2]);
	if (tmp[0] != save[0] or tmp[1] != save[1] or tmp[2] != save[2])
	{
		puts("NO");
		return 0;
	}
	
	if (stepa > stepx)
	{
		ans += stepa - stepx;
		jump(a[0], a[1], a[2], stepa - stepx);
		a[0] = save[0], a[1] = save[1], a[2] = save[2];
	}
	if (stepa < stepx)
	{
		ans += stepx - stepa;
		jump(x[0], x[1], x[2], stepx - stepa);
		x[0] = save[0], x[1] = save[1], x[2] = save[2];
	}
	
	int l = 0, r = min(stepa, stepx);
	while (l < r)
	{
		int mid = l + r >> 1;
		if (judge(mid)) r = mid;
		else l = mid + 1;
	}
	cout << "YES" << endl << (l << 1) + ans << endl;
	return 0;
}
