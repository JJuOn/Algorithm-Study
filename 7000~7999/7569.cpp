#include <iostream>
#include <queue>

using namespace std;

int tomato[100][100][100];
int day[100][100][100];

struct pos {
	int i;
	int j;
	int k;
};

pos make_pos(int i, int j, int k) {
	pos temp;
	temp.i = i;
	temp.j = j;
	temp.k = k;
	return temp;
}

int BFS(int green, int n, int m, int h) {
	queue<pos> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < h; k++) {
				if (tomato[i][j][k] == 1) {
					q.push(make_pos(i, j, k));
					day[i][j][k] = 1;
				}
			}
		}
	}
	int result = 0;
	while (green) {
		if (green != 0 && q.empty()) {
			return 0;
		}
		pos p = q.front();
		q.pop();
		if (p.i - 1 >= 0 && tomato[p.i - 1][p.j][p.k] == 0) {
			q.push(make_pos(p.i - 1, p.j, p.k));
			tomato[p.i - 1][p.j][p.k] = 1;
			day[p.i - 1][p.j][p.k] = day[p.i][p.j][p.k] + 1;
			if (--green == 0) {
				result = day[p.i - 1][p.j][p.k];
				break;
			}
		}
		if (p.i + 1 < n && tomato[p.i + 1][p.j][p.k] == 0) {
			q.push(make_pos(p.i + 1, p.j, p.k));
			tomato[p.i + 1][p.j][p.k] = 1;
			day[p.i + 1][p.j][p.k] = day[p.i][p.j][p.k] + 1;
			if (--green == 0) {
				result = day[p.i + 1][p.j][p.k];
				break;
			}
		}
		if (p.j - 1 >= 0 && tomato[p.i][p.j - 1][p.k] == 0) {
			q.push(make_pos(p.i, p.j - 1, p.k));
			tomato[p.i][p.j - 1][p.k] = 1;
			day[p.i][p.j - 1][p.k] = day[p.i][p.j][p.k] + 1;
			if (--green == 0) {
				result = day[p.i][p.j - 1][p.k];
				break;
			}
		}
		if (p.j + 1 < m && tomato[p.i][p.j + 1][p.k] == 0) {
			q.push(make_pos(p.i, p.j + 1, p.k));
			tomato[p.i][p.j + 1][p.k] = 1;
			day[p.i][p.j + 1][p.k] = day[p.i][p.j][p.k] + 1;
			if (--green == 0) {
				result = day[p.i][p.j + 1][p.k];
				break;
			}
		}
		if (p.k - 1 >= 0 && tomato[p.i][p.j][p.k - 1] == 0) {
			q.push(make_pos(p.i, p.j, p.k - 1));
			tomato[p.i][p.j][p.k - 1] = 1;
			day[p.i][p.j][p.k - 1] = day[p.i][p.j][p.k] + 1;
			if (--green == 0) {
				result = day[p.i][p.j][p.k - 1];
				break;
			}
		}
		if (p.k + 1 < h && tomato[p.i][p.j][p.k + 1] == 0) {
			q.push(make_pos(p.i, p.j, p.k + 1));
			tomato[p.i][p.j][p.k + 1] = 1;
			day[p.i][p.j][p.k + 1] = day[p.i][p.j][p.k] + 1;
			if (--green == 0) {
				result = day[p.i][p.j][p.k + 1];
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
	int m, n, h, ripe = 0, green = 0, empty = 0;
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == -1) {
					empty++;
				}
				else if (tomato[i][j][k] == 0) {
					green++;
				}
				else {
					ripe++;
				}
			}
		}
	}
	
	if (empty + ripe == n * m * h) {
		cout << "0\n";
	}
	else {
		cout << BFS(green, n, m, h) - 1 << "\n";
	}
	return 0;
}