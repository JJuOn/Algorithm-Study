#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int factorial[11], n, k;
	cin >> n >> k;
	factorial[0] = 1;
	for (int i = 1; i <= n; i++) {
		factorial[i] = i * factorial[i - 1];
	}
	cout << factorial[n] / factorial[k] / factorial[n - k] << "\n";
	return 0;
}