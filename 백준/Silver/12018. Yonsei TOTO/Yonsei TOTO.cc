#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

void Solution() {
    int p, l;
  
    vector<int> res;

    for (int i = 0;i < N;i++) {
        int m;
        cin >> p >> l;

        vector<int> mileage(p);

        for (int j = 0; j < p; j++) {
            cin >> mileage[j];
        }

        if (p < l) {
            res.push_back(1);
            continue;
        }
   
        sort(mileage.begin(), mileage.end(), greater<int>());
        res.push_back(mileage[l - 1]);
    }

    sort(res.begin(), res.end());

    int ans = 0;

    for (int i = 0;i < res.size();i++) {
        if (M >= res[i]) {
            M -= res[i];
            ans++;
        }
        else break;
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;
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
