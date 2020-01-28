#include<iostream>
using namespace std;

int neighbor(int k, int n);

int main() {
	int t;
	cin >> t;
	while (t) {
		int k, n;
		cin >> k >> n;
		cout << neighbor(k, n) << endl;
		t--;
	}
	return 0;
}

int neighbor(int k, int n) {
	if (k == 0) {
		return n;
	}
	else {
		int sum = 0;
		for (int i = 0; i <= n; i++) {
			sum += neighbor(k - 1, i);
		}
		return sum;
	}
}