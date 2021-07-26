#include <iostream>
#include <string>
#include <queue>

#define INF 10000000

using namespace std;

int n, m, a[1000][1000];
int visited[1000][1000][2];

int Min(int a, int b) {
	return a < b ? a : b;
}

struct pos{
	int i;
	int j;
	bool crashed;
	pos(int _i, int _j, bool _crashed) : i(_i), j(_j), crashed(_crashed) {};
};

int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

int BFS() {
	queue<pos> q;
	pos node = pos(0, 0, false);
	q.push(node);
	visited[0][0][0] = 1;
	while (!q.empty()) {
		pos node = q.front();
		q.pop();
		if (node.i == n - 1 && node.j == m - 1) {
			return visited[n - 1][m - 1][node.crashed];
		}
		for (int k = 0; k < 4; k++) {
			int ni = node.i + di[k];
			int nj = node.j + dj[k];
			if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
				if (!node.crashed && a[ni][nj] == 1) {
					q.push(pos(ni, nj, true));
					visited[ni][nj][1] = visited[node.i][node.j][node.crashed] + 1;
				}
				if (a[ni][nj] == 0 && !visited[ni][nj][node.crashed]) {
					q.push(pos(ni, nj, node.crashed));
					visited[ni][nj][node.crashed] = visited[node.i][node.j][node.crashed] + 1;
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < m; j++) {
			a[i][j] = line[j] - '0';
			visited[i][j][0] = 0;
			visited[i][j][1] = 0;
		}
	}
	cout << BFS() << "\n";
	return 0;
}