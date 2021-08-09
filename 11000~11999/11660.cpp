#include <iostream>

using namespace std;

int a[1025][1025], total[1025][1025];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		a[0][i] = 0;
		a[i][0] = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			total[i][j] = a[i][j];
			if (i - 1 >= 1) {
				total[i][j] += total[i - 1][j];
			}
			if (j - 1 >= 1) {
				total[i][j] += total[i][j - 1];
			}
			if (i - 1 >= 1 && j - 1 >= 1) {
				total[i][j] -= total[i - 1][j - 1];
			}
		}
	}
	while (m--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int result = total[x2][y2] - total[x2][y1 - 1] - total[x1 - 1][y2] + total[x1 - 1][y1 - 1];
		cout << result << "\n";
	}
	return 0;
}