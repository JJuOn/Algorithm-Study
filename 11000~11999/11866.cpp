#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	queue<int> q;
	vector<int> popped;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		popped.push_back(q.front());
		q.pop();
	}
	cout << "<";
	for (int i = 0; i < popped.size()-1; i++) {
		cout << popped[i] << ", ";
	}
	cout << popped[popped.size() - 1] << ">\n";
	return 0;
}