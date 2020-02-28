#include <iostream>
#include <queue>
#include <utility>

using namespace std;

bool visited[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	visited[n] = true;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		if (p.first == k) {
			cout << p.second << "\n";
			break;
		}
		else {
			if (p.first - 1 >= 0 && !visited[p.first - 1]) {
				q.push(make_pair(p.first - 1, p.second + 1));
				visited[p.first - 1] = true;
			}
			if (p.first + 1 <= 100000 && !visited[p.first + 1]) {
				q.push(make_pair(p.first + 1, p.second + 1));
				visited[p.first + 1] = true;
			}
			if (p.first * 2 <= 100000 && !visited[p.first * 2]) {
				q.push(make_pair(p.first * 2, p.second + 1));
				visited[p.first * 2] = true;
			}
		}
	}
	return 0;
}