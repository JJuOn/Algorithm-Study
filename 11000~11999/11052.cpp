#include <iostream>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int dp[1001], a[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = a[i];
	}
	dp[1] = a[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + a[j]);
		}
	}
	cout << dp[n] << "\n";
	return 0;
}