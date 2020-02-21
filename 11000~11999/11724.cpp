#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

bool visitable(vector<bool> visited, int& startNode) {
	int size = visited.size();
	for (int i = 0; i < size; i++) {
		if (!visited[i]) {
			startNode = i;
			return true;
		}
	}
	return false;
}

void BFS(vector<int> a[], vector<bool>& visited, int currentNode, int n) {
	queue<int> q;
	q.push(currentNode);
	visited[currentNode] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < a[node].size(); i++) {
			if (!visited[a[node][i]]) {
				visited[a[node][i]] = true;
				q.push(a[node][i]);
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n, m, count = 0, startNode;
	vector<int> *a;
	cin >> n >> m;
	a = new vector<int>[n + 1];
	vector<bool> visited(n + 1, false);
	visited[0] = true;
	for (int i = 0; i < m; i++) {
		int b, c;
		cin >> b >> c;
		a[b].push_back(c);
		a[c].push_back(b);
	}
	while (visitable(visited, startNode)) {
		BFS(a, visited, startNode, n);
		count++;
	}
	cout << count << "\n";
	return 0;
}
