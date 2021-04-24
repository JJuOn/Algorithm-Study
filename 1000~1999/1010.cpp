#include <iostream>

using namespace std;

long long dp[30][30];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i < 30; i++) {
		dp[i][i] = 1;
		dp[1][i] = i;
	}
	while (t--) {
		int n, m;
		cin >> n >> m;
		if (dp[n][m] != 0) {
			cout << dp[n][m] << "\n";
			continue;
		}
		else {
			for (int i = 2; i <= n; i++) {
				for (int j = i + 1; j <= m; j++) {
					if (dp[i][j] != 0) {
						continue;
					}
					for (int k = 1; k < j; k++) {
						dp[i][j] += dp[i - 1][k];
					}
				}
			}
			cout << dp[n][m] << "\n";
		}
	}
	return 0;
}