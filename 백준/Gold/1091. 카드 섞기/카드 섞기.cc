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
	string p = "", ans = "", p1 = "", p2 = "";
	char num;

	for (int i = 0; i < N; i++) {
		cin >> num;
		p.push_back(num);
		ans.push_back((i % 3) + 48);
		p2.push_back('0');
	}

	for (int i = 0; i < N; i++) cin >> s[i];

	p1 = p;

	while ((p1 != ans) && (p2 != ans)) {
		if (cnt % 2 == 0) {
			for (int i = 0; i < N; i++) p2[s[i]] = p1[i];
		}

		else {
			for (int i = 0; i < N; i++) p1[s[i]] = p2[i];
		}

		if (((p1 == p) || (p2 == p)) && cnt > 0) {
			cnt = -1;
			break;
		}

		++cnt;
	}

	cout << cnt;
	return 0;
}