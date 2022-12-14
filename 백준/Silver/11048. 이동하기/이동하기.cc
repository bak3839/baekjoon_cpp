#include <iostream>
#include <vector>

using namespace std;

int map[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N, M, num;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> num;
			map[i][j] = max(num + map[i - 1][j], num + map[i][j - 1]);
			map[i][j] = max(map[i][j], num + map[i - 1][j - 1]);
		}
	}

	cout << map[N][M];
	return 0;
}