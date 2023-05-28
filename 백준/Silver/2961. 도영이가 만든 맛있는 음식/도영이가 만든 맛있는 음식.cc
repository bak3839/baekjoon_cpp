#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int N, ans = 1000000001;
vector<pii> taste;

void Cook(int index, int sour, int bitter) {
    if (index >= N) {
        if (sour == 1 && bitter == 0) return;

        int res = sour - bitter;
        if (res < 0) res *= -1;
        ans = min(ans, res);
        return;
    }

    int s = taste[index].first;
    int b = taste[index].second;

    Cook(index + 1, sour * s, bitter + b);
    Cook(index + 1, sour, bitter);
}

void Solution() {
    Cook(0, 1, 0);
    cout << ans;
}

void Input() {
    cin >> N;
    taste.resize(N);

    for (int i = 0; i < N; i++) 
        cin >> taste[i].first >> taste[i].second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}