#include <iostream>

using namespace std;

long long n, temp[2][2];

void multiply(long long x[2][2], long long y[2][2]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				temp[i][j] += x[i][k] * y[k][j] % 1000000007;
				temp[i][j] %= 1000000007;
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			x[i][j] = temp[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	long long a[2][2] = { {1,1},{1,0} }, result[2][2] = { {1,0} ,{0,1} };
	n = n - 1;
	while (n > 0) {
		if (n % 2 == 1) {
			multiply(result, a);
		}
		multiply(a, a);
		n /= 2;
	}
	cout << result[0][0] << "\n";
	return 0;
}