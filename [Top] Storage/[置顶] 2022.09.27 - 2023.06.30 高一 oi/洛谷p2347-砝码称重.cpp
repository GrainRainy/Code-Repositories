#include <iostream>

using namespace std;

bool f[1010] = {1}; 

int nums[6];
int w[6] = {1, 2, 3, 5, 10, 20};

int main()
{
	for (int i = 0; i < 6; i ++)
		cin >> nums[i];
	
	for (int i = 0; i < 6; i ++)
		for (int j = 0; j < nums[i]; j ++)
			for (int k = 1000; k >= 0; k --)
				if (f[k]) f[k + w[i]] = true;
	
	int cnt = 0;
	for (int i = 0; i <= 1000; i ++)
		if (f[i]) cnt ++;
		
	cout << "Total=" << cnt - 1 << endl;
}
