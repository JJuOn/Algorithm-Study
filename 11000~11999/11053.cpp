#include <iostream>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int a[1001], dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, maxLength = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (dp[i] > maxLength) {
			maxLength = dp[i];
		}
	}
	cout << maxLength << "\n";
	return 0;
}