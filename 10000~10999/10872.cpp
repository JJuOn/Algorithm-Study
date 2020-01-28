#include <iostream>
using namespace std;
int main() {
	int n,*f;
	cin >> n;
	f = new int[n+1];
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = i * f[i - 1];
	}
	cout << f[n] << endl;
	delete[] f;
	return 0;
}
