#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int tomato[1000][1000];
int day[1000][1000];

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
	int result = 0;
	while (green) {
		if (green!=0 && q.empty()){
			return 0;
		}
		pair<int, int> p = q.front();
		q.pop();
		//up
		if (p.first - 1 >= 0 && tomato[p.first - 1][p.second] == 0) {
			q.push(make_pair(p.first - 1, p.second));
			tomato[p.first - 1][p.second] = 1;
			day[p.first - 1][p.second] = day[p.first][p.second] + 1;
			if (--green == 0) {
				result = day[p.first - 1][p.second];
				break;
			}
		}
		//down
		if (p.first + 1 < n && tomato[p.first + 1][p.second] == 0) {
			q.push(make_pair(p.first + 1, p.second));
			tomato[p.first + 1][p.second] = 1;
			day[p.first + 1][p.second] = day[p.first][p.second] + 1;
			if (--green == 0) {
				result = day[p.first + 1][p.second];
				break;
			}
		}
		//left
		if (p.second - 1 >= 0 && tomato[p.first][p.second - 1] == 0) {
			q.push(make_pair(p.first, p.second - 1));
			tomato[p.first][p.second - 1] = 1;
			day[p.first][p.second - 1] = day[p.first][p.second] + 1;
			if (--green == 0) {
				result = day[p.first][p.second - 1];
				break;
			}
		}
		//right
		if (p.second + 1 < m && tomato[p.first][p.second + 1] == 0) {
			q.push(make_pair(p.first, p.second + 1));
			tomato[p.first][p.second + 1] = 1;
			day[p.first][p.second + 1] = day[p.first][p.second] + 1;
			if (--green == 0) {
				result = day[p.first][p.second + 1];
				break;
			}
		}
	}
	return result;
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
	else {
		cout << BFS(green, n, m) - 1 << "\n";
	}
	return 0;
}