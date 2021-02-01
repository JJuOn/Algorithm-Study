#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, m;
	cin >> n >> m;
	cout << abs(n - m) << "\n";
	return 0;
}