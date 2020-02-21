#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct ScoreType {
	string name;
	int korean;
	int english;
	int math;
};

bool CustomCompare(ScoreType s1, ScoreType s2) {
	if (s1.korean != s2.korean) {
		return s1.korean > s2.korean;
	}
	else {
		if (s1.english != s2.english) {
			return s1.english < s2.english;
		}
		else {
			if (s1.math != s2.math) {
				return s1.math > s2.math;
			}
			else {
				return s1.name < s2.name;
			}
		}
	}
}

int main() {
	int n;
	vector<ScoreType> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ScoreType s;
		cin >> s.name >> s.korean >> s.english >> s.math;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), CustomCompare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].name << "\n";
	}
	return 0;
}
