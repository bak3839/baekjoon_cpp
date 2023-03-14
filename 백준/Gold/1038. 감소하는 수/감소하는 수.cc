#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool finish;
int N, cnt = 9;
long long ans = -1;

void solve(int size, char n, string num) {
	for (char i = '0'; i <= n; i++) {
		if (num.size() == 0 && i == '0') continue;
		if (finish) return;
		num.push_back(i);

		if (num.size() == size) {
			cnt++;
			if (cnt == N) {
				finish = true;
				ans = stoll(num);
				break;
			}
		}
		else solve(size, i - 1, num);

		num.pop_back();
	}

	if (n == '9' && size < 10) solve(size + 1, '9', "");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	if (N <= 10) cout << N;

	else {
		solve(2, '9', "");
		cout << ans;
	}
	
	return 0;
}