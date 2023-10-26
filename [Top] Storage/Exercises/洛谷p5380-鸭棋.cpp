#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
string nm[10];
map<string, int> val;
bool ovr, trn = 1;
pair<int, int> cpt[2] = {{9, 4}, {0, 4}};
int q, g[10][10] = {
	{ 15, 14, 13, 12, 11, 12, 13, 14, 15 }, 
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
	{ 16, 0, 0, 0, 0, 0, 0, 0, 16 }, 
	{ 17, 0, 17, 0, 17, 0, 17, 0, 17 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
	{ 7, 0, 7, 0, 7, 0, 7, 0, 7 },
	{ 6, 0, 0, 0, 0, 0, 0, 0, 6 }, 
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
	{ 5, 4, 3, 2, 1, 2, 3, 4, 5 }
};

bool ing(int x, int y) { return (x >= 0 and x < 10 and y >= 0 and y < 9); }
vector<pair<int, int>> avl(int id, int tp, int x, int y, int nx = 0, int ny = 0) {
	vector<pair<int, int>> res;
	if (id == 1) {
		for (int i : {-1, 1}) {
			if (ing(x + i, y) and (!g[x + i][y] or g[x + i][y] / 10 ^ tp)) res.push_back({x + i, y});
			if (ing(x, y + i) and (!g[x][y + i] or g[x][y + i] / 10 ^ tp)) res.push_back({x, y + i});
		}
	} else if (id == 2) {
		for (int i : {-1, 1}) for (int j : {-1, 1})
			if (ing(x + i, y + j) and (!g[x + i][y + j] or g[x + i][y + j] / 10 ^ tp))
				res.push_back({x + i, y + j});
	} else if (id == 3) {
		for (int i : {-1, 1}) for (int j : {-1, 1})
			if (ing(nx = x + i * 2, ny = y + j * 2) and !g[x + i][y + j])
				if (!g[nx][ny] or g[nx][ny] / 10 ^ tp) res.push_back({nx, ny});
	} else if (id == 4) {
		for (int i : {-1, 1}) for (int j : {-1, 1}) {
			if (ing(nx = x + i * 2, ny = y + j) and !g[x + i][y])
				if (!g[nx][ny] or g[nx][ny] / 10 ^ tp) res.push_back({nx, ny});
			if (ing(nx = x + i, ny = y + j * 2) and !g[x][y + j])
				if (!g[nx][ny] or g[nx][ny] / 10 ^ tp) res.push_back({nx, ny});
		}
	} else if (id == 5) {
		int px = x, py = y;
		while (ing(px - 1, y) and !g[px - 1][y]) px --, res.push_back({px, y});
		while (ing(x, py - 1) and !g[x][py - 1]) py --, res.push_back({x, py});
		if (ing(px - 1, y) and g[px - 1][y] / 10 ^ tp) res.push_back({px - 1, y});
		if (ing(x, py - 1) and g[x][py - 1] / 10 ^ tp) res.push_back({x, py - 1});
		px = x, py = y;
		while (ing(px + 1, y) and !g[px + 1][y]) px ++, res.push_back({px, y});
		while (ing(x, py + 1) and !g[x][py + 1]) py ++, res.push_back({x, py});
		if (ing(px + 1, y) and g[px + 1][y] / 10 ^ tp) res.push_back({px + 1, y});
		if (ing(x, py + 1) and g[x][py + 1] / 10 ^ tp) res.push_back({x, py + 1});
	} else if (id == 6) {
		for (int i : {-1, 1}) for (int j : {-1, 1}) {
			if (ing(nx = x + i * 3, ny = y + j * 2) and !g[x + i * 2][y + j] and !g[x + i][y])
				if (!g[nx][ny] or g[nx][ny] / 10 ^ tp) res.push_back({nx, ny});
			if (ing(nx = x + i * 2, ny = y + j * 3) and !g[x + i][y + j * 2] and !g[x][y + j])
				if (!g[nx][ny] or g[nx][ny] / 10 ^ tp) res.push_back({nx, ny});
		}
	} else if (id == 7) {
		for (int i : {-1, 0, 1}) for (int j : {-1, 0, 1})
			if (ing(nx = x + i, ny = y + j) and (i or j) and (!g[nx][ny] or g[nx][ny] / 10 ^ tp))
				res.push_back({nx, ny});
	} else return vector<pair<int, int>>();
	return res;
}

bool jg(int id, int xs, int ys, int xt, int yt) {
	for (auto t : avl(id % 10, id / 10, xs, ys))
		if (t.fi == xt and t.se == yt) return true;
	return false;
}

bool ck(int x, int y) {
	for (int i = x - 10; i <= x + 10; ++ i)
		for (int j = x - 10; j <= x + 10; ++ j)
			if (ing(i, j) and g[i][j] / 10 ^ g[x][y] / 10)
				for (auto t : avl(g[i][j] % 10, g[i][j] / 10, i, j))
					if (t.fi == x and t.se == y) return true;
	return false; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> q;
	val["captain"] = 1, nm[1] = "captain", val["guard"] = 2, nm[2] = "guard";
	val["elephant"] = 3, nm[3] = "elephant", val["horse"] = 4, nm[4] = "horse";
	val["car"] = 5, nm[5] = "car", val["duck"] = 6, nm[6] = "duck";
	val["soldier"] = 7, nm[7] = "soldier";
	for (int i = 1, xs, ys, xt, yt; i <= q; ++ i) {
		cin >> xs >> ys >> xt >> yt;
		if (g[xs][ys] / 10 != trn or !jg(g[xs][ys], xs, ys, xt, yt) or ovr) 
			cout << "Invalid command\n";
		else {
			if (g[xs][ys] / 10) cout << "red " << nm[g[xs][ys] - 10] << ';';
			else cout << "blue " << nm[g[xs][ys]] << ';';
			if (!g[xt][yt]) cout << "NA;";
			else if (!(g[xs][ys] / 10) and g[xt][yt] / 10) cout << "red " << nm[g[xt][yt] - 10] << ';';
			else if (g[xs][ys] / 10 and !(g[xt][yt] / 10)) cout << "blue " << nm[g[xt][yt]] << ';';
			if (g[xt][yt] % 10 == 1) ovr = true, cpt[g[xt][yt] / 10] = {114514, 1919810};
			if (g[xs][ys] % 10 == 1) cpt[g[xs][ys] / 10] = {xt, yt};
			g[xt][yt] = g[xs][ys], g[xs][ys] = 0, trn ^= 1;
			cout << (ck(cpt[0].fi, cpt[0].se) or ck(cpt[1].fi, cpt[1].se) ? "yes;" : "no;");
			cout << (ovr ? "yes\n" : "no\n");
		}
	}
	return 0;
}
