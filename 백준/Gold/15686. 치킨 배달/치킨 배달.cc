#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

vector<pii> home;
vector<pii> chicken;
vector<int> sale;
bool check[51];
int N, M, ans = 2100000000;

void calculator_dist() {
	int min_dist, sum = 0;

	for (int i = 0; i < home.size(); i++) {
		int x = home[i].first;
		int y = home[i].second;
		min_dist = abs(x - chicken[sale[0]].first) + abs(y - chicken[sale[0]].second);

		for (int j = 1; j < sale.size(); j++) {
			min_dist = min(abs(x - chicken[sale[j]].first) + abs(y - chicken[sale[j]].second), min_dist);
		}
		sum += min_dist;
	}
	ans = min(ans, sum);
}

void solution(int cnt, int start) {
	for (int i = start; i < chicken.size(); i++) {
		if (check[i]) continue;

		cnt++;
		check[i] = true;
		sale.push_back(i);

		if (cnt < M) solution(cnt, i + 1);
		else if (M == cnt) calculator_dist();

		cnt--;
		check[i] = false;
		sale.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> N >> M;	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n;
			if (n == 1) home.push_back({ i, j });
			else if (n == 2) chicken.push_back({ i, j });
		}
	}

	solution(0, 0);
	cout << ans;
	return 0;
}