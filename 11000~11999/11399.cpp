#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	vector<int> v, w;
	cin >> n;
	v.resize(n);
	w.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			w[i] += v[j];
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += w[i];
	}
	cout << sum << "\n";
	return 0;
}