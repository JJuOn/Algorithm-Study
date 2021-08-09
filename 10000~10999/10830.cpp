#include <iostream>

using namespace std;

long long n, a[5][5], result[5][5], temp[5][5];

void multiply(long long x[5][5], long long y[5][5]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < n; k++) {
				temp[i][j] += x[i][k] * y[k][j] % 1000;
				temp[i][j] %= 1000;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x[i][j] = temp[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long b;
	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		result[i][i] = 1;
	}
	while (b > 0) {
		if (b % 2 == 1) {
			multiply(result, a);
		}
		multiply(a, a);
		b /= 2;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}