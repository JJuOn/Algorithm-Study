#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int visited[300][300];

int BFS(pair<int, int> start, pair<int, int> end, int l) {
	queue<pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = 1;
	pair<int, int> node = make_pair(start.first, start.second);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (node.first == end.first && node.second == end.second) {
			return visited[node.first][node.second] - 1;
		}
		if (node.first - 1 >= 0 && node.second - 2 >= 0 && visited[node.first - 1][node.second - 2] == 0) {
			q.push(make_pair(node.first - 1, node.second - 2));
			visited[node.first - 1][node.second - 2] = visited[node.first][node.second] + 1;
			if (node.first - 1 == end.first && node.second - 2 == end.second) {
				return visited[node.first - 1][node.second - 2] - 1;
			}
		}
		if (node.first - 2 >= 0 && node.second - 1 >= 0 && visited[node.first - 2][node.second - 1] == 0) {
			q.push(make_pair(node.first - 2, node.second - 1));
			visited[node.first - 2][node.second - 1] = visited[node.first][node.second] + 1;
			if (node.first - 2 == end.first && node.second - 1 == end.second) {
				return visited[node.first - 2][node.second - 1] - 1;
			}
		}
		if (node.first + 1 < l && node.second - 2 >= 0 && visited[node.first + 1][node.second - 2] == 0) {
			q.push(make_pair(node.first + 1, node.second - 2));
			visited[node.first + 1][node.second - 2] = visited[node.first][node.second] + 1;
			if (node.first + 1 == end.first && node.second - 2 == end.second) {
				return visited[node.first + 1][node.second - 2] - 1;
			}
		}
		if (node.first + 2 < l && node.second - 1 >= 0 && visited[node.first + 2][node.second - 1] == 0) {
			q.push(make_pair(node.first + 2, node.second - 1));
			visited[node.first + 2][node.second - 1] = visited[node.first][node.second] + 1;
			if (node.first + 2 == end.first && node.second - 1 == end.second) {
				return visited[node.first + 2][node.second - 1] - 1;
			}
		}
		if (node.first - 1 >= 0 && node.second + 2 < l && visited[node.first - 1][node.second + 2] == 0) {
			q.push(make_pair(node.first - 1, node.second + 2));
			visited[node.first - 1][node.second + 2] = visited[node.first][node.second] + 1;
			if (node.first - 1 == end.first && node.second + 2 == end.second) {
				return visited[node.first - 1][node.second + 2] - 1;
			}
		}
		if (node.first - 2 >= 0 && node.second + 1 < l && visited[node.first - 2][node.second + 1] == 0) {
			q.push(make_pair(node.first - 2, node.second + 1));
			visited[node.first - 2][node.second + 1] = visited[node.first][node.second] + 1;
			if (node.first - 2 == end.first && node.second + 1 == end.second) {
				return visited[node.first - 2][node.second + 1] - 1;
			}
		}
		if (node.first + 1 < l && node.second + 2 < l && visited[node.first + 1][node.second + 2] == 0) {
			q.push(make_pair(node.first + 1, node.second + 2));
			visited[node.first + 1][node.second + 2] = visited[node.first][node.second] + 1;
			if (node.first + 1 == end.first && node.second + 2 == end.second) {
				return visited[node.first + 1][node.second + 2] - 1;
			}
		}
		if (node.first + 2 < l && node.second + 1 < l && visited[node.first + 2][node.second + 1] == 0) {
			q.push(make_pair(node.first + 2, node.second + 1));
			visited[node.first + 2][node.second + 1] = visited[node.first][node.second] + 1;
			if (node.first + 2 == end.first && node.second + 1 == end.second) {
				return visited[node.first + 2][node.second + 1] - 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		int l;
		cin >> l;
		pair<int, int> start, end;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;
		cout << BFS(start, end, l) << "\n";
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				visited[i][j] = 0;
			}
		}
	}

	return 0;
}