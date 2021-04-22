#include <iostream>

using namespace std;

int a[500][500];
int dp[500][500];

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int j = 0;
		for (; j <= i; j++) {
			cin >> a[i][j];
		}
		for (; j < n; j++) {
			a[i][j] = -1;
		}
	}
	if (n == 1) {
		cout << a[0][0] << "\n";
	}
	else if (n == 2) {
		cout << max(a[0][0] + a[1][0], a[0][0] + a[1][1]) << "\n";
	}
	else {
		dp[0][0] = a[0][0];
		dp[1][0] = dp[0][0] + a[1][0];
		dp[1][1] = dp[0][0] + a[1][1];
		for (int i = 2; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				if (j - 1 >= 0) {
					dp[i][j] = max(dp[i - 1][j - 1] + a[i][j], dp[i - 1][j] + a[i][j]);
				}
				else {
					dp[i][j] = dp[i - 1][j] + a[i][j];
				}
			}
		}
		int maxValue = -1;
		for (int j = 0; j < n; j++) {
			if (dp[n - 1][j] > maxValue) {
				maxValue = dp[n - 1][j];
			}
		}
		cout << maxValue << "\n";
	}
	return 0;
}