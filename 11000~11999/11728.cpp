#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m), c(n + m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	sort(c.begin(), c.end());
	for (vector<int>::iterator it = c.begin(); it != c.end(); it++) {
		cout << *it << " ";
	}
	cout << "\n";
	return 0;
}