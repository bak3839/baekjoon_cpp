#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Data{
    int l;
    int r;
    bool d;
    Data(int L, int R, bool D) : l(L), r(R), d(D) {}
};

int N;

void Solution() {
    bool D;
    int L, R;
    string word;
    queue<Data> q;

    for (int i = 0; i < N; i++) {
        int ans = 2;
        cin >> word;

        q.push(Data(0, word.size() - 1, false));

        while (!q.empty()) {
            L = q.front().l;
            R = q.front().r;
            D = q.front().d;
            q.pop();

            if (L >= R) {
                ans = (D ? 1 : 0);
                break;
            }

            if (word[L] != word[R]) {
                if (D) continue;

                q.push(Data(L + 1, R, true));
                q.push(Data(L, R - 1, true));
            }
            else {
                q.push(Data(L + 1, R - 1, D));
            }
        }
        while (!q.empty()) q.pop();

        cout << ans << "\n";
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
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}