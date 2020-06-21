#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	vector<int> v, w, mask;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cin >> m;
	w.resize(m);
	mask.resize(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < m; i++) {
		vector<int>::iterator ub = upper_bound(v.begin(), v.end(), w[i]);
		vector<int>::iterator lb = lower_bound(v.begin(), v.end(), w[i]);
		mask[i] = distance(lb,ub);
	}
	for (int i = 0; i < m; i++) {
		cout << mask[i] << " ";
	}
	cout << "\n";
	return 0;
}