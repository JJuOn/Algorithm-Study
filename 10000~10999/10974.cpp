#include <iostream>
#include <algorithm>

using namespace std;

int input[10000];

void Swap(int idx1, int idx2) {
	int temp = input[idx1];
	input[idx1] = input[idx2];
	input[idx2] = temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, i, j, nearIdx;
	cin >> n;
	for (i = 0; i < n; i++) {
		input[i] = i + 1;
	}
	for (i = 0; i < n; i++) {
		cout << input[i] << ' ';
	}
	cout << "\n";
	while (true) {
		for (i = n - 1; i > 0; i--) {
			if (input[i - 1] < input[i]) {
				break;
			}
		}
		if (i == 0) {
			break;
		}
		else {
			int near = 10001;
			nearIdx = i;
			for (j = i; j < n; j++) {
				if (input[i - 1] < input[j] && input[j] < near) {
					near = input[j];
					nearIdx = j;
				}
			}
			Swap(i - 1, nearIdx);
			sort(input + i, input + n);
			for (i = 0; i < n; i++) {
				cout << input[i] << ' ';
			}
			cout << "\n";
		}
	}
	return 0;
}