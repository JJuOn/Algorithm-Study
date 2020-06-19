#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<int> a, b, temp;
int min(int a, int b) {
	return a < b ? a : b;
}

int calcDiff() {
	int diff = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			diff++;
		}
	}
	return diff;
}

void reverseSwitch(int x) {
	for (int i = x - 1; i < x + 2; i++) {
		if (i >= 0 && i < n) {
			a[i] = (a[i] == 0) ? 1 : 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	int counter1 = 0, counter2 = 0;
	bool flag1 = true, flag2 = true;
	cin >> n;
	a.resize(n);
	b.resize(n);
	temp.resize(n);
	cin >> line;
	
	for (int i = 0; i < n; i++) {
		a[i] = line[i] - '0';
	}
	cin >> line;
	for (int i = 0; i < n; i++) {
		b[i] = line[i] - '0';
	}
	copy(a.begin(), a.end(), temp.begin());
	for (int i = 0; i < n - 1; i++) {
		if (a[i] != b[i]) {
			reverseSwitch(i + 1);
			counter1++;
		}
	}
	if (calcDiff() != 0) {
		flag1 = false;
	}
	copy(temp.begin(), temp.end(), a.begin());
	reverseSwitch(0);
	counter2++;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] != b[i]) {
			reverseSwitch(i + 1);
			counter2++;
		}
	}
	if (calcDiff() != 0) {
		flag2 = false;
	}
	if (flag1 && flag2) {
		cout << min(counter1, counter2) << "\n";
	}
	else if (flag1) {
		cout << counter1 << "\n";
	}
	else if (flag2) {
		cout << counter2 << "\n";
	}
	else {
		cout << "-1\n";
	}
	return 0;
}