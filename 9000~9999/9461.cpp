#include <iostream>

using namespace std;

long long a[101];

int main() {
	int t, n;
	cin >> t;
	a[1] = 1;
	a[2] = 1;
	a[3] = 1;
	a[4] = 2;
	a[5] = 2;
	while (t--) {
		cin >> n;
		for (int i = 6; i <= n; i++) {
			a[i] = a[i - 5] + a[i - 1];
		}
		cout << a[n] << "\n";
	}
	return 0;
}

