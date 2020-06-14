#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n, m;
vector<int> v, Select;
vector<bool> visited;
pair<int, int> p;

void DFS(int count) {
	if (count == m) {
		for (int i = 0; i < m; i++) {
			cout << Select[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < n ; i++) {
			if ((p.first != count || p.second != v[i]) && !visited[i]) {
				if (count == 0) {
					Select[count] = v[i];
					p.first = count;
					p.second = v[i];
					visited[i] = true;
					DFS(count + 1);
					visited[i] = false;
				}
				else {
					if (Select[count - 1] <= v[i]) {
						Select[count] = v[i];
						p.first = count;
						p.second = v[i];
						visited[i] = true;
						DFS(count + 1);
						visited[i] = false;
					}
				}
			}
		}
		p.first = count - 1;
		p.second = count > 0 ? Select[count - 1] : -1;
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
	p.first = -1;
	p.second = -1;
	DFS(0);
	return 0;
}