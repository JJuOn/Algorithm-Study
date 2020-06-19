#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct comparator {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		if (p1.second != p2.second) {
			return p1.second < p2.second;
		}
		else {
			return p1.first < p2.first;
		}
	}
};

int n, k;
vector<pair<int, int>> w;
vector<int> c;
priority_queue<pair<int,int>,vector<pair<int,int>>,comparator> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long sum = 0;
	cin >> n >> k;
	w.resize(n);
	c.resize(k);

	for (int i = 0; i < n; i++) {
		cin >> w[i].first >> w[i].second;
	}
	for (int i = 0; i < k; i++) {
		cin >> c[i];
	}
	sort(w.begin(), w.end());
	sort(c.begin(), c.end());
	for (int i = 0, j = 0; i < k; i++) {
		while (j < n && w[j].first <= c[i]) {
			pq.push(w[j]);
			j++;
		}
		if (!pq.empty()) {
			pair<int, int> p = pq.top();
			sum += p.second;
			pq.pop();
		}
	}
	cout << sum << "\n";
	return 0;
}