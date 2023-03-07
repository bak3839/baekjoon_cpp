#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
int N, max_ans, idx, cnt;
bool check[8];
vector<int> num;
vector<int> res;

void calculator() {
	int sum = 0;

	for (int i = 0; i < N - 1; i++) {
		sum += abs(res[i] - res[i + 1]);
	}

	max_ans = max(max_ans, sum);
}

void search() {
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			res[idx++] = num[i];
			check[i] = true;
			cnt++;

			if (cnt == N) calculator();
			else search();

			check[i] = false;
			idx--;
			cnt--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	num.resize(N);
	res.resize(N);

	for (int i = 0; i < N; i++) cin >> num[i];
	search();

	cout << max_ans;
	return 0;
}