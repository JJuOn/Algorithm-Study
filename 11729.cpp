#include <iostream>
#include <sstream>

using namespace std;

int counts = 0;
stringstream s;

void move(int n, int start, int end, int temp);

int main() {
	int n;
	cin >> n;
	move(n, 1, 3, 2);
	cout << counts << endl << s.str();
	return 0;
}
void move(int n, int start, int end, int temp) {
	if (n == 1) {
		s << start << " " << end << endl;
		counts++;
	}
	else {
		move(n - 1, start, temp, end);
		s << start << " " << end << endl;
		counts++;
		move(n - 1, temp, end, start);
	}
}