#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	long long v;
	long long l;
}Beer;


bool cmp(Beer b1, Beer b2) {
	if (b1.l < b2.l) return 1;
	else if (b1.l == b2.l) {
		if (b1.v < b2.v) return 1;
		else return 0;
	}
	else return 0;
}


struct cmp2 {
	bool operator()(Beer b1, Beer b2) {
		if (b1.v > b2.v) return 1;
		else if (b1.v == b2.v) {
			if (b1.l < b2.l) return 1;
			else return 0;
		}
		else return 0;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<Beer, vector<Beer>, cmp2> pq2;
	long long count = 0, M, l, N, K, v, max = 0;
	vector<Beer> p;
	Beer b;

	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		cin >> v >> l;
		b.v = v;
		b.l = l;
		p.push_back(b);
	}

	sort(p.begin(), p.end(), cmp);

	for (int i = 0; i < K; i++) {
		cout << p[i].v << " " << p[i].l << "\n";
	}

	for (int i = 0; i < K; i++) {
		if (count >= M && pq2.size() == N) break;

		if (pq2.size() < N) {
			pq2.push(p[i]);
			count += p[i].v;
			max = p[i].l;
		}

		else {
			if (count < M && pq2.top().v < p[i].v) { // 호감도 못채운 상태 다음 술이 현재 가진 호감도가 가장 낮은 술이랑 교체
				count = count - pq2.top().v + p[i].v;
				max = p[i].l;
				pq2.pop();
				pq2.push(p[i]);
			}
		}
	}

	if (count < M) cout << "-1";
	else cout << max;
	return 0;
}