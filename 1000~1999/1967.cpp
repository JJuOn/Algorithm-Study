#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int,int>> v[10001];
bool visited[10001];

int r = 0;
int fartest = 0;

void DFS(int node, int length) {
	if (length > r) {
		r = length;
		fartest = node;
	}
	visited[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		if (!visited[v[node][i].first]) {
			DFS(v[node][i].first, v[node][i].second + length);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size;
	cin >> size;
	for (int i = 1; i <= size; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < size - 1; i++) {
		int node, child, dist;
		cin >> node >> child >> dist;
		v[node].push_back(make_pair(child, dist));
		v[child].push_back(make_pair(node, dist));
	}
	DFS(1, 0);
	for (int i = 1; i <= size; i++) {
		visited[i] = false;
	}
	DFS(fartest, 0);
	cout << r << "\n";
	return 0;
}