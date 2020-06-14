#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v, Select;

void DFS(int count) {
	if (count == m) {
		for (int i = 0; i < m; i++) {
			cout << Select[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < n ; i++) {
			if (count > 0) {
				if (Select[count - 1] <= v[i]) {
					Select[count] = v[i];
					DFS(count + 1);
				}
			}
			else {
				Select[count] = v[i];
				DFS(count + 1);
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
	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	DFS(0);
	return 0;
}