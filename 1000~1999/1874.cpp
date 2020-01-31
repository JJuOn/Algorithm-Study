#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

void push(stack<int>& s, int target) {

}

void pop(stack<int>& s) {

}

int main() {
	int* a, n, i=0, j = 0;
	stack<int> s;
	stringstream ss;
	bool flag = true;
	cin >> n;
	a = new int[n];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	i = 1;
	while (j < n) {
		if (i <= a[j]) {
			s.push(i);
			ss << "+\n";
			i++;
		}
		else if (i > a[j] && (s.empty() || s.top() < a[j])) {
			flag = false;
			break;
		}
		while (!s.empty() && a[j] <= s.top()) {
			if (a[j]==s.top()) {
				j++;
			}
			s.pop();
			ss << "-\n";
		}
	}
	if (flag) {
		cout << ss.str();
	}
	else {
		cout << "NO\n";
	}
	delete[] a;
	return 0;
}