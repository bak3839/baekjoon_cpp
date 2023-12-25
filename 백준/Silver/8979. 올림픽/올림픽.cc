#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
    int num;
    int g;
    int s;
    int b;
}Medal;

int N, K;
vector<Medal> country;

bool cmp(Medal m1, Medal m2) {
    if (m1.g != m2.g) {
        return m1.g > m2.g;
    }
    else if (m1.s != m2.s) {
        return m1.s > m2.s;
    }
    else if (m1.b != m2.b) {
        return m1.b > m2.b;
    }

    return false;
}


void Solution() {
    int cnt = 1, prev = 1, ans = 1;

    for (int i = 1; i < N; i++) {
        Medal m1 = country[i - 1];
        Medal m2 = country[i];
        cnt++;

        if (m1.g != m2.g || m1.s != m2.s || m1.b != m2.b) {
            prev = cnt;
        }
        
        if (K == m2.num) {
            ans = prev;
            break;
        }
    }

    cout << ans;
}

void Input() {
    int num, g, s, b;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> num >> g >> s >> b;
        country.push_back({ num, g , s, b });
    }
    sort(country.begin(), country.end(), cmp);
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
