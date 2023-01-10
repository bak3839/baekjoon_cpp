#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, cnt = 0;
	cin >> N;
	vector<int> s(N);
	string p = "", ans = "", str = "";
	char num;

	for (int i = 0; i < N; i++) {
		cin >> num;
		p.push_back(num);
		ans.push_back((i % 3) + 48);
	}

	for (int i = 0; i < N; i++) cin >> s[i];

	str = p;

	while (str != ans) {
		string tmp = str;

		for (int i = 0; i < N; i++) str[s[i]] = tmp[i];

		if (str == p && cnt > 0) {
			cnt = -1;
			break;
		}

		++cnt;
	}

	cout << cnt;
	return 0;
}