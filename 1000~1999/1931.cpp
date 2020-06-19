#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n, meetings = 0;
vector<pair<long long,long long>> v;

struct customComparator{
	bool operator()(const pair<long long, long long>& p1, const pair<long long, long long>& p2) {
		if (p1.second != p2.second) {
			return p1.second < p2.second;
		}
		else {
			return p1.first < p2.first;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), customComparator());
	long long maxEnd = v[0].second;
	meetings++;
	for (int i = 1; i < n; i++) {
		if (v[i].first >= maxEnd) {
			maxEnd = v[i].second;
			meetings++;
		}
	}
	cout << meetings << "\n";
	return 0;
}