#include <iostream>

using namespace std;

int a[1001];

int main() {
	int n;
	cin >> n;
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i <= n; i++) {
		a[i] = (a[i - 1] + a[i - 2] * 2) % 10007;
	}
	cout << a[n] % 10007 << "\n";
	return 0;
}
