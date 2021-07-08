#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> a, b, c;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		a.push_back(temp);
	}
	for (int j = 0; j < m; j++) {
		string temp;
		cin >> temp;
		b.push_back(temp);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] == b[j]) {
			c.push_back(a[i]);
			i++;
			j++;
		}
		else if (a[i] < b[j]) {
			i++;
		}
		else {
			j++;
		}
	}
	cout << c.size() << "\n";
	for (int k = 0; k < c.size(); k++) {
		cout << c[k] << "\n";
	}
	return 0;
}