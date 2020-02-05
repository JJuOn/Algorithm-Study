#include <iostream>

using namespace std;

long long a[201][201];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		a[i][1] = 1;
	}
	for (int j = 1; j <= k; j++) {
		a[0][j] = 1;
		a[1][j] = j;
	}
	for (int j = 2; j <= k; j++) {
		for (int i = 2; i <= n; i++) {
			for (int l = 0; l <= i; l++) {
				a[i][j] += a[l][j - 1];
			}
			a[i][j] %= 1000000000;
		}
	}
	cout << a[n][k] << "\n";
	return 0;
}
