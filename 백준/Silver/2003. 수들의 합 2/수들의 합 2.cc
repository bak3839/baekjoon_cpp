#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> num;

void Solution() {
    int s = 0, e = 0, ans = 0, sum = num[0];

    while (s <= e && e < N) {
        if (s == e) {
            if (M == num[e++]) ans++;
            if(e < N) sum += num[e];
            continue;
        }

        if (sum > M) sum -= num[s++];

        else {
            e++;
            if (sum == M) ans++;
            if (e < N) sum += num[e];
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;
    num.resize(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}