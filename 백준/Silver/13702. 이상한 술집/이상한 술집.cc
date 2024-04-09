#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> alcohol;

void Solution() {
    long long L = 1, R = 2147483647, mid, ans = 0, cnt = 0;

    while(L <= R) {
        cnt = 0;
        mid = (L + R) / 2;

        for(int i = 0; i < N; i++) {
            cnt += alcohol[i] / mid;
        }

        if(cnt >= K) {           
            L = mid + 1;
            ans = mid;
        } else {
            R = mid - 1;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> K;

    alcohol.resize(N);

    for(int i = 0; i < N; i++) {
        cin >> alcohol[i];
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