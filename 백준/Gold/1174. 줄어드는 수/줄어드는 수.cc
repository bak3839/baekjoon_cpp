#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool finish;
int N, res;
string ans = "-1";
vector<long long> v;

void Search(int cnt, int x, string num) {
    if (cnt == 0) {
        res++;
        v.push_back(stoll(num));
        if (res == N) finish = true;
        return;
    }

    if (x < 0) return;

    int start = num.size() == 0 ? 1 : 0;

    for (int i = start; i <= x; i++) {
        Search(cnt - 1, i - 1, num + to_string(i));
        if (finish) return;
    }
}

void Solution() {
    res = 1;
    v.push_back(0);

    if (N > 1023) cout << "-1";

    else {
        for (int i = 1; i <= 10; i++) {
            Search(i, 9, "");
            if (finish) break;
        }
        sort(v.begin(), v.end());

        cout << v[N - 1];
    }   
}

void Input() {
    cin >> N;
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
