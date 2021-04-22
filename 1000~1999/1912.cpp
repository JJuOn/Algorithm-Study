#include <iostream>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int a[100000], dp[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, maxValue = -2100000000;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n >= 1) {
		dp[0] = a[0];
	}
	if (n >= 2) {
		dp[1] = max(a[1], dp[0] + a[1]);
	}
	if (n >= 3) {
		for (int i = 2; i < n; i++) {
			dp[i] = max(dp[i - 1] + a[i], a[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (dp[i] > maxValue) {
			maxValue = dp[i];
		}
	}
	cout << maxValue << "\n";
	return 0;
}