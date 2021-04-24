#include <iostream>

using namespace std;

long long dp[101][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	dp[1][0] = 0;
	for (int j = 1; j <= 9; j++) {
		dp[1][j] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j >= 1 && j <= 8) {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			}
			else if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			}
		}
	}
	long long sum = 0;
	for (int j = 0; j <= 9; j++) {
		sum += dp[n][j] % 1000000000;
	}
	cout << sum % 1000000000 << "\n";
	return 0;
}