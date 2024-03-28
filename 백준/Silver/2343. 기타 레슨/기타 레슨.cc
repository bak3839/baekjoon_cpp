#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, start;
vector<int> video;

void Solution() {
    int L = start, R = 1000000000, ans = 1000000000;

    while (L <= R) {
        int mid = (L + R) / 2, sum = 0, cnt = 1;

        for (int i = 0; i < N; i++) {
            if (sum + video[i] <= mid) 
                sum += video[i];

            else {    
                sum = video[i];
                cnt++;
            }
        }

        if (cnt <= M) {
            ans = min(ans, mid);
            R = mid - 1;
        }
        else
            L = mid + 1;
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;

    video.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> video[i];
        start = max(start, video[i]);
    }
        
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}