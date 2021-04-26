#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	set<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << "\n";
	return 0;
}