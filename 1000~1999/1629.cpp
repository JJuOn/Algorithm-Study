#include <iostream>

using namespace std;

long long multiply(long long a, long long b, long long c) {
	if (b == 1) {
		return a % c;
	}
	else if (b % 2 == 0) {
		long long m = multiply(a, b / 2, c);
		return m * m % c;
	}
	else {
		long long m = multiply(a, (b - 1) / 2, c);
		return (m * m) % c * a % c;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a, b, c;
	cin >> a >> b >> c;
	cout << multiply(a, b, c) << "\n";
	return 0;
}