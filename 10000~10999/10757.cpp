#include <iostream>
#include <string>
#include <vector>

using namespace std;

int charToInt(char c) {
	return c - '0';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	vector<int> result;
	cin >> a >> b;
	int aLen = a.length();
	int bLen = b.length();

	int carry = 0, i;
	for (i = 1; i <= aLen && i <= bLen; i++) {
		int sum = charToInt(a[aLen - i]) + charToInt(b[bLen - i]) + carry;
		if (sum >= 10) {
			carry = 1;
			sum -= 10;
		}
		else {
			carry = 0;
		}
		result.push_back(sum);
	}
	if (i > aLen) {
		for (; i <= bLen; i++) {
			int sum = charToInt(b[bLen - i]) + carry;
			if (sum >= 10) {
				carry = 1;
				sum -= 10;
			}
			else {
				carry = 0;
			}
			result.push_back(sum);
		}
	}
	else if (i > bLen) {
		for (; i <= aLen; i++) {
			int sum = charToInt(a[aLen - i]) + carry;
			if (sum >= 10) {
				carry = 1;
				sum -= 10;
			}
			else {
				carry = 0;
			}
			result.push_back(sum);
		}
	}
	if (carry == 1) {
		result.push_back(carry);
	}
	
	for (int j = result.size() - 1; j >= 0; j--) {
		cout << result[j];
	}
	cout << "\n";
	return 0;
}