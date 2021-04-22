#include <iostream>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int a[10000], dp[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n >= 1) {
		dp[0] = a[0];
	}
	if (n >= 2) {
		dp[1] = max(a[0] + a[1], a[1]);
	}
	if (n >= 3) {
		dp[2] = max(a[0] + a[2], a[1] + a[2]);
		dp[3] = max(dp[0] + a[2] + a[3], dp[1] + a[3]);
		for (int i = 4; i < n; i++) {
			dp[i] = max(max(dp[i - 3] + a[i - 1] + a[i], dp[i - 2] + a[i]), dp[i - 4] + a[i - 1] + a[i]);
		}
	}
	int maxValue = -1;
	for (int i = 0; i < n; i++) {
		if (dp[i] > maxValue) {
			maxValue = dp[i];
		}
	}
	cout << maxValue << "\n";
	return 0;
}