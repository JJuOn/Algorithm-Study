#include<iostream>
using namespace std;
int main() {
	int t, h, w, n;
	cin >> t;
	while (t) {
		cin >> h >> w >> n;
		int f, r;
		if (n % h == 0) {
			f = h;
		}
		else {
			f = n % h;
		}
		r = (n - 1) / h + 1;
		if (r < 10) {
			cout << f << "0" << r << endl;
		}
		else {
			cout << f << r << endl;
		}
		t--;
	}
	return 0;
}