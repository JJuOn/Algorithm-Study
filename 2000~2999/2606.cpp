#include <iostream>
#include <vector>

using namespace std;

bool visited[101];
vector<int> edges[101];

void DFS(int node) {
	if (visited[node]) {
		return;
	}
	else {
		visited[node] = true;
		for (int i = 0; i < edges[node].size(); i++) {
			if (!visited[edges[node][i]]) {
				DFS(edges[node][i]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	DFS(1);
	int c = 0;
	for (int i = 2; i <= v; i++) {
		if (visited[i]) {
			c++;
		}
	}
	cout << c << "\n";
	return 0;
}