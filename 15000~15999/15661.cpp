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
		if (team1.size() == 0 || team1.size() == n) {
			continue;
		}
		else {
			int team1Sum = 0, team2Sum = 0;
			int team1Size = team1.size(), team2Size = team2.size();
			for (int i = 0; i < team1Size; i++) {
				for (int j = 0; j < team1Size; j++) {
					team1Sum += s[team1[i]][team1[j]];
				}
			}
			for (int i = 0; i < team2Size; i++) {
				for (int j = 0; j < team2Size; j++) {
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