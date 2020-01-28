#include<iostream>

using namespace std;

int main() {
	int t;
	bool isPrime[10001];
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i <= 10000; i++) {
		isPrime[i] = true;
	}
	for (int i = 2; i <= 10000; i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j <= 10000; j += i) {
				isPrime[j] = false;
			}
		}
	}
	cin >> t;
	while (t) {
		int n;
		int partition[2];
		cin >> n;
		for (int i = 2; i <= n / 2; i++) {
			if (isPrime[i] && isPrime[n - i]) {
				partition[0] = i;
				partition[1] = n - i;
			}
		}
		cout << partition[0] << ' ' << partition[1] << endl;
		t--;
	}
	
	return 0;
}