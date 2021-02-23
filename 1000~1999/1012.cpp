#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int a[50][50];
bool visited[50][50];
vector<pair<int, int>> cabbages;

void DFS(int i, int j, int m, int n) {
	visited[i][j] = true;
	if (i - 1 >= 0 && a[i - 1][j] == 1 && !visited[i - 1][j]) {
		DFS(i - 1, j, m, n);
	}
	if (i + 1 < m && a[i + 1][j] == 1 && !visited[i + 1][j]) {
		DFS(i + 1, j, m, n);
	}
	if (j - 1 >= 0 && a[i][j - 1] == 1 && !visited[i][j - 1]) {
		DFS(i, j - 1, m, n);
	}
	if (j + 1 < n && a[i][j + 1] == 1 && !visited[i][j + 1]) {
		DFS(i, j + 1, m, n);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cabbages.clear();
		int m, n, k;
		cin >> m >> n >> k;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = 0;
				visited[i][j] = false;
			}
		}
		while (k--) {
			int i, j;
			cin >> i >> j;
			a[i][j] = 1;
			cabbages.push_back(make_pair(i, j));
		}
		int count = 0;
		for (int i = 0; i < cabbages.size(); i++) {
			if (!visited[cabbages[i].first][cabbages[i].second]) {
				DFS(cabbages[i].first, cabbages[i].second,m,n);
				count++;
			}
		}
		cout << count << "\n";
	}
	return 0;
}