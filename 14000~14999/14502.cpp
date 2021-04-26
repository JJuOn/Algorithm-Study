#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int a[9][9];
int n, m, maxSafeZone = -1;

int BFS() {
	int b[9][9];
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = a[i][j];
			if (b[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> coord = q.front();
		q.pop();
		if (coord.first - 1 >= 0 && b[coord.first - 1][coord.second] == 0) {
			b[coord.first - 1][coord.second] = 2;
			q.push(make_pair(coord.first - 1, coord.second));
		}
		if (coord.first + 1 < n && b[coord.first + 1][coord.second] == 0) {
			b[coord.first + 1][coord.second] = 2;
			q.push(make_pair(coord.first + 1, coord.second));
		}
		if (coord.second - 1 >= 0 && b[coord.first][coord.second - 1] == 0) {
			b[coord.first][coord.second - 1] = 2;
			q.push(make_pair(coord.first, coord.second - 1));
		}
		if (coord.second + 1 < m && b[coord.first][coord.second + 1] == 0) {
			b[coord.first][coord.second + 1] = 2;
			q.push(make_pair(coord.first, coord.second + 1));
		}
	}
	int c = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] == 0) {
				c++;
			}
		}
	}
	return c;
}

void wall(int c) {
	if (c == 3) {
		int safeZone = BFS();
		if (safeZone > maxSafeZone) {
			maxSafeZone = safeZone;
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0) {
					a[i][j] = 1;
					wall(c + 1);
					a[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	wall(0);
	cout << maxSafeZone << "\n";
	return 0;
}