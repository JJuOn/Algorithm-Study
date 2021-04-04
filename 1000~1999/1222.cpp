#include <iostream>

using namespace std;

long long divisor[2000001];

long long max(long long a, long long b) {
	return a > b ? a : b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		divisor[a]++;
	}
	long long maxParticipants = 0;
	for (long long i = 1; i <= 2000000; i++) {
		long long cnt = 0;
		for (long long j = i; j <= 2000000; j += i) {
			cnt += divisor[j];
		}
		if (cnt >= 2) {
			maxParticipants = max(maxParticipants, cnt * i);
		}
	}
	cout << maxParticipants << "\n";
}