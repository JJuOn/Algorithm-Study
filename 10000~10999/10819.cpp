#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	int n, i, max = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += abs(v[i] - v[i + 1]);
	}
	if (sum > max) {
		max = sum;
	}
	while (true) {
		for (i = n - 1; i > 0; i--) {
			if (v[i - 1] < v[i]) {
				break;
			}
		}
		if (i == 0) {
			break;
		}
		else {
			int near = 1000, nearIdx;
			for (int j = i; j < n; j++) {
				if (v[i - 1] < v[j] && v[j] < near) {
					near = v[j];
					nearIdx = j;
				}
			}
			swap(v[i - 1], v[nearIdx]);
			sort(v.begin() + i, v.end());
			sum=0;
			for (int i = 0; i < n - 1; i++) {
				sum += abs(v[i] - v[i + 1]);
			}
			if (sum > max) {
				max = sum;
			}
		}
	}
	sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += abs(v[i] - v[i + 1]);
	}
	if (sum > max) {
		max = sum;
	}
	cout << max << "\n";
	return 0;
}