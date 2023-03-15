#include <iostream>
#include <vector>

using namespace std;

int N, max_ans = -1000000001, min_ans = 1000000001;
int oper[4];
vector<int> num;

void solve(int idx, int sum) {
	if (idx == N) {
		max_ans = max(max_ans, sum);
		min_ans = min(min_ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int sub = 0;
		if (oper[i] == 0) continue;

		oper[i]--;
		switch (i){		
		case 0:		
			sub = sum + num[idx];
			break;
		case 1:
			sub = sum - num[idx];
			break;
		case 2:
			sub = sum * num[idx];
			break;
		case 3:
			sub = sum / num[idx];
			break;
		}

		solve(idx + 1, sub);
		oper[i]++;
	}
}
	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	num.resize(N);

	for (int i = 0; i < N; i++) cin >> num[i];
	for (int i = 0; i < 4; i++) cin >> oper[i];

	solve(1, num[0]);

	cout << max_ans << "\n" << min_ans;
	return 0;
}