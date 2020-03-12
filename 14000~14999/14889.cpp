#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n, s[21][21], minDiff = 2100000000;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j];
		}
	}
	for (int i = 1; i < pow(2, n); i++) {
		vector<int> team1, team2;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1 == 1) {
				team1.push_back(j + 1);
			}
			else {
				team2.push_back(j + 1);
			}
		}
		if (team1.size() != n / 2) {
			continue;
		}
		else {
			int team1Sum = 0, team2Sum = 0;
			for (int i = 0; i < n / 2; i++) {
				for (int j = 0; j < n / 2; j++) {
					team1Sum += s[team1[i]][team1[j]];
					team2Sum += s[team2[i]][team2[j]];
				}
			}
			int diff = abs(team1Sum - team2Sum);
			if (diff < minDiff) {
				minDiff = diff;
			}
		}
	}
	cout << minDiff << "\n";
	return 0;
}