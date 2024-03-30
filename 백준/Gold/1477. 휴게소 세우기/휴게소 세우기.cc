#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, Len;
vector<int> rest;

void Solution() {
    int L = 1, R = Len, mid, cnt, ans = 0;

    while(L <= R) {
        cnt = 0;
        mid = (L + R) / 2;

        for(int i = 1; i < rest.size(); i++) {
            int diff = rest[i] - rest[i - 1];

            cnt += (diff / mid);

            if(diff % mid == 0) {
                cnt--;
            }
        }

        if(cnt > M) {
            L = mid + 1;
        } else {
            ans = mid;
            R = mid - 1;
        }
    }

    cout << ans;
}

void Input() {
    int r;
    cin >> N >> M >> Len;

    rest.push_back(0);
    rest.push_back(Len);

    for(int i = 0; i < N; i++) {
        cin >> r;
        rest.push_back(r);
    }

    sort(rest.begin(), rest.end());
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