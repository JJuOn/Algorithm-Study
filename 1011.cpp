#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long start, end;
		cin >> start >> end;
		end -= start;
		start = 0;
		long long j;
		for (j = 0; j*j < end; j++);
		j--;
		if (end > (j * j + j)) {
			cout << 2 * j + 1 << endl;
		}
		else {
			cout << 2 * j << endl;
		}
	}
	return 0;
}