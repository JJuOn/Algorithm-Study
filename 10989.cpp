#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, c[10001];
	cin >> n;
	for (int i = 0; i < 10001; i++) {
		c[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		c[temp]++;
	}
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < c[i]; j++) {
			cout << i << "\n";
		}
	}
	return 0;
}