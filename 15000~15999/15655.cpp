#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v, Select;
vector<bool> visited;

void DFS(int count) {
	if (count == m) {
		for (int i = 0; i < m; i++) {
			cout << Select[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < n ; i++) {
			if (count == 0) {
				if (!visited[i]) {
					Select[count] = v[i];
					visited[i] = true;
					DFS(count + 1);
					visited[i] = false;
				}
			}
			else {
				if (!visited[i] && Select[count - 1] < v[i]) {
					Select[count] = v[i];
					visited[i] = true;
					DFS(count + 1);
					visited[i] = false;
				}
			}
			
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	v.resize(n);
	Select.resize(n);
	visited.resize(n, false);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	DFS(0);
	return 0;
}