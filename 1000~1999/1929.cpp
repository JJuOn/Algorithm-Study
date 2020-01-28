#include<iostream>

using namespace std;

int main() {
	int m, n;
	bool isPrime[1000001];
	isPrime[0] = false;
	isPrime[1] = false;
	cin >> m >> n;
	for (int i = 2; i <= n; i++) {
		isPrime[i] = true;
	}
	for (long long i = 2; i <= n; i++) {
		if (isPrime[i]) {
			for (long long j = i * 2; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
	for (int i = m; i <= n; i++) {
		if (isPrime[i]) {
			cout << i << '\n';
		}
	}
	return 0;
}