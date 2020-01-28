#include<iostream>
using namespace std;
int gcd(int a, int b);
int lcm(int a, int b);
int main() {
	int t;
	cin >> t;
	while (t) {
		int m, n, x, y, l;
		bool found = false;
		cin >> m >> n >> x >> y;
		l = lcm(m, n);
		int count = 1;
		int i=1, j=1;
		if (i == x && j == y) {
			found = true;
		}
		else {
			count += x - i;
			i = x;
			j = x;
			if (j > n) {
				j = j % n;
				if (j == 0) {
					j = n;
				}
			}
			if (i == x && j == y) {
				found = true;
			}
		}
		while (count <= l && !found) {
			count += m;
			j = (j + m) % n;
			if (j == 0) {
				j = n;
			}
			if (i == x && j == y) {
				found = true;
				break;
			}
		}
		if (count > l) {
			cout << -1 << endl;
		}
		else {
			cout << count << endl;
		}
		t--;
	}
	return 0;
}
int gcd(int a, int b) {
	if (b != 0) {
		gcd(b, a%b);
	}
	else {
		return a;
	}
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}