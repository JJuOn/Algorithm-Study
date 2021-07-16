#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	set<int> s;
	vector<int> v1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		s.insert(temp);
		v1.push_back(temp);
	}
	vector<int> v2(s.begin(), s.end());
	sort(v2.begin(), v2.end());
	for (int i = 0; i < n; i++) {
		cout << lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin() << " ";
	}
	return 0;
}