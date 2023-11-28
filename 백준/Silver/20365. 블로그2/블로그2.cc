#include <iostream>
#include <vector>

using namespace std;

int N;
string content;

void Solution() {
    int cntB = 0, cntR = 0;

    for (int i = 0;i < N - 1; i++) {
        if (content[i] == 'B' && content[i + 1] == 'R') cntB++;
        if (content[i] == 'R' && content[i + 1] == 'B') cntR++;
    }

    if (N != 1 && content[N - 1] == 'R') {
        int index = N - 2;

        while (index >= 0) {
            if (content[index--] == 'B') {
                cntR++;
                break;
            }
        }
    }
    if (N != 1 && content[N - 1] == 'B') {
        int index = N - 2;

        while (index >= 0) {
            if (content[index--] == 'R') {
                cntB++;
                break;
            }
        }
    }

    cout << min(cntB, cntR) + 1;
}

void Input() {
    cin >> N >> content;
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
