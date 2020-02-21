#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void addEdge(vector<int> a[], int i, int j) {
	a[i].push_back(j);
	a[j].push_back(i);
	return;
}

void DFS(vector<int> a[], int currentNode, stack<int> route, vector<bool> visited, int n, bool& found) {
	route.push(currentNode);
	visited[currentNode] = true;
	if (route.size() == 5) {
		found = true;
		return;
	}
	else {
		for (int i = 0; i < a[currentNode].size(); i++) {
			if (!visited[a[currentNode][i]]) {
				DFS(a, a[currentNode][i], route, visited, n, found);
				if (found) {
					return;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	vector<bool> visited(2000, false);
	int n, m;
	stack<int> route;
	vector<int>* a;
	bool found = false;
	cin >> n >> m;
	a = new vector<int>[n];
	for (int i = 0; i < m; i++) {
		int b, c;
		cin >> b >> c;
		addEdge(a, b, c);
	}
	for (int i = 0; i < n && !found; i++) {
		DFS(a, i, route, visited, n, found);
	}
	if (found) {
		cout << "1\n";
	}
	else {
		cout << "0\n";
	}
	delete[] a;
	return 0;
}
