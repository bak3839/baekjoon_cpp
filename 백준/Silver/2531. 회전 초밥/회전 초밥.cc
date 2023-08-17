#include <iostream>
#include <vector>

using namespace std;

int N, d, k, c;

vector<int> sushi;
vector<int> exist;

void Solution() {
    int ans = 0, res = 1;

    exist[c]++;

    for (int i = 0; i < k; i++) {
        int now = sushi[i];

        if (exist[now] == 0) {
            res++;
            ans = max(ans, res);
        }
       
        exist[now]++;     
    }

    for (int i = 1; i < N; i++) {
        int next = sushi[(i + k - 1) % N];
        int prev = sushi[i - 1];

        exist[prev]--;
        if (exist[prev] == 0) res--;

        if (exist[next] == 0) res++;
        exist[next]++;

        ans = max(ans, res);
    }

    cout << ans;
}

void Input() {
    cin >> N >> d >> k >> c;

    sushi.resize(N);
    exist.resize(d + 1, 0);

    for (int i = 0; i < N; i++)
        cin >> sushi[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}