#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(string s1, string s2) {
	if (s1.size() < s2.size()) return 1;
	else if(s1.size() > s2.size()) return 0;
	else if (s1.size() == s2.size()) {
		int n1 = 0;
		int n2 = 0;
		for (int i = 0;i < s2.size();i++) {
			if ('1' <= s1[i] && s1[i] <= '9') n1 += s1[i] - '0';
			if ('1' <= s2[i] && s2[i] <= '9') n2 += s2[i] - '0';
		}

		if (n1 < n2) return 1;
		else if (n1 > n2) return 0;
		else {
			if (s1 < s2) return 1;
			else return 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<string> v(N);

	for (int i = 0;i < N;i++) cin >> v[i];
	sort(v.begin(), v.end(), cmp);

	for (int i = 0;i < N;i++) cout << v[i] << "\n";
	return 0;
}