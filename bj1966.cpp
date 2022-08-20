#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
	int index; // 순서
	int imp;   // 중요도
}element;

int max_rank(int rank[]) { // 가장 높은 중요도 반환
	for (int i = 9; i > 0; i--) {
		if (rank[i] != 0) {
			rank[i]--;
			return i;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<element> q;
	element tmp;

	int test_case, N, M, num;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		int rank[10] = { 0, };
		int index = 0, count = 0;

		cin >> N; // 요소의 개수
		cin >> M; // 원하는 위치
		while (index < N) {
			cin >> num;
			rank[num]++;
			tmp.index = index++;
			tmp.imp = num;
			q.push(tmp);
		}

		while (1) {
			int max = max_rank(rank); // 가장 높은 중요도 반환
			while (q.front().imp != max) { // 맨 앞에 imp가 max가 아니면 뒤로 이동
				q.push(q.front());
				q.pop();
			}
			count++; // max를 출력했으므로 +1 해주고 만약 원하는 위치의 값이였으면 count 출력
			if (q.front().index == M) {
				cout << count << "\n";
				break;
			}
			q.pop();
		}
		while (!q.empty()) q.pop();
	}
	return 0;
}