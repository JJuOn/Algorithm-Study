#include <iostream>
#include <string>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = s1.length() - 1; i >= 0; i--) {
		for (int j = s2.length() - 1; j >= 0; j--) {
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i + 1][j + 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	cout << dp[0][0] << "\n";
	return 0;
}