#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n1,n2,n3,n4;
	double y;
	cin >> n1 >> n2 >> n3 >> n4;
	double x = n1 * 0.2 + n2 * 0.3 + n3 * 0.4 + n4 * 0.1;
	printf("Media: %.1lf\n",x);
	if (x > 7.0) cout << "Aluno aprovado." << endl;
	else if (x < 5.0) cout << "Aluno reprovado." << endl;
	else
	{
		cout << "Aluno em exame." << endl;
		cin >> y;
		cout << "Nota do exame: " << y << endl;
		double z = (x + y) * 1.0 / 2;
		if (z >= 5.0) cout << "Aluno aprovado." << endl;
		else cout << "Aluno reprovado." << endl;
		cout << "Media final: " << z << endl;
	}
}
