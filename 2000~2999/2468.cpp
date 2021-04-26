#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, a[100][100], maxLevel = -1;

int BFS(int level) {
	int b[100][100];
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] <= level) {
				b[i][j] = -1;
			}
			else {
				b[i][j] = 0;
			}
		}
	}
	int color = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i][j] == 0) {
				q.push(make_pair(i, j));
				b[i][j] = color;
				while (!q.empty()) {
					int ii = q.front().first, jj = q.front().second;
					q.pop();
					if (ii - 1 >= 0 && b[ii - 1][jj] == 0) {
						q.push(make_pair(ii - 1, jj));
						b[ii - 1][jj] = color;
					}
					if (ii + 1 < n && b[ii + 1][jj] == 0) {
						q.push(make_pair(ii + 1, jj));
						b[ii + 1][jj] = color;
					}
					if (jj - 1 >= 0 && b[ii][jj - 1] == 0) {
						q.push(make_pair(ii, jj - 1));
						b[ii][jj - 1] = color;
					}
					if (jj + 1 < n && b[ii][jj + 1] == 0) {
						q.push(make_pair(ii, jj + 1));
						b[ii][jj + 1] = color;
					}
				}
				color++;
			}
		}
	}
	return color - 1;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] > maxLevel) {
				maxLevel = a[i][j];
			}
		}
	}

	int maxSafeZone = 1;
	for (int level = 1; level <= maxLevel; level++) {
		int safeZone = BFS(level);
		if (safeZone > maxSafeZone) {
			maxSafeZone = safeZone;
		}
	}
	cout << maxSafeZone << "\n";
	return 0;
}