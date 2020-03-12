#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int E, S, M, e = 0, s = 0, m = 0, count = 1;
	cin >> E >> S >> M;
	while (true) {
		if (e + 1 == E && s + 1 == S && m + 1 == M) {
			cout << count << "\n";
			break;
		}
		else {
			e = (e + 1) % 15;
			s = (s + 1) % 28;
			m = (m + 1) % 19;
			count++;
		}
	}
	return 0;
}