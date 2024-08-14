#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N;

void Solution() {
    int n, x;
    deque<int> q;

    for(int i = 0; i < N; i++) {
        cin >> n;

        if(n == 1 || n == 2) {
            cin >> x;

            n == 1 ? q.push_front(x) : q.push_back(x);
        }

        else if(n == 3 || n == 4) {
            if(q.empty()) cout << "-1\n";

            else {
                cout << (n == 3 ? q.front() : q.back()) << "\n";
                n == 3 ? q.pop_front() : q.pop_back();
            }
        }

        else if(n == 5) {
            cout << q.size() << "\n";
        }

        else if(n == 6) {
            cout << (q.empty() ? 1 : 0) << "\n";
        }

        else {
            if(q.empty()) cout << "-1\n";

            else {
                cout << (n == 7 ? q.front() : q.back()) << "\n";
            }
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