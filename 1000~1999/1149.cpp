#include <iostream>

using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}

// dp[i][j]: i번 집을 j로 칠할 경우
int a[1000][3], n, dp[1000][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];
	dp[0][2] = a[0][2];
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
	}
	cout << min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << "\n";
	return 0;
}