#include<iostream>

using namespace std;

int main() {
	int m, n, min = -1, sum = 0;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (i == 1) {
			continue;
		}
		bool isPrime = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			if (min == -1) {
				min = i;
			}
			sum += i;
		}
	}
	if (min == -1) {
		cout << min << endl;
	}
	else {
		cout << sum << endl << min << endl;
	}
	return 0;
}