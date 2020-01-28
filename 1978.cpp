#include<iostream>

using namespace std;

int main() {
	int t, count = 0;
	cin >> t;
	while (t) {
		int n;
		cin >> n;
		bool isPrime = true;
		if (n == 1) {
			isPrime = false;
		}
		else {
			for (int i = 2; i < n; i++) {
				if (n%i == 0) {
					isPrime = false;
					break;
				}
			}
		}
		if (isPrime) {
			count++;
		}
		t--;
	}
	cout << count << endl;
	return 0;
}