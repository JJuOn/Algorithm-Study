#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

bool comparator(pair<int, int> p1, pair<int, int> p2) {
	return p1.second > p2.second;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	vector<pair<int, int>> v;
	priority_queue<int> pq;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	int sum = 0;
	sort(v.begin(), v.end(), comparator);
	for (int day = 10000, i = 0; day >= 1; day--) {
		while (i < n && v[i].second >= day) {
			pq.push(v[i].first);
			i++;
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum << "\n";
	return 0;
}