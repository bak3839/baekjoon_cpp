#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, C;
vector<char> v;

bool check(char ch) {
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
	else return false;
}

void solve(int cnt, int s, string sub) {
	bool pass = false;

	for (int i = s; i < C; i++) {
		sub.push_back(v[i]);
		if (check(v[i])) {
			cnt++;
			pass = true;
		}
		
		if (sub.size() == L) {
			if (cnt >= 1 && L - cnt >= 2) {
				cout << sub << "\n";
			}			
		}
		else solve(cnt, i + 1, sub);

		sub.pop_back();
		if (pass) {
			cnt--;
			pass = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> L >> C;
	v.resize(C);

	for (int i = 0; i < C; i++) cin >> v[i];
	sort(v.begin(), v.end());
	
	solve(0, 0, "");

	return 0;
}