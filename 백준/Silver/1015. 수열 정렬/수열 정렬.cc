#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> num, sortNum, ans;

void Solution() {
    for (int i = 0; i < N; i++) {
        int t = num[i];

        for (int j = 0; j < N; j++) {
            if (sortNum[j] == t) {
                ans.push_back(j);
                sortNum[j] = -1;
                break;
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
}

void Input() {
    cin >> N;

    num.resize(N);
    sortNum.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> num[i];
        sortNum[i] = num[i];
    }

    sort(sortNum.begin(), sortNum.end());
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