#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	vector<int> a, targets;
	cin >> n;
	a.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	targets.resize(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> targets[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < m; i++) {
		if (binary_search(a.begin(), a.end(), targets[i])) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}
	return 0;
}