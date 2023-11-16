#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int B, C, D, cnt;
vector<int> buger;
vector<int> cide;
vector<int> drink;

void Solution() {
    int ans = 0, ansDC = 0;

    for (int i = 0;i < cnt; i++) {
        int sum = 0, t = 0;

        if (i < B) {
            sum += buger[i];
            t++;
        }
        if (i < C) {
            sum += cide[i];
            t++;
        }
        if (i < D) {
            sum += drink[i];
            t++;
        }

        ans += sum;
        if (t != 3) ansDC += sum;
        else ansDC += sum * 0.9;
    }     

    cout << ans << "\n" << ansDC;
}

void Input() {
    cin >> B >> C >> D;

    cnt = max(max(B, C), D);

    buger.resize(B);
    cide.resize(C);
    drink.resize(D);

    for (int i = 0;i < B;i++) cin >> buger[i];
    for (int i = 0;i < C;i++) cin >> cide[i];
    for (int i = 0;i < D;i++) cin >> drink[i];

    sort(buger.begin(), buger.end(), greater<int>());
    sort(cide.begin(), cide.end(), greater<int>());
    sort(drink.begin(), drink.end(), greater<int>());
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
