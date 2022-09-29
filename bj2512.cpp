#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> req; // 요청금액을 담을 배열
	int N, num, sum, budget, res = 0, low, high = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		req.push_back(num);
		high = max(num, high); // 가장 큰 요청 액수
	}

	cin >> budget; // 총 예산액

	low = budget / N;
	int mid;

	while (low <= high) {
		sum = 0;
		mid = (low + high) / 2;

		for (int i = 0; i < req.size(); i++) { 
			sum += min(mid, req[i]); // 상한액과 요청액수를 비교하여 최소값 sum에 더하기
		}

		if (sum > budget) high = mid - 1; // 예산보다 합산액이 크면 high를 낮추기

		else { // 예산보다 합산액이 적으면 low증가
			low = mid + 1;
			res = max(mid, res); // res와 mid를 비교하여 더 큰 상한액 저장
		}
	}

	cout << res;
	return 0;
}