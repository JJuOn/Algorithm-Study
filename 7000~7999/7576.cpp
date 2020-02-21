#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int tomato[1000][1000];
int day[1000][1000];

bool canRipe(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0) {
				bool flag = false;
				if (i - 1 >= 0 && tomato[i - 1][j] != -1) {
					flag = true;
					continue;
				}
				if (i + 1 < n && tomato[i + 1][j] != -1) {
					flag = true;
					continue;
				}
				if (j - 1 >= 0 && tomato[i][j - 1] != -1) {
					flag = true;
					continue;
				}
				if (j + 1 < m && tomato[i][j + 1] != -1) {
					flag = true;
					continue;
				}
				if (!flag) {
					return false;
				}
			}
		}
	}
	return true;
}

int BFS(int green, int n, int m) {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 1) {
				q.push(make_pair(i, j));
				day[i][j] = 1;
			}
		}
	}
	while (green) {
		pair<int, int> p = q.front();
		q.pop();
		if (p.first - 1 >= 0 && tomato[p.first - 1][p.second] == 0) {
			q.push(make_pair(p.first - 1, p.second));
			tomato[p.first - 1][p.second] = 1;
			day[p.first - 1][p.second] = day[p.first][p.second] + 1;
			if (--green == 0) {
				return day[p.first - 1][p.second];
			}
		}
		if (p.first + 1 < n && tomato[p.first + 1][p.second] == 0) {
			q.push(make_pair(p.first + 1, p.second));
			tomato[p.first + 1][p.second] = 1;
			day[p.first + 1][p.second] = day[p.first][p.second] + 1;
			if (--green == 0) {
				return day[p.first + 1][p.second];
			}
		}
		if (p.second - 1 >= 0 && tomato[p.first][p.second - 1] == 0) {
			q.push(make_pair(p.first, p.second - 1));
			tomato[p.first][p.second - 1] = 1;
			day[p.first][p.second - 1] = day[p.first][p.second] + 1;
			if (--green == 0) {
				return day[p.first][p.second - 1];
			}
		}
		if (p.second + 1 < m && tomato[p.first][p.second + 1] == 0) {
			q.push(make_pair(p.first, p.second + 1));
			tomato[p.first][p.second + 1] = 1;
			day[p.first][p.second + 1] = day[p.first][p.second] + 1;
			if (--green == 0) {
				return day[p.first][p.second + 1];
			}
		}
	}
}
		

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m, n, ripe = 0, green = 0, empty = 0;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == -1) {
				empty++;
			}
			else if (tomato[i][j] == 0) {
				green++;
			}
			else {
				ripe++;
			}
		}
	}
	if (empty + ripe == n * m) {
		cout << "0\n";
	}
	else if (!canRipe(n, m)) {
		cout << "-1\n";
	}
	else {
		cout << BFS(green, n, m) - 1 << "\n";
	}
	return 0;
}