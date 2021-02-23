#include <iostream>
#include <utility>
#include <string>
#include <map>

using namespace std;

bool isNumber(string s) {
	return '0' <= s[0] && s[0] <= '9';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<int, string> dict;
	map<string, int> dict2;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		dict.insert(make_pair(i, s));
		dict2.insert(make_pair(s, i));
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (isNumber(s)) {
			cout << dict[stoi(s)] << "\n";
		}
		else {
			cout << dict2[s] << "\n";
		}
	}
	return 0;
}