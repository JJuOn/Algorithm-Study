#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string original;
	vector<string> suffixes;
	cin >> original;
	for (int i = 0; i < original.length(); i++) {
		suffixes.push_back(original.substr(i, original.length() - i));
	}
	sort(suffixes.begin(), suffixes.end());
	for (int i = 0; i < suffixes.size(); i++) {
		cout << suffixes[i] << "\n";
	}
	return 0;
}
