#include <iostream>
#define INT_MAX 2147483647

using namespace std;

int a[100001];

int main() {
	int n;
	cin >> n;
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	a[4] = 1;
	for (int i = 5; i <= n; i++) {
		int min = INT_MAX;
		for (int j = 1; (j*j) <= i; j++) {
			if (a[i - (j*j)] < min) {
				min = a[i - (j*j)];
			}
		}
		a[i] = min + 1;
	}
	cout << a[n] << "\n";
	return 0;
}
