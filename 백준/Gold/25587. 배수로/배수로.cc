#include <iostream>
#include <vector>

using namespace std;

int cnt;
int parent[100001];
vector<pair<int, int>> city;
vector<int> rain;

int getRoot(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = getRoot(parent[a]);
}

bool find(int a, int b) {
	a = getRoot(a);
	b = getRoot(b);
	if (a == b) return true;
	else return false;
}

void uni(int a, int b) {
	bool over = false;

	a = getRoot(a);
	b = getRoot(b);

	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	parent[b] = a;

	if (city[a].first < rain[a]) cnt -= city[a].second;
	if (city[b].first < rain[b]) cnt -= city[b].second;

	city[a].first += city[b].first;
	city[a].second += city[b].second;
	rain[a] += rain[b];

	if (city[a].first < rain[a]) cnt += city[a].second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, menu;
	cin >> N >> M;

	city.resize(N + 1);
	rain.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		cin >> city[i].first;
		city[i].second = 1;
	}

	for (int i = 1; i <= N; i++) {
		cin >> rain[i];
		if (rain[i] > city[i].first) ++cnt;
	}

	while (M--) {
		cin >> menu;
		
		if (menu == 1) {
			int a, b;
			cin >> a >> b;

			if (!find(a, b)) {
				uni(a, b);
			}
		}

		else if (menu == 2) {
			cout << cnt << "\n";
		}
	}

	return 0;
}