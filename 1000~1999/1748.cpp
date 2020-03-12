#include <iostream>

using namespace std;

int calDigit(long long n) {
	int digit = 0;
	while (n) {
		digit++;
		n /= 10;
	}
	return digit;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long count = 0, i;
	for (i = 1; i < n; i *= 10) {
		count += calDigit(i)*(i * 10 - i);
	}
	count += calDigit(n)*(n - i + 1);
	cout << count << "\n";
	return 0;
}