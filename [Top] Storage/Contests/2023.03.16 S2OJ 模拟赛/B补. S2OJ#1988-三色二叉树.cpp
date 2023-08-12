#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define max(a, b) ((a > b) ? (a) : (b))

using namespace std;

const int N = 5e5 + 100;
string s;
int cnt = 0;
int f[N][3], g[N][3]; // min and max, color

 void dp(int u){
	if (s[u] == '0')
		return f[u][0] = g[u][0] = 1, void();
	
	int l = ++ cnt; dp(l);
	if (s[u] == '1'){
		g[u][0] = max(g[l][1], g[l][2]) + 1;
		g[u][1] = max(g[l][0], g[l][2]);
		g[u][2] = max(g[l][0], g[l][1]);
		
		f[u][0] = min(f[l][1], f[l][2]) + 1;
		f[u][1] = min(f[l][0], f[l][2]);
		f[u][2] = min(f[l][0], f[l][1]);
	}
	
	else{
		int r = ++ cnt;
		dp(r);
		
		g[u][0] = max(g[l][1] + g[r][2], g[l][2] + g[r][1]) + 1;
		g[u][1] = max(g[l][0] + g[r][2], g[l][2] + g[r][0]);
		g[u][2] = max(g[l][0] + g[r][1], g[l][1] + g[r][0]);
		
		f[u][0] = min(f[l][1] + f[r][2], f[l][2] + f[r][1]) + 1;
		f[u][1] = min(f[l][0] + f[r][2], f[l][2] + f[r][0]);
		f[u][2] = min(f[l][0] + f[r][1], f[l][1] + f[r][0]);
	}
}

int main(){
	cin >> s;
	s = '0' + s;
	dp(++ cnt);
	cout << max(max(g[1][0], g[1][1]), g[1][2]) << " " << min(min(f[1][0], f[1][1]), f[1][2]) << endl;
	
	for (int i = 1; i < s.size(); i ++){
		for (int j = 0; j < 3; j ++)
			cout << g[i][j] << " ";
		cout << endl;
	}
			
	return 0;
}
