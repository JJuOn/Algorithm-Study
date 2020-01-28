#include<iostream>

using namespace std;

int main() {
	int n;
	bool isPrime[246913];
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i <= 246912; i++) {
		isPrime[i] = true;
	}
	for (long long i = 2; i <= 246913; i++) {
		if (isPrime[i]) {
			for (long long j = i * 2; j <= 246913; j += i) {
				isPrime[j] = false;
			}
		}
	}
	cin >> n;
	while (n != 0) {
		int count = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (isPrime[i]) {
				count++;
			}
		}
		cout << count << '\n';
		cin >> n;
	}
	return 0;
}