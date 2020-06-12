#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int a[10];
int w[10][10];
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, i, min = 100000000;
	cin >> n;
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
		a[i] = i;
	}
	int sum = 0;
	bool flag = true;
	for (i = 0; i < n - 1; i++) {
		if (w[a[i]][a[i + 1]] == 0) {
			flag = false;
			break;
		}
		sum += w[a[i]][a[i + 1]];

	}
	if (w[a[i]][a[0]] == 0) {
		flag = false;
	}
	sum += w[a[i]][a[0]];
	if (sum < min && flag) {
		min = sum;
	}
	while (true) {
		for (i = n - 1; i > 0; i--) {
			if (a[i - 1] < a[i]) {
				break;
			}
		}
		if (i == 0) {
			break;
		}
		else {
			int near = 11, nearIdx;
			for (int j = i; j < n; j++) {
				if (a[i - 1] < a[j] && a[j] < near) {
					near = a[j];
					nearIdx = j;
				}
			}
			swap(a[i - 1], a[nearIdx]);
			sort(a + i, a + n);
			sum = 0;
			flag = true;
			for (i = 0; i < n - 1; i++) {
				if (w[a[i]][a[i + 1]] == 0) {
					flag = false;
					break;
				}
				sum += w[a[i]][a[i + 1]];
				
			}
			if (w[a[i]][a[0]] == 0) {
				flag = false;
			}
			sum += w[a[i]][a[0]];
			if (sum < min && flag) {
				min = sum;
			}
		}
	}
	flag = true;
	for (i = 0; i < n - 1; i++) {
		if (w[a[i]][a[i + 1]] == 0) {
			flag = false;
			break;
		}
		sum += w[a[i]][a[i + 1]];

	}
	if (w[a[i]][a[0]] == 0) {
		flag = false;
	}
	sum += w[a[i]][a[0]];
	if (sum < min && flag) {
		min = sum;
	}
	cout << min << "\n";
	return 0;
}