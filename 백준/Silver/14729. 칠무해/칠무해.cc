#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> counting;

void Solution() {
    int cnt = 0;

    for (int i = 0; i <= 100000; i++) {
        if (!counting[i]) continue;

        if (cnt >= 7) break;

        while (counting[i]-- && cnt++ < 7)
            printf("%.3f\n", (double)i / 1000);
    }
}

void Input() {
    cin >> N;

    counting.resize(100001, 0);

    for (int i = 0; i < N; i++) {
        double point;
        cin >> point;
        counting[(int)(point * 1000)]++;
    }
}

void Solve() {
    Input();
    Solution();
}

int main() {
    Solve();
    return 0;
}