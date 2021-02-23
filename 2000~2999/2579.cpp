#include <iostream>

using namespace std;

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a[301], n, dp[301];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1] = a[1];
	dp[2] = max(a[1] + a[2], a[2]);
	dp[3] = max(a[2] + a[3], a[1] + a[3]);
	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 3] + a[i - 1] + a[i], dp[i - 2] + a[i]);
	}
	cout << dp[n] << "\n";
	return 0;
}