#include <iostream>

using namespace std;

int win[8] = {448, 56, 7, 292, 146, 73, 84, 273};
int ansa, ansu;


int main()
{
	string a;
	cin >> a;
	for (int i = 0; i < a.length(); i ++)
		if (i % 2) ansu = ansu | (1 << ('9' - a[i]));
		else ansa = ansa | (1 << ('9' - a[i]));
	
	 cerr << ansa << " " << ansu << endl;
		
	for (int i = 0; i < 8; i ++)
	{
		if ((ansu & win[i]) == win[i])
		{
			cout << "uim wins." << endl;
			return 0;	
		}
		if ((ansa & win[i]) == win[i])
		{
			// cerr << (ansa & win[i]) << " "<< win[i] << " " << (ansa & win[i] == win[i])<< endl;
			cout << "xiaoa wins." << endl;
			return 0;
		}
	}
	cout << "drew." << endl;
	return 0;
}
