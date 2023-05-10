#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> seq;
vector<int> ans;
int N;

void Solution() {
    ans.push_back(seq[0]);

    for (int i = 1; i < N; i++) {
        int now = seq[i];

        if (ans.back() < now) ans.push_back(now);

        else {
            int index = lower_bound(ans.begin(), ans.end(), now) - ans.begin();
            ans[index] = now;
        }
    }

    cout << ans.size();
}

void Input() {
    cin >> N;
    seq.resize(N);

    for (int i = 0; i < N; i++)
        cin >> seq[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}