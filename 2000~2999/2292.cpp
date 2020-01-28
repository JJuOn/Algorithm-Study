#include<iostream>

using namespace std;

int main() {
	long long n;
	cin >> n;
	long long i;
	for (i = 1; 3 * i * i - 3 * i + 1 < n; i++);
	cout << i << endl;
	return 0;
}