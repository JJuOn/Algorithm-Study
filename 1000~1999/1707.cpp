#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;


bool visitable(vector<int> visited, int& startNode) {
	int size = visited.size();
	for (int i = 1; i < size; i++) {
		if (visited[i] == -1) {
			startNode = i;
			return true;
		}
	}
	return false;
}

bool BFS(vector<int> a[], vector<int>& visited, int currentNode, int& graphNum, int v) {
	queue<int> q;
	graphNum = (graphNum + 1) % 2;
	q.push(currentNode);
	visited[currentNode] = graphNum;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < a[node].size(); i++) {
			if (visited[a[node][i]] == -1) {
				graphNum = (visited[node] + 1) % 2;
				visited[a[node][i]] = graphNum;
				q.push(a[node][i]);
			}
			else if (visited[node] == visited[a[node][i]]) {
				return false;
			}
		}
	}
	return true;

}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int k;
	cin >> k;
	while (k--) {
		int v, e, startNode;
		cin >> v >> e;
		vector<int>* a = new vector<int>[v + 1];
		vector<int> visited(v + 1, -1);
		for (int i = 0; i < e; i++) {
			int b, c;
			cin >> b >> c;
			a[b].push_back(c);
			a[c].push_back(b);
		}
		bool partition = true;
		int graphNum = -1;
		while (visitable(visited, startNode) && partition) {
			partition = BFS(a, visited, startNode, graphNum, v);
		}
		if (partition) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		delete[] a;
	}
	return 0;
}
