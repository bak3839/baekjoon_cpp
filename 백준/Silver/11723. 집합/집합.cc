#include <iostream>
#include <vector>

using namespace std;

int N;
vector<bool> S(21, false);

void Solution() {
    int x;
    string cmd;

    for (int i = 0; i < N; i++) {
        cin >> cmd;

        if (cmd == "add") {
            cin >> x;
            S[x] = true;
        }

        else if (cmd == "remove") {
            cin >> x;
            S[x] = false;
        }

        else if (cmd == "check") {
            cin >> x;
            if (S[x]) cout << "1\n";
            else cout << "0\n";
        }

        else if (cmd == "toggle") {
            cin >> x;
            S[x] = !S[x];
        }

        else if (cmd == "all") {
            for (int i = 1; i <= 20; i++)
                S[i] = true;
        }

        else if (cmd == "empty") {
            for (int i = 1; i <= 20; i++)
                S[i] = false;
        }
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
