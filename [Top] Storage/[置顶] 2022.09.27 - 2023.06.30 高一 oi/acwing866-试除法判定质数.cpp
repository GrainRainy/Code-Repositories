#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

int n, tmp;

void judge(int u){
	if (u == 1) return puts("No"), void();
	for (int i = 2; i <= u / i; i ++){
		if (u % i == 0) return puts("No"), void();
	}
	return puts("Yes"), void();
}

int main(){
	input(n);
	while (n --){input(tmp), judge(tmp);}
	return 0;
}
