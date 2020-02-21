#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

void DFS(vector<int> a[], int currentNode, stack<int> s, int n, bool& found, vector<bool>& visited) {
	s.push(currentNode);
	visited[currentNode] = true;
	cout << currentNode << " ";
	if (a[currentNode].size() == 0) {
		return;
	}
	for (int i = 0; i < a[currentNode].size(); i++) {
		if (!visited[a[currentNode][i]]) {
			DFS(a, a[currentNode][i], s, n, found, visited);
		}
		if (found) {
			return;
		}
	}
}

void BFS(vector<int> a[], int currentNode, queue<int> q, int n, bool& found, vector<bool>& visited) {
	q.push(currentNode);
	visited[currentNode] = true;
	while (!q.empty() && !found) {
		int node = q.front();
		q.pop();
		cout << node << " ";
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
	int n, m, v;
	vector<int>* a, route;
	stack<int> s;
	queue<int> q;
	bool found = false;
	cin >> n >> m >> v;
	vector<bool> visited(n + 1, false);
	a = new vector<int>[n + 1];
	for (int i = 0; i < m; i++) {
		int b, c;
		cin >> b >> c;
		a[b].push_back(c);
		a[c].push_back(b);
	}
	for (int i = 0; i < n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	DFS(a, v, s, n, found, visited);
	cout << "\n";
	route.clear();
	for (int i = 0; i < visited.size(); i++) {
		visited[i] = false;
	}
	found = false;
	BFS(a, v, q, n, found, visited);
	delete[] a;
	return 0;
}
