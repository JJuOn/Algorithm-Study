#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n, s, v[20];
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v[i] = a;
	}
	int count = 0, max = pow(2, n);
	for (int i = 1; i < max; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				sum += v[j];
			}
		}
		if (sum == s) {
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}