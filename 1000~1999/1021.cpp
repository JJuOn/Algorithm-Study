#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int moveLeft(deque<int> d, int target) {
	int count = 0;
	while (d.front() != target) {
		d.push_back(d.front());
		d.pop_front();
		count++;
	}
	return count;
}

int moveRight(deque<int> d, int target) {
	int count = 0;
	while (d.front() != target) {
		d.push_front(d.back());
		d.pop_back();
		count++;
	}
	return count;
}

int main() {
	int n, m;
	deque<int> d;
	vector<int> target;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		d.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		target.push_back(temp);
	}
	int count = 0;
	for (int i = 0; i < target.size(); i++) {
		int left = moveLeft(d, target[i]);
		int right = moveRight(d, target[i]);
		if (left < right) {
			count += left;
			for (int i = 0; i < left; i++) {
				d.push_back(d.front());
				d.pop_front();
			}
		}
		else {
			count += right;
			for (int i = 0; i < right; i++) {
				d.push_front(d.back());
				d.pop_back();
			}
		}
		d.pop_front();
	}
	cout << count << "\n";
	return 0;
}