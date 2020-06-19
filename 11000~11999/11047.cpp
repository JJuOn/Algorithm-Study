#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, coinCount = 0;
long long k;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	while (k) {
		for (int i = n - 1; i >= 0; i--) {
			if (k >= v[i]) {
				k -= v[i];
				coinCount++;
				break;
			}
		}
	}
	cout << coinCount << '\n';
	return 0;
}