#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, minVal = 2100000000, maxVal = -210000000;
vector<int> a;
vector<char> oprs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}
	for (int i = 0; i < 4; i++) {
		int c;
		cin >> c;
		for (int j = 0; j < c; j++) {
			switch (i) {
			case 0:
				oprs.push_back('+');
				break;
			case 1:
				oprs.push_back('-');
				break;
			case 2:
				oprs.push_back('*');
				break;
			case 3:
				oprs.push_back('/');
				break;
			default:
				break;
			}
		}
	}
	sort(oprs.begin(), oprs.end());
	int aSize = a.size();
	do {
		int result = a[0];
		for (int i = 1; i < aSize; i++) {
			switch (oprs[i - 1]) {
			case '+':
				result += a[i];
				break;
			case '-':
				result -= a[i];
				break;
			case '*':
				result *= a[i];
				break;
			case '/':
				result /= a[i];
				break;
			default:
				break;
			}
		}
		if (result > maxVal) {
			maxVal = result;
		}
		if (result < minVal) {
			minVal = result;
		}
	} while (next_permutation(oprs.begin(), oprs.end()));
	cout << maxVal << "\n" << minVal << "\n";
	return 0;
}