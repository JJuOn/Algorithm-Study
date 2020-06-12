#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	while (k != 0) {
		vector<int> v,mask;
		v.resize(k);
		mask.resize(k);
		for (int i = 0; i < k; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < 6; i++) {
			mask[i] = 1;
		}
		sort(mask.begin(), mask.end(),greater<int>());
		do {
			for (int i = 0; i < k; i++) {
				if (mask[i]) {
					cout << v[i] << " ";
				}
			}
			cout << "\n";
		} while (prev_permutation(mask.begin(), mask.end()));
		cout << "\n";
		cin >> k;
	}
	return 0;
}