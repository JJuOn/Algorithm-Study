#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	vector<int> v;
	int total = 0;
	for (int i = 0; i < 9; i++) {
		int num;
		cin >> num;
		v.push_back(num);
		total += num;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (total - v[i] - v[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						cout << v[k] << "\n";
					}
				}
				return 0;
			}
		}
	}
	return 0;
}