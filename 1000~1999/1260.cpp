#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> a;
vector<bool> visited;

void DFS(int node) {
	cout << node << " ";
	visited[node] = true;
	int size = a[node].size();
	for (int i = 0; i < size; i++) {
		if (!visited[a[node][i]]) {
			DFS(a[node][i]);
		}
	}
}

void BFS(int startNode) {
	queue<int> q;
	q.push(startNode);
	visited[startNode] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";
		int size = a[node].size();
		for (int i = 0; i < size; i++) {
			if (!visited[a[node][i]]) {
				q.push(a[node][i]);
				visited[a[node][i]] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n, m, v;
	cin >> n >> m >> v;
	a.resize(n + 1);
	visited.resize(n + 1, false);
	for (int i = 0; i < m; i++) {
		int b, c;
		cin >> b >> c;
		a[b].push_back(c);
		a[c].push_back(b);
	}
	for (int i = 0; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	DFS(v);
	cout << "\n";
	fill(visited.begin(), visited.end(), false);
	BFS(v);
	cout << "\n";
	return 0;
}