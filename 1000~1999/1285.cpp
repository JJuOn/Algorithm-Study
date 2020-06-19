#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}
int n;
int a[20][20];
int columnHCounts[20];
int minHCounts = 210000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < n; j++) {
			if (line[j] == 'H') {
				a[i][j] = 0;
			}
			else {
				a[i][j] = 1;
			}
		}
	}
	// for all cases of whether flip rows or not
	for (int k = 0; k < (1 << n); k++) {
		int matrixCount = 0;
		// intialize columnH
		for (int j = 0; j < n; j++) {
			columnHCounts[j] = 0;
		}
		// for rows
		for (int i = 0; i < n; i++) {
			int mask = (1 << i);
			// for columns
			for (int j = 0; j < n; j++) {
				// if flips
				if (k&mask) {
					// As flipped, check T
					if (a[i][j] == 1) {
						columnHCounts[j]++;
					}
				}
				// if not flips
				else {
					// As not flipped, check H
					if (a[i][j] == 0) {
						columnHCounts[j]++;
					}
				}
			}
		}
		for (int j = 0; j < n; j++) {
			matrixCount += min(columnHCounts[j], n - columnHCounts[j]);
		}
		if (matrixCount < minHCounts) {
			minHCounts = matrixCount;
		}
	}
	cout << minHCounts << "\n";
	return 0;
}