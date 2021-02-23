#include <iostream>
#include <utility>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pair<int, int> fibonacci[41];
	bool visited[41] = { false };
	fibonacci[0] = make_pair(1, 0);
	fibonacci[1] = make_pair(0, 1);
	visited[0] = true;
	visited[1] = true;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (!visited[n]) {
			for (int i = 2; i <= n; i++) {
				if (!visited[i]) {
					fibonacci[i] = make_pair(fibonacci[i - 1].first + fibonacci[i - 2].first, fibonacci[i - 1].second + fibonacci[i - 2].second);
					visited[i] = true;
				}
			}
		}
		cout << fibonacci[n].first << " " << fibonacci[n].second << "\n";
	}
	return 0;
}