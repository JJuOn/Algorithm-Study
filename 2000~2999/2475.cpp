#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a[5], squaredSum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
		squaredSum += a[i] * a[i];
	}
	cout << squaredSum % 10 << "\n";
	return 0;
}