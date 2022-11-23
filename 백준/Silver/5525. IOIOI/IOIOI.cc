#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s = "", p = "";
	int N, M;
	cin >> N >> M;
	cin >> s;

	int index = 0, cnt = 0, res = 0;
	
	while (index < M) {
		if (s[index] == 'I') {
			cnt = 0;
			while (index < M) {
				if (index + 2 < M && s[index + 1] == 'O' && s[index + 2] == 'I') {
					++cnt;
					index += 2;
				}
				else break;
			}
			if(cnt >= N) res += cnt - N + 1;
			++index;
		}
		else ++index;
	}

	cout << res;

	return 0;
}