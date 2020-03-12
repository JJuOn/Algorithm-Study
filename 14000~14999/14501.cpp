#include <iostream>

using namespace std;

int maxValue = 0, a[15][2];

void DFS(int today, int value, int n) {
	if (value > maxValue) {
		maxValue = value;
	}
	if (today == n) {
		return;
	}
	else {
		if (today + a[today][0] <= n) {
			DFS(today + a[today][0], value + a[today][1], n);
		}
		if (today + 1 <= n) {
			DFS(today + 1, value, n);
		}
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	DFS(0, 0, n);
	cout << maxValue << "\n";
	return 0;
}