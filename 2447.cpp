#include <iostream>

using namespace std;

void draw(int n,int i, int j);
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			draw(n, i, j);
		}
		cout << endl;
	}
	return 0;
}

void draw(int n, int i, int j) {
	if (i % 3 == 1 && j % 3 == 1) {
		cout << " ";
	}
	else if (i>=3 || j>=3){
		draw(n, i / 3, j / 3);
	}
	else {
		cout << "*";
	}
}