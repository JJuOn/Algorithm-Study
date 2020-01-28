#include<iostream>

using namespace std;

int main() {
	int x[3], y[3], resultX, resultY;
	cin >> x[0] >> y[0];
	cin >> x[1] >> y[1];
	cin >> x[2] >> y[2];
	if (x[0] == x[1]) {
		resultX = x[2];
	}
	else if (x[0] == x[2]) {
		resultX = x[1];
	}
	else {
		resultX = x[0];
	}
	if (y[0] == y[1]) {
		resultY = y[2];
	}
	else if (y[0] == y[2]) {
		resultY = y[1];
	}
	else {
		resultY = y[0];
	}
	cout << resultX << ' ' << resultY << endl;
	return 0;
}