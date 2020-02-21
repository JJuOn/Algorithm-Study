#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	vector<int> v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	nth_element(v.begin(), v.begin() + k - 1, v.end());
	cout << v[k - 1] << "\n";
	return 0;
}
