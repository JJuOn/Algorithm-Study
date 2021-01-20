#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

vector<int> v, answer;
int n;
long long x, y;

pair<long long, long long> getCoordinate(long long index, long long size, long long i, long long j) {
	if (size == 1) {
		return make_pair(i, j);
	}
	else {
		if (v[index] == 1) {
			return getCoordinate(index + 1, size / 2, i, j + size / 2);
		}
		else if (v[index] == 2) {
			return getCoordinate(index + 1, size / 2, i, j);
		}
		else if (v[index] == 3) {
			return getCoordinate(index + 1, size / 2, i + size / 2, j);
		}
		else {
			return getCoordinate(index + 1, size / 2, i + size / 2, j + size / 2);
		}
	}
}

void getAnswer(int index, long long size, long long i, long long j, long long targetRow, long long targetCol) {
	if (size == 1) {
		return;
	}
	else {
		if (targetRow < i + size / 2 && targetCol >= j + size / 2) {
			answer[index] = 1;
			getAnswer(index + 1, size / 2, i, j + size / 2, targetRow, targetCol);
		}
		else if (targetRow < i + size / 2 && targetCol < j + size / 2) {
			answer[index] = 2;
			getAnswer(index + 1, size / 2, i, j, targetRow, targetCol);
		}
		else if (targetRow >= i + size / 2 && targetCol < j + size / 2) {
			answer[index] = 3;
			getAnswer(index + 1, size / 2, i + size / 2, j, targetRow, targetCol);
		}
		else {
			answer[index] = 4;
			getAnswer(index + 1, size / 2, i + size / 2, j + size / 2, targetRow, targetCol);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	cin >> n >> line;
	v.resize(n);
	answer.resize(n);
	for (int i = 0; i < n; i++) {
		v[i] = line[i] - '0';
	}
	cin >> x >> y;
	long long size = (1LL << n);
	pair<long long, long long> coord = getCoordinate(0, size, 0, 0);
	coord.first -= y;
	coord.second += x;
	if (coord.first < 0 || coord.first >= size || coord.second < 0 || coord.second >= size) {
		cout << "-1\n";
	}
	else {
		getAnswer(0, size, 0, 0, coord.first, coord.second);
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i];
		}
		cout << "\n";
	}
	return 0;
}