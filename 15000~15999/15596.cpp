#include <vector>
using namespace std;
long long sum(vector<int> &a) {
	long long ans = 0;
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++) {
		ans += (*it);
	}
	return ans;
}