#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int maze[101][101], crashed[101][101];

struct cmp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		return crashed[p1.first][p1.second] > crashed[p2.first][p2.second];
	}
};

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		char line[101];
		cin >> line;
		for (int j = 1; j <= m; j++) {
			maze[i][j] = line[j - 1] - '0';
			crashed[i][j] = 987654321;
		}
	}
	
	priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;
	pq.push(make_pair(1, 1));
	crashed[1][1] = 0;
	while (!pq.empty()) {
		pair<int, int> p = pq.top();
		pq.pop();
		if (p.first - 1 > 0 && crashed[p.first - 1][p.second] > crashed[p.first][p.second] + maze[p.first - 1][p.second]) {
			pq.push(make_pair(p.first - 1, p.second));
			crashed[p.first - 1][p.second] = crashed[p.first][p.second] + maze[p.first - 1][p.second];
		}
		if (p.first + 1 <= n && crashed[p.first + 1][p.second] > crashed[p.first][p.second] + maze[p.first + 1][p.second]) {
			pq.push(make_pair(p.first + 1, p.second));
			crashed[p.first + 1][p.second] = crashed[p.first][p.second] + maze[p.first + 1][p.second];
		}
		if (p.second - 1 > 0 && crashed[p.first][p.second - 1] > crashed[p.first][p.second] + maze[p.first][p.second - 1]) {
			pq.push(make_pair(p.first, p.second - 1));
			crashed[p.first][p.second - 1] = crashed[p.first][p.second] + maze[p.first][p.second - 1];
		}
		if (p.second + 1 <= m && crashed[p.first][p.second + 1] > crashed[p.first][p.second] + maze[p.first][p.second + 1]) {
			pq.push(make_pair(p.first, p.second + 1));
			crashed[p.first][p.second + 1] = crashed[p.first][p.second] + maze[p.first][p.second + 1];
		}
	}
	cout << crashed[n][m] << "\n";
	return 0;
}