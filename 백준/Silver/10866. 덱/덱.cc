#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void Input() {
    deque<int> q;
    int N, n;
    string s;
    cin >> N;

    for (int i = 0;i < N;i++) {
        cin >> s;

        if (s == "push_front" || s == "push_back") {
            cin >> n;
            s == "push_front" ? q.push_front(n) : q.push_back(n);
        }

        else if (s == "pop_front" || s == "pop_back") {
            if (q.size() == 0) {
                cout << -1 << "\n";
                continue;
            }
            n = s == "pop_front" ? q.front() : q.back();
            s == "pop_front" ? q.pop_front() : q.pop_back();
            cout << n << "\n";
        }

        else if (s == "front" || s == "back") {
            if (q.size() == 0) {
                cout << -1 << "\n";
                continue;
            }
            n = s == "front" ? q.front() : q.back();
            cout << n << "\n";
        }

        else if (s == "size") cout << q.size() << "\n";
        else cout << (q.empty() ? 1 : 0) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    return 0;
}