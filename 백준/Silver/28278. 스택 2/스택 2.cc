#include <iostream>
#include <stack>

using namespace std;



void Solution() {
    stack<int> s;
    int N, cmd, n;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> cmd;

        switch (cmd){
        case 1:
            cin >> n;
            s.push(n);
            break;

        case 2:
            if (s.empty()) cout << -1 << "\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
            break;

        case 3:
            cout << s.size() << "\n";
            break;

        case 4:
            cout << s.empty() << "\n";
            break;

        case 5:
            if (s.empty()) cout << -1 << "\n";
            else cout << s.top() << "\n";
            break;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solution();
    return 0;
}
