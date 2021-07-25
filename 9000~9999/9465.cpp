#include <iostream>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int dp[3][100001], a[3][100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				dp[i][j] = 0;
			}
		}
		int maxValue = -1;
		dp[1][1] = a[1][1];
		if (dp[1][1] > maxValue) {
			maxValue = dp[1][1];
		}
		dp[2][1] = a[2][1];
		if (dp[2][1] > maxValue) {
			maxValue = dp[2][1];
		}
		dp[1][2] = dp[2][1] + a[1][2];
		if (dp[1][2] > maxValue) {
			maxValue = dp[1][2];
		}
		dp[2][2] = dp[1][1] + a[2][2];
		if (dp[2][2] > maxValue) {
			maxValue = dp[2][2];
		}
		for (int j = 3; j <= n; j++) {
			dp[1][j] = max(max(dp[1][j - 2], dp[2][j - 2]), dp[2][j - 1]) + a[1][j];
			dp[2][j] = max(max(dp[1][j - 2], dp[2][j - 2]), dp[1][j - 1]) + a[2][j];
			if (dp[1][j] > maxValue) {
				maxValue = dp[1][j];
			}
			if (dp[2][j] > maxValue) {
				maxValue = dp[2][j];
			}
		}
		cout << maxValue << "\n";
	}
	return 0;
}