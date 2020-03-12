#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int l, c;
	vector<char> a;
	char m[] = { 'a','e','i','o','u' };
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char temp;
		cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end(), greater<char>());
	int max = pow(2, c);
	for (int i = max-1; i >0; i--) {
		int count = 0, m_count = 0, j_count = 0;
		for (int j = c - 1; j >= 0; j--) {
			if ((i >> j) & 1 == 1) {
				count++;
				bool found = false;
				for (int k = 0; k < 5; k++) {
					if (m[k] == a[j]) {
						m_count++;
						found = true;
						break;
					}
				}
				if (!found) {
					j_count++;
				}
			}
		}
		if (count == l && m_count > 0 && j_count > 1) {
			for (int j = c - 1; j >= 0; j--) {
				if ((i >> j) & 1 == 1) {
					cout << a[j];
				}
			}
			cout << "\n";
		}
	}
	return 0;
}