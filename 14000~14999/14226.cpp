#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int visited[10001][2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int s;
	cin >> s;
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	visited[1][0] = 1;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		if (p.first == s) {
			cout << visited[p.first][p.second] - 1 << "\n";
			break;
		}
		else {
			// copy
			if (p.first < s && !visited[p.first][p.first]) {
				q.push(make_pair(p.first, p.first));
				visited[p.first][p.first] = visited[p.first][p.second] + 1;
			}
			// paste
			if (p.second != 0 && !visited[p.first + p.second][p.second]) {
				q.push(make_pair(p.first + p.second, p.second));
				visited[p.first + p.second][p.second] = visited[p.first][p.second] + 1;
			}
			// delete
			if (p.first - 1 >= 0 && !visited[p.first - 1][p.second]) {
				q.push(make_pair(p.first - 1, p.second));
				visited[p.first - 1][p.second] = visited[p.first][p.second] + 1;
			}
		}
	}
	return 0;
}