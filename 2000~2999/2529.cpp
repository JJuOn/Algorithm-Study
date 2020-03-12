#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long minNum = 9999999999, maxNum = 0;
char inequal[10];
bool visited[10];

long long vectorToLl(vector<int> v) {
	long long num = 0;
	for (int i = 0; i < v.size(); i++) {
		num += v[i];
		num *= 10;
	}
	return num / 10;
}

string llToString(long long num, int n) {
	string s;
	for (int i = 0; i < n; i++) {
		s += (num % 10) + '0';
		num /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

void DFS(int k, vector<int> v, int n) {
	if (v.size() == n) {
		long long num = vectorToLl(v);
		if (num > maxNum) {
			maxNum = num;
		}
		if (num < minNum) {
			minNum = num;
		}
		return;
	}
	else {
		if (inequal[k] == '<') {
			for (int i = v[v.size() - 1] + 1; i <= 9; i++) {
				if (!visited[i]) {
					visited[i] = true;
					v.push_back(i);
					DFS(k + 1, v, n);
					v.pop_back();
					visited[i] = false;
				}
			}
		}
		else if (inequal[k] == '>') {
			for (int i = v[v.size() - 1] - 1; i >= 0; i--) {
				if (!visited[i]) {
					visited[i] = true;
					v.push_back(i);
					DFS(k + 1, v, n);
					v.pop_back();
					visited[i] = false;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inequal[i];
	}
	for (int i = 0; i <= 9; i++) {
		visited[i] = true;
		v.push_back(i);
		DFS(0, v, n + 1);
		v.pop_back();
		visited[i] = false;
	}
	cout << llToString(maxNum, n + 1) << "\n" << llToString(minNum, n + 1) << "\n";
	return 0;
}