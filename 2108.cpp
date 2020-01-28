#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//count[0]: -4000
	//count[3999]: -1
	//count[4000]: 0
	//count[4001]: 1
	//count[8000]: 4000
	int n, count[8001], sum = 0;
	cin >> n;
	for (int i = 0; i < 8001; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		sum += temp;
		count[temp + 4000]++;
	}
	int mid = round((float)n / 2);
	cout << round((float)sum / n) << endl;
	int current = 0;
	for (int i = 0; i < 8001 && current < mid; i++) {
		if (current + count[i] >= mid) {
			cout << i - 4000 << '\n';
			break;
		}
		else {
			current += count[i];
		}
	}
	int modeValue = 0, mode, modeCount = 0;
	for (int i = 0; i < 8001; i++) {
		if (count[i] > modeValue) {
			modeValue = count[i];
			mode = i;
			modeCount = 1;
		}
		else if (count[i] == modeValue) {
			if (modeCount == 1) {
				mode = i;
				modeCount = 2;
			}
		}
	}
	cout << mode - 4000 << "\n";
	int minIdx, maxIdx;
	for (int i = 0; i < 8001; i++) {
		if (count[i] != 0) {
			minIdx = i;
			break;
		}
	}
	for (int i = 8000; i >= 0; i--) {
		if (count[i] != 0) {
			maxIdx = i;
			break;
		}
	}
	cout << maxIdx - minIdx << '\n';
	return 0;
}