#include <iostream>
#include <cstring>
#include <algorithm>

#define owo 0

using namespace std;
using LL = long long;

const int N = 50;
int h, w;
char ori[N][N], tran[N][N];

bool transform(int deltaX, int deltaY) {
	for (int i = 0; i < h; ++ i) {
		for (int j = 0; j < w; ++ j) {
			if (tran[(i + deltaX) % h][(j + deltaY) % w] != ori[i][j])
				return false;
		}
	}
	return true;
}

int main() {
	cin >> h >> w;
	
	for (int i = 0; i < h; ++ i) {
		for (int j = 0; j < w; j ++) {
			cin >> tran[i][j];
		}
	}
	for (int i = 0; i < h; ++ i) {
		for (int j = 0; j < w; ++ j) {
			cin >> ori[i][j];
		}
	}
	
	for (int i = 0; i < h; ++ i) {
		for (int j = 0; j < w; ++ j) {
			if (transform(i, j)) return puts("Yes"), owo;
		}
	}
	return puts("No"), owo;
}
