#include <iostream>
using namespace std;
int main() {
	int n, *original, max=0;
	float *edited, sum=0.0;
	cin >> n;
	original = new int[n];
	edited = new float[n];
	for (int i = 0; i < n; i++) {
		cin >> original[i];
		if (original[i] > max) {
			max = original[i];
		}
	}
	for (int i = 0; i < n; i++) {
		edited[i] = original[i] / (float)max * 100;
		sum += edited[i];
	}
	cout << fixed;
	cout.precision(2);
	cout << sum / (float)n << endl;
	delete[] original;
	delete[] edited;
	return 0;
}