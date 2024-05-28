#include <iostream>
#include <vector>

using namespace std;

int C, B, ans;
vector<int> v;

void Search(int sum, int x) {
    if(sum > C) {

        return;
    }

    ans = max(ans, sum);

    for(int i = x; i < B; i++) {
        Search(sum + v[i], i + 1);
    }
}

void Solution() {
    Search(0, 0);
    cout << ans;
}

void Input() {
    cin >> C >> B;

    v.resize(B);

    for(int i = 0;i < B; i++) {
        cin >> v[i];
    }
}

void Solve() {
    Input();
    Solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}