#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	long long v;
	long long l;
}Beer;

struct cmp{
	bool operator()(Beer b1, Beer b2) {
		if (b1.l > b2.l) return 1;
		else if (b1.l == b2.l) {
			if (b1.v < b2.v) return 1;
			else return 0;
		}
		else return 0;
	}
};

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

	priority_queue<Beer, vector<Beer>, cmp> pq;
	priority_queue<Beer, vector<Beer>, cmp2> pq2; 
	long long count = 0, M, l, N, K, v, max = 0;
	Beer b;

	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		cin >> v >> l;
		b.v = v;
		b.l = l;
		pq.push(b);
	}
	long long size;
	for (int i = 0; i < K; i++) {
		size = pq2.size();

		if (count >= M && size == N) break;

		if (size < N) {
			pq2.push(pq.top());
			count += pq.top().v;
			max = pq.top().l;
			pq.pop();
		}

		else {
			if (count < M && pq2.top().v < pq.top().v) { // 호감도 못채운 상태 다음 술이 현재 가진 호감도가 가장 낮은 술이랑 교체
				count = count - pq2.top().v + pq.top().v;
				max = pq.top().l;
				pq2.pop();
				pq2.push(pq.top());
				pq.pop();
			}
			else pq.pop();
		}
	}

	if (count < M) cout << "-1";
	else cout << max;
	return 0;
}