#include <iostream>
using namespace std;
int main() {
	int n, m;
	int **score;
	int *sum;
	float *average, *percent;
	cin >> n;
	score = new int*[n];
	sum = new int[n];
	average = new float[n];
	percent = new float[n];
	for (int i = 0; i < n; i++) {
		cin >> m;
		score[i] = new int[m];
		sum[i] = 0;
		for (int j = 0; j < m; j++) {
			cin >> score[i][j];
			sum[i] += score[i][j];
		}
		average[i] = (float)sum[i] / m;
		int count = 0;
		for (int j = 0; j < m; j++) {
			if (score[i][j] > average[i]) {
				count++;
			}
		}
		percent[i] = (float)count / m * 100;
	}
	for (int i = 0; i < n; i++) {
		cout << fixed;
		cout.precision(3);
		cout << percent[i] << "%\n";
	}
	for (int i = 0; i < n; i++) {
		delete[] score[i];
	}
	delete score;
	delete sum;
	delete average;
	delete percent;
	return 0;
}