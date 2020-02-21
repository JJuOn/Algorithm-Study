#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n, size, maxCount, tempCount;
	long long maxNum;
	vector<long long> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	size = v.size();
	maxNum = v[0];
	maxCount = 1;
	tempCount = 1;
	for (int i = 1; i < size; i++) {
		if (v[i] != v[i - 1]) {
			if (tempCount > maxCount) {
				maxNum = v[i - 1];
				maxCount = tempCount;
			}
			tempCount = 1;
		}
		else {
			tempCount++;
			if (tempCount > maxCount) {
				maxNum = v[i];
				maxCount = tempCount;
			}
		}
	}
	cout << maxNum << "\n";
	return 0;
}
